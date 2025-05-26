#include <GL/glut.h>
#include <iostream>
using namespace std;
float x1 = 0.3, y_1 = 0.4;
float x2 = 0.6, y_2 = 0.4;
float x3 = 0.45, y_3 = 0.7;
int choice;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0); 
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0); 
    glEnd();
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y_1);
    glVertex2f(x2, y_2);
    glVertex2f(x3, y_3);
    glEnd();
    switch(choice) {
        case 1: 
            glColor3f(0, 0, 1);
            glBegin(GL_POLYGON);
            glVertex2f(x1, -y_1);
            glVertex2f(x2, -y_2);
            glVertex2f(x3, -y_3);
            glEnd();
            break;
        case 2: 
            glColor3f(0, 1, 0);
            glBegin(GL_POLYGON);
            glVertex2f(-x1, y_1);
            glVertex2f(-x2, y_2);
            glVertex2f(-x3, y_3);
            glEnd();
            break;
        case 3:
            glColor3f(1, 0, 0);
            glBegin(GL_POLYGON);
            glVertex2f(-x1, -y_1);
            glVertex2f(-x2, -y_2);
            glVertex2f(-x3, -y_3);
            glEnd();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    glFlush();
}
int main(int argc, char** argv) {
    cout << "Reflection Menu:\n";
    cout << "1. X-axis\n";
    cout << "2. Y-axis\n";
    cout << "3. Origin\n";
    cout << "Enter choice (1,2,3): ";
    cin >> choice;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Reflection");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
