#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

FILE * fdtofp(char * filename){
    int fd = open(filename, O_RDWR);

    if (fd == -1){
        printf("can not open file %s \n", filename);
        exit(1);
    }
    printf("the file descriptor is %d \n", fd);

    FILE * fp = fdopen(fd, "r");
    printf("test file name is %s \n", fp->name);

    if (fp == NULL){
        printf("cannot transfer file struct pointer to file descriptor \n");
        exit(1);
    }
    printf("the file struct pointer is %p \n", fp);

    return fp;
}
