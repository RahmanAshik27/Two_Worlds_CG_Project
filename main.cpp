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
    glColor3f(1.0f, 0.82f, 0.15f);

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

    drawCircle(x, y, 25);
    drawCircle(x + 25, y + 10, 30);
    drawCircle(x + 55, y + 5, 27);
    drawCircle(x + 80, y, 23);
}

// ======================================
// SUPPORTING FUNCTION
// Distant City Skyline
// Background Decoration Only
// ======================================
void drawDistantCity()
{
    // =====================================
    // Building 1
    // =====================================
    glColor3f(0.38f, 0.52f, 0.65f);

    glBegin(GL_QUADS);
        glVertex2f(10, 250);
        glVertex2f(55, 250);
        glVertex2f(55, 390);
        glVertex2f(10, 390);
    glEnd();

    // Windows
    glColor3f(0.75f, 0.88f, 0.92f);

    for (int y = 275; y <= 355; y += 28)
    {
        for (int x = 18; x <= 40; x += 16)
        {
            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + 8, y);
                glVertex2f(x + 8, y + 12);
                glVertex2f(x, y + 12);
            glEnd();
        }
    }


    // =====================================
    // Building 2
    // =====================================
    glColor3f(0.46f, 0.58f, 0.68f);

    glBegin(GL_QUADS);
        glVertex2f(70, 250);
        glVertex2f(110, 250);
        glVertex2f(110, 350);
        glVertex2f(70, 350);
    glEnd();

    glColor3f(0.78f, 0.88f, 0.90f);

    for (int y = 272; y <= 325; y += 26)
    {
        for (int x = 78; x <= 94; x += 16)
        {
            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + 8, y);
                glVertex2f(x + 8, y + 11);
                glVertex2f(x, y + 11);
            glEnd();
        }
    }


    // =====================================
    // Building 3
    // Tall
    // =====================================
    glColor3f(0.34f, 0.47f, 0.60f);

    glBegin(GL_QUADS);
        glVertex2f(285, 250);
        glVertex2f(330, 250);
        glVertex2f(330, 420);
        glVertex2f(285, 420);
    glEnd();

    glColor3f(0.72f, 0.85f, 0.90f);

    for (int y = 275; y <= 385; y += 28)
    {
        for (int x = 294; x <= 314; x += 16)
        {
            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + 8, y);
                glVertex2f(x + 8, y + 12);
                glVertex2f(x, y + 12);
            glEnd();
        }
    }


    // =====================================
    // Building 4
    // =====================================
    glColor3f(0.50f, 0.63f, 0.72f);

    glBegin(GL_QUADS);
        glVertex2f(445, 250);
        glVertex2f(490, 250);
        glVertex2f(490, 380);
        glVertex2f(445, 380);
    glEnd();

    glColor3f(0.80f, 0.90f, 0.92f);

    for (int y = 275; y <= 345; y += 28)
    {
        for (int x = 454; x <= 474; x += 16)
        {
            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + 8, y);
                glVertex2f(x + 8, y + 12);
                glVertex2f(x, y + 12);
            glEnd();
        }
    }


    // =====================================
    // Building 5
    // Tall
    // =====================================
    glColor3f(0.31f, 0.44f, 0.56f);

    glBegin(GL_QUADS);
        glVertex2f(500, 250);
        glVertex2f(540, 250);
        glVertex2f(540, 435);
        glVertex2f(500, 435);
    glEnd();

    glColor3f(0.74f, 0.86f, 0.90f);

    for (int y = 275; y <= 400; y += 28)
    {
        for (int x = 508; x <= 524; x += 16)
        {
            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + 8, y);
                glVertex2f(x + 8, y + 12);
                glVertex2f(x, y + 12);
            glEnd();
        }
    }


    // =====================================
    // Building 6
    // =====================================
    glColor3f(0.42f, 0.56f, 0.66f);

    glBegin(GL_QUADS);
        glVertex2f(552, 250);
        glVertex2f(590, 250);
        glVertex2f(590, 365);
        glVertex2f(552, 365);
    glEnd();

    glColor3f(0.78f, 0.88f, 0.92f);

    for (int y = 275; y <= 330; y += 28)
    {
        for (int x = 560; x <= 575; x += 15)
        {
            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + 7, y);
                glVertex2f(x + 7, y + 11);
                glVertex2f(x, y + 11);
            glEnd();
        }
    }
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
    glColor3f(0.16f, 0.17f, 0.18f);

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

        glVertex2f(0, 175);
        glVertex2f(600, 175);
        glVertex2f(600, 180);
        glVertex2f(0, 180);

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

            glVertex2f(x, 117);
            glVertex2f(x + 45, 117);
            glVertex2f(x + 45, 123);
            glVertex2f(x, 123);

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
    glColor3f(0.68f, 0.68f, 0.68f);

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
    // =====================================
    // LEFT WING
    // Warm cream
    // =====================================
    glColor3f(0.92f, 0.88f, 0.76f);

    glBegin(GL_QUADS);

        glVertex2f(35, 205);
        glVertex2f(130, 205);
        glVertex2f(130, 390);
        glVertex2f(35, 390);

    glEnd();


    // =====================================
    // RIGHT WING
    // =====================================
    glColor3f(0.92f, 0.88f, 0.76f);

    glBegin(GL_QUADS);

        glVertex2f(200, 205);
        glVertex2f(295, 205);
        glVertex2f(295, 390);
        glVertex2f(200, 390);

    glEnd();


    // =====================================
    // CENTER GLASS SECTION
    // =====================================
    glColor3f(0.45f, 0.70f, 0.84f);

    glBegin(GL_QUADS);

        glVertex2f(130, 205);
        glVertex2f(200, 205);
        glVertex2f(200, 410);
        glVertex2f(130, 410);

    glEnd();


    // =====================================
    // DARK NAVY FRAMES
    // =====================================
    glColor3f(0.05f, 0.12f, 0.22f);

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


    // =====================================
    // LEFT WING WINDOWS
    // =====================================
    glColor3f(0.42f, 0.67f, 0.80f);

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


    // =====================================
    // RIGHT WING WINDOWS
    // =====================================
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


    // =====================================
    // GLASS FLOOR DIVIDERS
    // =====================================
    glColor3f(0.78f, 0.88f, 0.92f);

    for (int y = 260; y <= 360; y += 50)
    {
        glBegin(GL_QUADS);

            glVertex2f(133, y);
            glVertex2f(197, y);
            glVertex2f(197, y + 3);
            glVertex2f(133, y + 3);

        glEnd();
    }


    // =====================================
    // MAIN ENTRANCE
    // =====================================
    glColor3f(0.08f, 0.24f, 0.38f);

    glBegin(GL_QUADS);

        glVertex2f(145, 205);
        glVertex2f(185, 205);
        glVertex2f(185, 255);
        glVertex2f(145, 255);

    glEnd();


    // Entrance divider
    glColor3f(0.88f, 0.90f, 0.90f);

    glBegin(GL_QUADS);

        glVertex2f(163, 205);
        glVertex2f(166, 205);
        glVertex2f(166, 255);
        glVertex2f(163, 255);

    glEnd();


    // =====================================
    // TOP ROOF
    // =====================================
    glColor3f(0.05f, 0.15f, 0.28f);

    glBegin(GL_QUADS);

        glVertex2f(25, 390);
        glVertex2f(305, 390);
        glVertex2f(305, 405);
        glVertex2f(25, 405);

    glEnd();


    // =====================================
    // AIUB SIGN PANEL
    // =====================================
    glColor3f(0.06f, 0.20f, 0.38f);

    glBegin(GL_QUADS);

        glVertex2f(120, 410);
        glVertex2f(210, 410);
        glVertex2f(210, 440);
        glVertex2f(120, 440);

    glEnd();


    // =====================================
    // FRONT STEPS
    // =====================================
    glColor3f(0.74f, 0.74f, 0.74f);

    glBegin(GL_QUADS);

        glVertex2f(135, 195);
        glVertex2f(195, 195);
        glVertex2f(195, 205);
        glVertex2f(135, 205);

    glEnd();


    glColor3f(0.62f, 0.62f, 0.62f);

    glBegin(GL_QUADS);

        glVertex2f(125, 185);
        glVertex2f(205, 185);
        glVertex2f(205, 195);
        glVertex2f(125, 195);

    glEnd();
}


// ======================================
// OBJECT ID: OBJ_CITY_06
// Object: Modern High-Rise Building
// Created by: Apon
// ======================================
void drawHighRiseBuilding()
{
    // =====================================
    // MAIN BODY
    // Soft sandstone / warm beige
    // =====================================
    glColor3f(0.74f, 0.68f, 0.58f);

    glBegin(GL_QUADS);

        glVertex2f(330, 205);
        glVertex2f(430, 205);
        glVertex2f(430, 460);
        glVertex2f(330, 460);

    glEnd();


    // =====================================
    // DARK SIDE PANEL
    // =====================================
    glColor3f(0.18f, 0.23f, 0.30f);

    glBegin(GL_QUADS);

        glVertex2f(330, 205);
        glVertex2f(348, 205);
        glVertex2f(348, 460);
        glVertex2f(330, 460);

    glEnd();


    // =====================================
    // ROOF
    // =====================================
    glColor3f(0.12f, 0.18f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(325, 460);
        glVertex2f(435, 460);
        glVertex2f(435, 475);
        glVertex2f(325, 475);

    glEnd();


    // =====================================
    // WINDOWS
    // Muted cyan-blue
    // =====================================
    glColor3f(0.30f, 0.60f, 0.72f);

    for (int y = 240; y <= 410; y += 42)
    {
        for (int x = 360; x <= 400; x += 28)
        {
            glBegin(GL_QUADS);

                glVertex2f(x, y);
                glVertex2f(x + 18, y);
                glVertex2f(x + 18, y + 24);
                glVertex2f(x, y + 24);

            glEnd();
        }
    }


    // =====================================
    // WINDOW HIGHLIGHTS
    // =====================================
    glColor3f(0.66f, 0.82f, 0.88f);

    for (int y = 240; y <= 410; y += 42)
    {
        for (int x = 360; x <= 400; x += 28)
        {
            glBegin(GL_QUADS);

                glVertex2f(x, y + 19);
                glVertex2f(x + 18, y + 19);
                glVertex2f(x + 18, y + 24);
                glVertex2f(x, y + 24);

            glEnd();
        }
    }


    // =====================================
    // ACCENT STRIP
    // Muted orange
    // =====================================
    glColor3f(0.85f, 0.46f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(348, 315);
        glVertex2f(430, 315);
        glVertex2f(430, 322);
        glVertex2f(348, 322);

    glEnd();


    // =====================================
    // ENTRANCE
    // =====================================
    glColor3f(0.10f, 0.40f, 0.52f);

    glBegin(GL_QUADS);

        glVertex2f(365, 205);
        glVertex2f(395, 205);
        glVertex2f(395, 250);
        glVertex2f(365, 250);

    glEnd();


    // Door divider
    glColor3f(0.90f, 0.92f, 0.90f);

    glBegin(GL_QUADS);

        glVertex2f(378, 205);
        glVertex2f(381, 205);
        glVertex2f(381, 250);
        glVertex2f(378, 250);

    glEnd();


    // =====================================
    // BOTTOM BASE
    // =====================================
    glColor3f(0.12f, 0.18f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(322, 200);
        glVertex2f(438, 200);
        glVertex2f(438, 208);
        glVertex2f(322, 208);

    glEnd();
}

// ======================================
// OBJECT ID: OBJ_CITY_07
// Object: Modern Food Court
// Created by: Apon
// ======================================
void drawFoodCourt()
{
    // =====================================
    // MAIN BUILDING BODY
    // Warm cream
    // =====================================
    glColor3f(0.90f, 0.82f, 0.68f);

    glBegin(GL_QUADS);

        glVertex2f(445, 205);
        glVertex2f(590, 205);
        glVertex2f(590, 325);
        glVertex2f(445, 325);

    glEnd();


    // =====================================
    // TOP SIGN AREA
    // Warm terracotta brown
    // =====================================
    glColor3f(0.55f, 0.28f, 0.12f);

    glBegin(GL_QUADS);

        glVertex2f(435, 325);
        glVertex2f(600, 325);
        glVertex2f(600, 350);
        glVertex2f(435, 350);

    glEnd();


    // =====================================
    // DARK LOWER ROOF STRIP
    // =====================================
    glColor3f(0.12f, 0.18f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(440, 315);
        glVertex2f(595, 315);
        glVertex2f(595, 325);
        glVertex2f(440, 325);

    glEnd();


    // =====================================
    // LARGE FRONT GLASS WINDOW
    // =====================================
    glColor3f(0.42f, 0.70f, 0.82f);

    glBegin(GL_QUADS);

        glVertex2f(465, 235);
        glVertex2f(555, 235);
        glVertex2f(555, 300);
        glVertex2f(465, 300);

    glEnd();


    // =====================================
    // GLASS WINDOW DIVIDERS
    // =====================================
    glColor3f(0.12f, 0.22f, 0.30f);

    // Vertical divider 1
    glBegin(GL_QUADS);

        glVertex2f(494, 235);
        glVertex2f(498, 235);
        glVertex2f(498, 300);
        glVertex2f(494, 300);

    glEnd();


    // Vertical divider 2
    glBegin(GL_QUADS);

        glVertex2f(523, 235);
        glVertex2f(527, 235);
        glVertex2f(527, 300);
        glVertex2f(523, 300);

    glEnd();


    // Horizontal divider
    glBegin(GL_QUADS);

        glVertex2f(465, 266);
        glVertex2f(555, 266);
        glVertex2f(555, 270);
        glVertex2f(465, 270);

    glEnd();


    // =====================================
    // MAIN DOOR
    // =====================================
    glColor3f(0.33f, 0.18f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(560, 205);
        glVertex2f(585, 205);
        glVertex2f(585, 270);
        glVertex2f(560, 270);

    glEnd();


    // =====================================
    // DOOR GLASS
    // =====================================
    glColor3f(0.35f, 0.62f, 0.72f);

    glBegin(GL_QUADS);

        glVertex2f(564, 230);
        glVertex2f(581, 230);
        glVertex2f(581, 263);
        glVertex2f(564, 263);

    glEnd();


    // =====================================
    // LEFT DECORATIVE PANEL
    // =====================================
    glColor3f(0.68f, 0.38f, 0.16f);

    glBegin(GL_QUADS);

        glVertex2f(445, 205);
        glVertex2f(458, 205);
        glVertex2f(458, 315);
        glVertex2f(445, 315);

    glEnd();


    // =====================================
    // BOTTOM BASE
    // =====================================
    glColor3f(0.16f, 0.18f, 0.20f);

    glBegin(GL_QUADS);

        glVertex2f(440, 200);
        glVertex2f(595, 200);
        glVertex2f(595, 207);
        glVertex2f(440, 207);

    glEnd();
}

// ======================================
// OBJECT ID: OBJ_CITY_08
// Object: Riverfront City Park
// Created by: Apon
// ======================================
void drawCityPark()
{
    // =====================================
    // MAIN PARK GROUND
    // Wide green riverfront area
    // =====================================
    glColor3f(0.34f, 0.62f, 0.22f);

    glBegin(GL_QUADS);

        glVertex2f(0, -50);
        glVertex2f(600, -50);
        glVertex2f(600, 35);
        glVertex2f(0, 35);

    glEnd();


    // =====================================
    // WALKING PATH
    // =====================================
    glColor3f(0.78f, 0.70f, 0.53f);

    glBegin(GL_QUADS);

        glVertex2f(0, -32);
        glVertex2f(600, -32);
        glVertex2f(600, -20);
        glVertex2f(0, -20);

    glEnd();


    // =====================================
    // TREE 1
    // =====================================
    glColor3f(0.40f, 0.23f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(70, -10);
        glVertex2f(77, -10);
        glVertex2f(77, 18);
        glVertex2f(70, 18);

    glEnd();

    glColor3f(0.14f, 0.46f, 0.16f);

    drawCircle(73, 27, 17);
    drawCircle(61, 23, 12);
    drawCircle(85, 23, 12);


    // =====================================
    // TREE 2
    // =====================================
    glColor3f(0.40f, 0.23f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(280, -10);
        glVertex2f(287, -10);
        glVertex2f(287, 18);
        glVertex2f(280, 18);

    glEnd();

    glColor3f(0.18f, 0.52f, 0.18f);

    drawCircle(283, 28, 18);
    drawCircle(271, 24, 12);
    drawCircle(295, 24, 12);


    // =====================================
    // TREE 3
    // =====================================
    glColor3f(0.40f, 0.23f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(510, -10);
        glVertex2f(517, -10);
        glVertex2f(517, 18);
        glVertex2f(510, 18);

    glEnd();

    glColor3f(0.16f, 0.48f, 0.17f);

    drawCircle(513, 28, 18);
    drawCircle(501, 24, 12);
    drawCircle(525, 24, 12);


    // =====================================
    // BENCH 1
    // =====================================
    glColor3f(0.55f, 0.31f, 0.13f);

    glBegin(GL_QUADS);

        // Seat
        glVertex2f(135, -5);
        glVertex2f(195, -5);
        glVertex2f(195, 2);
        glVertex2f(135, 2);

        // Back
        glVertex2f(138, 6);
        glVertex2f(192, 6);
        glVertex2f(192, 13);
        glVertex2f(138, 13);

    glEnd();


    // Bench legs
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);

        glVertex2f(142, -12);
        glVertex2f(147, -12);
        glVertex2f(147, -5);
        glVertex2f(142, -5);

        glVertex2f(183, -12);
        glVertex2f(188, -12);
        glVertex2f(188, -5);
        glVertex2f(183, -5);

    glEnd();


    // =====================================
    // BENCH 2
    // =====================================
    glColor3f(0.55f, 0.31f, 0.13f);

    glBegin(GL_QUADS);

        glVertex2f(380, -5);
        glVertex2f(440, -5);
        glVertex2f(440, 2);
        glVertex2f(380, 2);

        glVertex2f(383, 6);
        glVertex2f(437, 6);
        glVertex2f(437, 13);
        glVertex2f(383, 13);

    glEnd();


    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);

        glVertex2f(387, -12);
        glVertex2f(392, -12);
        glVertex2f(392, -5);
        glVertex2f(387, -5);

        glVertex2f(428, -12);
        glVertex2f(433, -12);
        glVertex2f(433, -5);
        glVertex2f(428, -5);

    glEnd();


    // =====================================
    // FLOWERS LEFT SIDE
    // =====================================
    glColor3f(0.95f, 0.30f, 0.35f);
    drawCircle(105, -8, 3);

    glColor3f(1.0f, 0.75f, 0.12f);
    drawCircle(115, -5, 3);

    glColor3f(0.95f, 0.42f, 0.15f);
    drawCircle(125, -8, 3);


    // =====================================
    // FLOWERS CENTER
    // =====================================
    glColor3f(0.90f, 0.30f, 0.55f);
    drawCircle(325, -7, 3);

    glColor3f(1.0f, 0.75f, 0.10f);
    drawCircle(335, -4, 3);

    glColor3f(0.95f, 0.32f, 0.20f);
    drawCircle(345, -7, 3);


    // =====================================
    // FLOWERS RIGHT
    // =====================================
    glColor3f(0.95f, 0.30f, 0.35f);
    drawCircle(465, -8, 3);

    glColor3f(1.0f, 0.72f, 0.12f);
    drawCircle(475, -5, 3);

    glColor3f(0.90f, 0.35f, 0.55f);
    drawCircle(485, -8, 3);
}
// ======================================
// OBJECT ID: OBJ_CITY_09
// Object: Bus Stop
// Created by: Apon
// ======================================
void drawBusStop()
{
    // =====================================
    // MAIN ROOF
    // =====================================
    glColor3f(0.10f, 0.18f, 0.28f);

    glBegin(GL_QUADS);

        glVertex2f(295, 105);
        glVertex2f(350, 105);
        glVertex2f(350, 115);
        glVertex2f(295, 115);

    glEnd();


    // =====================================
    // LEFT SUPPORT
    // =====================================
    glColor3f(0.18f, 0.22f, 0.28f);

    glBegin(GL_QUADS);

        glVertex2f(300, 60);
        glVertex2f(305, 60);
        glVertex2f(305, 105);
        glVertex2f(300, 105);

    glEnd();


    // =====================================
    // RIGHT SUPPORT
    // =====================================
    glBegin(GL_QUADS);

        glVertex2f(340, 60);
        glVertex2f(345, 60);
        glVertex2f(345, 105);
        glVertex2f(340, 105);

    glEnd();


    // =====================================
    // BACK GLASS
    // =====================================
    glColor3f(0.40f, 0.70f, 0.82f);

    glBegin(GL_QUADS);

        glVertex2f(305, 68);
        glVertex2f(340, 68);
        glVertex2f(340, 102);
        glVertex2f(305, 102);

    glEnd();


    // =====================================
    // GLASS DIVIDER
    // =====================================
    glColor3f(0.85f, 0.90f, 0.92f);

    glBegin(GL_QUADS);

        glVertex2f(321, 68);
        glVertex2f(324, 68);
        glVertex2f(324, 102);
        glVertex2f(321, 102);

    glEnd();


    // =====================================
    // BENCH
    // =====================================
    glColor3f(0.52f, 0.30f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(310, 70);
        glVertex2f(335, 70);
        glVertex2f(335, 76);
        glVertex2f(310, 76);

    glEnd();


    // =====================================
    // BENCH LEGS
    // =====================================
    glColor3f(0.14f, 0.14f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(313, 62);
        glVertex2f(317, 62);
        glVertex2f(317, 70);
        glVertex2f(313, 70);

        glVertex2f(329, 62);
        glVertex2f(333, 62);
        glVertex2f(333, 70);
        glVertex2f(329, 70);

    glEnd();


    // =====================================
    // BUS STOP SIGN POLE
    // =====================================
    glColor3f(0.15f, 0.18f, 0.20f);

    glBegin(GL_QUADS);

        glVertex2f(286, 60);
        glVertex2f(290, 60);
        glVertex2f(290, 105);
        glVertex2f(286, 105);

    glEnd();


    // =====================================
    // BUS STOP SIGN BOARD
    // =====================================
    glColor3f(0.10f, 0.35f, 0.60f);

    glBegin(GL_QUADS);

        glVertex2f(278, 92);
        glVertex2f(298, 92);
        glVertex2f(298, 108);
        glVertex2f(278, 108);

    glEnd();
}
// ======================================
// OBJECT ID: OBJ_ENV_05
// Object: Green River Bank
// Created by: Ashik
// ======================================
void drawRiverBank()
{
    glColor3f(0.20f, 0.55f, 0.16f);

    glBegin(GL_QUADS);

        glVertex2f(0, -70);
        glVertex2f(1200, -70);
        glVertex2f(1200, 0);
        glVertex2f(0, 0);

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
        glVertex2f(1200, -70);
        glVertex2f(0, -70);

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

            glVertex2f(x, -95);
            glVertex2f(x + 35, -95);

            glVertex2f(x + 40, -135);
            glVertex2f(x + 70, -135);

            glVertex2f(x + 10, -175);
            glVertex2f(x + 45, -175);

        glEnd();
    }
}


// ======================================
// DISPLAY FUNCTION
// ======================================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    drawSky();
    drawGround();

    // Background city
    drawDistantCity();


    // City foundation
    drawCityBase();

    drawCitySidewalk();
    drawCityHighway();
    drawRoadBorder();
    drawRoadMarkings();


    // River
    drawRiver();
    drawRiverDetails();

    drawRiverBank();


    // Riverfront City Park
    drawCityPark();


    // Main City Objects
    drawAIUBBuilding();
    drawHighRiseBuilding();
    drawFoodCourt();

    drawBusStop();


    // Sky Objects
    drawSun();

    drawCloud(250, 600);
    drawCloud(520, 550);
    drawCloud(850, 620);

    glFlush();
}

// ======================================
// INITIALIZATION
// ======================================
void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1200, -200, 700);
}


// ======================================
// MAIN FUNCTION
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

