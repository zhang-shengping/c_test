# include<stdio.h>

int main(int ac, char *av[]){
    printf("ac %d \n", ac);
    for(int i=0; i <= ac-1; ++i)
        printf("*av[i] is %s \n ", av[i]);
}
