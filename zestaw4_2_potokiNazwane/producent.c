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

int main(int argc, char** argv) {
    char* file_to_read = argv[1];
    char* pipe_name = argv[2];
    produce(file_to_read, pipe_name);
}