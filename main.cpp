#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// ======================================
// Helper Function: Draw Circle
// ======================================
void drawCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416f / 180.0f;

        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

// ======================================
// OBJECT ID: OBJ_BASE_03
// Object: Sun
// Created by: Ashik
// ======================================
void drawSun()
{
    glColor3f(1.0f, 0.85f, 0.0f);

    drawCircle(100, 610, 45);
}

// ======================================
// OBJECT ID: OBJ_BASE_04
// Object: Cloud
// Created by: Ashik
// ======================================
void drawCloud(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    drawCircle(x,      y,      25);
    drawCircle(x + 25, y + 10, 30);
    drawCircle(x + 55, y + 5,  27);
    drawCircle(x + 80, y,      23);
}


// ======================================
// OBJECT ID: OBJ_BASE_01
// Object: Sky
// Created by: Ashik
// ======================================
void drawSky()
{
    glColor3f(0.53f, 0.81f, 0.98f);

    glBegin(GL_QUADS);

        glVertex2f(0, 250);
        glVertex2f(1200, 250);
        glVertex2f(1200, 700);
        glVertex2f(0, 700);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_BASE_02
// Object: Ground
// Created by: Ashik
// ======================================
void drawGround()
{
    glColor3f(0.35f, 0.70f, 0.25f);

    glBegin(GL_QUADS);

        glVertex2f(0, 0);
        glVertex2f(1200, 0);
        glVertex2f(1200, 250);
        glVertex2f(0, 250);

    glEnd();
}


// ======================================
// Display Function
// ======================================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawGround();

    drawSun();

    drawCloud(250, 600);
    drawCloud(520, 550);
    drawCloud(850, 620);

    glFlush();
}

// ======================================
// Initialization
// ======================================
void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1200, 0, 700);
}


// ======================================
// Main Function
// ======================================
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 700);
    glutInitWindowPosition(100, 50);

    glutCreateWindow(
        "Two Worlds - Smart City and Traditional Village"
    );

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
