#include <unistd.h>
#include <err.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include "params_handling.h"
#define looking_for_process_constant 0
int main(int argc, char** argv) {
    pid_t pid;
    pid = fork();
    handle_params(argc,argv);
    switch (pid) {
    case 0: 
        // signal(signal_code,SIG_IGN);
        setpgid(getpid(),0);
        printf("jestem typem typu dziecko o id %d i rodzicu nr %d i grupie numer %d \n", getpid(),getppid(), getpgid(getpid()));
        // wait(NULL);
        pid_t pidd;
        for(int i = 0;i<3;i++) {
            pidd = fork();
            switch (pidd)
            {
            case 0:
                if(execl("./zadA.x","./zadA.x" ,handling_mode_string ,signal_code_string, NULL) == -1) {
                    perror("execl error");
                    exit(EXIT_FAILURE);
                }
                break;
            
            default:
                break;
            }

        }
        break;
    
    default:
        sleep(1);       
        printf("jestem procesem id %d i rodzicu nr %d i dziecku nr%d i grupie nr %d \n", getpid(),getppid(),pid, getpgid(getpid()));
        if(kill(-pid, 0) == -1) {
            perror("o nie nie znalazłem zadnego");
            exit(EXIT_FAILURE);
        }
        kill(-pid,signal_code);
        break;
    }
}