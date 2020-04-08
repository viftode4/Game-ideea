#pragma once
#include <Windows.h>
#include <iostream>
#include "shapes.h"
#include "draw.h"
using namespace std;
//normale
char scr[100][100];
int scr_h = 20;
int scr_w = 100;
int x;
//consola
HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
COORD src = {0, 0};
SMALL_RECT  = {0, 0, scr_h, scr_w};

void ClrScr()
{
    // ia informatia despre buffer
    CONSOLE_SCREEN_BUFFER_INFO console_buffer_info;
    //e un struct dubios
    DWORD size = console_buffer_info.dwSize.X * console_buffer_info.dwSize.Y;
    DWORD count;
    // fill unde, cu ce caracter, cat, si de unde si cat pana acum
    FillConsoleOutputCharacter ( console, ' ', size, src, &count );
    // sa fie tot aceeasi culoare si atribute de caracter
    FillConsoleOutputAttribute ( console, console_buffer_info.wAttributes, size, src, &count );
    //seteaza cursorul in 0,0
    SetConsoleCursorPosition ( console, src );
}
void gameLoop()
{
    while ( 1 )
        {
            ClrScr();
            drawScreen ( scr, scr_h, scr_w );
            Sleep ( 1000 );
            //qDraw.push()
            //cin >> x;
        }
}
int main()
{
    memset ( scr, '#', sizeof scr );
    gameLoop();
    return 0;
}
