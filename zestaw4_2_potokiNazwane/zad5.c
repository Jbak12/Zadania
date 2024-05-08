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
            execl("./konsument.x", "/.konsument.x", file_to_write, pipe_name, NULL);
            break;
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        default:
            execl("./producent.x", "/.producent.x", file_to_read, pipe_name, NULL);
            break;
    }
    atexit(remove_pipe);
    return 0;
}
