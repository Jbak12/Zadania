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

int main(int argc, char** argv) {
    printf(argv[0]);
    char* file_to_write = argv[1];
    char* pipe_name = argv[2];
    consume(file_to_write, pipe_name);
}