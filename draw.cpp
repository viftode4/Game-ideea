#include <iostream>
#include "draw.h"
using namespace std;
void drawScreen ( CHAR_INFO scr[1000][1000], COORD size, SMALL_RECT rect )
{
    HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
    COORD src = {0, 0};
    WriteConsoleOutput ( console, ( CHAR_INFO* ) scr, size, src, &rect );
}
