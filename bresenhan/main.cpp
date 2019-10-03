#include<gl/glut.h>
#include<gl/gl.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
int x1,x2;
int my,y2;
void display(void)
{
int x,y,k,step;
int dx,dy;
dx = x2-x1;
dy = y2-my;
float m = (float)dy/dx;

if(x1<x2)
{
    x = x1; y=my;
}
else{
    x= x2; y=y2;
}

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

if ( m <= 1)
{
    step = dx;
    int p = 2*dy - dx;
    for (k=1 ;k<=step;k++)
    {
        if(p<=0)
        {
            p = p +2*dy;
            x++;
        }
        else
        {
           p = p + 2*dy - 2*dx;
            x++;
            y++;
        }
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
}
else
{
    step = dy;
    int p = 2*dx - dy;
    for (k=1 ;k<=step;k++)
    {
        if(p<=0)
        {
            p = p +2*dx;
            y++;
        }
        else
        {
           p = p + 2*dx - 2*dy;
            x++;
            y++;
        }
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glEnd();
    }
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
printf("Enter the value of x1 : ");
scanf("%d",&x1);
printf("Enter the value of y1 : ");
scanf("%d",&my);
printf("Enter the value of x2 : ");
scanf("%d",&x2);
printf("Enter the value of y2 : ");
scanf("%d",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("Bresenhan");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
