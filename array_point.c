#include<stdio.h>
#include<string.h>

int main(){
    char a[] = "hello hell";

    int len = strlen(a);
    char * aptr[len];

    for(int i=0; i < len; ++i){
            aptr[i] = a+i;
            printf("%c is stored\n", *(a+i));
            printf("*aptr[i] %c\n", *aptr[i]);
        }
}
