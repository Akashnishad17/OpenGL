#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

char c;
const int n=8;
int board[n][n];
int k;

void printSolution()
{
    printf("%d-\n",++k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", board[i][j]);
        if(board[i][j] == 0)
            glColor3f(1.0,0.0,0.0);
        else
            glColor3f(0.0,1.0,0.0);
        glBegin(GL_POLYGON);
            glVertex2i(i*50+0,(n-j)*50+0);
            glVertex2i(i*50+0,(n-j)*50+45);
            glVertex2i(i*50+45,(n-j)*50+45);
            glVertex2i(i*50+45,(n-j)*50+0);
        glEnd();
        }
        printf("\n");
    }
    printf("\n");
    glFlush();
}

/* A utility function to check if a queen can
be placed on board[row][col]. note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int row, int col)
{
    int i, j;


    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;


    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;


    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool solvenQUtil(int col)
{
    /* base case: If all queens are placed
    then return true */
    if (col == n )
    {
        printSolution();
        printf("Enter a key to continue: ");
        scanf("%c",&c);
        return true;
    }

    /* Consider this column and try placing
    this queen in all rows one by one */
    for (int i = 0; i < n; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */
        if ( isSafe(i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;


            solvenQUtil(col + 1) ;

            // below commented statement is replaced
            // by above one
            /* if ( solvenQUtil(board, col + 1) )
                 return true;*/

            /* If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }

    /* If queen can not be place in any row in
        this column col then return false */
    return false;
}

/* This function solves the n Queen problem using
Backtracking. It mainly uses solvenQUtil() to
solve the problem. It returns false if queens
canot be placed, otherwise return true and
prints placement of queens in the form of 1s.
*/
void solvenQ()
{
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
        {
            board [i] [j] = 0;
        }

    if (solvenQUtil(0))
    {
        printf("Solution does not exist\n");
        return ;
    }

    return ;
}

void Display(void)
{
    k = 0;
    system("cls");
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0,450.0,0.0,500.0,-1.0,1.0);
    solvenQ();
}
int main(int args,char** argc)
{
    glutInit(&args,argc);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("N Queens");
    glutDisplayFunc(Display);
    glutMainLoop();
}
