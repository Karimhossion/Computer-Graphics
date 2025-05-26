#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
float x1=0.1,y_1=0.1;
float x2=0.3,y_2=0.1;
float x3=0.3,y_3=0.3;
float x4=0.1,y_4=0.3;
float Sx=0.0, Sy=0.0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
    glVertex2f(1.,0.0);
    glVertex2f(-1.,0.0);
    glEnd();
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y_1);
    glVertex2f(x2, y_2); 
    glVertex2f(x3, y_3);
    glVertex2f(x4, y_4); 
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x1*Sx, y_1*Sy);
    glVertex2f(x2*Sx, y_2*Sy); 
    glVertex2f(x3*Sx, y_3*Sy);
    glVertex2f(x4*Sx, y_4*Sy); 
    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
    cout << "Enter Sx value = ";
    cin >> Sx;
    cout << "Enter Sy value = ";
    cin >> Sy;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Original and Scaling Shape = ");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
