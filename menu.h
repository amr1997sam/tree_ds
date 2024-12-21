#ifndef MENU
#define MENU

// keyboard codes
#define ENTER_KEY 10
#define ESC_KEY 27
#define BACKSPACE_KEY 127
#define EXTEND -32

#define RIGHT_KEY 67
#define LEFT_KEY 68
#define UP_KEY 65
#define DOWN_KEY 66

#define HOME_KEY 72
#define END_KEY 70


//libraries
#include <stdio.h>
#include <stdlib.h>

#define MENU_L 5

void PrintMenu();
void gotoxy(int x, int y);
void returnToMainMenu(int* py);
int getch();

#endif //MENU
