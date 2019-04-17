/* _XOPEN_SOURCE 必须在首行, 编译才能通过*/
#define _XOPEN_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ioctl.h>

/* #define PATH_MAX 1000 */

char buf[1] = {'\0'};
/* char file_path[PATH_MAX]; */

int main(){
    /* get master pesudoterminal, master 在网络这一端，和用户键盘/屏幕连接*/
    int mfd = open("/dev/ptmx", O_RDWR);

    /* fcntl(mfd, F_GETPATH, file_path); */
    /* printf ("master pesudoterminal file name is %s \n", file_path); */

    grantpt(mfd);
    unlockpt(mfd);

    /* print slave pesudoterminal file struct point from master file descriptor */
    /* slave 是和 login 程序连接 */
    printf("slave pesudoterminal file name is %s \n", ptsname(mfd));

    /* 分为两个进程 */
    int pid = fork();

    /* 标准输入 ---> mfd ---> 标准输出 */
    if(pid){
        /* 从 master 读入数据写向标准输出 */
        while(1){
            if(read(mfd, buf, 1) > 0)
                write(1, buf, 1);
            else
                sleep(1);
        }
    }else{
        /* 从标准输入读数据写向 master pesudoterminal */
        while(1){
            if(read(0, buf, 1) > 0)
                write(mfd, buf, 1);
            else
                sleep(1);
        }
    }
    return 0;
}
