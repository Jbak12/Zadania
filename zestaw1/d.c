#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define FORKS 3

int main() {
    int i;
    printf("pid procesu: %d, ppid procesu: %d, gpid procesu: %d\n ", getpid(), getppid(), getpgid(getpid()));
    for ( i = 0; i < FORKS; i++) {
        switch (fork()){
        case -1:
            perror("fork error");
            exit(1);
            break;
        case 0:
            printf("pid procesu: %d, ppid procesu: %d, gpid procesu: %d\n ", getpid(), getppid(), getpgid(getpid()));
            sleep(1);
            break;
        default:
            break;
        }
    }
    sleep(4);
    
}