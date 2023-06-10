#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define FORKS 3
int main(int argc, char* argv[]) {
    int i = 0;
    printf("current id: %d, parent id: %d , group id: %d\n", getpid(), getppid(), getpgid(getpid()) );
    for (int i = 0; i < FORKS; i++) {
        //int id = fork();
        switch (fork()) {
        case -1:
            perror("fork error");
            exit(1);
            break;
        case 0:
            setpgid(getpid(), 0);
            break;    
        default:
            wait(NULL);
            break;
        }
    }
    printf("current id: %d, parent id: %d , group id: %d\n", getpid(), getppid(), getpgid(getpid()) );

}
