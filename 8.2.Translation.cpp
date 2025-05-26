#include <Gl/glut.h>
#include <iostream>
using namespace std;
float x_1 = 0.1, y_1 = 0.1;
float x_2 = 0.3, y_2 = 0.1;       
float x_3 = 0.3, y_3 = 0.3;
float x_4 = 0.1, y_4 = 0.3;
float tx=0.0, ty=0.0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();
    
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x_1, y_1);
    glVertex2f(x_2, y_2);
    glVertex2f(x_3, y_3);
    glVertex2f(x_4, y_4); 
    glEnd();
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x_1 + tx, y_1 + ty);
    glVertex2f(x_2 + tx, y_2 + ty);
    glVertex2f(x_3 + tx, y_3 + ty);
    glVertex2f(x_4 + tx, y_4 + ty);
    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
    cout << "Enter tx value :";
    cin >> tx;
    cout << "Enter ty value :";
    cin >> ty;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Translation Example");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}