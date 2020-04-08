#include <iostream>
#include "draw.h"
using namespace std;
void drawScreen ( CHAR_INFO scr[1000][1000], COORD size )
{
    HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
    SMALL_RECT rect = {0, 0, size.X, size.Y};
    COORD src = {0, 0};
    WriteConsoleOutput ( console, ( CHAR_INFO * ) scr, size, src, &rect );
}
