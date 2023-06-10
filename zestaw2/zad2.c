#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    //printf("%s\n", argv[1]);
    if(argc != 2) {
        printf("Wrong number of command line arguments");
        return 0;
    }


    printf( "PROCES MACIERZYSTY: user id: %d group id: %d process id: %d parent id: %d process group id:%d\n",
            getuid(), getgid(), getpid(), getppid(), getpgid(getpid())
    );
    pid_t pid;
    for(int i = 0; i<3; i++) {
        pid = fork();
        switch (pid) {
        case -1:
            perror("fork error");
            exit(1);
            break;
        case 0:
            execl(argv[1],NULL);
            perror("execl error");
            exit(1);
            break;
        default:
            wait(NULL);
            break;
        }
    }
}