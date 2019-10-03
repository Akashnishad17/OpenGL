#include <gl/glut.h>
#include <gl/gl.h>
#include <stdlib.h>
#include <stdio.h>
int x1,y1,x2,y2,x3,y3,x4,y4;
float fillcolor[3] = {1.0,0.0,0.0};
float boundary[3] = {0.0,0.0,0.0};
int matchColor(float c1[3], float c2[3])
{
    if(c1[0] != c2[0])  return 0;
    else if(c1[1] != c2[1]) return 0;
    else if(c1[2] != c2[2]) return 0;
    else    return 1;
}
void polygonFill(int x,int y, float fillcolor[3],float oldcolor[3])
{
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if(matchColor(color,oldcolor) == 1)
    {
        glColor3fv(fillcolor);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        polygonFill(x+1,y,fillcolor,oldcolor);
        polygonFill(x-1,y,fillcolor,oldcolor);
        polygonFill(x,y+1,fillcolor,oldcolor);
        polygonFill(x,y-1,fillcolor,oldcolor);
    }
    else return;
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(boundary);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
    glFlush();
    float oldcolor[3];
    float x=x1+5, y=y1-5;
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,oldcolor);
    polygonFill(x,y,fillcolor,oldcolor);
}
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}
int main(int argc, char** argv) {
printf("Enter the x1 and y1: "); scanf("%d %d",&x1,&y1);
printf("Enter the x2 and y2: "); scanf("%d %d",&x2,&y2);
printf("Enter the x3 and y3: "); scanf("%d %d",&x3,&y3);
printf("Enter the x4 and y4: "); scanf("%d %d",&x4,&y4);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (250,250);
glutCreateWindow ("4 connected Polygon Flood Filling...");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
