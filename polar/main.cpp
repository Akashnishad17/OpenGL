#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int r;

void plot(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glVertex2i(x,-y);
    glVertex2i(y,x);
    glVertex2i(y,-x);
    glVertex2i(-x,-y);
    glVertex2i(-x,y);
    glVertex2i(-y,-x);
    glVertex2i(-y,+x);
    glEnd();
}

void display(void)
{
int x = r, y = 0;
double theta = 0, d = 1.0/r;
plot(x,y);
while( x > y)
{
    theta += d;
    x = round(r*cos(theta));
    y = round(r*sin(theta));
    plot(x,y);
}
glFlush();
}

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv) {
printf("Enter the radius : ");
scanf("%d",&r);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("Circle using polar equation");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
