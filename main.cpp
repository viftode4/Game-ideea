#pragma once
#include <Windows.h>
#include <iostream>
#include "shapes.h"
#include "draw.h"
#define BLOCK '/u2588'
#define SPACE '/u0020'
using namespace std;
int row = 5;
int col = 5;
HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
COORD src = {0, 0};
COORD size = {row, row};
CHAR_INFO scr[1000][1000];
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
    Sleep ( 1000 );
    Sleep ( 1000 );
    ClrScr ( 0x7 );
    Sleep ( 1000 );
    Sleep ( 1000 );
    drawScreen ( scr, size );
    Sleep ( 1000 );
    //qDraw.push()
    //cin >> x;
}
int main()
{
    for ( int i = 1; i <= row; i++ )
        for ( int j = 1; j <= col; j++ )
            {
//                if ( i == 0 || j == 0 )
//                    {
//                        a[i][j] = '#';
//                        scr[i][j].Char.AsciiChar = '#';
//                    }
//                else
//                    {
//                        a[i][j] = '@';
//                        scr[i][j].Char.AsciiChar = '#';
//                    }
                a[i][j] = '#';
                scr[i - 1][j - 1].Char.AsciiChar = '#';
                scr[i - 1][j - 1].Attributes = 0x7;
            }

    drawScreen ( scr, size );
    gameLoop();
    return 0;
}
