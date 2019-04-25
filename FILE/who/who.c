#include<stdio.h>
#include<utmp.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>

#define SIZE 20
#define UTMP_SIZE sizeof(struct utmp)
#define BUFFER_SIZE SIZE*UTMP_SIZE

/* void show(int, struct utmp []); */
void showwho(int, struct utmp *);
void showtime(long);

int main(){
    int utmpfp;
    int read_size;
    struct utmp buffer[BUFFER_SIZE];

    utmpfp = open("/var/run/utmp", O_RDONLY);
    if (utmpfp == -1){
        printf("open file error");
        return -1;
    }

    while((read_size = read(utmpfp, buffer, BUFFER_SIZE))){
        showwho(read_size, buffer);
    }

    if (read_size == -1){
        printf("read file error");
        return -1;
    }

    int close_result = close(utmpfp);
    if(close_result == -1){
        printf("close file error");
        return -1;
    }

    return 1;
}

/* void show(int read_size, struct utmp buffer[]){ */
    /* int count = read_size/UTMP_SIZE; */
    /* struct utmp utmp_unit; */

    /* for (int i=0; i<count; ++i){ */
        /* utmp_unit = buffer[i]; */
        /* printf("ut_user is %s \n", utmp_unit.ut_user); */
    /* } */
/* } */

void showwho(int read_size, struct utmp * buffer){
    int count = read_size/UTMP_SIZE;
    struct utmp * utmp_unit;

    for(int i=0; i<count; ++i){
        utmp_unit = buffer + i;
        printf("ut_user is %-8.8s", utmp_unit -> ut_user);
        printf("ut_line is %-8.8s", utmp_unit -> ut_line);
        showtime(utmp_unit -> ut_time);
        printf("\n");
    }
}

void showtime(long timeval){
    char * timep;
    timep = ctime(&timeval);
    printf("ut_time is %-8s", timep);
}
