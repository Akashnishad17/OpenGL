#include <gl/glut.h>
#include <gl/gl.h>
#include <stdio.h>
float rx,ry;

void plot(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glVertex2i(x,-y);
    glVertex2i(-x,-y);
    glVertex2i(-x,y);
    glEnd();
}

void display(void)
{
float x = 0, y = ry;
float p1 = ry*ry - rx*rx*ry + rx*rx/4.0;
float dx,dy;
dx = 2 * ry * ry * x;
dy = 2 * rx * rx * y;
plot(x,y);
while(dx < dy)
{
    x++;
    if (p1 < 0){
        dx = dx + (2 * ry * ry);
        p1 = p1 + dx + (ry * ry);
    }
    else{
        y--;
        dx = dx + (2 * ry * ry);
        dy = dy - (2 * rx * rx);
        p1 = p1 + dx - dy + (ry * ry);
    }
    plot(x,y);
}
float p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
while (y >= 0){
    y--;
    if (p2 > 0){
        dy = dy - (2 * rx * rx);
        p2 = p2 + (rx * rx) - dy;
    }
    else {
        x++;
        dx = dx + (2 * ry * ry);
        dy = dy - (2 * rx * rx);
        p2 = p2 + dx - dy + (rx * rx);
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
printf("Enter the Rx : ");
scanf("%f",&rx);
printf("Enter the Ry : ");
scanf("%f",&ry);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("Mid Point Algo for Ellipse");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

