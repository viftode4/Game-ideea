#pragma once
#include <Windows.h>
#include <iostream>
#include "shapes.h"
#include "draw.h"
#define BLOCK '/u2588'
#define SPACE '/u0020'
#define row 60
#define col 230
using namespace std;
HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
COORD src = {0, 0};
COORD size = {row, col + 1};
char scr[row][col + 1];
int x;
void gameLoop()
{
    ClrScr ( 0x7, size );
    Sleep ( 1000 );
    drawScreen ( ( char* ) scr, size );
    ClrScrprost ( console, src );
    Sleep ( 1000 );
    drawScreen ( ( char* ) scr, size );
    Sleep ( 1000 );
}
int main()
{
    SetConsoleTextAttribute ( console, 0x7 );

    for ( int i = 0; i < row; i++ )
        for ( int j = 0; j <= col; j++ )
            {
                scr[i][j] = '#';

                if ( j == col )
                    scr[i][j] = '\n';
            }

    gameLoop();
    return 0;
}
