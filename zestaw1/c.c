#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define FORKS 3
int main(int argc, char* argv[]) {
    int id1 = fork();
    int id2 = fork();
    int id3 = fork();
    if(id1 == 0 || id2 == 0 || id3 == 0) {
        sleep(1);
    }    
    printf("%d, %d \n", getpid(), getppid());
}
