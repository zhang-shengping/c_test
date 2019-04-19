#include <stdio.h>
int main()
{
    union{
            int n;
            char ch;
        } data;

    if(data.ch == 1){
            printf("Little-endian\n");
        }else{
                printf("Big-endian\n");
            }
    return 0;
}
