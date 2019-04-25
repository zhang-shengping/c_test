#include<stdio.h>

char a[5]={'A','B','C','D'};
char * b = NULL;
int main()
{
   /* char (*p3)[5] = &a; */
   /* char (*p4)[5] = a; */
   b = a;
   printf("b is %p \n", b);
   printf("&b is %p \n", &b);
   /* &a 是整个数组的首地址 */
   printf("&a is %p \n", &a);
   printf("&a[0] is %p \n", &a[0]);
   /* a是数组首元素的首地址 */
   printf("a is %p \n", a);
   return 0;
}
