#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
float x1=0.1,y_1=0.1;
float x2=0.3,y_2=0.1;
float x3=0.3,y_3=0.3;
float x4=0.1,y_4=0.3;
float rad;
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
    glVertex2f(x1*cos(rad)-y_1*sin(rad), y_1*cos(rad) + x1*sin(rad));
    glVertex2f(x2*cos(rad)-y_2*sin(rad), y_2*cos(rad) + x2*sin(rad));
    glVertex2f(x3*cos(rad)-y_3*sin(rad), y_3*cos(rad) + x3*sin(rad));
    glVertex2f(x4*cos(rad)-y_4*sin(rad), y_4*cos(rad) + x4*sin(rad));
    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
    float deg;
    cout << " Enter degree = ";
    cin >> deg;
    rad = deg * M_PI /(float)180;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Original and Rotation Shape = ");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
