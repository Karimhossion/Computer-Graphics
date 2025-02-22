#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
float xstart, ystart, xend, yend;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    float dx = xend - xstart;
    float dy = yend - ystart;
    int step = max(abs(dx * 1000), abs(dy * 1000));
    float x_increment = dx / step;
    float y_increment = dy / step;
    float x = xstart, y = ystart;
    for (int k = 0; k <= step; k++) {
        glVertex2f(x, y);
        x += x_increment;
        y += y_increment;
    }
    glEnd();
    glFlush();
}
int main(int argc, char *argv[]) {
    cout << "Enter (xstart, ystart): ";
    cin >> xstart >> ystart;
    cout << "Enter (xend, yend): ";
    cin >> xend >> yend;

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("DDA");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
