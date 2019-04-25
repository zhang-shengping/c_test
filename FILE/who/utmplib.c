/* 1. open file set fd */
/* 2. reload buffer */
/* 3. cosume buffer */
/* 4. close file */

#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>

#define UTMPSIZE (sizeof(struct utmp))
#define BUFFERSIZE 10

int rec, cur = 0;
int utmpfd = -1;
int fd = 0;

// notice if use struct utmp, things will be different
char buffer[UTMPSIZE * BUFFERSIZE];

int create_utmpfd(char *);
int reload_utmpfd();
struct utmp * next_utmp();
void remove_utmpfd(int);

int create_utmpfd(char * filename){
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        perror("can not open file");
    return fd;
}

int reload_utmpfd(){
    rec = read(fd, buffer, UTMPSIZE*BUFFERSIZE);
    if (rec == -1)
        perror("can not read file");
    cur = 0;
    return rec/UTMPSIZE;
}

struct utmp * next_utmp(){
    if (cur == rec){
        rec = reload_utmpfd();
        if (rec == 0)
            return NULL;
    }

    // struct utmp * res = (struct utmp *)(buffer + cur *UTMPSIZE);
    struct utmp * res = (struct utmp *) &buffer[cur *UTMPSIZE];
    ++cur;
    return res;
}

void remove_utmpfd(int fd){
    int res = close(fd);
    if(res == -1)
        perror("can not close file");
}
