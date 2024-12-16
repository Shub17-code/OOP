#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    // Initialize graphics mode
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    // Define the polygon vertices (edges as x1, y1, x2, y2)
    float edges[4][4] = {
        {100, 10, 200, 300},  // Edge 1
        {200, 300, 100, 250}, // Edge 2
        {100, 250, 0, 300},   // Edge 3
        {0, 300, 100, 10}     // Edge 4
    };

    // Draw the polygon by connecting the edges
    for (int i = 0; i < 4; i++) {
        line(edges[i][0], edges[i][1], edges[i][2], edges[i][3]);
    }

    // Find the highest and lowest y-coordinates to determine the scan lines
    int ymax = edges[0][1], ymin = edges[0][1];
    for (int i = 0; i < 4; i++) {
        if (edges[i][1] > ymax) ymax = edges[i][1];
        if (edges[i][3] > ymax) ymax = edges[i][3];
        if (edges[i][1] < ymin) ymin = edges[i][1];
        if (edges[i][3] < ymin) ymin = edges[i][3];
    }

    // Iterate over each scan line (from ymin to ymax)
    for (int y = ymax - 1; y > ymin; y--) {
        int intersections[10]; // Array to store intersection points
        int count = 0;

        // Find intersection points with each edge
        for (int i = 0; i < 4; i++) {
            float x1 = edges[i][0], y1 = edges[i][1], x2 = edges[i][2], y2 = edges[i][3];
            if ((y > y1 && y < y2) || (y > y2 && y < y1)) {
                // Calculate the intersection point
                float x = ((y - y1) * (x2 - x1)) / (y2 - y1) + x1;
                intersections[count++] = x;
            } 
        }

        // Sort the intersection points
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (intersections[i] > intersections[j]) {
                    float temp = intersections[i];
                    intersections[i] = intersections[j];
                    intersections[j] = temp;
                }
            }
        }

        // Fill between the intersection points (for each pair of intersections)
        for (int i = 0; i < count; i += 2) {
            for (int x = intersections[i]; x < intersections[i + 1]; x++) {
                putpixel(x, y, YELLOW);  // Fill with yellow color
            }
        }
    }

    // Wait for user input to close the window
    getch();
    closegraph();
    return 0;
}
