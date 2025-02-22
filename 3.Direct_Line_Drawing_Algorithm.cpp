#include<windows.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;
float x1, x2, yStart, yEnd;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    float xstart = 0.1, ystart = 0.1;
    float xend = 0.5, yend = 0.8;
    float x = xstart, y = ystart;
    float m = (yend - ystart)/(xend - xstart);
    float b = ystart - (m * xstart);
    while (x <= xend)
    {
        glVertex2f(x, y);
        x += 0.01;
        y = (m * x) + b;
    }
    glColor3f(0.0,0.0,1.0);
    xstart = (x1 < x2) ? x1 : x2;
    ystart = (yStart < yEnd) ? yStart : yEnd;
    xend = (x1 > x2)?x1:x2;
    yend = (yStart>yEnd)?yStart:yEnd;
    x = xstart;
    y = ystart;
    m = (yend - ystart) / (xend - xstart);
    b = ystart - (m * xstart);
    while (x <= xend)
    {
        glVertex2f(x, y);
        x += 0.01;
        y = (m * x) + b;
    }
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    cout << "Enter (x1, y1): ";
    cin >> x1 >> yStart;
    cout << "Enter (x2, y2): ";
    cin >> x2 >> yEnd;
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
