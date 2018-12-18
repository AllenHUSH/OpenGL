#include <windows.h>
#include <GL\freeglut.h>
#include <cmath>
#include <stdlib.h>
float xr=0;
float yr=0;


void myInit() {
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-100,100,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(0+xr,0+yr);
    glVertex2f(0+xr,10+yr);
    glVertex2f(10+xr,10+yr);
    glVertex2f(10+xr,0+yr);
    glEnd();

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

}
void callback(int key,int x,int y) {

    switch(key)
    {
    case GLUT_KEY_UP:
        yr=yr+1;

        glutPostRedisplay();

        break;

    case GLUT_KEY_DOWN:
        yr--;

        glutPostRedisplay();
        break;


    }


}

void callup(int key,int x,int y) {

    switch(key)
    {

    case GLUT_KEY_UP:
while(yr!=0)
{


        yr--;

        glutPostRedisplay();
}
        break;

    case GLUT_KEY_DOWN:
        yr++;

        glutPostRedisplay();
        break;


    }


}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);

    glutCreateWindow("SP16-BCS-092");
    glutDisplayFunc(display);
    glutSpecialFunc(callback);
    glutSpecialUpFunc(callup);
    myInit();
    glutMainLoop();

    return 0;
}
