#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>

#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);
int see_more(FILE *);
void set_output_mode();

int main(int argc, char * argv[])
{
    FILE *fp;

    if (argc == 1)
        do_more(stdin);
    else
        while(--argc)
            if((fp = fopen(*++argv, "r")) != NULL){
                do_more(fp);
                fclose(fp);
            }else
                exit(1);
}

void do_more(FILE * fp)
{
    char line[LINELEN];
    int num_of_lines = 0;
    int reply;

    FILE * fp_tty;
    fp_tty = fopen("/dev/tty", "r");
    if(fp_tty == NULL)
        exit(1);

    while(fgets(line, LINELEN, fp)){
        if (num_of_lines == PAGELEN){
            reply = see_more(fp_tty);
            if (reply == 0)
                break;
            num_of_lines -= reply;
        }
        if (fputs(line, stdout) == EOF)
            exit(1);
        num_of_lines ++;
    }
}

void set_output_mode(){
    struct termios term;

    int err = tcgetattr(STDIN_FILENO, &term);
    if(err == -1){
        printf("Can not get attribute of slave terminal");
        exit(1);
    }

    printf("the original term.c_iflag is %x", term.c_iflag);

    err = tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
    if(err == -1){
        printf("Can no t set attribute of slave terminal");
        exit(1);
    }
}

int see_more(FILE * cmd)
{
    int c;
    printf("\033[7m more? \033[m\n");
    while((c=getc(cmd))!= EOF){
        if (c == 'q')
            return 0;
        if (c == ' ')
            return PAGELEN;
        if (c == '\n')
            return 1;
    }
}
