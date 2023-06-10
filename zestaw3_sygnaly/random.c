#include <stdlib.h>
#include <stdio.h>
enum program_mode {Default = 1, Ignore = 2, Intercept = 3};
enum program_mode handling_mode;
int main(int argc, char** argv) {


    printf("liczba argumentow: %s \n",argv[0]);

    handling_mode = atoi(argv[1]);
    if(handling_mode == Ignore) {
        printf("sukces\n");
    }

    return 0;
}
