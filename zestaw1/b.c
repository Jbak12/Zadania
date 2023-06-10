#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define FORKS 3
int main(int argc, char* argv[]) {
    printf("%d, %d \n", getpid(), getppid());
    int id1 = fork();
    int id2 = fork();
    int id3 = fork();
    printf("%d, %d \n", getpid(), getppid());
    while(wait(NULL) != -1 || errno != ECHILD);
}
