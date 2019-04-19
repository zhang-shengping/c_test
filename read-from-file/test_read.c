#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<utmp.h>

int main(){
    int size = 0;
    struct utmp utmp_buffer;
    int buffer_size = sizeof(utmp_buffer);

    int fd = open(UTMP_FILE, O_RDONLY);

    if(fd == -1){
        printf("error happens with open file");
        perror(UTMP_FILE);
    }
    int c = 0;
    while ((size = read(fd, &utmp_buffer, buffer_size)) == buffer_size){
        // left align wihtout turncate
        printf("%-8s", "aaaaaaaaaaaaaaaaaa");
        printf(" ");
        // left align, turncated if access .8
        printf("%-8.8s", "aaaaaaaaaaaaaaaaaa");
        printf(" ");
        printf("%-8s", utmp_buffer.ut_user);
        printf(" ");
        printf("%-8s", utmp_buffer.ut_host);
        printf(" ");
        printf("\n");
    }
}
