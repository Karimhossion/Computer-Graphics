//Bresenham Line Drawing – ( m≥1 )
#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
int xstart,ystart,xend,yend;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex2i(0, 50);
    glVertex2i(0, -50);
    glVertex2i(50, 0.0);
    glVertex2i(-50, 0.0);
    glEnd();
    glBegin(GL_POINTS);
    int x = xstart;
    int y = ystart;
    int dx = (xend - xstart);
    int dy =( yend - ystart);
    int stepx, stepy;

    if (xstart<xend){
        stepx=1;
    }
    else{
        stepx=-1;
    }
    if(ystart<yend){
        stepy=1;
    }else{
        stepy= -1;
    }
    
    int p = 2 * dx - dy;
    for (int i = 0; i <= dy; i++)
    {
        glVertex2i(x, y);
        y = y + stepy;
         if (p < 0) {
            p =p + 2 * dx;
        } else {
            x = x + stepx;
            p = p + (2*dx) - (2*dy);
        }
    }
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    cout<<"(x1,y1)=";
    cin>>xstart>>ystart;
    cout<<"(x2,y2)=";
    cin>>xend>>yend;
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50,50,-50,50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
