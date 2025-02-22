#include <windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
int x_center, y_center, radius;
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex2i(-50, 0);
    glVertex2i(50, 0);
    glVertex2i(0, -50);
    glVertex2i(0, 50);
    glEnd();
    int x_k = 0;
    int y_k = radius;
    int pk = 1 - radius;
    glBegin(GL_POINTS);
    while(x_k<=y_k) {
        glVertex2i(x_center + x_k, y_center + y_k);
        glVertex2i(x_center - x_k, y_center + y_k);
        glVertex2i(x_center + x_k, y_center - y_k);
        glVertex2i(x_center - x_k, y_center - y_k);
        glVertex2i(x_center + y_k, y_center + x_k);
        glVertex2i(x_center - y_k, y_center + x_k);
        glVertex2i(x_center + y_k, y_center - x_k);
        glVertex2i(x_center - y_k, y_center - x_k);
        if (pk < 0) {
            pk=pk+(2*x_k)+3;
        } else {
            y_k--;
            pk = pk+(2*x_k)-(2*y_k)+5;
        }
        x_k++;
    }
    glEnd();
    glFlush();
}
int main(int argc, char *argv[]) {
    cout << "circle center,(x, y): ";
    cin >> x_center >> y_center;
    cout << "radius,(r): ";
    cin >> radius;
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("Midpoint Circle Algorithm");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
