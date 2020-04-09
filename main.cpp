#pragma once
#include <Windows.h>
#include <bits/stdc++.h>
#include "shapes.h"
#include "draw.h"
#include "map.h"
#define BLOCK '/u2588'
#define SPACE '/u0020'
#define row 61
#define col 231
using namespace std;
HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
COORD src = {0, 0};
COORD size = {row, col + 1};
char scr[row][col + 1];
queue<Block> qBlock;
void gameLoop()
{
    while ( 1 )
        {
            drawScreen ( ( char* ) scr, size );
            Sleep ( 1000 );
            ClrScrprost();//lol
        }
}
void intro()
{
    COORD centre = {row / 2 - 11 / 2, col / 2 - 11 / 2-7};
    ifstream fin ( "DRAGON_EGG_ANI.txt" );
    char ani[12][34];
    for ( int frame = 1; frame <= 18; frame++ )
        {
            for ( int i = 0; i < 11; i++ )
                {
                    fin.getline ( ani[i], 34 );
                    fin.clear();
                }
            for ( int i = 0; i < 11; i++ )
                for ( int j = 0; j < 33; j++ )
                    scr[i + centre.X][j + centre.Y] = ani[i][j];
            ClrScr ( 0x7, size );
            drawScreen ( ( char* ) scr, size );
            Sleep ( 1000 );
        }
}
void init()
{
    //initializari
    // text alb pe ecran negru
    SetConsoleTextAttribute ( console, 0x7 );
    // dam clear la consola
    ClrScr ( 0x7, src );

    //border la ecran
    for ( int i = 0; i < row; i++ )
        for ( int j = 0; j <= col; j++ )
            {
                if ( i == 0 || j == 0 || i == row - 1 || j == col - 1 )
                    scr[i][j] = '#';
                else
                    scr[i][j] = ' ';

                if ( j == col )
                    scr[i][j] = '\n';
            }
    intro();
    //intro();
}
int main()
{
    init();
    //gameLoop();
    return 0;
}
