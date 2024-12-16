/*
5. B) Write a c++ program inscribed and
circumscribed circles in triangle
*/

#include <iostream>
#include <graphics.h>
#include <stdio.h>
void ddaAlg(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = dx > dy ? dx : dy;
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(x, y, 14);
        x += xInc;
        y += yInc;
    }
}
void display(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, 3);
    putpixel(xc - x, yc + y, 3);
    putpixel(xc + x, yc - y, 3);
    putpixel(xc - x, yc - y, 3);
    putpixel(xc + y, yc + x, 3);
    putpixel(xc - y, yc + x, 3);
    putpixel(xc + y, yc - x, 3);
    putpixel(xc - y, yc - x, 3);
}

void CircleB(int x1, int y1, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    display(x1, y1, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        display(x1, y1, x, y);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    // Coordinates of the triangle vertices
    int x1 = 102, y1 = 150, x2 = 150, y2 = 236, x3 = 198, y3 = 150;

    // Drawing the Circumscribed Circle (around the triangle)
    int circumscribedRadius = 57;           // Arbitrary radius
    CircleB(150, 180, circumscribedRadius); // Circle at (150, 180) with radius 57

    // Drawing the Inscribed Circle (inside the triangle)
    int inscribedRadius = circumscribedRadius / 2; // Inscribed circle with half the radius
    CircleB(150, 180, inscribedRadius);            // Circle at (150, 180) with radius 28

    // Drawing the Triangle using the DDA algorithm
    ddaAlg(x1, y1, x2, y2); // Line from (102, 150) to (150, 236)
    ddaAlg(x2, y2, x3, y3); // Line from (150, 236) to (198, 150)
    ddaAlg(x3, y3, x1, y1); // Line from (198, 150) to (102, 150)

    getch();
    closegraph();
    return 0;
}
