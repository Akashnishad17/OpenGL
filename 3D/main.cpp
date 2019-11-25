#include <GL\glut.h>
GLfloat x, y, z;
void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(0.1, 0.1, 0.5);
    glRotatef(x,1.0,0.0,0.0);
    glRotatef(y,0.0,1.0,0.0);
    glRotatef(z,0.0,0.0,1.0);
    glutSolidCube(1.5);
    glFlush();
    glutSwapBuffers();
}
void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}
void keyboard(int key, int x, int y)
{
    if(key == GLUT_KEY_DOWN)
        z += 1;
    else if(key == GLUT_KEY_UP)
        z -= 1;
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
        z += 1;
    else if(button == GLUT_RIGHT_BUTTON)
        z -= 1;
    glutPostRedisplay();
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D-CUBE");
    z=30;
    x=43;
    y=50;
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
