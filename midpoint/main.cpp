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
int x = 0, y = r;
float d = 5.0/4.0-r;

plot(x,y);
while( x < y)
{
    x++;
    if (d < 0)
        d = d + 2*x +1;
    else{
        y--;
        d = d + 2*(x-y) +1;
    }
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
glutCreateWindow ("Mid Point Algo");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

