#include <windows.h>
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);

    glVertex2f(0.0,3.0);
    glVertex2f(0.0,-3.0);


    glVertex2f(3.0,0.0);
    glVertex2f(-3.0,0.0);


    glVertex2f(-0.8,0.8);
    glVertex2f(+0.8,-0.8);
    glVertex2f(0.8,0.8);
    glVertex2f(-0.8,-0.8);

    glVertex2f(-0.8,0.8);
    glVertex2f(0.8,0.8);

    glVertex2f(-0.8,0.8);
    glVertex2f(-0.8,-0.8);

     glVertex2f(0.8,0.8);
    glVertex2f(0.8,-0.8);

    glVertex2f(-0.8,-0.8);
    glVertex2f(0.8,-0.8);


    /*-------------*/

    glVertex2f(-0.4,0.4);
    glVertex2f(0.4,0.4);

    glVertex2f(-0.4,0.4);
    glVertex2f(-0.4,-0.4);

     glVertex2f(0.4,0.4);
    glVertex2f(0.4,-0.4);

    glVertex2f(-0.4,-0.4);
    glVertex2f(0.4,-0.4);


   /* glVertex2f(0.1,0.1);
    glVertex2f(-0.1,-0.1);

    /*
    glVertex2f(-0.5,1.0);
    glVertex2f(0.5,-1.0);*/


    glEnd();
    // ================
    glPointSize(80.0);
    glBegin(GL_POINTS);


    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.8, -0.8);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.8, 0.8);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.8, 0.8);

    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.8, -0.8);


    glColor3f(1.0,0.0,1.0);
    glVertex2f(-0.4,0.4);

    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.4,0.4);

    glColor3f(1.0, 0.5, 0.0);
    glVertex2f(-0.4,0.4);

    glColor3f(0.5, 0.0, 0.5);
    glVertex2f(-0.4,-0.4);


    glColor3f(0.5, 0.25, 0.0);
    glVertex2f(0.4,0.4);



    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.4,-0.4);

    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(-0.4,-0.4);


    glColor3f(0.5, 0.5, 0.0);
    glVertex2f(0.4,-0.4);


    glColor3f(0.8, 0.6, 0.7);
    glVertex2f(0.0,0.0);

    glColor3f(1.0, 0.8, 0.0);
    glVertex2f(0.0,0.8);

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

    return 0;
}
