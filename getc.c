#include <stdio.h>
#include <stdlib.h>

#include <termio.h>
#include <unistd.h>

int getch() ;


int main()
{
    int ch;
    int i;
    for(i=0; i<20; i++){
        ch = getch();
        printf("%d\n", ch);
        if(ch == 27){
            ch = getch();
            printf("%d\n", ch);
            if(ch == 91){
                ch = getch();
                printf("%d\n", ch);
            }
        }
        return 0;
    }
}



int getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);          // Save the terminal attributes
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply the new settings

    ch = getchar();                          // Read a single character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore the terminal attributes
    return ch;
}