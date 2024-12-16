/*
5. A) Write a C++ program for drawing a
following pattern(diamond in rectangle)
*/

#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int sign(int x)
{
    if (x < 0)
        return -1;
    else if (x > 0)
        return 1;
    else
        return 0;
}
void bline(int x1, int y1, int x2, int y2, int col)
{
    int dx, dy, e, x, y, i = 1;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    e = 2 * dy - dx;
    while (i <= dx)
    {
        while (e >= 0)
        {
            y++;
            e = e - 2 * dx;
        }
        x++;

        e = e + 2 * dy;
        putpixel(x, y, col);
        i++;
    }
}
void ddaline(int x1, int y1, int x2, int y2, int col)
{
    int x, y, len, i;
    float dx, dy;
    if (x1 == x2 && y1 == y2)
        putpixel(x1, y1, col);
    else
    {
        dx = x2 - x1;
        dy = y2 - y1;
        if (dx > dy)
            len = dx;
        else
            len = dy;
        dx = (x2 - x1) / len;
        dy = (y2 - y1) / len;
        x = x1 + 0.5 * sign(dx);
        y = y1 + 0.5 * sign(dy);
        i = 1;
        while (i < len)
        {
            putpixel(x, y, col);
            x = x + dx;
            y = y + dy;
            i++;
        }
    }
}
int main()
{
    int ch, col, x1, x2, y1, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    int left = 50, top = 50, right = 350, bottom = 200;

    // Draw the rectangle (4 lines)
    ddaline(left, top, left, bottom, 2);     // Left vertical line
    ddaline(left, top, right, top, 4);       // Top horizontal line
    ddaline(right, top, right, bottom, 6);   // Right vertical line
    ddaline(left, bottom, right, bottom, 7); // Bottom horizontal line

    // Coordinates for the diamond lines
    int centerX = 200, centerY = 125;

    // Draw the diamond (4 lines)
    ddaline(centerX, top, left, centerY, 9);      // Upper-left diagonal line
    bline(left, centerY, centerX, bottom, 12);    // Left-lower diagonal line
    ddaline(right, centerY, centerX, bottom, 14); // Lower-right diagonal line
    bline(centerX, top, right, centerY, 3);       // Right-upper diagonal line

    // Coordinates for the inner diamond lines
    int innerLeft = 125, innerTop = 87, innerRight = 275, innerBottom = 163;

    // Draw the inner diamond (4 lines)
    ddaline(innerRight, innerTop, innerRight, innerBottom, 4);   // Right vertical line
    ddaline(innerLeft, innerTop, innerRight, innerTop, 5);       // Top horizontal line
    ddaline(innerLeft, innerTop, innerLeft, innerBottom, 6);     // Left vertical line
    ddaline(innerLeft, innerBottom, innerRight, innerBottom, 2); // Bottom horizontal line

    getch();
    closegraph();
    return 0;
}