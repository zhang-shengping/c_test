#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char * find_path(char * );
void get_stat(char *, struct stat *);
char * find_name(char *, ino_t inode);

char * path = "";

int main(){
    /* struct stat *buffer; */
    /* struct stat buffer; */
    /* int res = stat("..", &buffer); */
    /* if(res != 0){ */
        /* perror("error"); */
        /* exit(1); */
    /* } */
    //printf("%d", buffer->st_ino);
    /* printf("%d", buffer.st_ino); */

    find_path(".");

    return 0;
}

char * find_path(char * path){
    char * current_name;
    struct stat current;
    struct stat parent;

    int dirchanged = chdir(path);
    if (dirchanged != 0){
        perror("can not change dir");
        exit(1);
    }

    get_stat(".", &current);
    get_stat("..", &parent);

    if (current.st_ino == parent.st_ino){
        printf("/");
//        strcat(path, "/");
        return "/";
    }

    current_name = find_name("..", current.st_ino);
    if (current_name == NULL){
        perror("can not find name");
        exit(1);
    }
 //   char * tmp = strcat("/", current_name);
 //   strcat(path, tmp);

    printf("/%s", current_name);

    find_path("..");
    return current_name;
}

void get_stat(char * name, struct stat * buffer){
    int res;
    res = stat(name, buffer);
    if (res != 0){
        perror("can not get current/parent stat");
        exit(1);
    }
}

char * find_name(char * dirname, ino_t inode){
    struct dirent * dirbuff;
    DIR * dir;

    dir = opendir(dirname);
    while((dirbuff = readdir(dir)) != NULL){
        if(dirbuff->d_ino == inode)
            return dirbuff->d_name;
    }
    return NULL;
}
