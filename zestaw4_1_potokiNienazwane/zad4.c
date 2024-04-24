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

void consume(char* file_to_write, int fd[2]) {
    if (close(fd[1]) == -1) {
        perror("close error z produce");
        exit(EXIT_FAILURE);
    }
    int write_descriptor = open(file_to_write, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    size_t rand_bytes = rand() % 512 + 1;
    size_t bytes_read = 1;
    size_t bytes_wrote;
    size_t bytes_wrote_to_terminal;
    char buffer[512];
    while (1) {
        sleep(rand()%4);
        bytes_read = read(fd[0], buffer, rand_bytes);
        if (bytes_read == 0) break; // dojscie do końca pliku
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

    if (close(fd[0]) == -1) {
        perror("close error z produce");
        exit(EXIT_FAILURE);
    }
}

void produce(char* file_to_read, int fd[2]) {
    if (close(fd[0]) == -1) {
        perror("close errorz produce");
        exit(EXIT_FAILURE);
    }

    int read_descriptor = open(file_to_read, O_RDONLY, 0644);
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
        bytes_wrote = write(fd[1], buffer, bytes_read);
        if (bytes_wrote == -1) {
            perror("write error z produce");
            exit(EXIT_FAILURE);
        }
    }

    if (close(fd[1]) == -1) {
        perror("close error z produce");
        exit(EXIT_FAILURE);
    }
}

void handle_params(int argc, char** argv) {
    if (!(argc == 3)) {
        perror("zla ilosc argumentow");
        exit(EXIT_FAILURE);
    }
    file_to_read = argv[1];
    file_to_write = argv[2];
}

int main(int argc, char** argv) {
    int fds[2];
    if (pipe(fds) == -1) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }
    handle_params(argc, argv);
    switch (fork()) {
        case 0:
            consume(file_to_write, fds);
            break;
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        default:
            produce(file_to_read, fds);
            break;
    }
    return 0;
}
