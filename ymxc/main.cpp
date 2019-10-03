#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

void Display(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,100,-100,100);
    glBegin(GL_LINES);
      glVertex2i(20,60);
      glVertex2i(30,80);
      glColor3f(1,0,0);
    glEnd();
    glFlush();


}
int main(int args,char** argc )
{
    glutInit(&args,argc);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);

    glutCreateWindow("Line Plot");
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;

}
