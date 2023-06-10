#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    printf( "user id: %d group id: %d process id: %d parent id: %d process group id:%d\n",
            getuid(), getgid(), getpid(), getppid(), getpgid(getpid())
    );
}