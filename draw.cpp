#include <iostream>
#include "draw.h"
using namespace std;
void drawScreen ( char scr[100][100], int scr_h, int scr_w )
{
//    for ( int i = 0; i < scr_h; i++ )
//        {
//            for ( int j = 0; j < scr_w; j++ )
//                cout << screen[i][j];
//
//            cout << '\n';
//        }
//
//    cout << flush;
    HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
    WriteConsoleOutput ( console, ( char* ) scr, )
}
