enum signal_mode {Default = 0, Ignore = 1, Custom = 2} handling_mode;
char* handling_mode_string;
int signal_code;
char* signal_code_string;
void handle_params(int argc, char** argv) {
    // printf("argc: %d\n", argc);
    // for(int i = 0; i<argc; i++){
    //     printf("%s\n", argv[i]);
    // }

    //uzywam guard statement dla czytelnosci i unikania wielu wcięćś
    if (!(argc==3)) {
        perror("nieodpowiednia ilosc argumentow programu\n");
        _exit(1);
        return;
    }
    if(atoi(argv[1]) > 2 ) {
        perror("zly tryb pracy\n" );       
        _exit(1);
        return;
    }
    if(atoi(argv[2])> 31 || atoi(argv[2])< 0) {
         perror("zly kod  sygnału\n" );       
        exit(1);
        return;
    }
    handling_mode_string = argv[1];
    handling_mode  = atoi(handling_mode_string);
    signal_code_string = argv[2];
    signal_code = atoi(signal_code_string);
}
