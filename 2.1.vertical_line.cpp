#include <windows.h>
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
    glVertex2f(1.,0.0);
    glVertex2f(-1.,0.0);
    glEnd();
    glBegin(GL_POINTS);
    float x=0.3,y_start=-0.5,y_end=0.5;
    float y=y_start;
    while(y<=y_end)
    {
        glVertex2f(x,y);
        y=y+0.01;
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
