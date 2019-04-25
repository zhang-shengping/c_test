root@ubuntu:~/C/FILE/who# gcc -o who2.o who2.c utmplib.c who.h  -Wall
who2.c: In function 'main':
who2.c:11:20: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
     while ((utmptr = next_utmp())){
                            ^
