#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;
int x_start,y_start,x_end,y_end;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2i(0,100);
    glVertex2i(0,-100);
    glVertex2i(100,0);
    glVertex2i(-100,0);
    glEnd();
    glBegin(GL_POINTS);
    float x=x_start;
    float y=y_start;
    float m = (y_end - y_start)/(x_end - x_start);
    float b = (y_start - (m*x_start));

    while(x<=x_end)
    {
        glVertex2i(x,floor(y+0.5));
        x=x+1;
        y=((m*x) + b);
    }
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    cout<<"Enter (x_start, y_start) = ";
    cin>>x_start>>y_start;
    cout<<"Enter (x_end, y_end) = ";
    cin>>x_end>>y_end;
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    gluOrtho2D(-10,10,-10,10);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
