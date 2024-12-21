#include "menu.h"
#include <termios.h>
#include <unistd.h>

void PrintMenu(){
    // printing the menu
    printf(" This a Tree Data Structure\n");
    printf("===========================\n");
    printf("> isert node\n");
    printf("> print tree preorder\n");
    printf("> print tree inorder\n");
    printf("> print tree postorder\n");
    printf("> exit\n");
}

void returnToMainMenu(int* py){
    system("clear");
    PrintMenu();
    *py=3;
    gotoxy(0, *py);
}









void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
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