#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int xstart, ystart, xend, yend;
int choice;

void LowSlope()
{
    int x = xstart;
    int y = ystart;
    int dx = abs(xend - xstart);
    int dy = abs(yend - ystart);
    int stepx = (xstart < xend) ? 1 : -1;
    int stepy = (ystart < yend) ? 1 : -1;

    int p = 2 * dy - dx;
    for (int i = 0; i <= dx; i++)
    {
        glVertex2i(x, y);
        x += stepx;
        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y += stepy;
            p += (2 * dy) - (2 * dx);
        }
    }
}

void HighSlope()
{
    int x = xstart;
    int y = ystart;
    int dx = abs(xend - xstart);
    int dy = abs(yend - ystart);
    int stepx = (xstart < xend) ? 1 : -1;
    int stepy = (ystart < yend) ? 1 : -1;

    int p = 2 * dx - dy;
    for (int i = 0; i <= dy; i++)
    {
        glVertex2i(x, y);
        y += stepy;
        if (p < 0)
        {
            p += 2 * dx;
        }
        else
        {
            x += stepx;
            p += (2 * dx) - (2 * dy);
        }
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw axis
    glBegin(GL_LINES);
    glVertex2i(0, 50);
    glVertex2i(0, -50);
    glVertex2i(50, 0);
    glVertex2i(-50, 0);
    glEnd();

    // Draw line
    glBegin(GL_POINTS);
    int dx = xend - xstart;
    int dy = yend - ystart;
    float m = fabs((float)dy / dx); 

    if (choice == 1 && m < 1)
    {
        LowSlope();
    }
    else if (choice == 2 && m >= 1)
    {
        HighSlope();
    }
    else
    {
        cout << "Invalid .\n";
    }

    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    cout << "Enter (x1, y1): ";
    cin >> xstart >> ystart;
    cout << "Enter (x2, y2): ";
    cin >> xend >> yend;
    cout << "Choose line type:\n";
    cout << "1. Slope (m < 1)\n";
    cout << "2. Slope (m >= 1)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("Bresenham Line Drawing");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
