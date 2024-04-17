#include <unistd.h>
#include<err.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include "params_handling.h"
extern const char * const sys_siglist[];
void sig_callback(int sig) {
    printf("przyjalem sygnal  numer %d ,super :))))\n", sig);
}

void handle_signals() {
    switch (handling_mode){
        case Default:
            printf("default\n");
            signal(signal_code,SIG_DFL);
            break;
        case Ignore:
            printf("ignore\n");
            signal(signal_code,SIG_IGN);
            break;
        case Custom:
            printf("custom\n");
            signal(signal_code,sig_callback);
            break;
    }
}


int main(int argc, char** argv) {
    printf("pid procesu w zadA: %d\n", getpid());
    handle_params(argc,argv);
    handle_signals();
    // printf(sys_siglist[1]);
    pause();
    return 0;
}
