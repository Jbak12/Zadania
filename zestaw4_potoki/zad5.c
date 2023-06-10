#include <unistd.h>
#include <err.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/param.h>
#include <limits.h>
char* file_to_write;
char* file_to_read;
char* pipe_name;

void remove_pipe() {
    if (remove(pipe_name) == 0) {
        printf("Potok nazwany został usunięty.\n");
    } else {
        perror("remove pipe error");
    }

}

void consume(char* file_to_write, char* pipe_name) {
    int write_descriptor = open(file_to_write, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (write_descriptor == -1) perror("aaaa open error");
    int fifo_descriptor = open(pipe_name,O_RDONLY,0644);
    if (fifo_descriptor == -1) perror("open fifo error");
    size_t rand_bytes = rand() % 512 + 1;
    size_t bytes_read = 1;
    size_t bytes_wrote;
    size_t bytes_wrote_to_terminal;
    char buffer[512];
    while (1) {
        sleep(rand()%4);
        /*If all file descriptors referring to the write end of a pipe have
       been closed, then an attempt to read(2) from the pipe will see
       end-of-file (read(2) will return 0)*/
        bytes_read = read(fifo_descriptor, buffer, rand_bytes);
        if (bytes_read == 0) break;
        if (bytes_read == -1) {
            perror("read error z consume");
            exit(EXIT_FAILURE);
        }
        bytes_wrote = write(write_descriptor, buffer, bytes_read);
        if (bytes_wrote == -1) {
            perror("write error z consume");
            exit(EXIT_FAILURE);
        }
        bytes_wrote_to_terminal = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_wrote_to_terminal == -1) {
            perror("write to terminal error z consume");
            exit(EXIT_FAILURE);
        }

    }
}

void produce(char* file_to_read, char* pipe_name) {

    int read_descriptor = open(file_to_read, O_RDONLY, 0644);
    if (read_descriptor == -1) perror("open error");
    int fifo_descriptor = open(pipe_name,O_WRONLY | O_CREAT | O_TRUNC,0644);
    if (fifo_descriptor == -1) perror("open fifo error");
    size_t rand_bytes = rand() % 512 + 1;
    size_t bytes_read = 1;
    size_t bytes_wrote;
    char buffer[512];

    while (1) {
        sleep(rand()%4);
        bytes_read = read(read_descriptor, buffer, rand_bytes);
        if (bytes_read == 0) break;
        if (bytes_read == -1) {
            perror("read error z produce");
            exit(EXIT_FAILURE);
        }
        bytes_wrote = write(fifo_descriptor, buffer, bytes_read);
        if (bytes_wrote == -1) {
            perror("write error z produce");
            exit(EXIT_FAILURE);
        }
    }
}

void handle_params(int argc, char** argv) {
    if (!(argc == 4)) {
        perror("zla ilosc argumentow");
        exit(EXIT_FAILURE);
    }
    file_to_read = argv[1];
    file_to_write = argv[2];
    pipe_name = argv[3];
}

int main(int argc, char** argv) {
    handle_params(argc, argv);
    if(mkfifo(pipe_name,0644) == -1) {
        perror("named pipe error\n");
        exit(EXIT_FAILURE);
    }
    switch (fork()) {
        case 0:
            consume(file_to_write, pipe_name);
            break;
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        default:
            produce(file_to_read, pipe_name);
            break;
    }
    atexit(remove_pipe);
    return 0;
}
