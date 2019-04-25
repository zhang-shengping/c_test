#include<stdio.h>
#include<utmp.h>
#include"who.h"

int main(){
    char * filename = "/var/run/utmp";
    int fd;
    struct utmp * utmptr;

    fd = create_utmpfd(filename);
    while ((utmptr = next_utmp())){
        char * user = utmptr -> ut_user;
        printf("ut_user %s \n", user);
    }
    remove_utmpfd(fd);
}

