#include <windows.h>
#include <GL/glut.h>

// ==============================
// OBJECT ID: OBJ_01
// Ground
// ==============================
void drawGround()
{
    glColor3f(0.2, 0.7, 0.2);

    glBegin(GL_QUADS);

        glVertex2f(0, 0);
        glVertex2f(1200, 0);
        glVertex2f(1200, 150);
        glVertex2f(0, 150);

    glEnd();
}


// Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();

    glFlush();
}


// Initialization Function
void init()
{
    glClearColor(0.5, 0.8, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1200, 0, 700);
}


// Main Function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 700);
    glutInitWindowPosition(100, 50);

    glutCreateWindow("Two Worlds - Smart City and Traditional Village");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
