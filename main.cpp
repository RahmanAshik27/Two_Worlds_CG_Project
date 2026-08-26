#include <windows.h>
#include <GL/glut.h>
#include <cmath>


// ======================================
// HELPER FUNCTION: Draw Circle
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
// OBJECT ID: OBJ_CITY_01
// Object: City Base
// Created by: Ashik
// ======================================
void drawCityBase()
{
    glColor3f(0.55f, 0.75f, 0.35f);

    glBegin(GL_QUADS);

        glVertex2f(0, 0);
        glVertex2f(600, 0);
        glVertex2f(600, 250);
        glVertex2f(0, 250);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_CITY_02
// Object: City Highway
// Created by: Ashik
// ======================================
void drawCityHighway()
{
    glColor3f(0.20f, 0.20f, 0.20f);

    glBegin(GL_QUADS);

        glVertex2f(0, 60);
        glVertex2f(600, 60);
        glVertex2f(600, 180);
        glVertex2f(0, 180);

    glEnd();
}


// ======================================
// Supporting Function: Road Border
// ======================================
void drawRoadBorder()
{
    glColor3f(0.85f, 0.85f, 0.85f);

    glBegin(GL_QUADS);

        // Upper road border
        glVertex2f(0, 175);
        glVertex2f(600, 175);
        glVertex2f(600, 180);
        glVertex2f(0, 180);

        // Lower road border
        glVertex2f(0, 60);
        glVertex2f(600, 60);
        glVertex2f(600, 65);
        glVertex2f(0, 65);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_CITY_03
// Object: Road Markings
// Created by: Ashik
// ======================================
void drawRoadMarkings()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int x = 20; x < 600; x += 80)
    {
        glBegin(GL_QUADS);

            glVertex2f(x,      117);
            glVertex2f(x + 45, 117);
            glVertex2f(x + 45, 123);
            glVertex2f(x,      123);

        glEnd();
    }
}


// ======================================
// OBJECT ID: OBJ_CITY_04
// Object: City Sidewalk
// Created by: Ashik
// ======================================
void drawCitySidewalk()
{
    glColor3f(0.65f, 0.65f, 0.65f);

    glBegin(GL_QUADS);

        // Upper sidewalk
        glVertex2f(0, 180);
        glVertex2f(600, 180);
        glVertex2f(600, 205);
        glVertex2f(0, 205);

        // Lower sidewalk
        glVertex2f(0, 35);
        glVertex2f(600, 35);
        glVertex2f(600, 60);
        glVertex2f(0, 60);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_CITY_05
// Object: AIUB Academic Building
// Created by: Ashik
// ======================================
void drawAIUBBuilding()
{
    // Left wing
    glColor3f(0.88f, 0.90f, 0.92f);

    glBegin(GL_QUADS);

        glVertex2f(35, 205);
        glVertex2f(130, 205);
        glVertex2f(130, 390);
        glVertex2f(35, 390);

    glEnd();


    // Right wing
    glColor3f(0.88f, 0.90f, 0.92f);

    glBegin(GL_QUADS);

        glVertex2f(200, 205);
        glVertex2f(295, 205);
        glVertex2f(295, 390);
        glVertex2f(200, 390);

    glEnd();


    // Center glass section
    glColor3f(0.25f, 0.55f, 0.72f);

    glBegin(GL_QUADS);

        glVertex2f(130, 205);
        glVertex2f(200, 205);
        glVertex2f(200, 410);
        glVertex2f(130, 410);

    glEnd();


    // Dark blue vertical frames
    glColor3f(0.08f, 0.20f, 0.35f);

    glBegin(GL_QUADS);

        glVertex2f(127, 205);
        glVertex2f(133, 205);
        glVertex2f(133, 410);
        glVertex2f(127, 410);

        glVertex2f(197, 205);
        glVertex2f(203, 205);
        glVertex2f(203, 410);
        glVertex2f(197, 410);

    glEnd();


    // Left wing windows
    glColor3f(0.20f, 0.45f, 0.62f);

    for (int y = 250; y <= 350; y += 50)
    {
        for (int x = 48; x <= 103; x += 28)
        {
            glBegin(GL_QUADS);

                glVertex2f(x, y);
                glVertex2f(x + 18, y);
                glVertex2f(x + 18, y + 25);
                glVertex2f(x, y + 25);

            glEnd();
        }
    }


    // Right wing windows
    for (int y = 250; y <= 350; y += 50)
    {
        for (int x = 215; x <= 270; x += 28)
        {
            glBegin(GL_QUADS);

                glVertex2f(x, y);
                glVertex2f(x + 18, y);
                glVertex2f(x + 18, y + 25);
                glVertex2f(x, y + 25);

            glEnd();
        }
    }


    // Glass floor dividers
    glColor3f(0.75f, 0.85f, 0.90f);

    for (int y = 260; y <= 360; y += 50)
    {
        glBegin(GL_QUADS);

            glVertex2f(133, y);
            glVertex2f(197, y);
            glVertex2f(197, y + 3);
            glVertex2f(133, y + 3);

        glEnd();
    }


    // Main glass entrance
    glColor3f(0.10f, 0.28f, 0.42f);

    glBegin(GL_QUADS);

        glVertex2f(145, 205);
        glVertex2f(185, 205);
        glVertex2f(185, 255);
        glVertex2f(145, 255);

    glEnd();


    // Entrance divider
    glColor3f(0.80f, 0.85f, 0.88f);

    glBegin(GL_QUADS);

        glVertex2f(163, 205);
        glVertex2f(166, 205);
        glVertex2f(166, 255);
        glVertex2f(163, 255);

    glEnd();


    // Top roof
    glColor3f(0.10f, 0.22f, 0.38f);

    glBegin(GL_QUADS);

        glVertex2f(25, 390);
        glVertex2f(305, 390);
        glVertex2f(305, 405);
        glVertex2f(25, 405);

    glEnd();


    // AIUB name panel
    glColor3f(0.08f, 0.22f, 0.42f);

    glBegin(GL_QUADS);

        glVertex2f(120, 410);
        glVertex2f(210, 410);
        glVertex2f(210, 440);
        glVertex2f(120, 440);

    glEnd();


    // Front step 1
    glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);

        glVertex2f(135, 195);
        glVertex2f(195, 195);
        glVertex2f(195, 205);
        glVertex2f(135, 205);

    glEnd();


    // Front step 2
    glColor3f(0.62f, 0.62f, 0.62f);

    glBegin(GL_QUADS);

        glVertex2f(125, 185);
        glVertex2f(205, 185);
        glVertex2f(205, 195);
        glVertex2f(125, 195);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_ENV_05
// Object: Green River Bank
// Created by: Ashik
// ======================================
void drawRiverBank()
{
    glColor3f(0.25f, 0.65f, 0.20f);

    glBegin(GL_QUADS);

        glVertex2f(0, 0);
        glVertex2f(1200, 0);
        glVertex2f(1200, 35);
        glVertex2f(0, 35);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_ENV_06
// Object: River
// Created by: Ashik
// ======================================
void drawRiver()
{
    glColor3f(0.10f, 0.55f, 0.85f);

    glBegin(GL_QUADS);

        glVertex2f(0, -200);
        glVertex2f(1200, -200);
        glVertex2f(1200, 0);
        glVertex2f(0, 0);

    glEnd();
}


// ======================================
// Supporting Function: River Details
// ======================================
void drawRiverDetails()
{
    glColor3f(0.75f, 0.90f, 1.0f);

    for (int x = 30; x < 1200; x += 100)
    {
        glBegin(GL_LINES);

            glVertex2f(x, -50);
            glVertex2f(x + 35, -50);

            glVertex2f(x + 40, -110);
            glVertex2f(x + 70, -110);

            glVertex2f(x + 10, -165);
            glVertex2f(x + 45, -165);

        glEnd();
    }
}


// ======================================
// Display Function
// ======================================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    // Background
    drawSky();
    drawGround();


    // City foundation
    drawCityBase();

    drawCitySidewalk();
    drawCityHighway();
    drawRoadBorder();
    drawRoadMarkings();


    // River area
    drawRiverBank();
    drawRiver();
    drawRiverDetails();


    // City objects
    drawAIUBBuilding();


    // Sky objects
    drawSun();

    drawCloud(250, 600);
    drawCloud(520, 550);
    drawCloud(850, 620);


    glFlush();
}


// ======================================
// Initialization Function
// ======================================
void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Extra space added below for river
    gluOrtho2D(0, 1200, -200, 700);
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
