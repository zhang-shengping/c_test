#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define COPYMODE 0644
#define BUFFER 4096


int main(int argc, char * argv[]){

    char buffer[BUFFER] = {};
    int read_size = 0;
    int source_fd = 0;
    int target_fd = 0;
    int action = 0;

    if (argc < 3){
        printf("Please enter your source file and target file \n");
        return -1;
    }

    char * source_file = argv[1];
    char * target_file = argv[2];
    printf("Ready to copy from %s to %s \n", source_file, target_file);

    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1){
        printf("Can not open source file %s \n", source_file);
        return -1;
    }

    target_fd = creat(target_file, COPYMODE);
    if (target_fd == -1){
        printf("Can not open/create target file %s \n", target_file);
        return -1;
    }

    while ((read_size = read(source_fd, buffer, BUFFER))){
        if (write(target_fd, &buffer, read_size) != read_size){
            printf("Error happens while writing target file %s \n", target_file);
            return -1;
        }
    }
    if (read_size == -1){
        printf("Error happens while reading source file %s \n", source_file);
        return -1;
    }

    printf("Copy action completed\n");

    action = close(source_fd);
    if (action == -1){
        printf("Error happens while closing source file %s \n", source_file);
        return -1;
    }

    action = close(target_fd);
    if (action == -1){
        printf("Error happens while closing target file %s \n", target_file);
        return -1;
    }

    return 0;
}
