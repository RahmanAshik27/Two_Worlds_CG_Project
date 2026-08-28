#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// HELPER FUNCTION: Draw Circle

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



// OBJECT ID: OBJ_BASE_01
// Object: Sky
// Created by: Ashik

void drawSky()
{
    glColor3f(0.53f, 0.81f, 0.98f);

    glBegin(GL_QUADS);

        glVertex2f(0, 250);
        glVertex2f(1600, 250);
        glVertex2f(1600, 700);
        glVertex2f(0, 700);

    glEnd();
}



// OBJECT ID: OBJ_BASE_02
// Object: Ground
// Created by: Ashik

void drawGround()
{
    glColor3f(0.35f, 0.70f, 0.25f);

    glBegin(GL_QUADS);

        glVertex2f(0, -70);
        glVertex2f(1600, -70);
        glVertex2f(1600, 250);
        glVertex2f(0, 250);

    glEnd();
}



// OBJECT ID: OBJ_BASE_03
// Object: Sun
// Created by: Ashik

void drawSun()
{
    glColor3f(1.0f, 0.82f, 0.15f);

    drawCircle(100, 610, 45);
}



// OBJECT ID: OBJ_BASE_04
// Object: Cloud
// Created by: Ashik

void drawCloud(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    drawCircle(x, y, 25);
    drawCircle(x + 25, y + 10, 30);
    drawCircle(x + 55, y + 5, 27);
    drawCircle(x + 80, y, 23);
}


// SUPPORTING FUNCTION
// Distant City Skyline
// Background Decoration Only

void drawDistantCity()
{

    // Building 1

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



    // Building 2

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



    // Building 3
    // Tall

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



    // Building 4

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



    // Building 5
    // Tall

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



    // Building 6

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


// OBJECT ID: OBJ_CITY_01
// Object: City Base
// Created by: Ashik

void drawCityBase()
{
    glColor3f(0.55f, 0.75f, 0.35f);

    glBegin(GL_QUADS);

        glVertex2f(0, 0);
        glVertex2f(700, 0);
        glVertex2f(700, 250);
        glVertex2f(0, 250);

    glEnd();
}


// OBJECT ID: OBJ_CITY_02
// Object: City Highway
// Created by: Ashik

void drawCityHighway()
{
    glColor3f(0.18f, 0.18f, 0.18f);

    glBegin(GL_QUADS);

        glVertex2f(0, 60);
        glVertex2f(700, 60);
        glVertex2f(700, 180);
        glVertex2f(0, 180);

    glEnd();
}

// Supporting Function: Road Border

void drawRoadBorder()
{
    glColor3f(0.82f, 0.82f, 0.82f);

    glBegin(GL_QUADS);

        // Upper border
        glVertex2f(0, 175);
        glVertex2f(700, 175);
        glVertex2f(700, 180);
        glVertex2f(0, 180);

        // Lower border
        glVertex2f(0, 60);
        glVertex2f(700, 60);
        glVertex2f(700, 65);
        glVertex2f(0, 65);

    glEnd();
}


// OBJECT ID: OBJ_CITY_03
// Object: Road Markings
// Created by: Ashik

void drawRoadMarkings()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int x = 20; x < 700; x += 80)
    {
        glBegin(GL_QUADS);

            glVertex2f(x, 117);
            glVertex2f(x + 45, 117);
            glVertex2f(x + 45, 123);
            glVertex2f(x, 123);

        glEnd();
    }
}



// OBJECT ID: OBJ_CITY_04
// Object: City Sidewalk
// Created by: Ashik

void drawCitySidewalk()
{
    glColor3f(0.68f, 0.68f, 0.68f);

    glBegin(GL_QUADS);

        // Upper sidewalk
        glVertex2f(0, 180);
        glVertex2f(700, 180);
        glVertex2f(700, 205);
        glVertex2f(0, 205);

        // Lower sidewalk
        glVertex2f(0, 35);
        glVertex2f(700, 35);
        glVertex2f(700, 60);
        glVertex2f(0, 60);

    glEnd();
}


// OBJECT ID: OBJ_CITY_05
// Object: AIUB Academic Building
// Created by: Ashik

void drawAIUBBuilding()
{

    // LEFT WING
    // Warm cream

    glColor3f(0.92f, 0.88f, 0.76f);

    glBegin(GL_QUADS);

        glVertex2f(35, 205);
        glVertex2f(130, 205);
        glVertex2f(130, 390);
        glVertex2f(35, 390);

    glEnd();



    // RIGHT WING

    glColor3f(0.92f, 0.88f, 0.76f);

    glBegin(GL_QUADS);

        glVertex2f(200, 205);
        glVertex2f(295, 205);
        glVertex2f(295, 390);
        glVertex2f(200, 390);

    glEnd();



    // CENTER GLASS SECTION

    glColor3f(0.45f, 0.70f, 0.84f);

    glBegin(GL_QUADS);

        glVertex2f(130, 205);
        glVertex2f(200, 205);
        glVertex2f(200, 410);
        glVertex2f(130, 410);

    glEnd();



    // DARK NAVY FRAMES

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



    // LEFT WING WINDOWS

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



    // RIGHT WING WINDOWS

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



    // GLASS FLOOR DIVIDERS

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



    // MAIN ENTRANCE

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



    // TOP ROOF

    glColor3f(0.05f, 0.15f, 0.28f);

    glBegin(GL_QUADS);

        glVertex2f(25, 390);
        glVertex2f(305, 390);
        glVertex2f(305, 405);
        glVertex2f(25, 405);

    glEnd();



    // AIUB SIGN PANEL

    glColor3f(0.06f, 0.20f, 0.38f);

    glBegin(GL_QUADS);

        glVertex2f(120, 410);
        glVertex2f(210, 410);
        glVertex2f(210, 440);
        glVertex2f(120, 440);

    glEnd();



    // FRONT STEPS

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



// OBJECT ID: OBJ_CITY_06
// Object: Modern High-Rise Building
// Created by: Apon

void drawHighRiseBuilding()
{

    // MAIN BODY
    // Soft sandstone / warm beige

    glColor3f(0.74f, 0.68f, 0.58f);

    glBegin(GL_QUADS);

        glVertex2f(330, 205);
        glVertex2f(430, 205);
        glVertex2f(430, 460);
        glVertex2f(330, 460);

    glEnd();



    // DARK SIDE PANEL

    glColor3f(0.18f, 0.23f, 0.30f);

    glBegin(GL_QUADS);

        glVertex2f(330, 205);
        glVertex2f(348, 205);
        glVertex2f(348, 460);
        glVertex2f(330, 460);

    glEnd();



    // ROOF

    glColor3f(0.12f, 0.18f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(325, 460);
        glVertex2f(435, 460);
        glVertex2f(435, 475);
        glVertex2f(325, 475);

    glEnd();



    // WINDOWS
    // Muted cyan-blue

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



    // WINDOW HIGHLIGHTS

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



    // ACCENT STRIP
    // Muted orange

    glColor3f(0.85f, 0.46f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(348, 315);
        glVertex2f(430, 315);
        glVertex2f(430, 322);
        glVertex2f(348, 322);

    glEnd();



    // ENTRANCE

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



    // BOTTOM BASE

    glColor3f(0.12f, 0.18f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(322, 200);
        glVertex2f(438, 200);
        glVertex2f(438, 208);
        glVertex2f(322, 208);

    glEnd();
}


// OBJECT ID: OBJ_CITY_07
// Object: Modern Food Court
// Created by: Apon

void drawFoodCourt()
{

    // MAIN BUILDING BODY
    // Warm cream

    glColor3f(0.90f, 0.82f, 0.68f);

    glBegin(GL_QUADS);

        glVertex2f(445, 205);
        glVertex2f(590, 205);
        glVertex2f(590, 325);
        glVertex2f(445, 325);

    glEnd();



    // TOP SIGN AREA
    // Warm terracotta brown

    glColor3f(0.55f, 0.28f, 0.12f);

    glBegin(GL_QUADS);

        glVertex2f(435, 325);
        glVertex2f(600, 325);
        glVertex2f(600, 350);
        glVertex2f(435, 350);

    glEnd();



    // DARK LOWER ROOF STRIP

    glColor3f(0.12f, 0.18f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(440, 315);
        glVertex2f(595, 315);
        glVertex2f(595, 325);
        glVertex2f(440, 325);

    glEnd();



    // LARGE FRONT GLASS WINDOW

    glColor3f(0.42f, 0.70f, 0.82f);

    glBegin(GL_QUADS);

        glVertex2f(465, 235);
        glVertex2f(555, 235);
        glVertex2f(555, 300);
        glVertex2f(465, 300);

    glEnd();



    // GLASS WINDOW DIVIDERS

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



    // MAIN DOOR

    glColor3f(0.33f, 0.18f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(560, 205);
        glVertex2f(585, 205);
        glVertex2f(585, 270);
        glVertex2f(560, 270);

    glEnd();



    // DOOR GLASS

    glColor3f(0.35f, 0.62f, 0.72f);

    glBegin(GL_QUADS);

        glVertex2f(564, 230);
        glVertex2f(581, 230);
        glVertex2f(581, 263);
        glVertex2f(564, 263);

    glEnd();



    // LEFT DECORATIVE PANEL

    glColor3f(0.68f, 0.38f, 0.16f);

    glBegin(GL_QUADS);

        glVertex2f(445, 205);
        glVertex2f(458, 205);
        glVertex2f(458, 315);
        glVertex2f(445, 315);

    glEnd();



    // BOTTOM BASE

    glColor3f(0.16f, 0.18f, 0.20f);

    glBegin(GL_QUADS);

        glVertex2f(440, 200);
        glVertex2f(595, 200);
        glVertex2f(595, 207);
        glVertex2f(440, 207);

    glEnd();
}


// OBJECT ID: OBJ_CITY_10
// Object: City Hospital
// Created by: Mostafiz

void drawHospital()
{

    // MAIN BODY
    // Soft off-white

    glColor3f(0.88f, 0.90f, 0.88f);

    glBegin(GL_QUADS);

        glVertex2f(600, 205);
        glVertex2f(720, 205);
        glVertex2f(720, 345);
        glVertex2f(600, 345);

    glEnd();



    // LEFT ACCENT PANEL
    // Muted blue

    glColor3f(0.22f, 0.42f, 0.58f);

    glBegin(GL_QUADS);

        glVertex2f(600, 205);
        glVertex2f(615, 205);
        glVertex2f(615, 345);
        glVertex2f(600, 345);

    glEnd();



    // TOP ROOF
    // Dark slate

    glColor3f(0.14f, 0.20f, 0.26f);

    glBegin(GL_QUADS);

        glVertex2f(595, 345);
        glVertex2f(725, 345);
        glVertex2f(725, 357);
        glVertex2f(595, 357);

    glEnd();



    // WINDOWS
    // Soft hospital blue

    glColor3f(0.35f, 0.65f, 0.78f);

    for (int y = 250; y <= 310; y += 40)
    {
        for (int x = 625; x <= 690; x += 32)
        {
            glBegin(GL_QUADS);

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 22);
                glVertex2f(x, y + 22);

            glEnd();
        }
    }



    // MAIN ENTRANCE

    glColor3f(0.12f, 0.35f, 0.48f);

    glBegin(GL_QUADS);

        glVertex2f(650, 205);
        glVertex2f(680, 205);
        glVertex2f(680, 245);
        glVertex2f(650, 245);

    glEnd();


    // Door divider
    glColor3f(0.85f, 0.90f, 0.90f);

    glBegin(GL_QUADS);

        glVertex2f(664, 205);
        glVertex2f(667, 205);
        glVertex2f(667, 245);
        glVertex2f(664, 245);

    glEnd();



    // HOSPITAL SIGN PANEL

    glColor3f(0.92f, 0.92f, 0.88f);

    glBegin(GL_QUADS);

        glVertex2f(635, 315);
        glVertex2f(685, 315);
        glVertex2f(685, 340);
        glVertex2f(635, 340);

    glEnd();



    // RED MEDICAL CROSS

    glColor3f(0.82f, 0.12f, 0.12f);

    // Vertical part
    glBegin(GL_QUADS);

        glVertex2f(657, 318);
        glVertex2f(663, 318);
        glVertex2f(663, 337);
        glVertex2f(657, 337);

    glEnd();

    // Horizontal part
    glBegin(GL_QUADS);

        glVertex2f(650, 324);
        glVertex2f(670, 324);
        glVertex2f(670, 331);
        glVertex2f(650, 331);

    glEnd();



    // BOTTOM BASE

    glColor3f(0.16f, 0.20f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(595, 200);
        glVertex2f(725, 200);
        glVertex2f(725, 207);
        glVertex2f(595, 207);

    glEnd();
}



// OBJECT ID: OBJ_CITY_08
// Object: Riverfront City Park
// Created by: Apon

void drawCityPark()
{

    // MAIN PARK GROUND
    // Full city-side riverfront area

    glColor3f(0.34f, 0.62f, 0.22f);

    glBegin(GL_QUADS);

        glVertex2f(0, -50);
        glVertex2f(700, -50);
        glVertex2f(700, 35);
        glVertex2f(0, 35);

    glEnd();



    // WALKING PATH

    glColor3f(0.78f, 0.70f, 0.53f);

    glBegin(GL_QUADS);

        glVertex2f(0, -32);
        glVertex2f(700, -32);
        glVertex2f(700, -20);
        glVertex2f(0, -20);

    glEnd();



    // TREE 1

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



    // TREE 2

    glColor3f(0.40f, 0.23f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(275, -10);
        glVertex2f(282, -10);
        glVertex2f(282, 18);
        glVertex2f(275, 18);

    glEnd();

    glColor3f(0.18f, 0.52f, 0.18f);

    drawCircle(278, 28, 18);
    drawCircle(266, 24, 12);
    drawCircle(290, 24, 12);



    // TREE 3

    glColor3f(0.40f, 0.23f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(500, -10);
        glVertex2f(507, -10);
        glVertex2f(507, 18);
        glVertex2f(500, 18);

    glEnd();

    glColor3f(0.16f, 0.48f, 0.17f);

    drawCircle(503, 28, 18);
    drawCircle(491, 24, 12);
    drawCircle(515, 24, 12);



    // TREE 4
    // Extra tree for new width

    glColor3f(0.40f, 0.23f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(640, -10);
        glVertex2f(647, -10);
        glVertex2f(647, 18);
        glVertex2f(640, 18);

    glEnd();

    glColor3f(0.20f, 0.52f, 0.20f);

    drawCircle(643, 27, 17);
    drawCircle(631, 23, 12);
    drawCircle(655, 23, 12);



    // BENCH 1

    glColor3f(0.55f, 0.31f, 0.13f);

    glBegin(GL_QUADS);

        // Seat
        glVertex2f(130, -5);
        glVertex2f(190, -5);
        glVertex2f(190, 2);
        glVertex2f(130, 2);

        // Back
        glVertex2f(133, 6);
        glVertex2f(187, 6);
        glVertex2f(187, 13);
        glVertex2f(133, 13);

    glEnd();


    // Bench 1 legs
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);

        glVertex2f(138, -12);
        glVertex2f(143, -12);
        glVertex2f(143, -5);
        glVertex2f(138, -5);

        glVertex2f(178, -12);
        glVertex2f(183, -12);
        glVertex2f(183, -5);
        glVertex2f(178, -5);

    glEnd();



    // BENCH 2

    glColor3f(0.55f, 0.31f, 0.13f);

    glBegin(GL_QUADS);

        glVertex2f(355, -5);
        glVertex2f(415, -5);
        glVertex2f(415, 2);
        glVertex2f(355, 2);

        glVertex2f(358, 6);
        glVertex2f(412, 6);
        glVertex2f(412, 13);
        glVertex2f(358, 13);

    glEnd();


    // Bench 2 legs
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);

        glVertex2f(363, -12);
        glVertex2f(368, -12);
        glVertex2f(368, -5);
        glVertex2f(363, -5);

        glVertex2f(403, -12);
        glVertex2f(408, -12);
        glVertex2f(408, -5);
        glVertex2f(403, -5);

    glEnd();



    // BENCH 3
    // Extra bench for wider park

    glColor3f(0.55f, 0.31f, 0.13f);

    glBegin(GL_QUADS);

        glVertex2f(545, -5);
        glVertex2f(600, -5);
        glVertex2f(600, 2);
        glVertex2f(545, 2);

        glVertex2f(548, 6);
        glVertex2f(597, 6);
        glVertex2f(597, 13);
        glVertex2f(548, 13);

    glEnd();


    // Bench 3 legs
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);

        glVertex2f(552, -12);
        glVertex2f(557, -12);
        glVertex2f(557, -5);
        glVertex2f(552, -5);

        glVertex2f(588, -12);
        glVertex2f(593, -12);
        glVertex2f(593, -5);
        glVertex2f(588, -5);

    glEnd();



    // FLOWERS - LEFT AREA

    glColor3f(0.95f, 0.30f, 0.35f);
    drawCircle(100, -8, 3);

    glColor3f(1.0f, 0.75f, 0.12f);
    drawCircle(110, -5, 3);

    glColor3f(0.95f, 0.42f, 0.15f);
    drawCircle(120, -8, 3);



    // FLOWERS - CENTER AREA

    glColor3f(0.90f, 0.30f, 0.55f);
    drawCircle(320, -7, 3);

    glColor3f(1.0f, 0.75f, 0.10f);
    drawCircle(330, -4, 3);

    glColor3f(0.95f, 0.32f, 0.20f);
    drawCircle(340, -7, 3);



    // FLOWERS - RIGHT AREA

    glColor3f(0.95f, 0.30f, 0.35f);
    drawCircle(465, -8, 3);

    glColor3f(1.0f, 0.72f, 0.12f);
    drawCircle(475, -5, 3);

    glColor3f(0.90f, 0.35f, 0.55f);
    drawCircle(485, -8, 3);


    // Extra right-side flowers
    glColor3f(1.0f, 0.70f, 0.10f);
    drawCircle(615, -7, 3);

    glColor3f(0.95f, 0.35f, 0.45f);
    drawCircle(625, -4, 3);
}

// OBJECT ID: OBJ_CITY_09
// Object: Bus Stop
// Created by: Apon

void drawBusStop()
{

    // MAIN ROOF

    glColor3f(0.10f, 0.18f, 0.28f);

    glBegin(GL_QUADS);

        glVertex2f(295, 105);
        glVertex2f(350, 105);
        glVertex2f(350, 115);
        glVertex2f(295, 115);

    glEnd();



    // LEFT SUPPORT

    glColor3f(0.18f, 0.22f, 0.28f);

    glBegin(GL_QUADS);

        glVertex2f(300, 60);
        glVertex2f(305, 60);
        glVertex2f(305, 105);
        glVertex2f(300, 105);

    glEnd();



    // RIGHT SUPPORT

    glBegin(GL_QUADS);

        glVertex2f(340, 60);
        glVertex2f(345, 60);
        glVertex2f(345, 105);
        glVertex2f(340, 105);

    glEnd();



    // BACK GLASS

    glColor3f(0.40f, 0.70f, 0.82f);

    glBegin(GL_QUADS);

        glVertex2f(305, 68);
        glVertex2f(340, 68);
        glVertex2f(340, 102);
        glVertex2f(305, 102);

    glEnd();



    // GLASS DIVIDER

    glColor3f(0.85f, 0.90f, 0.92f);

    glBegin(GL_QUADS);

        glVertex2f(321, 68);
        glVertex2f(324, 68);
        glVertex2f(324, 102);
        glVertex2f(321, 102);

    glEnd();



    // BENCH

    glColor3f(0.52f, 0.30f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(310, 70);
        glVertex2f(335, 70);
        glVertex2f(335, 76);
        glVertex2f(310, 76);

    glEnd();



    // BENCH LEGS

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



    // BUS STOP SIGN POLE

    glColor3f(0.15f, 0.18f, 0.20f);

    glBegin(GL_QUADS);

        glVertex2f(286, 60);
        glVertex2f(290, 60);
        glVertex2f(290, 105);
        glVertex2f(286, 105);

    glEnd();



    // BUS STOP SIGN BOARD

    glColor3f(0.10f, 0.35f, 0.60f);

    glBegin(GL_QUADS);

        glVertex2f(278, 92);
        glVertex2f(298, 92);
        glVertex2f(298, 108);
        glVertex2f(278, 108);

    glEnd();
}

// OBJECT ID: OBJ_ENV_05
// Object: River Bank
// Created by: Ashik

void drawRiverBank()
{
    glColor3f(0.18f, 0.50f, 0.15f);

    // Bottom left river edge
    glBegin(GL_QUADS);

        glVertex2f(0, -70);
        glVertex2f(730, -70);
        glVertex2f(730, -55);
        glVertex2f(0, -55);

    glEnd();


    // Bottom right river edge
    glBegin(GL_QUADS);

        glVertex2f(910, -70);
        glVertex2f(1200, -70);
        glVertex2f(1200, -55);
        glVertex2f(910, -55);

    glEnd();
}

// OBJECT ID: OBJ_ENV_06
// Object: Connected Curved River
// Created by: Ashik

void drawRiver()
{
    glColor3f(0.10f, 0.55f, 0.85f);



    // MAIN HORIZONTAL RIVER

    glBegin(GL_QUADS);

        glVertex2f(0, -200);
        glVertex2f(1600, -200);
        glVertex2f(1600, -70);
        glVertex2f(0, -70);

    glEnd();



    // CURVED RIVER CHANNEL
    // KEEP THESE COORDINATES SAME

    glBegin(GL_POLYGON);

        glVertex2f(715, 230);
        glVertex2f(720, 205);
        glVertex2f(730, 180);
        glVertex2f(745, 145);
        glVertex2f(760, 105);
        glVertex2f(775, 65);
        glVertex2f(790, 20);
        glVertex2f(800, -70);

        glVertex2f(920, -70);
        glVertex2f(905, 10);
        glVertex2f(890, 55);
        glVertex2f(870, 95);
        glVertex2f(850, 130);
        glVertex2f(825, 165);
        glVertex2f(795, 195);
        glVertex2f(760, 220);

    glEnd();
}


// Supporting Function
// River Side Bushes

void drawRiverSideBushes()
{
    // LEFT SIDE
    glColor3f(0.12f, 0.42f, 0.15f);

    drawCircle(700, 215, 10);
    drawCircle(715, 185, 11);
    drawCircle(730, 150, 10);
    drawCircle(750, 110, 11);
    drawCircle(770, 65, 10);


    // RIGHT SIDE
    glColor3f(0.17f, 0.48f, 0.18f);

    drawCircle(785, 215, 10);
    drawCircle(820, 185, 11);
    drawCircle(850, 150, 10);
    drawCircle(875, 110, 11);
    drawCircle(900, 65, 10);
}


// Supporting Function
// River Water Details

void drawRiverDetails()
{
    glColor3f(0.72f, 0.88f, 1.0f);

    glBegin(GL_LINES);

        // Curved channel
        glVertex2f(745, 195);
        glVertex2f(775, 195);

        glVertex2f(760, 160);
        glVertex2f(800, 160);

        glVertex2f(780, 120);
        glVertex2f(825, 120);

        glVertex2f(795, 75);
        glVertex2f(845, 75);

        glVertex2f(815, 25);
        glVertex2f(870, 25);

        glVertex2f(830, -25);
        glVertex2f(890, -25);


        // Bottom river
        glVertex2f(40, -105);
        glVertex2f(100, -105);

        glVertex2f(160, -155);
        glVertex2f(230, -155);

        glVertex2f(330, -110);
        glVertex2f(400, -110);

        glVertex2f(500, -155);
        glVertex2f(570, -155);

        glVertex2f(960, -110);
        glVertex2f(1020, -110);

        glVertex2f(1090, -155);
        glVertex2f(1160, -155);

    glEnd();
}

// OBJECT ID: OBJ_ENV_07
// Object: City-Village Bridge
// Created by: Mostafiz

void drawBridge()
{

    // MAIN BRIDGE ROAD
    // Exact same level as city road

    glColor3f(0.18f, 0.18f, 0.18f);

    glBegin(GL_QUADS);

        glVertex2f(700, 60);
        glVertex2f(900, 60);
        glVertex2f(900, 180);
        glVertex2f(700, 180);

    glEnd();



    // ROAD LANE MARKINGS

    glColor3f(1.0f, 1.0f, 1.0f);

    for (int x = 715; x < 890; x += 60)
    {
        glBegin(GL_QUADS);

            glVertex2f(x, 117);
            glVertex2f(x + 35, 117);
            glVertex2f(x + 35, 123);
            glVertex2f(x, 123);

        glEnd();
    }

    // UPPER CONCRETE EDGE
    glColor3f(0.65f, 0.65f, 0.63f);

    glBegin(GL_QUADS);

        glVertex2f(700, 175);
        glVertex2f(900, 175);
        glVertex2f(900, 183);
        glVertex2f(700, 183);

    glEnd();

    // LOWER CONCRETE EDGE

    glBegin(GL_QUADS);

        glVertex2f(700, 57);
        glVertex2f(900, 57);
        glVertex2f(900, 65);
        glVertex2f(700, 65);

    glEnd();

    // UPPER RAILING POSTS
    glColor3f(0.88f, 0.88f, 0.85f);

    for (int x = 710; x <= 890; x += 30)
    {
        glBegin(GL_QUADS);

            glVertex2f(x, 183);
            glVertex2f(x + 4, 183);
            glVertex2f(x + 4, 197);
            glVertex2f(x, 197);

        glEnd();
    }

    // Upper horizontal railing
    glBegin(GL_QUADS);

        glVertex2f(705, 193);
        glVertex2f(895, 193);
        glVertex2f(895, 198);
        glVertex2f(705, 198);

    glEnd();

    // LOWER RAILING POSTS
    for (int x = 710; x <= 890; x += 30)
    {
        glBegin(GL_QUADS);

            glVertex2f(x, 43);
            glVertex2f(x + 4, 43);
            glVertex2f(x + 4, 57);
            glVertex2f(x, 57);

        glEnd();
    }


    // Lower horizontal railing
    glBegin(GL_QUADS);

        glVertex2f(705, 40);
        glVertex2f(895, 40);
        glVertex2f(895, 45);
        glVertex2f(705, 45);

    glEnd();

    // BRIDGE SUPPORT LEFT
    glColor3f(0.45f, 0.45f, 0.45f);

    glBegin(GL_QUADS);

        glVertex2f(750, 57);
        glVertex2f(765, 57);
        glVertex2f(765, -30);
        glVertex2f(750, -30);

    glEnd();

    // BRIDGE SUPPORT RIGHT

    glBegin(GL_QUADS);

        glVertex2f(835, 57);
        glVertex2f(850, 57);
        glVertex2f(850, -30);
        glVertex2f(835, -30);

    glEnd();
}


// Supporting Function
// Village Dirt Road

void drawVillageEntryRoad()
{

    // MAIN VILLAGE DIRT ROAD
    glColor3f(0.58f, 0.40f, 0.22f);

    glBegin(GL_QUADS);

        glVertex2f(900, 70);
        glVertex2f(1600, 70);
        glVertex2f(1600, 170);
        glVertex2f(900, 170);

    glEnd();

    // SMALL DIRT DETAILS
    glColor3f(0.40f, 0.27f, 0.15f);

    glBegin(GL_LINES);

        glVertex2f(940, 100);
        glVertex2f(985, 100);

        glVertex2f(1030, 140);
        glVertex2f(1075, 140);

        glVertex2f(1130, 100);
        glVertex2f(1180, 100);

        glVertex2f(1240, 140);
        glVertex2f(1290, 140);

        glVertex2f(1360, 100);
        glVertex2f(1410, 100);

        glVertex2f(1480, 140);
        glVertex2f(1530, 140);

    glEnd();
}

// OBJECT ID: OBJ_CITY_11
// Object: Traffic Signal
// Created by: Mostafiz

void drawTrafficSignal()
{
    // SIGNAL POLE
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);

        glVertex2f(305, 180);
        glVertex2f(312, 180);
        glVertex2f(312, 255);
        glVertex2f(305, 255);

    glEnd();

    // SIGNAL BOX
    glColor3f(0.10f, 0.10f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(290, 245);
        glVertex2f(327, 245);
        glVertex2f(327, 320);
        glVertex2f(290, 320);

    glEnd();

    // RED LIGHT
    glColor3f(0.90f, 0.10f, 0.10f);

    drawCircle(308, 303, 8);

    // YELLOW LIGHT
    glColor3f(1.0f, 0.75f, 0.10f);

    drawCircle(308, 282, 8);

    // GREEN LIGHT
    glColor3f(0.10f, 0.75f, 0.20f);

    drawCircle(308, 261, 8);

    // POLE BASE
    glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);

        glVertex2f(296, 175);
        glVertex2f(321, 175);
        glVertex2f(321, 183);
        glVertex2f(296, 183);

    glEnd();
}

// OBJECT ID: OBJ_CITY_12
// Object: Zebra Crossing
// Created by: Mostafiz

void drawZebraCrossing()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Horizontal white stripes
    for (int y = 72; y <= 162; y += 18)
    {
        glBegin(GL_QUADS);

            glVertex2f(270, y);
            glVertex2f(340, y);

            glVertex2f(340, y + 9);
            glVertex2f(270, y + 9);

        glEnd();
    }
}

// OBJECT ID: OBJ_CITY_13
// Object: Street Lights
// Created by: Mostafiz

void drawStreetLights()
{
    // UPPER SIDE STREET LIGHTS

    int upperX[] = {90, 435, 590, 690};

    for (int i = 0; i < 4; i++)
    {
        int x = upperX[i];

        // Pole
        glColor3f(0.12f, 0.12f, 0.12f);

        glBegin(GL_QUADS);

            glVertex2f(x, 180);
            glVertex2f(x + 6, 180);
            glVertex2f(x + 6, 245);
            glVertex2f(x, 245);

        glEnd();


        // Lamp head
        glColor3f(0.16f, 0.16f, 0.16f);

        glBegin(GL_QUADS);

            glVertex2f(x - 8, 242);
            glVertex2f(x + 14, 242);
            glVertex2f(x + 10, 253);
            glVertex2f(x - 4, 253);

        glEnd();


        // Yellow light
        glColor3f(1.0f, 0.82f, 0.20f);

        glBegin(GL_QUADS);

            glVertex2f(x - 3, 243);
            glVertex2f(x + 9, 243);
            glVertex2f(x + 7, 249);
            glVertex2f(x - 1, 249);

        glEnd();


        // Base
        glColor3f(0.25f, 0.25f, 0.25f);

        glBegin(GL_QUADS);

            glVertex2f(x - 7, 176);
            glVertex2f(x + 13, 176);
            glVertex2f(x + 13, 182);
            glVertex2f(x - 7, 182);

        glEnd();
    }

    // LOWER SIDE STREET LIGHTS

    int lowerX[] = {170, 390, 520, 635};

    for (int i = 0; i < 4; i++)
    {
        int x = lowerX[i];

        // Pole
        glColor3f(0.12f, 0.12f, 0.12f);

        glBegin(GL_QUADS);

            glVertex2f(x, 35);
            glVertex2f(x + 6, 35);
            glVertex2f(x + 6, 100);
            glVertex2f(x, 100);

        glEnd();


        // Lamp head
        glColor3f(0.16f, 0.16f, 0.16f);

        glBegin(GL_QUADS);

            glVertex2f(x - 8, 97);
            glVertex2f(x + 14, 97);
            glVertex2f(x + 10, 108);
            glVertex2f(x - 4, 108);

        glEnd();


        // Yellow light
        glColor3f(1.0f, 0.82f, 0.20f);

        glBegin(GL_QUADS);

            glVertex2f(x - 3, 98);
            glVertex2f(x + 9, 98);
            glVertex2f(x + 7, 104);
            glVertex2f(x - 1, 104);

        glEnd();


        // Base
        glColor3f(0.25f, 0.25f, 0.25f);

        glBegin(GL_QUADS);

            glVertex2f(x - 7, 32);
            glVertex2f(x + 13, 32);
            glVertex2f(x + 13, 38);
            glVertex2f(x - 7, 38);

        glEnd();
    }
}

// Village Background Hills
// Created by: Ashik

void drawVillageHills()
{
    // Left transition hill
    glColor3f(0.40f, 0.62f, 0.36f);

    glBegin(GL_TRIANGLES);
        glVertex2f(830, 250);
        glVertex2f(940, 365);
        glVertex2f(1050, 250);
    glEnd();


    // Back distant hills
    glColor3f(0.36f, 0.58f, 0.34f);

    glBegin(GL_TRIANGLES);

        glVertex2f(900, 250);
        glVertex2f(1030, 430);
        glVertex2f(1160, 250);

        glVertex2f(1050, 250);
        glVertex2f(1210, 470);
        glVertex2f(1370, 250);

        glVertex2f(1260, 250);
        glVertex2f(1430, 420);
        glVertex2f(1600, 250);

    glEnd();


    // Front hills
    glColor3f(0.26f, 0.52f, 0.25f);

    glBegin(GL_TRIANGLES);

        glVertex2f(900, 250);
        glVertex2f(1110, 380);
        glVertex2f(1300, 250);

        glVertex2f(1170, 250);
        glVertex2f(1390, 390);
        glVertex2f(1600, 250);

    glEnd();


    // Small hill highlights
    glColor3f(0.44f, 0.66f, 0.38f);

    glBegin(GL_TRIANGLES);

        glVertex2f(970, 250);
        glVertex2f(1030, 330);
        glVertex2f(1090, 250);

        glVertex2f(1330, 250);
        glVertex2f(1430, 340);
        glVertex2f(1520, 250);

    glEnd();
}

// Village Background Trees
// Created by: Ashik

void drawVillageBackgroundTrees()
{
    int treeX[]      = {930, 995, 1080, 1160, 1260, 1350, 1450, 1540};
    int treeHeight[] = {32, 42, 35, 46, 38, 44, 34, 40};
    int treeRadius[] = {17, 21, 18, 22, 19, 21, 17, 20};

    for (int i = 0; i < 8; i++)
    {
        int x = treeX[i];
        int h = treeHeight[i];
        int r = treeRadius[i];

        // Trunk
        glColor3f(0.38f, 0.23f, 0.12f);

        glBegin(GL_QUADS);
            glVertex2f(x, 250);
            glVertex2f(x + 7, 250);
            glVertex2f(x + 7, 250 + h);
            glVertex2f(x, 250 + h);
        glEnd();


        // Main foliage
        glColor3f(0.13f, 0.40f, 0.14f);

        drawCircle(x + 3, 250 + h + 12, r);


        // Left foliage
        glColor3f(0.15f, 0.44f, 0.15f);

        drawCircle(
            x - r / 2,
            250 + h + 7,
            r - 5
        );


        // Right foliage
        glColor3f(0.12f, 0.37f, 0.13f);

        drawCircle(
            x + r / 2 + 5,
            250 + h + 7,
            r - 5
        );
    }
}


// Village Background Pine Trees
// Created by: Ashik

void drawVillagePineTrees()
{
    // PINE TREE 1

    // Trunk
    glColor3f(0.35f, 0.20f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(940, 250);
        glVertex2f(948, 250);
        glVertex2f(948, 320);
        glVertex2f(940, 320);
    glEnd();

    // Bottom leaves
    glColor3f(0.10f, 0.35f, 0.13f);

    glBegin(GL_TRIANGLES);
        glVertex2f(905, 300);
        glVertex2f(944, 380);
        glVertex2f(983, 300);
    glEnd();

    // Middle leaves
    glColor3f(0.12f, 0.40f, 0.14f);

    glBegin(GL_TRIANGLES);
        glVertex2f(914, 330);
        glVertex2f(944, 405);
        glVertex2f(974, 330);
    glEnd();

    // Top leaves
    glColor3f(0.14f, 0.44f, 0.16f);

    glBegin(GL_TRIANGLES);
        glVertex2f(924, 360);
        glVertex2f(944, 425);
        glVertex2f(964, 360);
    glEnd();

    // PINE TREE 2
    // Taller


    glColor3f(0.35f, 0.20f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(1120, 250);
        glVertex2f(1128, 250);
        glVertex2f(1128, 330);
        glVertex2f(1120, 330);
    glEnd();

    glColor3f(0.09f, 0.33f, 0.12f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1080, 305);
        glVertex2f(1124, 395);
        glVertex2f(1168, 305);
    glEnd();

    glColor3f(0.11f, 0.38f, 0.14f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1090, 340);
        glVertex2f(1124, 425);
        glVertex2f(1158, 340);
    glEnd();

    glColor3f(0.14f, 0.43f, 0.16f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1102, 375);
        glVertex2f(1124, 450);
        glVertex2f(1146, 375);
    glEnd();

    // PINE TREE 3
    // Medium


    glColor3f(0.35f, 0.20f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(1340, 250);
        glVertex2f(1348, 250);
        glVertex2f(1348, 315);
        glVertex2f(1340, 315);
    glEnd();

    glColor3f(0.10f, 0.35f, 0.13f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1305, 295);
        glVertex2f(1344, 375);
        glVertex2f(1383, 295);
    glEnd();

    glColor3f(0.12f, 0.40f, 0.14f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1315, 325);
        glVertex2f(1344, 400);
        glVertex2f(1373, 325);
    glEnd();

    glColor3f(0.14f, 0.44f, 0.16f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1325, 355);
        glVertex2f(1344, 420);
        glVertex2f(1363, 355);
    glEnd();


    // PINE TREE 4
    // Right side

    glColor3f(0.35f, 0.20f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(1515, 250);
        glVertex2f(1523, 250);
        glVertex2f(1523, 325);
        glVertex2f(1515, 325);
    glEnd();

    glColor3f(0.09f, 0.33f, 0.12f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1477, 300);
        glVertex2f(1519, 388);
        glVertex2f(1561, 300);
    glEnd();

    glColor3f(0.11f, 0.38f, 0.14f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1488, 335);
        glVertex2f(1519, 415);
        glVertex2f(1550, 335);
    glEnd();

    glColor3f(0.14f, 0.43f, 0.16f);

    glBegin(GL_TRIANGLES);
        glVertex2f(1499, 370);
        glVertex2f(1519, 438);
        glVertex2f(1539, 370);
    glEnd();
}


// DISPLAY FUNCTION

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    drawSky();
    drawGround();

    // Background scenery
    drawDistantCity();
    drawVillageHills();
    drawVillageBackgroundTrees();
    drawVillagePineTrees();

    // River
    drawRiver();
    drawRiverDetails();

    // City Foundation
    drawCityBase();
    drawCitySidewalk();
    drawCityHighway();
    drawRoadBorder();
    drawRoadMarkings();

    // City Park
    drawCityPark();

    // City Objects
    drawAIUBBuilding();
    drawHighRiseBuilding();
    drawFoodCourt();
    drawHospital();
    drawBusStop();

    // City Infrastructure
    drawTrafficSignal();
    drawZebraCrossing();
    drawStreetLights();

    // River decoration
    drawRiverSideBushes();

    // Connection
    drawBridge();
    drawVillageEntryRoad();

    // Sky Objects
    drawSun();

    drawCloud(250, 600);
    drawCloud(520, 550);
    drawCloud(1050, 600);
    drawCloud(1400, 550);

    glFlush();
}


// INITIALIZATION

void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1600, -200, 700);
}

// MAIN FUNCTION

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1600, 900);

    glutInitWindowPosition(50, 30);

    glutCreateWindow(
        "Two Worlds - Smart City and Traditional Village"
    );

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

