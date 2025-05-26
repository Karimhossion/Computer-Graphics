#include <GL/glut.h>
#include <iostream>
using namespace std;
float x_1 = 0.1, y_1 = 0.1;
float x_2 = 0.3, y_2 = 0.1;
float x_3 = 0.3, y_3 = 0.3;
float x_4 = 0.1, y_4 = 0.3;
float Shr;
int choice;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
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
    if (choice == 1)
    {
        glVertex2f(x_1 + Shr * y_1, y_1);
        glVertex2f(x_2 + Shr * y_2, y_2);
        glVertex2f(x_3 + Shr * y_3, y_3);
        glVertex2f(x_4 + Shr * y_4, y_4);
    }
    else if (choice == 2)
    {
        glVertex2f(x_1, y_1 + Shr * x_1);
        glVertex2f(x_2, y_2 + Shr * x_2);
        glVertex2f(x_3, y_3 + Shr * x_3);
        glVertex2f(x_4, y_4 + Shr * x_4);
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    cout << "------ Shearing Options ------" << endl;
    cout << "1. X-axis" << endl;
    cout << "2. Y-axis" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 3)
    {
        cout << "Exit........" << endl;
        return 0;
    }
    if (choice != 1 && choice != 2)
    {
        cout << "Invalid choice! Exiting....." << endl;
        return 0;
    }
    cout << "Enter shear value (Shr): ";
    cin >> Shr;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Shearing Transformation");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
