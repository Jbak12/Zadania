#include <unistd.h>
#include <err.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include "params_handling.h"
#include "itoa.h"
extern int signal_code;
int main(int argc, char** argv) {
    handle_params(argc, argv);
    int child_process_pid = fork();
    switch (child_process_pid) {
    case -1:
        perror("aaaa eror\n");
        break;
    case 0:        
        printf("jest to dziecko");
        if(execl("./zadA.x","./zadA.x" ,handling_mode_string ,signal_code_string, NULL) == -1) {
            perror("execl error");
        }
    
    default:
        sleep(1);
        if(kill(child_process_pid, 0) == -1) {
            perror("nie ma procesu : /");
            exit(1);
        }
        if(kill(child_process_pid,signal_code) == -1) {
            perror("zabijanie dziecka sie nie powiodlo");
            exit(1);
        }
        break;
    }

    if(handling_mode == Ignore) {
        sleep(2);
        kill(child_process_pid,SIGKILL);
    }
    return 0;
}
