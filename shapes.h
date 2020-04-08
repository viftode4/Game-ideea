#ifndef SHAPES_H
#define SHAPES_H // SHAPES_H
class Rectangle {
private:
    int n, m;
    int x, y;
public:

    Rectangle() {
        setRect ( 0, 0, 0, 0 );
    }
    Rectangle ( int a, int b, int c, int d ) {
        setRect ( a, b, c, d );
    }
    void setRect ( int a, int b, int c, int d ) {
        x = a, y = b, n = c, m = d;
    }
    void draw ( char scr[1000][1000] ) {
        for ( int i = x; i < x + n; i++ )
            for ( int j = y; j < y + m; j++ )
                scr[i][j] = '#';
    }
};
#endif
