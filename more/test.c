#include <termios.h>
#include <unistd.h>

int main(){

struct termios term;

if(tcgetattr(STDIN_FILENO, &term))

}
