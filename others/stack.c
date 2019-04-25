#include<stdio.h>
#define STACKSIZE 10

int count = 0;
int stack[STACKSIZE] = {};

void push(int);
int pop();

int main(){

    for(int i = 0; i < 10; ++i)
        push(i);

    for(int i = 0; i < 10; ++i)
        printf("%d \t", pop());
}

void push(int x){
    if (count >= STACKSIZE){
        printf("error, stack is full");
        return;
    }
    stack[count++] = x;
}

int pop(){
    if (count <= -1){
        printf("error, stack is empty");
        return -1;
    }
    return stack[--count];
}
