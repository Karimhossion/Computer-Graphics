#include <windows.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glEnd();

    glBegin(GL_POINTS);
    //vertical Line

    float x=-0.5;
    for(float i=-0.2;i<1;i=i+0.01)
    {
        glVertex2f(x,i);
    }
    //horizontal line
    float y=0.7;
    for(float i=-0.2; i<1; i=i+0.01)
    {
        glVertex2f(i,y);
    }
    //m=1 line drawing
    x=0;
    y=0;
    float xend=0.4;
    while(x <= xend)
    {
        x=x+(0.01);
        y=y+(0.01);
        glVertex2f(x,y);
    }

    //m=-1 line drawing
    x=0;
    y=0;
    xend=0.4;
    while(x<=xend)
    {
        y=y-(0.01);
        x=x+(0.01);

        glVertex2f(y,x);
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
    glutCreateWindow("(Vertical line,Horizontal line, slope m=1 line,slope m=-1 line drawing)");
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
