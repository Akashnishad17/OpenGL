//Window

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

void Display(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,100,-100,100);
}
int main(int args,char** argc )
{
    glutInit(&args,argc);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);

    glutCreateWindow("Black Screen");
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
