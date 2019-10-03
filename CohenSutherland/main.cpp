#include <gl/glut.h>
#include <gl/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int xl,yl,xr,yr;
struct code{
    float x,y;
    int l,r,u,d;
}first,second;
void findCode(struct code *c)
{
    if(c->x>=xl && c->x<=xr && c->y>=yl && c->y<=yr)    return;
    if (c->x<xl)       c->l=1;
    else if (c->x>xr)  c->r=1;
    if (c->y<yl)       c->d=1;
    else if (c->y>yr)  c->u=1;
}

void clipLine(struct code *c,float m)
{
    if (c->l == 0 && c->r == 0 && c->u == 0 && c->d == 0)
        return;
    if (c->l != 0)
    {
        c->x = xl;  c->y = (c->x - xl)/m + c->y;
    }
    else if (c->r != 0)
    {
        c->x = xr;  c->y = (c->x - xr)/m + c->y;
    }
    if(c->u != 0)
    {
        c->y = yr;  c->x = c->x - (c->y - yr)*m;
    }
    else if(c->d != 0)
    {
        c->y = yl;  c->x = c->x - (c->y - yl)*m;
    }
}
void display(void)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(xl,yl);
    glVertex2i(xl,yr);
    glVertex2i(xr,yr);
    glVertex2i(xr,yl);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2i(ceil(first.x),ceil(first.y));
    glVertex2i(ceil(second.x),ceil(second.y));
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,100,-100,200);
}
int main(int argc, char** argv) {
printf("Enter the left bottom corner: ");   scanf("%d %d",&xl,&yl);
printf("Enter the right up corner: ");      scanf("%d %d",&xr,&yr);
printf("Enter the first coordinate: ");     scanf("%f %f",&first.x,&first.y);
printf("Enter the second coordinate: ");    scanf("%f %f",&second.x,&second.y);
float m = (second.y-first.y)/(second.x-first.x);
findCode(&first);
findCode(&second);
clipLine(&first,m);
clipLine(&second,m);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (10,10);
glutCreateWindow ("Cohen Sutherland Line Clipping...");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
