#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("identyfikator uzytkownika: %d\n ", getuid());
    printf("identyfikator grupy uzytkownika: %d\n ", getgid());
    printf("identyfikator procesu macierzystego: %d\n ", getppid());
    printf("identyfikator procesu: %d\n ", getppid());
    printf("identyfikator grupy procesow: %d\n ", (getpgid(getpid())));
}