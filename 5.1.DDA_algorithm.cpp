//m>=1 ----problem
#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include<algorithm>
#include <iostream>
using namespace std;

int x_start,y_start,x_end,y_end;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2i(0,100);
    glVertex2i(0,-100);
    glVertex2f(100,0);
    glVertex2f(-100,0);
    glEnd();
    glBegin(GL_POINTS);
    float m = float(y_end - y_start)/float(x_end - x_start);
    if(abs(m)>1 && y_start>y_end)
    {
        swap(x_start, x_end);
        swap(y_start, y_end);
    }
    glVertex2i(x_start, y_start);

    if(abs(m)>1)
    {

        m=1/m;
        //cout<<m<<endl;
        float y=y_start+1;
        float x=x_start;
        while(y<=y_end - 1)
        {
            x=x+m;
            glVertex2i(floor(x+0.5),y );
            y=y+1;

        }
        glVertex2i(x_end, y_end);

    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{

    cout<<"Enter (x_start, y_start) = ";
    cin>>x_start>>y_start;
    cout<<"Enter (x_end, y_end) = ";
    cin>>x_end>>y_end;
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    gluOrtho2D(-10, 10, -10, 10);

    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
