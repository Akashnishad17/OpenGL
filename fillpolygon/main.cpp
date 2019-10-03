#include <gl/glut.h>
#include <gl/gl.h>
#include <stdlib.h>
#include <stdio.h>
int x1,y1,x2,y2,x3,y3,x4,y4;

void polygon()
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(x3,y3);
    glVertex2i(x2,y2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x4,y4);
    glEnd();
}
void polygonFill()
{
    int i,j;
    for(i=x2;i>=x4;i--)
    {
        for(j=x2;j>=x1;j--)
        {
            glBegin(GL_POINTS);
            glVertex2i(i,j);
            glEnd();
        }
    }
}

void display(void)
{
    polygon();
    polygonFill();
glFlush();
}

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv) {
printf("Enter the x1 and y1: "); scanf("%d %d",&x1,&y1);
printf("Enter the x2 and y2: "); scanf("%d %d",&x2,&y2);
printf("Enter the x3 and y3: "); scanf("%d %d",&x3,&y3);
printf("Enter the x4 and y4: "); scanf("%d %d",&x4,&y4);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("Filling Polygon");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
