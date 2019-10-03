#include<gl/glut.h>
#include<gl/gl.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
int r;
void display(void)
{
int d = 3-2*r;
int x = 0, y = r;

while( x <= y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    if (d < 0)
        d = d + 4*x +6;
    else{
        d = d + 4*(x-y) +10;
        y--;
    }
    x++;
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
glutInitWindowSize (600, 600);
glutInitWindowPosition (0,0);
glutCreateWindow ("Circle");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

