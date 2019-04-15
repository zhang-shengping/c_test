#include<stdio.h>

#define MAXVAL 1000

int sp = 0;
double val[MAXVAL];

void push(double f){
    if (sp < 1000)
        val[sp++] = f;
    else
        printf("error: stack full , can't push %g\n", f);
}

double pop(){
    if (sp >= 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

