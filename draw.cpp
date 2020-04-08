#include <iostream>
#include "draw.h"
using namespace std;
void drawScreen ( char *scr, COORD size )
{
    HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
    DWORD count;
    DWORD cellCount = size.X * size.Y;
    WriteConsole ( console, ( char* ) scr, cellCount, &count, NULL );
}
void ClrScr ( char atrib, COORD size )
{
    HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
    DWORD count;
    COORD src = { 0, 0 };
    DWORD cellCount;
    cellCount = size.X * size.Y * 2;
    FillConsoleOutputCharacter ( console, ' ', cellCount, src, &count );
    FillConsoleOutputAttribute ( console, 0x7, cellCount, src, &count );
    SetConsoleCursorPosition ( console, src );
}
