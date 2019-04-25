#include<utmp.h>

int create_utmpfd(char *);
int reload_utmpfd();
struct umtp * next_utmp();
void remove_utmpfd(int);
