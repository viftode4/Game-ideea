#pragma once
#include <Windows.h>
#include <iostream>
#include "shapes.h"
#include "draw.h"
#define BLOCK '/u2588'
#define SPACE '/u0020'
#define row 5
#define col 5
using namespace std;
HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
COORD src = {0, 0};
COORD size = {col, row};
CHAR_INFO scr[1000][1000];
SMALL_RECT rect = {0, 0, col, row};
char a[1000][1000];
void ClrScr ( char atrib )
{
    //ia informatia despre buffer
    //e un struct dubios
    DWORD sizee = row * col;
    DWORD count;
    // fill unde, cu ce caracter, cat, si de unde si cat pana acum
    FillConsoleOutputCharacter ( console, ' ', sizee, src, &count );
    // sa fie tot aceeasi culoare si atribute de caracter
    FillConsoleOutputAttribute ( console, atrib, sizee, src, &count );
    //seteaza cursorul in 0,0
    SetConsoleCursorPosition ( console, src );
}
void gameLoop()
{
    ClrScr ( 0x7 );
    Sleep ( 1000 );
    drawScreen ( scr, size, rect );
    Sleep ( 1000 );
    ClrScr ( 0x7 );
    Sleep ( 1000 );
    //qDraw.push()
    //cin >> x;
}
int main()
{
    for ( int i = 0; i < row; i++ )
        for ( int j = 0; j < col; j++ )
            {
                a[i][j] = '#';
                scr[i][j].Char.AsciiChar = '#';
                scr[i][j].Attributes = 0x7;
            }

    gameLoop();
    return 0;
}
