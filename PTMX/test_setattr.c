#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>

void set_output_mode();

int main(){
    set_output_mode();

    char c;
    while((c=getchar()) != EOF)
        putchar(c);
}

void set_output_mode(){
    struct termios term;

    int err = tcgetattr(STDIN_FILENO, &term);
    if(err == -1){
            printf("Can not get attribute of slave terminal \n");
            exit(1);
        }

    printf("the original term.c_iflag is %#06x \r", term.c_iflag);
    printf("the original term.c_oflag is %#06x \r", term.c_oflag);
    printf("the original term.c_cflag is %#06x \r", term.c_cflag);
    printf("the original term.c_lflag is %#06x \r", term.c_lflag);
    //printf("the original term.cc_t is %0x", term.c_cc);

    //printf("OCRNL is %#06x \n", OCRNL);
    //printf("INLCR is %#06x \n", INLCR);
    //printf("IGNCR is %#06x \n", IGNCR);
    printf("ICRNL is %#06x \n", ICRNL);

    //term.c_iflag |= IGNCR;

    printf("the original term.c_iflag is %#06x \n", term.c_iflag);

    err = tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
    if(err == -1){
            printf("Can no t set attribute of slave terminal \n");
            exit(1);
        }
}
