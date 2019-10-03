#include <gl/glut.h>
#include <gl/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int xmin,ymin,xmax,ymax;
struct point{
    int x, y;
    struct point *next;
}*head;
void display(void)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();
    glFlush();
    struct point *p = head;
    glBegin(GL_LINE_LOOP);
    while(p != NULL)
    {
        glVertex2i(ceil(p->x),ceil(p->y));
        p = p->next;
    }
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
struct point *p = (struct point*)malloc(sizeof(struct point*));
head = p;
p->next = NULL;
printf("Enter the first coordinate: ");     scanf("%d %d",&p->x,&p->y);
p = (struct point*)malloc(sizeof(struct point*));
head->next = p;
p->next = NULL;
printf("Enter the second coordinate: ");    scanf("%d %d",&p->x,&p->y);
p = (struct point*)malloc(sizeof(struct point*));
head->next->next = p;
p->next = NULL;
printf("Enter the third coordinate: ");    scanf("%d %d",&p->x,&p->y);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (10,10);
glutCreateWindow ("Sutherland Hodgeman Polygon Clipping...");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
