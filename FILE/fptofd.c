#include<stdio.h>
#include<stdlib.h>

int fptofd(char * filename){
    FILE * fp = fopen("test.txt", "r+");

    if (fp == NULL){
        printf("cannot open file %s \n", filename);
        exit(1);
    }
    printf("the file struct pointer is %p \n", fp);

    int fd = fileno(fp);
    if (fd == -1){
        printf("cannot transfer file struct pointer to file descriptor \n");
        exit(1);
    }
    printf("the file descriptor is %d \n", fd);

    return fd;
}

/* int main(int argc, char * argv[]) */
/* { */
    /* if(argc < 2){ */
        /* printf("Please provide a filename \n"); */
        /* exit(1); */
    /* } */

    /* char * filename = argv[1]; */
    /* printf("input filename is %s \n", filename); */

    /* int fd = fptofd(filename); */
    /* printf("the file descriptor of file %s is %d \n", filename, fd); */
    /* return 0; */
/* } */
