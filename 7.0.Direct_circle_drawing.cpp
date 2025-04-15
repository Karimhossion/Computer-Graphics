#include<windows.h>
#include <GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;
float r;
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
    glColor3f(0.0,0.0,1.0);
    float x1=0,y1=0,x=x1,y=y1;
    while (x < r)
    {
        x += 0.0001;
        y = sqrt(r*r - x*x);
        glVertex2f(x, y);
        glVertex2f(x, -y);
        glVertex2f(-x, y);
        glVertex2f(-x, -y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    cout << "Enter (r): ";
    cin >> r ;
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
