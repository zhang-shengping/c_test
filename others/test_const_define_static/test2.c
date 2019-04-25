#include <stdio.h>

/* extern m; */
extern const int m;
extern int test();
/* defined macro symbol 不能使用extern, 只能使用 header file  */
/* extern n; */

int main(void)
{
    printf("m in test2 %d \n", m);
    /* printf("n in test2 %d \n", n); */
    printf("test2 \n");
    test();
}
