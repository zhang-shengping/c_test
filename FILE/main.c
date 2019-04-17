#include<stdio.h>
#include<stdlib.h>
#include "testfile.h"

int main(int argc, char * argv[])
{
    if(argc < 2){
        printf("Please provide a filename \n");
        exit(1);
    }

    char * filename = argv[1];
    printf("input filename is %s \n", filename);
    printf("\n\n");

    int fd = fptofd(filename);
    printf("the file descriptor of file %s is %d \n", filename, fd);

    printf("\n\n");

    FILE * fp = fdtofp(filename);
    printf("the file struct point of file %s is %p \n", filename, fp);
    return 0;
}
