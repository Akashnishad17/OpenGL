#include <gl/glut.h>
#include <gl/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int xmin,ymin,xmax,ymax,dx,dy;
float x,y,x2,y2,umin,umax,q[4],p[4],u[4];
void calculateU()
{
    dx = x2-x;  dy = y2-y;
    p[0] = -dx;     p[1] = dx;      p[2] = -dy;     p[3] = dy;
    q[0] = x-xmin;  q[1] = xmax-x;  q[2] = y-ymin;  q[3] = ymax-y;
    for (int i=0;i<4;i++)
    {
        u[i] = q[i]/p[i];
        if(u[i]>0 && u[i]<1)
        {
            umin=u[i];  umax=u[i];
        }
    }
    for(int i=0;i<4;i++)
    {
        if(u[i]<umin && u[i]>0 && u[i]<1)   umin=u[i];
        if(u[i]>umax && u[i]>0 && u[i]<1)   umax=u[i];
    }
    x2 = x+dx*umax; y2 = y+dy*umax;
    x = x+dx*umin;  y = y+dy*umin;
}

void display(void)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2i(ceil(x),ceil(y));
    glVertex2i(ceil(x2),ceil(y2));
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,200,-100,200);
}
int main(int argc, char** argv) {
printf("Enter the left bottom corner: ");   scanf("%d %d",&xmin,&ymin);
printf("Enter the right up corner: ");      scanf("%d %d",&xmax,&ymax);
printf("Enter the first coordinate: ");     scanf("%f %f",&x,&y);
printf("Enter the second coordinate: ");    scanf("%f %f",&x2,&y2);
calculateU();
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (10,10);
glutCreateWindow ("Liang Barsky Line Clipping...");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
