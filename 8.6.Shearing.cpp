#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
float x_1=0.1,y_1=0.1;
float x_2=0.1,y_2=0.3;
float x_3=0.3,y_3=0.3;
float x_4=0.3,y_4=0.1;
float Shr;
int choice;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0,1,1);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,1);
    glVertex2f(x_1,y_1);
    glVertex2f(x_2,y_2);
    glVertex2f(x_3,y_3);
    glVertex2f(x_4,y_4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    switch(choice)
    {
    case 1:
        glVertex2f(x_1 + Shr * y_1, y_1);
        glVertex2f(x_2 + Shr * y_2, y_2);
        glVertex2f(x_3 + Shr * y_3, y_3);
        glVertex2f(x_4 + Shr * y_4, y_4);
        break;
    case 2:

        glVertex2f(x_1, y_1 + Shr * x_1);
        glVertex2f(x_2, y_2 + Shr * x_2);
        glVertex2f(x_3, y_3 + Shr * x_3);
        glVertex2f(x_4, y_4 + Shr * x_4);
        break;
    default:
        cout<<"Invalid"<<endl;
    }
    glEnd();
    glFlush();

}



int main(int argc, char *argv[])
{
    cout<<"Menue:";
    cout<<"1. X-axish\n";
    cout<<"2. Y-axish\n";
    cout<<"3. Origin\n";
    cout<<"Enter Choice(1,2) :";
    cin>>choice;
    cout<<"Shr : ";
    cin>>Shr;

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");


    glutDisplayFunc(display);

    glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
