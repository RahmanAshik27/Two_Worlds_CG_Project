#include <windows.h>
#include <GL/glut.h>
#include <cmath>

float cloudMove = 0.0f;
float windmillAngle = 0.0f;

float backgroundRainMove = 0.0f;
float foregroundRainMove = 0.0f;;

float cowMove = 0.0f;
float carMove = 0.0f;
float busMove = 0.0f;

int sceneMode = 0;

// 0 = Day
// 1 = Evening
// 2 = Night
// 3 = Rain

int trafficState = 0;
float paddySway = 0.0f;
bool paddyDirection = true;

// Boat movement position
float boatMove = 0.0f;

// Bird movement position
float birdMove = 0.0f;
float birdWave = 0.0f;

float airplaneMove = 0.0f;

int ambulanceLight = 0;

float reverseCarMove = 0.0f;

float worldTransitionMove = 0.0f;

float pedestrianMove = 0.0f;
float personMove1 = 0.0f;
float personMove2 = 250.0f;
float personMove3 = 500.0f;
float personMove4 = 850.0f;
float personMove5 = 1100.0f;
float personMove6 = 1350.0f;

float pedestrianMoveLeft = 0.0f;
float cityPersonLeft1 = 700.0f;
float cityPersonLeft2 = 520.0f;

float villagePersonLeft1 = 1600.0f;
float villagePersonLeft2 = 1400.0f;

float rippleMove = 0.0f;




void drawCityCar(float x, float y, float s);
void drawVillageVanDriver(float x, float y, float s);

// FUNCTION ID: FUNC_ANIM_13
// Function: City Car to Village Van Transition
// Created by: Apon

void updateWorldTransition(int value)
{
    worldTransitionMove += 2.0f;

    if (worldTransitionMove > 800.0f)
        worldTransitionMove = 0.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateWorldTransition, 0);
}


// FUNCTION ID: FUNC_ANIM_12
// Function: Ambulance Emergency Light
// Created by: Mostafiz

void updateAmbulanceLight(int value)
{
    ambulanceLight = 1 - ambulanceLight;

    glutPostRedisplay();
    glutTimerFunc(400, updateAmbulanceLight, 0);
}

// FUNCTION ID: FUNC_ANIM_11
// Function: Airplane Movement
// Created by: Rony

void updateAirplane(int value)
{
    airplaneMove += 2.5f;

    // Restart from left after crossing the screen
    if (airplaneMove > 1800.0f)
    {
        airplaneMove = -500.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(30, updateAirplane, 0);
}
// FUNCTION ID: FUNC_ANIM_10
// Function: Flying Birds Movement
// Created by: Apon

void updateBirds(int value)
{
    birdMove += 0.7f;
    birdWave += 0.08f;

    if (birdMove > 1700.0f)
    {
        birdMove = -1700.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(30, updateBirds, 0);
}

// FUNCTION ID: FUNC_ANIM_09
// Function: River Boat Movement
// Created by: Shajia

void updateBoat(int value)
{
    boatMove += 0.5f;

    // Keep the boats inside the visible river area
    if (boatMove > 300.0f)
    {
        boatMove = -300.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(30, updateBoat, 0);
}

// FUNCTION ID: FUNC_ANIM_08
// Function: Paddy Field Sway Animation
// Created by: Shajia
void updatePaddy(int value)
{
    if (paddyDirection)
        paddySway += 0.5f;
    else
        paddySway -= 0.5f;

    if (paddySway >= 4.0f)
        paddyDirection = false;

    if (paddySway <= -4.0f)
        paddyDirection = true;

    glutPostRedisplay();
    glutTimerFunc(40, updatePaddy, 0);
}

// FUNCTION ID: FUNC_ANIM_01
// Function: Cloud Movement Animation

void updateCloud(int value)
{
    cloudMove += 1.0f;

    if (cloudMove > 1600)
        cloudMove = -400;

    glutPostRedisplay();
    glutTimerFunc(30, updateCloud, 0);
}

// FUNCTION ID: FUNC_ANIM_02
// Function: Rain Animation
// Created by: Ashik

void updateRain(int value)
{
    backgroundRainMove += 18.0f;
    foregroundRainMove += 22.0f;

    if (backgroundRainMove > 900)
        backgroundRainMove = 0;

    if (foregroundRainMove > 900)
        foregroundRainMove = 0;

    glutPostRedisplay();
    glutTimerFunc(25, updateRain, 0);
}

// FUNCTION ID: FUNC_ANIM_03
// Function: Windmill Rotation
// Created by: Rony

void updateWindmill(int value)
{
    windmillAngle += 2.0f;

    if (windmillAngle >= 360.0f)
        windmillAngle = 0.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateWindmill, 0);
}

// FUNCTION ID: FUNC_ANIM_04
// Function: Cow Forward Movement
// Created by: Rony
void updateCow(int value)
{
    cowMove += 1.5f;

    if (cowMove > 700.0f)
        cowMove = -650.0f;

    glutPostRedisplay();
    glutTimerFunc(50, updateCow, 0);
}

// FUNCTION ID: FUNC_ANIM_05
// Function: City Car Movement
// Created by: Apon

void updateCar(int value)
{
    carMove += 2.5f;

    // Cars disappear near village entry
    // Then restart from city side
    if (carMove > 720.0f)
        carMove = -700.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateCar, 0);
}

// FUNCTION ID: FUNC_ANIM_06
// Function: City Bus Movement
// Created by: Apon
void updateBus(int value)
{
    busMove += 1.8f;

    if (busMove > 1800.0f)
        busMove = -300.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateBus, 0);
}


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

// FUNCTION ID: FUNC_ANIM_07
// Function: Traffic Signal Animation
// Created by: Mostafiz
void updateTrafficSignal(int value)
{
    trafficState++;

    if (trafficState > 2)
        trafficState = 0;

    glutPostRedisplay();

    if (trafficState == 0)
        glutTimerFunc(3000, updateTrafficSignal, 0);
    else if (trafficState == 1)
        glutTimerFunc(4000, updateTrafficSignal, 0);
    else
        glutTimerFunc(1500, updateTrafficSignal, 0);
}



// OBJECT ID: OBJ_BASE_01
// Object: Sky
// Created by: Ashik

void drawSky()
{
    if (sceneMode == 0)
    {
        glColor3f(0.45f, 0.78f, 0.95f);
    }
    else if (sceneMode == 1)
    {
        glColor3f(0.95f, 0.48f, 0.28f);
    }
    else if (sceneMode == 2)
    {
        glColor3f(0.05f, 0.08f, 0.20f);
    }
    else
    {
        // Rain sky
        glColor3f(0.25f, 0.31f, 0.37f);
    }

    glBegin(GL_QUADS);
        glVertex2f(0, 205);
        glVertex2f(1600, 205);
        glVertex2f(1600, 700);
        glVertex2f(0, 700);
    glEnd();
}

// FUNCTION ID: FUNC_INT_01
// Function: Day Evening Night Control
// Created by: Ashik

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        sceneMode = 0;
    }
    else if (key == 'e' || key == 'E')
    {
        sceneMode = 1;
    }
    else if (key == 'n' || key == 'N')
    {
        sceneMode = 2;
    }
    else if (key == 'r' || key == 'R')
    {
        sceneMode = 3;
    }

    glutPostRedisplay();
}

// FUNCTION ID: FUNC_ANIM_02
// Function: Heavy Rain Animation
// Created by: Ashik

// Heavy rain behind all objects
void drawBackgroundRain()
{
    if (sceneMode != 3)
        return;

    glColor3f(0.72f, 0.80f, 0.88f);
    glLineWidth(1.0f);

    glBegin(GL_LINES);

    // First dense layer
    for (int x = 0; x <= 1600; x += 10)
    {
        float y = 700 - ((x * 7 + (int)backgroundRainMove) % 900);

        glVertex2f(x, y);
        glVertex2f(x - 6, y - 20);
    }

    // Second dense layer
    for (int x = 5; x <= 1600; x += 12)
    {
        float y = 700 - ((x * 11 + 300 + (int)backgroundRainMove) % 900);

        glVertex2f(x, y);
        glVertex2f(x - 5, y - 18);
    }

    // Third layer
    for (int x = 8; x <= 1600; x += 16)
    {
        float y = 700 - ((x * 5 + 550 + (int)backgroundRainMove) % 900);

        glVertex2f(x, y);
        glVertex2f(x - 7, y - 22);
    }

    glEnd();

    glLineWidth(1.0f);
}

// Light rain in front of all objects
void drawForegroundRain()
{
    if (sceneMode != 3)
        return;

    glColor3f(0.88f, 0.93f, 1.0f);
    glLineWidth(1.4f);

    glBegin(GL_LINES);

    for (int x = 20; x <= 1600; x += 60)
    {
        float y = 700 - ((x * 5 + (int)foregroundRainMove) % 900);

        glVertex2f(x, y);
        glVertex2f(x - 10, y - 35);
    }

    glEnd();

    glLineWidth(1.0f);
}

void drawMoon()
{
    glColor3f(0.95f, 0.95f, 0.80f);
    drawCircle(1450, 600, 38);
}

void drawStars()
{
    if (sceneMode != 2)
        return;

    // Small stars
    glColor3f(0.92f, 0.95f, 1.0f);
    glPointSize(2.0f);

    glBegin(GL_POINTS);
        glVertex2f(90, 640);
        glVertex2f(160, 570);
        glVertex2f(245, 620);
        glVertex2f(330, 550);
        glVertex2f(420, 655);
        glVertex2f(510, 585);
        glVertex2f(600, 635);
        glVertex2f(690, 545);
        glVertex2f(790, 610);
        glVertex2f(880, 660);
        glVertex2f(970, 565);
        glVertex2f(1060, 630);
        glVertex2f(1160, 550);
        glVertex2f(1250, 650);
        glVertex2f(1340, 585);
        glVertex2f(1530, 625);
    glEnd();

    // Medium stars
    glColor3f(1.0f, 0.96f, 0.72f);
    glPointSize(4.0f);

    glBegin(GL_POINTS);
        glVertex2f(210, 660);
        glVertex2f(470, 620);
        glVertex2f(740, 655);
        glVertex2f(1010, 600);
        glVertex2f(1210, 670);
        glVertex2f(1490, 560);
    glEnd();

    // Bright cross stars
    glColor3f(1.0f, 1.0f, 0.90f);
    glLineWidth(1.5f);

    glBegin(GL_LINES);

        glVertex2f(365, 610);
        glVertex2f(365, 626);
        glVertex2f(357, 618);
        glVertex2f(373, 618);

        glVertex2f(920, 625);
        glVertex2f(920, 643);
        glVertex2f(911, 634);
        glVertex2f(929, 634);

        glVertex2f(1380, 635);
        glVertex2f(1380, 653);
        glVertex2f(1371, 644);
        glVertex2f(1389, 644);

    glEnd();

    glPointSize(1.0f);
    glLineWidth(1.0f);
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
    if (sceneMode == 3)
    {
        // Rain cloud
        glColor3f(0.50f, 0.54f, 0.58f);
    }
    else if (sceneMode == 2)
    {
        // Night cloud
        glColor3f(0.75f, 0.78f, 0.82f);
    }
    else
    {
        // Day and Evening cloud
        glColor3f(1.0f, 1.0f, 1.0f);
    }


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

        glVertex2f(x, 68);
        glVertex2f(x + 4, 68);
        glVertex2f(x + 4, 92);
        glVertex2f(x, 92);

    glEnd();
}

// Lower horizontal railing
glBegin(GL_QUADS);

    glVertex2f(705, 88);
    glVertex2f(895, 88);
    glVertex2f(895, 94);
    glVertex2f(705, 94);

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
if (trafficState == 0)
    glColor3f(0.90f, 0.10f, 0.10f);
else
    glColor3f(0.25f, 0.03f, 0.03f);

drawCircle(308, 303, 8);

// YELLOW LIGHT
if (trafficState == 2)
    glColor3f(1.0f, 0.75f, 0.10f);
else
    glColor3f(0.25f, 0.18f, 0.02f);

drawCircle(308, 282, 8);

// GREEN LIGHT
if (trafficState == 1)
    glColor3f(0.10f, 0.75f, 0.20f);
else
    glColor3f(0.02f, 0.20f, 0.05f);

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
        if (sceneMode == 0)
    glColor3f(0.30f, 0.30f, 0.25f);
else
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

    glVertex2f(850, 250);
    glVertex2f(1030, 500);
    glVertex2f(1210, 250);

    glVertex2f(1020, 250);
    glVertex2f(1230, 560);
    glVertex2f(1440, 250);

    glVertex2f(1220, 250);
    glVertex2f(1460, 520);
    glVertex2f(1680, 250);

glEnd();


// Front hills
glColor3f(0.26f, 0.52f, 0.25f);

glBegin(GL_TRIANGLES);

    glVertex2f(870, 250);
    glVertex2f(1080, 420);
    glVertex2f(1290, 250);

    glVertex2f(1140, 250);
    glVertex2f(1390, 435);
    glVertex2f(1620, 250);

glEnd();

// Small hill highlights
glColor3f(0.44f, 0.66f, 0.38f);

glBegin(GL_TRIANGLES);

    glVertex2f(900, 250);
    glVertex2f(1030, 360);
    glVertex2f(1160, 250);

    glVertex2f(1250, 250);
    glVertex2f(1430, 375);
    glVertex2f(1600, 250);

glEnd();
}

// Hills between city and village beside the river
// Created by: Ashik

void drawRiverSideHills()
{
    // Back hill
    glColor3f(0.40f, 0.60f, 0.38f);

    glBegin(GL_TRIANGLES);

        glVertex2f(700, 250);
        glVertex2f(800, 390);
        glVertex2f(900, 250);

        glVertex2f(800, 250);
        glVertex2f(930, 430);
        glVertex2f(1060, 250);

    glEnd();


    // Front hills
    glColor3f(0.30f, 0.52f, 0.28f);

    glBegin(GL_TRIANGLES);

        glVertex2f(720, 250);
        glVertex2f(790, 330);
        glVertex2f(860, 250);

        glVertex2f(860, 250);
        glVertex2f(950, 350);
        glVertex2f(1040, 250);

    glEnd();


    // Small light hills
    glColor3f(0.46f, 0.67f, 0.40f);

    glBegin(GL_TRIANGLES);

        glVertex2f(750, 250);
        glVertex2f(800, 300);
        glVertex2f(850, 250);

        glVertex2f(910, 250);
        glVertex2f(950, 310);
        glVertex2f(1000, 250);

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

// OBJECT ID: OBJ_VILLAGE_01
// Object: Traditional Mud House
// Created by: Roni
void drawMudHouse()
{
    // Main mud wall
    glColor3f(0.64f, 0.42f, 0.23f);

    glBegin(GL_QUADS);

        glVertex2f(980, 250);
        glVertex2f(1130, 250);
        glVertex2f(1130, 350);
        glVertex2f(980, 350);

    glEnd();

    // Main roof
    glColor3f(0.40f, 0.22f, 0.10f);

    glBegin(GL_TRIANGLES);

        glVertex2f(960, 350);
        glVertex2f(1055, 425);
        glVertex2f(1150, 350);

    glEnd();

    // Roof lower edge
    glColor3f(0.30f, 0.16f, 0.08f);

    glBegin(GL_QUADS);

        glVertex2f(965, 345);
        glVertex2f(1145, 345);
        glVertex2f(1140, 355);
        glVertex2f(970, 355);

    glEnd();

    // Main door
    glColor3f(0.28f, 0.15f, 0.07f);

    glBegin(GL_QUADS);

        glVertex2f(1035, 250);
        glVertex2f(1075, 250);
        glVertex2f(1075, 320);
        glVertex2f(1035, 320);

    glEnd();

    // Door inner panel
    glColor3f(0.38f, 0.22f, 0.10f);

    glBegin(GL_QUADS);

        glVertex2f(1041, 258);
        glVertex2f(1069, 258);
        glVertex2f(1069, 312);
        glVertex2f(1041, 312);

    glEnd();

    // Door handle
    glColor3f(0.90f, 0.72f, 0.20f);
    drawCircle(1063, 284, 3);


    // Left window
    glColor3f(0.18f, 0.28f, 0.24f);

    glBegin(GL_QUADS);

        glVertex2f(995, 285);
        glVertex2f(1025, 285);
        glVertex2f(1025, 315);
        glVertex2f(995, 315);

    glEnd();


    // Right window
    glBegin(GL_QUADS);

        glVertex2f(1085, 285);
        glVertex2f(1110, 285);
        glVertex2f(1110, 315);
        glVertex2f(1085, 315);

    glEnd();

    // Window frames
    glColor3f(0.72f, 0.52f, 0.27f);

    glBegin(GL_LINES);

        // Left
        glVertex2f(1010, 285);
        glVertex2f(1010, 315);

        glVertex2f(995, 300);
        glVertex2f(1025, 300);

        // Right
        glVertex2f(1097, 285);
        glVertex2f(1097, 315);

        glVertex2f(1085, 300);
        glVertex2f(1110, 300);

    glEnd();
    // Bottom base
    glColor3f(0.42f, 0.28f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(975, 245);
        glVertex2f(1135, 245);
        glVertex2f(1135, 253);
        glVertex2f(975, 253);

    glEnd();
}

// OBJECT ID: OBJ_VILLAGE_02
// Object: Traditional Tin House
// Created by: Roni

void drawTinHouse()
{
    // Main wall
    glColor3f(0.70f, 0.76f, 0.72f);

    glBegin(GL_QUADS);

        glVertex2f(1180, 250);
        glVertex2f(1330, 250);
        glVertex2f(1330, 345);
        glVertex2f(1180, 345);

    glEnd();

    // Tin roof
    glColor3f(0.40f, 0.48f, 0.52f);

    glBegin(GL_QUADS);

        glVertex2f(1160, 345);
        glVertex2f(1350, 345);
        glVertex2f(1320, 390);
        glVertex2f(1190, 390);

    glEnd();

    // Roof light strip
    glColor3f(0.62f, 0.70f, 0.72f);

    glBegin(GL_QUADS);

        glVertex2f(1175, 352);
        glVertex2f(1335, 352);
        glVertex2f(1328, 360);
        glVertex2f(1182, 360);

    glEnd();

    // Main door
    glColor3f(0.32f, 0.22f, 0.14f);

    glBegin(GL_QUADS);

        glVertex2f(1235, 250);
        glVertex2f(1275, 250);
        glVertex2f(1275, 315);
        glVertex2f(1235, 315);

    glEnd();

    // Door inner shade
    glColor3f(0.42f, 0.30f, 0.18f);

    glBegin(GL_QUADS);

        glVertex2f(1241, 258);
        glVertex2f(1269, 258);
        glVertex2f(1269, 307);
        glVertex2f(1241, 307);

    glEnd();

    // Door handle
    glColor3f(0.90f, 0.72f, 0.20f);
    drawCircle(1263, 282, 3);

    // Left window
    glColor3f(0.20f, 0.38f, 0.42f);

    glBegin(GL_QUADS);

        glVertex2f(1195, 285);
        glVertex2f(1222, 285);
        glVertex2f(1222, 315);
        glVertex2f(1195, 315);

    glEnd();


    // Right window
    glBegin(GL_QUADS);

        glVertex2f(1285, 285);
        glVertex2f(1312, 285);
        glVertex2f(1312, 315);
        glVertex2f(1285, 315);

    glEnd();


    // Window frames
    glColor3f(0.80f, 0.86f, 0.84f);

    glBegin(GL_LINES);

        // Left
        glVertex2f(1208, 285);
        glVertex2f(1208, 315);

        glVertex2f(1195, 300);
        glVertex2f(1222, 300);


        // Right
        glVertex2f(1298, 285);
        glVertex2f(1298, 315);

        glVertex2f(1285, 300);
        glVertex2f(1312, 300);

    glEnd();


    // Bottom base
    glColor3f(0.45f, 0.46f, 0.42f);

    glBegin(GL_QUADS);

        glVertex2f(1175, 245);
        glVertex2f(1335, 245);
        glVertex2f(1335, 253);
        glVertex2f(1175, 253);

    glEnd();
}
// OBJECT ID: OBJ_VILLAGE_03
// Object: Traditional Windmill
// Created by: Roni
void drawWindmill()
{
    // Tower
    glColor3f(0.58f, 0.42f, 0.25f);

    glBegin(GL_QUADS);

        glVertex2f(1130, 250);
        glVertex2f(1170, 250);
        glVertex2f(1160, 400);
        glVertex2f(1140, 400);

    glEnd();

    // Top cap
    glColor3f(0.35f, 0.20f, 0.10f);

    glBegin(GL_TRIANGLES);

        glVertex2f(1125, 400);
        glVertex2f(1150, 435);
        glVertex2f(1175, 400);

    glEnd();

    // Center hub
    glColor3f(0.25f, 0.25f, 0.25f);
    drawCircle(1150, 400, 10);

    glPushMatrix();

    glTranslatef(1150, 400, 0);
    glRotatef(windmillAngle, 0, 0, 1);
    glTranslatef(-1150, -400, 0);


    // Blade 1 (Vertical)
    glLineWidth(4);

    glBegin(GL_LINES);

        glVertex2f(1150, 400);
        glVertex2f(1150, 480);

        glVertex2f(1150, 400);
        glVertex2f(1150, 320);

    glEnd();

    // Blade 2 (Horizontal)
    glBegin(GL_LINES);

        glVertex2f(1070, 400);
        glVertex2f(1150, 400);

        glVertex2f(1150, 400);
        glVertex2f(1230, 400);

    glEnd();


    // Blade decorations
    glColor3f(0.88f, 0.88f, 0.82f);

    glBegin(GL_TRIANGLES);

        glVertex2f(1150, 480);
        glVertex2f(1138, 450);
        glVertex2f(1162, 450);

        glVertex2f(1150, 320);
        glVertex2f(1138, 350);
        glVertex2f(1162, 350);

        glVertex2f(1070, 400);
        glVertex2f(1100, 388);
        glVertex2f(1100, 412);

        glVertex2f(1230, 400);
        glVertex2f(1200, 388);
        glVertex2f(1200, 412);

    glEnd();

    glPopMatrix();
}

// Draw one large village tree
// Created by: Roni
void drawVillageTree(float x, float y, float s)
{
    // Main trunk
    glColor3f(0.38f, 0.22f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(x - 10 * s, y);
        glVertex2f(x + 10 * s, y);
        glVertex2f(x + 7 * s, y + 95 * s);
        glVertex2f(x - 7 * s, y + 95 * s);
    glEnd();

    // Left branch
    glBegin(GL_QUADS);
        glVertex2f(x - 5 * s, y + 65 * s);
        glVertex2f(x + 2 * s, y + 70 * s);
        glVertex2f(x - 30 * s, y + 115 * s);
        glVertex2f(x - 37 * s, y + 110 * s);
    glEnd();

    // Right branch
    glBegin(GL_QUADS);
        glVertex2f(x - 2 * s, y + 70 * s);
        glVertex2f(x + 6 * s, y + 65 * s);
        glVertex2f(x + 38 * s, y + 108 * s);
        glVertex2f(x + 30 * s, y + 115 * s);
    glEnd();

    // Dark leaves
    glColor3f(0.08f, 0.32f, 0.10f);

    drawCircle(x - 42 * s, y + 125 * s, 35 * s);
    drawCircle(x + 42 * s, y + 125 * s, 35 * s);
    drawCircle(x, y + 150 * s, 42 * s);

    // Main leaves
    glColor3f(0.10f, 0.42f, 0.12f);

    drawCircle(x - 25 * s, y + 150 * s, 42 * s);
    drawCircle(x + 27 * s, y + 150 * s, 42 * s);
    drawCircle(x, y + 175 * s, 38 * s);

    // Light leaves
    glColor3f(0.16f, 0.50f, 0.16f);

    drawCircle(x - 18 * s, y + 180 * s, 27 * s);
    drawCircle(x + 22 * s, y + 178 * s, 28 * s);

    // Roots
    glColor3f(0.32f, 0.18f, 0.08f);

    glBegin(GL_TRIANGLES);

        glVertex2f(x - 5 * s, y + 5 * s);
        glVertex2f(x - 30 * s, y);
        glVertex2f(x, y);

        glVertex2f(x + 5 * s, y + 5 * s);
        glVertex2f(x + 30 * s, y);
        glVertex2f(x, y);

    glEnd();
}


// OBJECT ID: OBJ_VILLAGE_04
// Object: Large Village Trees
// Created by: Roni

void drawLargeVillageTrees()
{
    drawVillageTree(970, 250, 0.72f);

    drawVillageTree(1435, 250, 0.82f);

    drawVillageTree(1570, 250, 0.68f);
}

// OBJECT ID: OBJ_VILLAGE_05
// Object: Village Cows
// Created by: Roni

void drawCow(float x, float y, float s)
{
    // Body
    glColor3f(0.92f, 0.88f, 0.76f);

    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + 95 * s, y);
        glVertex2f(x + 95 * s, y + 50 * s);
        glVertex2f(x, y + 50 * s);
    glEnd();

    drawCircle(x + 5 * s, y + 25 * s, 25 * s);
    drawCircle(x + 90 * s, y + 25 * s, 25 * s);

    // Head
    glColor3f(0.82f, 0.72f, 0.56f);
    drawCircle(x + 115 * s, y + 35 * s, 27 * s);

    // Face
    glColor3f(0.90f, 0.82f, 0.68f);

    glBegin(GL_QUADS);
        glVertex2f(x + 105 * s, y + 15 * s);
        glVertex2f(x + 135 * s, y + 15 * s);
        glVertex2f(x + 135 * s, y + 38 * s);
        glVertex2f(x + 105 * s, y + 38 * s);
    glEnd();

    // Ears
    glColor3f(0.55f, 0.38f, 0.22f);

    glBegin(GL_TRIANGLES);
        glVertex2f(x + 103 * s, y + 48 * s);
        glVertex2f(x + 85 * s, y + 58 * s);
        glVertex2f(x + 106 * s, y + 38 * s);

        glVertex2f(x + 127 * s, y + 48 * s);
        glVertex2f(x + 145 * s, y + 58 * s);
        glVertex2f(x + 124 * s, y + 38 * s);
    glEnd();

    // Horns
    glColor3f(0.88f, 0.78f, 0.52f);

    glBegin(GL_TRIANGLES);
        glVertex2f(x + 105 * s, y + 52 * s);
        glVertex2f(x + 100 * s, y + 70 * s);
        glVertex2f(x + 112 * s, y + 52 * s);

        glVertex2f(x + 120 * s, y + 52 * s);
        glVertex2f(x + 128 * s, y + 70 * s);
        glVertex2f(x + 128 * s, y + 50 * s);
    glEnd();

    // Body spots
    glColor3f(0.25f, 0.20f, 0.16f);

    drawCircle(x + 25 * s, y + 32 * s, 14 * s);
    drawCircle(x + 65 * s, y + 18 * s, 12 * s);

    // Legs
    glColor3f(0.72f, 0.62f, 0.48f);

    glBegin(GL_QUADS);
        glVertex2f(x + 10 * s, y);
        glVertex2f(x + 22 * s, y);
        glVertex2f(x + 22 * s, y - 40 * s);
        glVertex2f(x + 10 * s, y - 40 * s);

        glVertex2f(x + 32 * s, y);
        glVertex2f(x + 44 * s, y);
        glVertex2f(x + 44 * s, y - 40 * s);
        glVertex2f(x + 32 * s, y - 40 * s);

        glVertex2f(x + 65 * s, y);
        glVertex2f(x + 77 * s, y);
        glVertex2f(x + 77 * s, y - 40 * s);
        glVertex2f(x + 65 * s, y - 40 * s);

        glVertex2f(x + 83 * s, y);
        glVertex2f(x + 95 * s, y);
        glVertex2f(x + 95 * s, y - 40 * s);
        glVertex2f(x + 83 * s, y - 40 * s);
    glEnd();

    // Hooves
    glColor3f(0.20f, 0.16f, 0.12f);

    glBegin(GL_QUADS);
        glVertex2f(x + 8 * s, y - 42 * s);
        glVertex2f(x + 24 * s, y - 42 * s);
        glVertex2f(x + 24 * s, y - 35 * s);
        glVertex2f(x + 8 * s, y - 35 * s);

        glVertex2f(x + 30 * s, y - 42 * s);
        glVertex2f(x + 46 * s, y - 42 * s);
        glVertex2f(x + 46 * s, y - 35 * s);
        glVertex2f(x + 30 * s, y - 35 * s);

        glVertex2f(x + 63 * s, y - 42 * s);
        glVertex2f(x + 79 * s, y - 42 * s);
        glVertex2f(x + 79 * s, y - 35 * s);
        glVertex2f(x + 63 * s, y - 35 * s);

        glVertex2f(x + 81 * s, y - 42 * s);
        glVertex2f(x + 97 * s, y - 42 * s);
        glVertex2f(x + 97 * s, y - 35 * s);
        glVertex2f(x + 81 * s, y - 35 * s);
    glEnd();

    // Eye
    glColor3f(0.05f, 0.05f, 0.05f);
    drawCircle(x + 123 * s, y + 42 * s, 3 * s);

    // Nose
    drawCircle(x + 125 * s, y + 23 * s, 2.5f * s);

    // Tail
    glLineWidth(3);

    glBegin(GL_LINES);
        glVertex2f(x - 5 * s, y + 38 * s);
        glVertex2f(x - 25 * s, y + 8 * s);
    glEnd();

    drawCircle(x - 25 * s, y + 6 * s, 5 * s);

    glLineWidth(1);
}

// OBJECT ID: OBJ_VILLAGE_05
// Object: Village Cows
// Created by: Rony

void drawVillageCows()
{
    drawCow(970 + cowMove, 190, 0.55f);
    drawCow(1360 + cowMove, 190, 0.62f);
    drawCow(1490 + cowMove, 188, 0.52f);
}

// OBJECT ID: OBJ_VILLAGE_06
// Object: Paddy Field
// Created by: Shajia

void drawPaddyField()
{
    // Large paddy field base
    glColor3f(0.55f, 0.67f, 0.18f);

    glBegin(GL_QUADS);
        glVertex2f(940, -55);
        glVertex2f(1585, -55);
        glVertex2f(1585, 45);
        glVertex2f(940, 45);
    glEnd();

    // Field row lines
    glColor3f(0.32f, 0.48f, 0.12f);
    glLineWidth(1.5f);

    for (int y = -42; y <= 32; y += 18)
    {
        glBegin(GL_LINES);
            glVertex2f(950, y);
            glVertex2f(1575, y);
        glEnd();
    }

    // Dense paddy plants
    for (int y = -35; y <= 20; y += 18)
    {
        for (int x = 955; x <= 1570; x += 20)
        {
            // Stem
            glColor3f(0.16f, 0.42f, 0.08f);

            glBegin(GL_LINES);
                glVertex2f(x, y);
                glVertex2f(x + paddySway, y + 20);

                glVertex2f(x, y + 9);
                glVertex2f(x - 5 + paddySway, y + 15);

                glVertex2f(x, y + 11);
                glVertex2f(x + 5 + paddySway, y + 17);
            glEnd();

            // Golden paddy grains
            glColor3f(0.92f, 0.73f, 0.12f);

            drawCircle(x - 3 + paddySway, y + 21, 1.8f);
            drawCircle(x + paddySway, y + 23, 1.8f);
            drawCircle(x + 3 + paddySway, y + 21, 1.8f);
        }
    }

    // Front field border
    glColor3f(0.38f, 0.52f, 0.12f);

    glBegin(GL_QUADS);
        glVertex2f(935, -60);
        glVertex2f(1590, -60);
        glVertex2f(1585, -50);
        glVertex2f(940, -50);
    glEnd();

    glLineWidth(1);
}

// OBJECT ID: OBJ_VILLAGE_07
// Object: Bamboo Fence
// Created by: Shajia

void drawBambooFence()
{
    // Vertical bamboo poles
    for (int x = 950; x <= 1570; x += 45)
    {
        glColor3f(0.55f, 0.38f, 0.14f);

        glBegin(GL_QUADS);
            glVertex2f(x, -58);
            glVertex2f(x + 7, -58);
            glVertex2f(x + 7, -15);
            glVertex2f(x, -15);
        glEnd();

        // Bamboo joint marks
        glColor3f(0.35f, 0.24f, 0.10f);

        glBegin(GL_LINES);
            glVertex2f(x, -45);
            glVertex2f(x + 7, -45);

            glVertex2f(x, -28);
            glVertex2f(x + 7, -28);
        glEnd();
    }

    // Lower horizontal bamboo rail
    glColor3f(0.62f, 0.43f, 0.16f);

    glBegin(GL_QUADS);
        glVertex2f(945, -48);
        glVertex2f(1578, -48);
        glVertex2f(1578, -41);
        glVertex2f(945, -41);
    glEnd();

    // Upper horizontal bamboo rail
    glBegin(GL_QUADS);
        glVertex2f(945, -30);
        glVertex2f(1578, -30);
        glVertex2f(1578, -23);
        glVertex2f(945, -23);
    glEnd();

    // Diagonal supports
    glColor3f(0.50f, 0.34f, 0.13f);
    glLineWidth(4);

    for (int x = 955; x <= 1510; x += 135)
    {
        glBegin(GL_LINES);
            glVertex2f(x, -55);
            glVertex2f(x + 45, -18);
        glEnd();
    }

    glLineWidth(1);
}

// OBJECT ID: OBJ_VILLAGE_08
// Object: Hay Stack
// Created by: Shajia

void drawHayStack(float x)
{
    glPushMatrix();

    // 1375 is the original starting X position
    glTranslatef(x - 1375, 0, 0);

    // Main hay body
    glColor3f(0.82f, 0.60f, 0.16f);

    glBegin(GL_POLYGON);
        glVertex2f(1375, 250);
        glVertex2f(1382, 280);
        glVertex2f(1395, 315);
        glVertex2f(1415, 345);
        glVertex2f(1435, 365);
        glVertex2f(1455, 345);
        glVertex2f(1475, 315);
        glVertex2f(1488, 280);
        glVertex2f(1495, 250);
    glEnd();

    // Lighter middle hay
    glColor3f(0.90f, 0.70f, 0.22f);

    glBegin(GL_POLYGON);
        glVertex2f(1392, 255);
        glVertex2f(1402, 292);
        glVertex2f(1418, 325);
        glVertex2f(1435, 350);
        glVertex2f(1452, 325);
        glVertex2f(1468, 292);
        glVertex2f(1478, 255);
    glEnd();

    // Hay texture lines
    glColor3f(0.58f, 0.39f, 0.10f);
    glLineWidth(1);

    glBegin(GL_LINES);

        glVertex2f(1390, 270);
        glVertex2f(1430, 340);

        glVertex2f(1410, 260);
        glVertex2f(1438, 345);

        glVertex2f(1430, 260);
        glVertex2f(1442, 340);

        glVertex2f(1450, 260);
        glVertex2f(1445, 325);

        glVertex2f(1470, 265);
        glVertex2f(1448, 320);

        glVertex2f(1395, 290);
        glVertex2f(1470, 290);

        glVertex2f(1405, 310);
        glVertex2f(1462, 310);

    glEnd();

    // Top straw
    glLineWidth(2);

    glBegin(GL_LINES);

        glVertex2f(1435, 360);
        glVertex2f(1425, 380);

        glVertex2f(1435, 360);
        glVertex2f(1435, 383);

        glVertex2f(1435, 360);
        glVertex2f(1447, 379);

    glEnd();

    glLineWidth(1);

    glPopMatrix();
}

// OBJECT ID: OBJ_CITY_05
// Object: City Car
// Created by: Apon
void drawCityCar(float x, float y, float s)
{
    // Lower body
    glColor3f(0.85f, 0.16f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + 100 * s, y);
        glVertex2f(x + 100 * s, y + 30 * s);
        glVertex2f(x, y + 30 * s);
    glEnd();

    // Upper body
    glColor3f(0.92f, 0.20f, 0.15f);
    glBegin(GL_POLYGON);
        glVertex2f(x + 20 * s, y + 30 * s);
        glVertex2f(x + 35 * s, y + 52 * s);
        glVertex2f(x + 70 * s, y + 52 * s);
        glVertex2f(x + 85 * s, y + 30 * s);
    glEnd();

    // Windows
    glColor3f(0.55f, 0.78f, 0.88f);

    glBegin(GL_QUADS);
        glVertex2f(x + 37 * s, y + 47 * s);
        glVertex2f(x + 50 * s, y + 47 * s);
        glVertex2f(x + 50 * s, y + 32 * s);
        glVertex2f(x + 27 * s, y + 32 * s);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(x + 54 * s, y + 47 * s);
        glVertex2f(x + 68 * s, y + 47 * s);
        glVertex2f(x + 79 * s, y + 32 * s);
        glVertex2f(x + 54 * s, y + 32 * s);
    glEnd();

    // Bumpers
    glColor3f(0.18f, 0.18f, 0.18f);
    glBegin(GL_QUADS);
        glVertex2f(x - 4 * s, y + 4 * s);
        glVertex2f(x + 5 * s, y + 4 * s);
        glVertex2f(x + 5 * s, y + 12 * s);
        glVertex2f(x - 4 * s, y + 12 * s);

        glVertex2f(x + 95 * s, y + 4 * s);
        glVertex2f(x + 104 * s, y + 4 * s);
        glVertex2f(x + 104 * s, y + 12 * s);
        glVertex2f(x + 95 * s, y + 12 * s);
    glEnd();

    // Wheels
    glColor3f(0.08f, 0.08f, 0.08f);
    drawCircle(x + 22 * s, y, 11 * s);
    drawCircle(x + 78 * s, y, 11 * s);

    // Wheel centers
    glColor3f(0.60f, 0.60f, 0.60f);
    drawCircle(x + 22 * s, y, 5 * s);
    drawCircle(x + 78 * s, y, 5 * s);

    // Headlight
    glColor3f(1.0f, 0.90f, 0.35f);
    drawCircle(x + 97 * s, y + 20 * s, 4 * s);
}

// OBJECT ID: OBJ_CITY_06
// Object: City Bus
// Created by: Apon
void drawCityBus(float x, float y, float s)
{
    // Main body
    glColor3f(0.12f, 0.42f, 0.72f);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + 150 * s, y);
        glVertex2f(x + 150 * s, y + 55 * s);
        glVertex2f(x, y + 55 * s);
    glEnd();

    // Upper body
    glColor3f(0.10f, 0.36f, 0.65f);
    glBegin(GL_QUADS);
        glVertex2f(x + 8 * s, y + 55 * s);
        glVertex2f(x + 142 * s, y + 55 * s);
        glVertex2f(x + 135 * s, y + 78 * s);
        glVertex2f(x + 15 * s, y + 78 * s);
    glEnd();

    // Windows
    glColor3f(0.65f, 0.85f, 0.92f);

    for (int i = 0; i < 5; i++)
    {
        float wx = x + (18 + i * 24) * s;

        glBegin(GL_QUADS);
            glVertex2f(wx, y + 45 * s);
            glVertex2f(wx + 18 * s, y + 45 * s);
            glVertex2f(wx + 18 * s, y + 68 * s);
            glVertex2f(wx, y + 68 * s);
        glEnd();
    }

    // Front window
    glColor3f(0.50f, 0.76f, 0.88f);
    glBegin(GL_QUADS);
        glVertex2f(x + 125 * s, y + 43 * s);
        glVertex2f(x + 143 * s, y + 43 * s);
        glVertex2f(x + 136 * s, y + 68 * s);
        glVertex2f(x + 125 * s, y + 68 * s);
    glEnd();

    // Door
    glColor3f(0.18f, 0.25f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2f(x + 105 * s, y + 8 * s);
        glVertex2f(x + 122 * s, y + 8 * s);
        glVertex2f(x + 122 * s, y + 42 * s);
        glVertex2f(x + 105 * s, y + 42 * s);
    glEnd();

    // Wheels
    glColor3f(0.07f, 0.07f, 0.07f);
    drawCircle(x + 30 * s, y, 13 * s);
    drawCircle(x + 120 * s, y, 13 * s);

    glColor3f(0.55f, 0.55f, 0.55f);
    drawCircle(x + 30 * s, y, 6 * s);
    drawCircle(x + 120 * s, y, 6 * s);

    // Headlight
    glColor3f(1.0f, 0.90f, 0.30f);
    drawCircle(x + 147 * s, y + 18 * s, 4 * s);
}

// Animal Farm Shed
// Created by: Ashik

void drawAnimalFarm()
{
    // Shed back wall
    glColor3f(0.55f, 0.34f, 0.18f);

    glBegin(GL_QUADS);
        glVertex2f(1380, 250);
        glVertex2f(1535, 250);
        glVertex2f(1535, 325);
        glVertex2f(1380, 325);
    glEnd();

    // Open dark area
    glColor3f(0.20f, 0.14f, 0.08f);

    glBegin(GL_QUADS);
        glVertex2f(1400, 250);
        glVertex2f(1515, 250);
        glVertex2f(1515, 305);
        glVertex2f(1400, 305);
    glEnd();

    // Roof
    glColor3f(0.32f, 0.20f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(1365, 325);
        glVertex2f(1550, 325);
        glVertex2f(1530, 355);
        glVertex2f(1385, 355);
    glEnd();

    // Roof top layer
    glColor3f(0.42f, 0.27f, 0.12f);

    glBegin(GL_QUADS);
        glVertex2f(1385, 355);
        glVertex2f(1530, 355);
        glVertex2f(1515, 370);
        glVertex2f(1400, 370);
    glEnd();

    // Left wooden pillar
    glColor3f(0.30f, 0.17f, 0.07f);

    glBegin(GL_QUADS);
        glVertex2f(1390, 245);
        glVertex2f(1400, 245);
        glVertex2f(1400, 330);
        glVertex2f(1390, 330);
    glEnd();

    // Middle pillar
    glBegin(GL_QUADS);
        glVertex2f(1452, 245);
        glVertex2f(1462, 245);
        glVertex2f(1462, 330);
        glVertex2f(1452, 330);
    glEnd();

    // Right pillar
    glBegin(GL_QUADS);
        glVertex2f(1515, 245);
        glVertex2f(1525, 245);
        glVertex2f(1525, 330);
        glVertex2f(1515, 330);
    glEnd();

    // Ground inside farm
    glColor3f(0.56f, 0.42f, 0.24f);

    glBegin(GL_QUADS);
        glVertex2f(1360, 220);
        glVertex2f(1585, 220);
        glVertex2f(1585, 250);
        glVertex2f(1360, 250);
    glEnd();

    // Fence posts
    glColor3f(0.45f, 0.27f, 0.10f);

    for (int x = 1365; x <= 1580; x += 35)
    {
        glBegin(GL_QUADS);
            glVertex2f(x, 205);
            glVertex2f(x + 5, 205);
            glVertex2f(x + 5, 245);
            glVertex2f(x, 245);
        glEnd();
    }

    // Fence horizontal bars
    glBegin(GL_QUADS);
        glVertex2f(1360, 215);
        glVertex2f(1585, 215);
        glVertex2f(1585, 221);
        glVertex2f(1360, 221);

        glVertex2f(1360, 235);
        glVertex2f(1585, 235);
        glVertex2f(1585, 241);
        glVertex2f(1360, 241);
    glEnd();

    // Feeding trough
    glColor3f(0.38f, 0.22f, 0.08f);

    glBegin(GL_QUADS);
        glVertex2f(1430, 225);
        glVertex2f(1490, 225);
        glVertex2f(1482, 238);
        glVertex2f(1438, 238);
    glEnd();
}

// Small Chicken
// Created by: Ashik

void drawChicken(float x, float y, float s)
{
    // Body
    glColor3f(0.95f, 0.85f, 0.55f);
    drawCircle(x, y, 10 * s);

    // Head
    drawCircle(x + 9 * s, y + 8 * s, 6 * s);

    // Wing
    glColor3f(0.80f, 0.60f, 0.30f);
    drawCircle(x - 2 * s, y + 1 * s, 5 * s);

    // Eye
    glColor3f(0.05f, 0.05f, 0.05f);
    drawCircle(x + 11 * s, y + 10 * s, 1.2f * s);

    // Beak
    glColor3f(1.0f, 0.55f, 0.10f);

    glBegin(GL_TRIANGLES);
        glVertex2f(x + 15 * s, y + 8 * s);
        glVertex2f(x + 21 * s, y + 10 * s);
        glVertex2f(x + 15 * s, y + 12 * s);
    glEnd();

    // Comb
    glColor3f(0.90f, 0.10f, 0.10f);
    drawCircle(x + 6 * s, y + 15 * s, 2.5f * s);
    drawCircle(x + 10 * s, y + 16 * s, 2.5f * s);

    // Legs
    glColor3f(0.80f, 0.45f, 0.10f);

    glBegin(GL_LINES);
        glVertex2f(x - 2 * s, y - 9 * s);
        glVertex2f(x - 2 * s, y - 16 * s);

        glVertex2f(x + 4 * s, y - 9 * s);
        glVertex2f(x + 4 * s, y - 16 * s);
    glEnd();
}

void drawSmallHayStack(float x, float y, float s)
{
    // Main hay
    glColor3f(0.82f, 0.60f, 0.16f);

    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 8 * s, y + 25 * s);
        glVertex2f(x + 20 * s, y + 50 * s);
        glVertex2f(x + 35 * s, y + 70 * s);
        glVertex2f(x + 50 * s, y + 50 * s);
        glVertex2f(x + 62 * s, y + 25 * s);
        glVertex2f(x + 70 * s, y);
    glEnd();

    // Light hay layer
    glColor3f(0.92f, 0.70f, 0.22f);

    glBegin(GL_TRIANGLES);
        glVertex2f(x + 10 * s, y);
        glVertex2f(x + 35 * s, y + 60 * s);
        glVertex2f(x + 58 * s, y);
    glEnd();

    // Hay lines
    glColor3f(0.55f, 0.36f, 0.08f);
    glLineWidth(1.5f);

    glBegin(GL_LINES);

        glVertex2f(x + 15 * s, y + 8 * s);
        glVertex2f(x + 35 * s, y + 60 * s);

        glVertex2f(x + 30 * s, y + 5 * s);
        glVertex2f(x + 40 * s, y + 55 * s);

        glVertex2f(x + 48 * s, y + 8 * s);
        glVertex2f(x + 38 * s, y + 58 * s);

    glEnd();

    glLineWidth(1.0f);
}

void drawFarmChickens()
{
    drawChicken(1385, 265, 0.70f);
    drawChicken(1420, 270, 0.60f);
    drawChicken(1460, 260, 0.75f);
    drawChicken(1500, 268, 0.62f);
    drawChicken(1540, 260, 0.68f);
}

// OBJECT ID: OBJ_VILLAGE_09
// Object: Wooden Village House
// Created by: Ashik
void drawWoodenVillageHouse()
{
    // Raised platform
    glColor3f(0.35f, 0.20f, 0.08f);

    glBegin(GL_QUADS);
        glVertex2f(885, 250);
        glVertex2f(975, 250);
        glVertex2f(975, 258);
        glVertex2f(885, 258);
    glEnd();

    // Main wooden wall
    glColor3f(0.66f, 0.43f, 0.22f);

    glBegin(GL_QUADS);
        glVertex2f(892, 258);
        glVertex2f(968, 258);
        glVertex2f(968, 325);
        glVertex2f(892, 325);
    glEnd();

    // Roof
    glColor3f(0.32f, 0.16f, 0.06f);

    glBegin(GL_TRIANGLES);
        glVertex2f(878, 325);
        glVertex2f(930, 372);
        glVertex2f(982, 325);
    glEnd();

    // Door
    glColor3f(0.22f, 0.12f, 0.05f);

    glBegin(GL_QUADS);
        glVertex2f(918, 258);
        glVertex2f(942, 258);
        glVertex2f(942, 305);
        glVertex2f(918, 305);
    glEnd();

    // Windows
    glColor3f(0.45f, 0.70f, 0.72f);

    glBegin(GL_QUADS);

        glVertex2f(900, 282);
        glVertex2f(914, 282);
        glVertex2f(914, 300);
        glVertex2f(900, 300);

        glVertex2f(946, 282);
        glVertex2f(960, 282);
        glVertex2f(960, 300);
        glVertex2f(946, 300);

    glEnd();

    // Wooden support legs
    glColor3f(0.30f, 0.18f, 0.07f);

    glBegin(GL_QUADS);

        glVertex2f(900, 238);
        glVertex2f(907, 238);
        glVertex2f(907, 258);
        glVertex2f(900, 258);

        glVertex2f(952, 238);
        glVertex2f(959, 238);
        glVertex2f(959, 258);
        glVertex2f(952, 258);

    glEnd();

    // Front stairs
    glColor3f(0.48f, 0.30f, 0.12f);

    glBegin(GL_QUADS);

        glVertex2f(912, 245);
        glVertex2f(948, 245);
        glVertex2f(948, 252);
        glVertex2f(912, 252);

        glVertex2f(918, 238);
        glVertex2f(942, 238);
        glVertex2f(942, 245);
        glVertex2f(918, 245);

    glEnd();
}

// OBJECT ID: OBJ_VILLAGE_10
// Object: Additional Village Trees
// Created by: Mostafiz

void drawAdditionalVillageTrees()
{
    drawVillageTree(905, 250, 0.52f);
    drawVillageTree(1150, 250, 0.48f);
    drawVillageTree(1350, 250, 0.55f);
    drawVillageTree(1550, 250, 0.58f);
    drawVillageTree(700, 250, 0.58f);
    drawVillageTree(755, 250, 0.52f);
    drawVillageTree(850, 250, 0.48f);
    drawVillageTree(800, 250, 0.55f);
}

// OBJECT ID: OBJ_VILLAGE_12
// Object: Banana Tree
// Created by: Apon

void drawBananaTree(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Keep normal width but make the tree shorter
    glScalef(s, s * 0.82f, 1);

    // Trunk
    glColor3f(0.55f, 0.42f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(-7, 0);
        glVertex2f(7, 0);
        glVertex2f(5, 90);
        glVertex2f(-5, 90);
    glEnd();

    // Left wide leaf
    glColor3f(0.16f, 0.52f, 0.18f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 88);
        glVertex2f(-18, 105);
        glVertex2f(-55, 118);
        glVertex2f(-88, 112);
        glVertex2f(-55, 100);
        glVertex2f(-15, 92);
    glEnd();

    // Right wide leaf
    glColor3f(0.20f, 0.60f, 0.22f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 90);
        glVertex2f(18, 108);
        glVertex2f(58, 124);
        glVertex2f(92, 118);
        glVertex2f(58, 104);
        glVertex2f(18, 94);
    glEnd();

    // Top leaf
    glColor3f(0.13f, 0.48f, 0.16f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 90);
        glVertex2f(-8, 115);
        glVertex2f(-12, 150);
        glVertex2f(0, 168);
        glVertex2f(10, 145);
        glVertex2f(8, 112);
    glEnd();

    // Upper left leaf
    glColor3f(0.18f, 0.56f, 0.20f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 92);
        glVertex2f(-20, 102);
        glVertex2f(-42, 135);
        glVertex2f(-38, 158);
        glVertex2f(-18, 135);
        glVertex2f(-5, 108);
    glEnd();

    // Upper right leaf
    glColor3f(0.15f, 0.52f, 0.18f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 92);
        glVertex2f(22, 104);
        glVertex2f(45, 135);
        glVertex2f(40, 158);
        glVertex2f(20, 135);
        glVertex2f(5, 108);
    glEnd();

    // Banana bunch
    glColor3f(0.92f, 0.78f, 0.10f);
    drawCircle(-8, 82, 5);
    drawCircle(0, 80, 5);
    drawCircle(8, 82, 5);
    drawCircle(-4, 74, 5);
    drawCircle(5, 73, 5);

    glPopMatrix();
}

// OBJECT ID: OBJ_VILLAGE_13
// Object: Small Vegetable Garden
// Created by: Rony

void drawVegetableGarden(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Garden soil
    glColor3f(0.45f, 0.28f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(150, 0);
        glVertex2f(140, 55);
        glVertex2f(10, 55);
    glEnd();

    // Three crop rows
    glColor3f(0.30f, 0.18f, 0.08f);

    glBegin(GL_QUADS);
        glVertex2f(15, 8);
        glVertex2f(40, 8);
        glVertex2f(45, 48);
        glVertex2f(22, 48);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(62, 8);
        glVertex2f(87, 8);
        glVertex2f(87, 48);
        glVertex2f(64, 48);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(110, 8);
        glVertex2f(135, 8);
        glVertex2f(128, 48);
        glVertex2f(105, 48);
    glEnd();

    // Vegetable plants
    glColor3f(0.10f, 0.55f, 0.12f);

    drawCircle(28, 18, 7);
    drawCircle(32, 34, 7);

    drawCircle(74, 18, 7);
    drawCircle(75, 35, 7);

    drawCircle(122, 18, 7);
    drawCircle(116, 35, 7);

    // Small vegetables / tomatoes
    glColor3f(0.85f, 0.12f, 0.08f);

    drawCircle(28, 20, 3);
    drawCircle(34, 35, 3);

    drawCircle(72, 20, 3);
    drawCircle(78, 36, 3);

    drawCircle(120, 20, 3);
    drawCircle(115, 36, 3);

    // Bamboo fence posts
    glColor3f(0.58f, 0.40f, 0.18f);
    glLineWidth(4.0f);

    glBegin(GL_LINES);

        glVertex2f(0, 0);
        glVertex2f(0, 70);

        glVertex2f(50, 0);
        glVertex2f(50, 70);

        glVertex2f(100, 0);
        glVertex2f(100, 70);

        glVertex2f(150, 0);
        glVertex2f(150, 70);

        // Horizontal bamboo
        glVertex2f(0, 20);
        glVertex2f(150, 20);

        glVertex2f(0, 52);
        glVertex2f(150, 52);

    glEnd();

    glLineWidth(1.0f);

    glPopMatrix();
}

// OBJECT ID: OBJ_RIVER_01
// Object: Wooden River Boat
// Created by: Mostafiz

void drawWoodenBoat(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Main wooden body
    glColor3f(0.48f, 0.25f, 0.08f);
    glBegin(GL_POLYGON);
        glVertex2f(-75, 15);
        glVertex2f(-55, -10);
        glVertex2f(45, -10);
        glVertex2f(75, 15);
        glVertex2f(55, 5);
        glVertex2f(-55, 5);
    glEnd();

    // Upper edge
    glColor3f(0.30f, 0.15f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-58, 5);
        glVertex2f(58, 5);
        glVertex2f(52, 12);
        glVertex2f(-52, 12);
    glEnd();

    // Inside of boat
    glColor3f(0.25f, 0.13f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-42, 12);
        glVertex2f(42, 12);
        glVertex2f(32, 20);
        glVertex2f(-32, 20);
    glEnd();

    // Wooden seats
    glColor3f(0.68f, 0.42f, 0.16f);

    glBegin(GL_QUADS);
        glVertex2f(-30, 10);
        glVertex2f(-20, 10);
        glVertex2f(-16, 20);
        glVertex2f(-27, 20);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(18, 10);
        glVertex2f(28, 10);
        glVertex2f(25, 20);
        glVertex2f(14, 20);
    glEnd();

    // Oar
    glColor3f(0.42f, 0.24f, 0.09f);
    glLineWidth(5.0f);

    glBegin(GL_LINES);
        glVertex2f(5, 18);
        glVertex2f(58, -22);
    glEnd();

    glLineWidth(1.0f);

    // Oar blade
    glColor3f(0.55f, 0.32f, 0.12f);
    glBegin(GL_POLYGON);
        glVertex2f(52, -18);
        glVertex2f(65, -30);
        glVertex2f(72, -25);
        glVertex2f(60, -14);
    glEnd();

    glPopMatrix();
}

// OBJECT ID: OBJ_RIVER_02
// Object: River Bank Decoration
// Created by: Ashik

void drawRiverBankDecoration(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Rocks

    glColor3f(0.42f, 0.43f, 0.40f);
    drawCircle(-35, 3, 12);

    glColor3f(0.50f, 0.50f, 0.46f);
    drawCircle(-18, 2, 9);

    glColor3f(0.36f, 0.38f, 0.35f);
    drawCircle(-48, 1, 7);

    // Left Bush

    glColor3f(0.10f, 0.42f, 0.12f);
    drawCircle(10, 10, 14);
    drawCircle(25, 14, 18);
    drawCircle(42, 10, 14);

    glColor3f(0.16f, 0.52f, 0.16f);
    drawCircle(20, 22, 12);
    drawCircle(35, 22, 11);

    // Tall River Grass / Reeds

    glColor3f(0.16f, 0.40f, 0.10f);
    glLineWidth(3.0f);

    glBegin(GL_LINES);

        glVertex2f(65, 0);
        glVertex2f(60, 42);

        glVertex2f(73, 0);
        glVertex2f(75, 50);

        glVertex2f(82, 0);
        glVertex2f(88, 38);

        glVertex2f(92, 0);
        glVertex2f(95, 47);

        glVertex2f(102, 0);
        glVertex2f(108, 35);

    glEnd();

    glLineWidth(1.0f);

    // Reed Tops

    glColor3f(0.40f, 0.25f, 0.08f);

    drawCircle(60, 43, 4);
    drawCircle(75, 51, 4);
    drawCircle(88, 39, 4);
    drawCircle(95, 48, 4);
    drawCircle(108, 36, 4);

    // Small Grass

    glColor3f(0.12f, 0.48f, 0.10f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);

        glVertex2f(120, 0);
        glVertex2f(115, 20);

        glVertex2f(120, 0);
        glVertex2f(121, 24);

        glVertex2f(120, 0);
        glVertex2f(127, 18);

        glVertex2f(140, 0);
        glVertex2f(135, 18);

        glVertex2f(140, 0);
        glVertex2f(141, 23);

        glVertex2f(140, 0);
        glVertex2f(147, 17);

    glEnd();

    glLineWidth(1.0f);

    glPopMatrix();
}

// OBJECT ID: OBJ_ENV_01
// Object: Flying Birds
// Created by: Shajia

void drawSingleBird(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Body
    glColor3f(0.10f, 0.10f, 0.10f);
    glBegin(GL_POLYGON);
        glVertex2f(-10, 0);
        glVertex2f(-3, 4);
        glVertex2f(8, 4);
        glVertex2f(15, 1);
        glVertex2f(8, -3);
        glVertex2f(-3, -4);
    glEnd();

    // Head
    drawCircle(14, 2, 4);

    // Beak
    glColor3f(0.85f, 0.55f, 0.08f);
    glBegin(GL_TRIANGLES);
        glVertex2f(18, 3);
        glVertex2f(25, 1);
        glVertex2f(18, 0);
    glEnd();

    // Left wing
    glColor3f(0.16f, 0.16f, 0.16f);
    glBegin(GL_TRIANGLES);
        glVertex2f(2, 2);
        glVertex2f(-12, 17);
        glVertex2f(8, 5);
    glEnd();

    // Right wing
    glBegin(GL_TRIANGLES);
        glVertex2f(3, 0);
        glVertex2f(-5, -15);
        glVertex2f(10, -3);
    glEnd();

    // Tail
    glBegin(GL_TRIANGLES);
        glVertex2f(-8, 2);
        glVertex2f(-19, 8);
        glVertex2f(-13, 0);

        glVertex2f(-8, -2);
        glVertex2f(-19, -7);
        glVertex2f(-13, 0);
    glEnd();

    glPopMatrix();
}
// OBJECT ID: OBJ_ENV_01
// Object: Flying Birds
// Created by: Shajia

void drawBirds()
{
    glPushMatrix();

    // Whole bird group movement
    float groupWave = sin(birdWave) * 5.0f;
    glTranslatef(birdMove, groupWave, 0);

    // Single birds
    drawSingleBird(130, 545 + sin(birdWave + 0.2f) * 6.0f, 0.55f);
    drawSingleBird(430, 610 + sin(birdWave + 0.8f) * 5.0f, 0.50f);
    drawSingleBird(820, 560 + sin(birdWave + 1.3f) * 7.0f, 0.62f);
    drawSingleBird(1510, 600 + sin(birdWave + 1.9f) * 5.0f, 0.52f);

    // Flock 1 - City side
    drawSingleBird(250, 520 + sin(birdWave + 0.1f) * 4.0f, 0.60f);
    drawSingleBird(285, 545 + sin(birdWave + 0.5f) * 6.0f, 0.52f);
    drawSingleBird(320, 522 + sin(birdWave + 0.9f) * 5.0f, 0.58f);

    // Flock 2 - Center sky
    drawSingleBird(650, 600 + sin(birdWave + 0.3f) * 5.0f, 0.55f);
    drawSingleBird(690, 625 + sin(birdWave + 0.7f) * 6.0f, 0.48f);
    drawSingleBird(730, 600 + sin(birdWave + 1.1f) * 4.0f, 0.53f);
    drawSingleBird(770, 620 + sin(birdWave + 1.5f) * 5.0f, 0.45f);

    // Flock 3 - Village side
    drawSingleBird(1080, 525 + sin(birdWave + 0.4f) * 6.0f, 0.62f);
    drawSingleBird(1120, 550 + sin(birdWave + 0.8f) * 5.0f, 0.54f);
    drawSingleBird(1160, 525 + sin(birdWave + 1.2f) * 4.0f, 0.60f);

    // Flock 4 - Far village sky
    drawSingleBird(1280, 615 + sin(birdWave + 0.2f) * 5.0f, 0.48f);
    drawSingleBird(1320, 635 + sin(birdWave + 0.6f) * 6.0f, 0.42f);
    drawSingleBird(1360, 612 + sin(birdWave + 1.0f) * 4.0f, 0.46f);

    glPopMatrix();
}
// DISPLAY FUNCTION

// OBJECT ID: OBJ_CITY_12
// Object: City Sky Airplane
// Created by: Mostafiz

void drawAirplane(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Main body
    glColor3f(0.88f, 0.90f, 0.92f);
    glBegin(GL_POLYGON);
        glVertex2f(-75, -8);
        glVertex2f(-55, 8);
        glVertex2f(45, 8);
        glVertex2f(78, 0);
        glVertex2f(45, -8);
        glVertex2f(-55, -8);
    glEnd();

    // Nose
    glColor3f(0.72f, 0.76f, 0.80f);
    glBegin(GL_TRIANGLES);
        glVertex2f(45, 8);
        glVertex2f(85, 0);
        glVertex2f(45, -8);
    glEnd();

    // Upper wing
    glColor3f(0.65f, 0.69f, 0.74f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-5, 7);
        glVertex2f(25, 7);
        glVertex2f(-25, 40);
    glEnd();

    // Lower wing
    glColor3f(0.58f, 0.63f, 0.68f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-5, -7);
        glVertex2f(25, -7);
        glVertex2f(-20, -35);
    glEnd();

    // Tail wing
    glColor3f(0.25f, 0.45f, 0.70f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-58, 7);
        glVertex2f(-42, 7);
        glVertex2f(-67, 30);
    glEnd();

    // Tail side
    glBegin(GL_TRIANGLES);
        glVertex2f(-65, 0);
        glVertex2f(-45, 0);
        glVertex2f(-72, 15);
    glEnd();

    // Cockpit window
    glColor3f(0.12f, 0.30f, 0.42f);
    glBegin(GL_POLYGON);
        glVertex2f(43, 3);
        glVertex2f(57, 2);
        glVertex2f(64, 0);
        glVertex2f(50, -1);
    glEnd();

    // Passenger windows
    glColor3f(0.10f, 0.32f, 0.48f);

    drawCircle(25, 1, 3);
    drawCircle(12, 1, 3);
    drawCircle(-1, 1, 3);
    drawCircle(-14, 1, 3);
    drawCircle(-27, 1, 3);
    drawCircle(-40, 1, 3);

    // Engine
    glColor3f(0.38f, 0.42f, 0.46f);
    glBegin(GL_QUADS);
        glVertex2f(5, -11);
        glVertex2f(25, -11);
        glVertex2f(21, -20);
        glVertex2f(8, -20);
    glEnd();

    glPopMatrix();
}

// OBJECT ID: OBJ_CITY_13
// Object: Hospital Ambulance
// Created by: Apon

void drawAmbulance(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Main ambulance body
    glColor3f(0.94f, 0.94f, 0.92f);
    glBegin(GL_QUADS);
        glVertex2f(0, 15);
        glVertex2f(115, 15);
        glVertex2f(115, 65);
        glVertex2f(0, 65);
    glEnd();

    // Front cabin
    glColor3f(0.90f, 0.90f, 0.88f);
    glBegin(GL_POLYGON);
        glVertex2f(115, 15);
        glVertex2f(145, 15);
        glVertex2f(145, 50);
        glVertex2f(132, 65);
        glVertex2f(115, 65);
    glEnd();

    // Front window
    glColor3f(0.20f, 0.42f, 0.55f);
    glBegin(GL_QUADS);
        glVertex2f(120, 48);
        glVertex2f(132, 48);
        glVertex2f(139, 38);
        glVertex2f(120, 38);
    glEnd();

    // Side window
    glBegin(GL_QUADS);
        glVertex2f(98, 40);
        glVertex2f(112, 40);
        glVertex2f(112, 58);
        glVertex2f(98, 58);
    glEnd();

    // Red side stripe
    glColor3f(0.82f, 0.08f, 0.08f);
    glBegin(GL_QUADS);
        glVertex2f(0, 27);
        glVertex2f(143, 27);
        glVertex2f(143, 34);
        glVertex2f(0, 34);
    glEnd();

    // Medical cross
    glColor3f(0.85f, 0.05f, 0.05f);

    glBegin(GL_QUADS);
        glVertex2f(43, 38);
        glVertex2f(53, 38);
        glVertex2f(53, 60);
        glVertex2f(43, 60);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(36, 44);
        glVertex2f(60, 44);
        glVertex2f(60, 54);
        glVertex2f(36, 54);
    glEnd();

    // Emergency light base
    glColor3f(0.20f, 0.20f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(65, 65);
        glVertex2f(90, 65);
        glVertex2f(90, 69);
        glVertex2f(65, 69);
    glEnd();

    // Blinking emergency lights
    if (ambulanceLight == 0)
    {
        // Red ON
        glColor3f(1.0f, 0.05f, 0.05f);
        glBegin(GL_QUADS);
            glVertex2f(68, 69);
            glVertex2f(76, 69);
            glVertex2f(76, 76);
            glVertex2f(68, 76);
        glEnd();

        // Blue DIM
        glColor3f(0.05f, 0.10f, 0.30f);
        glBegin(GL_QUADS);
            glVertex2f(79, 69);
            glVertex2f(87, 69);
            glVertex2f(87, 76);
            glVertex2f(79, 76);
        glEnd();
    }
    else
    {
        // Red DIM
        glColor3f(0.30f, 0.05f, 0.05f);
        glBegin(GL_QUADS);
            glVertex2f(68, 69);
            glVertex2f(76, 69);
            glVertex2f(76, 76);
            glVertex2f(68, 76);
        glEnd();

        // Blue ON
        glColor3f(0.05f, 0.30f, 1.0f);
        glBegin(GL_QUADS);
            glVertex2f(79, 69);
            glVertex2f(87, 69);
            glVertex2f(87, 76);
            glVertex2f(79, 76);
        glEnd();
    }

    // Wheels
    glColor3f(0.08f, 0.08f, 0.08f);
    drawCircle(30, 15, 14);
    drawCircle(118, 15, 14);

    // Wheel centers
    glColor3f(0.55f, 0.55f, 0.55f);
    drawCircle(30, 15, 6);
    drawCircle(118, 15, 6);

    // Front light
    glColor3f(1.0f, 0.85f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(140, 28);
        glVertex2f(146, 28);
        glVertex2f(146, 38);
        glVertex2f(140, 38);
    glEnd();

    glPopMatrix();
}

// OBJECT ID: OBJ_ENV_08
// Object: Village Welcome Billboard
// Created by: Ashik

void drawVillageWelcomeBoard(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Two support poles
    glColor3f(0.25f, 0.18f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(-65, 0);
        glVertex2f(-57, 0);
        glVertex2f(-57, 100);
        glVertex2f(-65, 100);

        glVertex2f(67, 0);
        glVertex2f(75, 0);
        glVertex2f(75, 100);
        glVertex2f(67, 100);
    glEnd();

    // Main wooden board
    glColor3f(0.45f, 0.25f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(-85, 70);
        glVertex2f(95, 70);
        glVertex2f(95, 150);
        glVertex2f(-85, 150);
    glEnd();

    // Inner board
    glColor3f(0.72f, 0.50f, 0.20f);

    glBegin(GL_QUADS);
        glVertex2f(-78, 77);
        glVertex2f(88, 77);
        glVertex2f(88, 143);
        glVertex2f(-78, 143);
    glEnd();

    // Welcome text
    glColor3f(1.0f, 1.0f, 0.85f);
    glRasterPos2f(-60, 118);

    const char *text1 = "WELCOME TO";

    for (int i = 0; text1[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);

    // Village text
    glRasterPos2f(-52, 92);

    const char *text2 = "VILLAGE";

    for (int i = 0; text2[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);

    glPopMatrix();
}

// OBJECT ID: OBJ_VILLAGE_14
// Object: Traditional Bullock Cart
// Created by: Shajia

void drawBullockCart(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Cart body
    glColor3f(0.48f, 0.27f, 0.10f);
    glBegin(GL_QUADS);
        glVertex2f(0, 30);
        glVertex2f(115, 30);
        glVertex2f(105, 68);
        glVertex2f(10, 68);
    glEnd();

    // Wooden upper rails
    glColor3f(0.62f, 0.38f, 0.16f);

    glBegin(GL_LINES);
        glVertex2f(10, 68);
        glVertex2f(10, 92);

        glVertex2f(35, 68);
        glVertex2f(35, 92);

        glVertex2f(60, 68);
        glVertex2f(60, 92);

        glVertex2f(85, 68);
        glVertex2f(85, 92);

        glVertex2f(105, 68);
        glVertex2f(105, 92);

        glVertex2f(8, 88);
        glVertex2f(108, 88);
    glEnd();

    // Wheels
    glColor3f(0.18f, 0.12f, 0.07f);
    drawCircle(25, 25, 23);
    drawCircle(90, 25, 23);

    // Wheel centers
    glColor3f(0.72f, 0.48f, 0.20f);
    drawCircle(25, 25, 7);
    drawCircle(90, 25, 7);

    // Wheel spokes
    glColor3f(0.72f, 0.48f, 0.20f);
    glBegin(GL_LINES);

        glVertex2f(25, 3);
        glVertex2f(25, 47);
        glVertex2f(3, 25);
        glVertex2f(47, 25);

        glVertex2f(10, 10);
        glVertex2f(40, 40);
        glVertex2f(10, 40);
        glVertex2f(40, 10);

        glVertex2f(90, 3);
        glVertex2f(90, 47);
        glVertex2f(68, 25);
        glVertex2f(112, 25);

        glVertex2f(75, 10);
        glVertex2f(105, 40);
        glVertex2f(75, 40);
        glVertex2f(105, 10);

    glEnd();

    // Long wooden shaft
    glColor3f(0.48f, 0.27f, 0.10f);
    glLineWidth(5.0f);

    glBegin(GL_LINES);
        glVertex2f(108, 48);
        glVertex2f(190, 38);

        glVertex2f(108, 40);
        glVertex2f(190, 30);
    glEnd();

    glLineWidth(1.0f);

    // Small hay inside cart
    glColor3f(0.82f, 0.62f, 0.18f);

    glBegin(GL_TRIANGLES);
        glVertex2f(20, 68);
        glVertex2f(45, 105);
        glVertex2f(65, 68);

        glVertex2f(50, 68);
        glVertex2f(75, 110);
        glVertex2f(98, 68);
    glEnd();

    glPopMatrix();
}
// OBJECT ID: OBJ_VILLAGE_15
// Object: Traditional Village Tea Stall
// Created by: Rony

void drawVillageTeaStall(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Main wall
    glColor3f(0.58f, 0.38f, 0.18f);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(130, 0);
        glVertex2f(130, 85);
        glVertex2f(0, 85);
    glEnd();

    // Tin roof
    glColor3f(0.35f, 0.38f, 0.38f);
    glBegin(GL_POLYGON);
        glVertex2f(-15, 85);
        glVertex2f(145, 85);
        glVertex2f(125, 115);
        glVertex2f(5, 115);
    glEnd();

    // Roof lines
    glColor3f(0.20f, 0.22f, 0.22f);
    glBegin(GL_LINES);
        glVertex2f(10, 88);
        glVertex2f(25, 112);

        glVertex2f(40, 88);
        glVertex2f(50, 112);

        glVertex2f(70, 88);
        glVertex2f(75, 112);

        glVertex2f(100, 88);
        glVertex2f(100, 112);

        glVertex2f(130, 88);
        glVertex2f(125, 110);
    glEnd();

    // Front opening
    glColor3f(0.20f, 0.14f, 0.08f);
    glBegin(GL_QUADS);
        glVertex2f(15, 18);
        glVertex2f(82, 18);
        glVertex2f(82, 72);
        glVertex2f(15, 72);
    glEnd();

    // Counter
    glColor3f(0.72f, 0.45f, 0.18f);
    glBegin(GL_QUADS);
        glVertex2f(8, 16);
        glVertex2f(92, 16);
        glVertex2f(92, 28);
        glVertex2f(8, 28);
    glEnd();

    // Door
    glColor3f(0.34f, 0.20f, 0.10f);
    glBegin(GL_QUADS);
        glVertex2f(98, 0);
        glVertex2f(123, 0);
        glVertex2f(123, 62);
        glVertex2f(98, 62);
    glEnd();

    // Tea sign board
    glColor3f(0.15f, 0.42f, 0.18f);
    glBegin(GL_QUADS);
        glVertex2f(25, 78);
        glVertex2f(105, 78);
        glVertex2f(105, 98);
        glVertex2f(25, 98);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.85f);
    glRasterPos2f(46, 84);

    const char *text = "TEA STALL";

    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);

    // Tea cups on counter
    glColor3f(0.92f, 0.90f, 0.80f);

    glBegin(GL_QUADS);
        glVertex2f(30, 28);
        glVertex2f(40, 28);
        glVertex2f(39, 38);
        glVertex2f(31, 38);

        glVertex2f(52, 28);
        glVertex2f(62, 28);
        glVertex2f(61, 38);
        glVertex2f(53, 38);
    glEnd();

    // Small bench
    glColor3f(0.48f, 0.27f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(-10, -2);
        glVertex2f(55, -2);
        glVertex2f(55, 6);
        glVertex2f(-10, 6);

        glVertex2f(0, -15);
        glVertex2f(6, -15);
        glVertex2f(6, -2);
        glVertex2f(0, -2);

        glVertex2f(42, -15);
        glVertex2f(48, -15);
        glVertex2f(48, -2);
        glVertex2f(42, -2);
    glEnd();

    glPopMatrix();
}

// OBJECT ID: OBJ_ENV_09
// Object: Covered Wooden Transition Bridge
// Created by: Mostafiz

void drawBridgeCanopy()
{
    // Left front pillar
    glColor3f(0.34f, 0.20f, 0.09f);
    glBegin(GL_QUADS);
        glVertex2f(705, 60);
        glVertex2f(716, 60);
        glVertex2f(716, 210);
        glVertex2f(705, 210);
    glEnd();

    // Middle pillar
    glBegin(GL_QUADS);
        glVertex2f(795, 60);
        glVertex2f(806, 60);
        glVertex2f(806, 210);
        glVertex2f(795, 210);
    glEnd();

    // Right pillar
    glBegin(GL_QUADS);
        glVertex2f(884, 60);
        glVertex2f(895, 60);
        glVertex2f(895, 210);
        glVertex2f(884, 210);
    glEnd();

    // Top horizontal wooden beam
    glColor3f(0.42f, 0.25f, 0.10f);
    glBegin(GL_QUADS);
        glVertex2f(695, 198);
        glVertex2f(905, 198);
        glVertex2f(905, 214);
        glVertex2f(695, 214);
    glEnd();

    // Main sloping roof
    glColor3f(0.50f, 0.28f, 0.10f);
    glBegin(GL_POLYGON);
        glVertex2f(680, 210);
        glVertex2f(920, 210);
        glVertex2f(885, 255);
        glVertex2f(715, 255);
    glEnd();

    // Dark roof edge
    glColor3f(0.27f, 0.15f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(680, 208);
        glVertex2f(920, 208);
        glVertex2f(915, 218);
        glVertex2f(685, 218);
    glEnd();

    // Roof detail lines
    glColor3f(0.30f, 0.17f, 0.07f);
    glBegin(GL_LINES);
        glVertex2f(715, 215);
        glVertex2f(740, 252);

        glVertex2f(750, 215);
        glVertex2f(765, 252);

        glVertex2f(785, 215);
        glVertex2f(792, 252);

        glVertex2f(820, 215);
        glVertex2f(820, 252);

        glVertex2f(855, 215);
        glVertex2f(848, 252);

        glVertex2f(890, 215);
        glVertex2f(875, 252);
    glEnd();

    // Small sign board
    glColor3f(0.28f, 0.16f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(748, 220);
        glVertex2f(852, 220);
        glVertex2f(852, 242);
        glVertex2f(748, 242);
    glEnd();

    // Sign text
    glColor3f(1.0f, 0.88f, 0.55f);
    glRasterPos2f(765, 227);

    const char *text = "TWO WORLDS";

    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
}
// OBJECT ID: OBJ_ENV_10
// Object: Bridge Lower White Railing
// Created by: Mostafiz

void drawBridgeLowerRailing()
{
    glColor3f(0.88f, 0.88f, 0.85f);

    // Railing posts
    for (int x = 710; x <= 890; x += 30)
    {
        glBegin(GL_QUADS);

            glVertex2f(x, 68);
            glVertex2f(x + 4, 68);
            glVertex2f(x + 4, 92);
            glVertex2f(x, 92);

        glEnd();
    }

    // Horizontal railing
    glBegin(GL_QUADS);

        glVertex2f(705, 88);
        glVertex2f(895, 88);
        glVertex2f(895, 94);
        glVertex2f(705, 94);

    glEnd();
}

// OBJECT ID: OBJ_VILLAGE_17
// Object: Village Van with Driver
// Created by: Shajia

void drawVillageVanDriver(float x, float y, float s)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(s, s, 1);

    // Van platform
    glColor3f(0.58f, 0.34f, 0.14f);

    glBegin(GL_QUADS);
        glVertex2f(0, 28);
        glVertex2f(115, 28);
        glVertex2f(115, 45);
        glVertex2f(0, 45);
    glEnd();

    // Wooden side frame
    glColor3f(0.72f, 0.48f, 0.20f);

    glBegin(GL_LINES);
        glVertex2f(5, 45);
        glVertex2f(5, 68);

        glVertex2f(30, 45);
        glVertex2f(30, 68);

        glVertex2f(55, 45);
        glVertex2f(55, 68);

        glVertex2f(80, 45);
        glVertex2f(80, 68);

        glVertex2f(100, 45);
        glVertex2f(100, 68);

        glVertex2f(5, 66);
        glVertex2f(100, 66);
    glEnd();

    // Back wheel
    glColor3f(0.12f, 0.12f, 0.12f);
    drawCircle(20, 22, 20);

    glColor3f(0.70f, 0.70f, 0.70f);
    drawCircle(20, 22, 14);

    glColor3f(0.15f, 0.15f, 0.15f);
    drawCircle(20, 22, 4);

    // Front wheel
    glColor3f(0.12f, 0.12f, 0.12f);
    drawCircle(105, 22, 20);

    glColor3f(0.70f, 0.70f, 0.70f);
    drawCircle(105, 22, 14);

    glColor3f(0.15f, 0.15f, 0.15f);
    drawCircle(105, 22, 4);

    // Driver seat
    glColor3f(0.30f, 0.20f, 0.12f);

    glBegin(GL_QUADS);
        glVertex2f(102, 45);
        glVertex2f(128, 45);
        glVertex2f(128, 52);
        glVertex2f(102, 52);
    glEnd();

    // Driver body
    glColor3f(0.18f, 0.45f, 0.70f);

    glBegin(GL_QUADS);
        glVertex2f(108, 52);
        glVertex2f(121, 52);
        glVertex2f(121, 78);
        glVertex2f(108, 78);
    glEnd();

    // Driver head
    glColor3f(0.82f, 0.62f, 0.44f);
    drawCircle(115, 87, 8);

    // Hair
    glColor3f(0.12f, 0.08f, 0.05f);

    glBegin(GL_POLYGON);
        glVertex2f(108, 88);
        glVertex2f(110, 95);
        glVertex2f(116, 97);
        glVertex2f(122, 93);
        glVertex2f(122, 88);
    glEnd();

    // Driver legs
    glColor3f(0.18f, 0.18f, 0.20f);
    glLineWidth(3.0f);

    glBegin(GL_LINES);
        glVertex2f(111, 53);
        glVertex2f(103, 37);

        glVertex2f(118, 53);
        glVertex2f(109, 37);
    glEnd();

    // Driver arm
    glColor3f(0.82f, 0.62f, 0.44f);

    glBegin(GL_LINES);
        glVertex2f(119, 70);
        glVertex2f(138, 61);
    glEnd();

    // Van handle
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_LINES);
        glVertex2f(138, 61);
        glVertex2f(148, 72);

        glVertex2f(140, 72);
        glVertex2f(154, 72);
    glEnd();

    glLineWidth(1.0f);

    glPopMatrix();
}

// FUNCTION ID: FUNC_TRANS_01
// Function: Two Worlds Vehicle Transformation
// Created by: Apon

void drawWorldTransitionVehicle()
{
    float vanX = 900 + worldTransitionMove;

    drawVillageVanDriver(vanX, 100, 0.72f);
}

// SUPPORTING FUNCTION
// Function: Reverse City Car
// Created by: Apon

void drawReverseCityCar(float x, float y, float s)
{
    glPushMatrix();

    glTranslatef(2 * x, 0, 0);
    glScalef(-1.0f, 1.0f, 1.0f);

    drawCityCar(x, y, s);

    glPopMatrix();
}

// FUNCTION ID: FUNC_ANIM_14
// Function: Reverse City Car Movement
// Created by: Apon

void updateReverseCar(int value)
{
    reverseCarMove += 2.2f;

    if (reverseCarMove > 900.0f)
        reverseCarMove = 0.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateReverseCar, 0);
}

// FUNCTION ID: FUNC_ANIM_15
// Function: Bidirectional Pedestrian Movement
// Created by: Mostafiz

void updatePedestrian(int value)
{
    pedestrianMove += 1.0f;

    if (pedestrianMove > 1800.0f)
        pedestrianMove = -700.0f;

    cityPersonLeft1 -= 0.9f;
    cityPersonLeft2 -= 0.7f;

    if (cityPersonLeft1 < -30.0f)
        cityPersonLeft1 = 700.0f;

    if (cityPersonLeft2 < -30.0f)
        cityPersonLeft2 = 700.0f;

    villagePersonLeft1 -= 0.8f;
    villagePersonLeft2 -= 1.0f;

    if (villagePersonLeft1 < 920.0f)
        villagePersonLeft1 = 1600.0f;

    if (villagePersonLeft2 < 920.0f)
        villagePersonLeft2 = 1600.0f;


    glutPostRedisplay();
    glutTimerFunc(30, updatePedestrian, 0);
}

// OBJECT ID: OBJ_ENV_10
// Object: Walking Pedestrian with Rain Umbrella
// Created by: Mostafiz

void drawWalkingPerson(float x, float y, float s)
{
    // Head
    glColor3f(0.95f, 0.75f, 0.55f);
    drawCircle(x, y + 42 * s, 7 * s);

    // Hair
    glColor3f(0.12f, 0.08f, 0.05f);
    glBegin(GL_POLYGON);
        glVertex2f(x - 7 * s, y + 44 * s);
        glVertex2f(x - 5 * s, y + 50 * s);
        glVertex2f(x + 5 * s, y + 50 * s);
        glVertex2f(x + 7 * s, y + 44 * s);
    glEnd();

    // Body / shirt
    glColor3f(0.18f, 0.38f, 0.75f);
    glBegin(GL_QUADS);
        glVertex2f(x - 6 * s, y + 18 * s);
        glVertex2f(x + 6 * s, y + 18 * s);
        glVertex2f(x + 6 * s, y + 37 * s);
        glVertex2f(x - 6 * s, y + 37 * s);
    glEnd();

    // Arms
    glColor3f(0.95f, 0.75f, 0.55f);
    glLineWidth(3.0f);

    glBegin(GL_LINES);

        glVertex2f(x - 5 * s, y + 32 * s);
        glVertex2f(x - 13 * s, y + 21 * s);

        glVertex2f(x + 5 * s, y + 32 * s);
        glVertex2f(x + 13 * s, y + 23 * s);

    glEnd();

    // Pants
    glColor3f(0.10f, 0.12f, 0.18f);

    glBegin(GL_QUADS);
        glVertex2f(x - 6 * s, y + 18 * s);
        glVertex2f(x + 6 * s, y + 18 * s);
        glVertex2f(x + 5 * s, y + 12 * s);
        glVertex2f(x - 5 * s, y + 12 * s);
    glEnd();

    // Legs - slightly different position gives walking pose
    glLineWidth(4.0f);

    glBegin(GL_LINES);

        glVertex2f(x - 3 * s, y + 13 * s);
        glVertex2f(x - 9 * s, y);

        glVertex2f(x + 3 * s, y + 13 * s);
        glVertex2f(x + 9 * s, y + 3 * s);

    glEnd();

    // Shoes
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(3.0f);

    glBegin(GL_LINES);

        glVertex2f(x - 9 * s, y);
        glVertex2f(x - 14 * s, y);

        glVertex2f(x + 9 * s, y + 3 * s);
        glVertex2f(x + 14 * s, y + 3 * s);

    glEnd();

    glLineWidth(1.0f);

    if (sceneMode == 3)
    {
        // Umbrella upper canopy
        glColor3f(0.55f, 0.12f, 0.20f);

        glBegin(GL_TRIANGLE_FAN);

            // Center/bottom point
            glVertex2f(x, y + 58 * s);

            // Upper semicircle
            for (int i = 0; i <= 180; i += 10)
            {
                float angle = i * 3.1416f / 180.0f;

                glVertex2f(
                    x + cos(angle) * 24 * s,
                    y + 58 * s + sin(angle) * 14 * s
                );
            }

        glEnd();


        // Umbrella center stick
        glColor3f(0.15f, 0.15f, 0.15f);
        glLineWidth(2.0f);

        glBegin(GL_LINES);

            glVertex2f(x, y + 58 * s);
            glVertex2f(x, y + 25 * s);

        glEnd();


        // Umbrella handle
        glBegin(GL_LINES);

            glVertex2f(x, y + 25 * s);
            glVertex2f(x + 5 * s, y + 21 * s);

        glEnd();

        glLineWidth(1.0f);
    }
}


// OBJECT ID: OBJ_CITY_14
// Object: City Background Trees and Bushes
// Created by: Shajia

void drawCityBackgroundTree(float x, float y, float s)
{
    // Trunk
    glColor3f(0.30f, 0.18f, 0.08f);
    glBegin(GL_QUADS);
        glVertex2f(x - 5*s, y);
        glVertex2f(x + 5*s, y);
        glVertex2f(x + 5*s, y + 55*s);
        glVertex2f(x - 5*s, y + 55*s);
    glEnd();

    // Dark leaves
    glColor3f(0.08f, 0.35f, 0.10f);
    drawCircle(x, y + 75*s, 24*s);

    // Left leaves
    glColor3f(0.12f, 0.45f, 0.12f);
    drawCircle(x - 18*s, y + 68*s, 18*s);

    // Right leaves
    drawCircle(x + 18*s, y + 68*s, 18*s);

    // Top leaves
    glColor3f(0.18f, 0.52f, 0.16f);
    drawCircle(x, y + 92*s, 18*s);
}

void drawCityBackgroundBush(float x, float y, float s)
{
    glColor3f(0.06f, 0.30f, 0.08f);

    drawCircle(x, y, 12*s);
    drawCircle(x + 14*s, y + 3*s, 14*s);
    drawCircle(x + 28*s, y, 12*s);

    glColor3f(0.12f, 0.42f, 0.10f);

    drawCircle(x + 8*s, y + 8*s, 8*s);
    drawCircle(x + 22*s, y + 8*s, 8*s);
}

// OBJECT ID: OBJ_VILLAGE_GREENERY
// Object: Natural Village Roadside Greenery
// Created by: Rony

void drawVillageGrass(float x, float y, float s)
{
    glColor3f(0.12f, 0.38f, 0.08f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);

        glVertex2f(x, y);
        glVertex2f(x - 4*s, y + 12*s);

        glVertex2f(x + 3*s, y);
        glVertex2f(x + 3*s, y + 16*s);

        glVertex2f(x + 6*s, y);
        glVertex2f(x + 11*s, y + 11*s);

        glVertex2f(x + 10*s, y);
        glVertex2f(x + 15*s, y + 15*s);

    glEnd();

    glLineWidth(1.0f);
}

void drawVillageLowShrub(float x, float y, float s)
{
    glColor3f(0.08f, 0.32f, 0.07f);
    drawCircle(x, y + 4*s, 7*s);
    drawCircle(x + 9*s, y + 6*s, 9*s);
    drawCircle(x + 18*s, y + 4*s, 7*s);

    glColor3f(0.16f, 0.46f, 0.10f);
    drawCircle(x + 5*s, y + 8*s, 5*s);
    drawCircle(x + 14*s, y + 9*s, 5*s);
}

// OBJECT ID: OBJ_RIVER_03
// Object: Moving River Ripples
// Created by: Shajia

void drawRiverRipples()
{
    glColor3f(0.72f, 0.88f, 0.95f);
    glLineWidth(2.0f);

    float r = rippleMove;

    glBegin(GL_LINES);

        // Ripple 1
        glVertex2f(80 + r, -95);
        glVertex2f(125 + r, -95);

        // Ripple 2
        glVertex2f(260 + r, -145);
        glVertex2f(315 + r, -145);

        // Ripple 3
        glVertex2f(470 + r, -110);
        glVertex2f(520 + r, -110);

        // Ripple 4
        glVertex2f(690 + r, -165);
        glVertex2f(750 + r, -165);

        // Ripple 5
        glVertex2f(920 + r, -105);
        glVertex2f(970 + r, -105);

        // Ripple 6
        glVertex2f(1130 + r, -150);
        glVertex2f(1190 + r, -150);

        // Ripple 7
        glVertex2f(1360 + r, -115);
        glVertex2f(1415 + r, -115);

    glEnd();

    glLineWidth(1.0f);
}
// FUNCTION ID: FUNC_ANIM_16
// Function: River Ripple Movement
// Created by: Shajia

void updateRiverRipple(int value)
{
    rippleMove += 0.6f;

    if (rippleMove > 180.0f)
        rippleMove = -180.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateRiverRipple, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawStars();

    drawBackgroundRain();
    drawAirplane(400 + airplaneMove , 600, 0.85f);
    drawBirds();

    drawCloud((250 + cloudMove > 1700) ? 250 + cloudMove - 1900 : 250 + cloudMove, 600);

    drawCloud((520 + cloudMove > 1700) ? 520 + cloudMove - 1900 : 520 + cloudMove, 550);

    drawCloud((1050 + cloudMove > 1700) ? 1050 + cloudMove - 1900 : 1050 + cloudMove, 600);

    drawCloud((1400 + cloudMove > 1700) ? 1400 + cloudMove - 1900 : 1400 + cloudMove, 550);
    drawGround();

    drawDistantCity();
    drawRiverSideHills();
    drawVillageHills();
    drawVillageBackgroundTrees();
    drawVillagePineTrees();
    drawAdditionalVillageTrees();

    drawBananaTree(780, 250, 0.70f);
    drawBananaTree(850, 250, 0.90f);
    drawBananaTree(820, 250, 0.40f);
    drawBananaTree(870, 250, 0.40f);

    drawVegetableGarden(780, 200, 0.70f);

    drawPaddyField();
    drawBambooFence();

    drawLargeVillageTrees();

    drawHayStack(1500);
    drawSmallHayStack(1300, 250, 0.85f);
    drawSmallHayStack(1345, 250, 0.65f);

    drawWindmill();
    drawSmallHayStack(1110, 250, 0.85f);
    drawSmallHayStack(1145, 250, 0.65f);

    drawWoodenVillageHouse();
    drawAnimalFarm();
    drawFarmChickens();
    drawMudHouse();
    drawTinHouse();


    drawVillageGrass(925, 176, 0.70f);
    drawVillageGrass(970, 177, 0.55f);

    drawVillageLowShrub(1010, 177, 0.60f);

    drawVillageGrass(1070, 176, 0.65f);
    drawVillageGrass(1110, 178, 0.50f);

    drawVillageLowShrub(1160, 177, 0.55f);

    drawVillageGrass(1220, 176, 0.70f);
    drawVillageGrass(1270, 177, 0.55f);

    drawVillageLowShrub(1320, 177, 0.60f);

    drawVillageGrass(1390, 176, 0.65f);
    drawVillageGrass(1440, 178, 0.55f);

    drawVillageLowShrub(1490, 177, 0.55f);

    drawVillageGrass(1550, 176, 0.65f);

    drawWalkingPerson(700 + pedestrianMove, 185, 0.72f);
    drawWalkingPerson(800 + pedestrianMove, 185, 0.68f);
    drawWalkingPerson(1200 + pedestrianMove, 185, 0.90f);
    drawWalkingPerson(950 + pedestrianMove*1.5, 185, 0.69f);
    drawWalkingPerson(1550 + pedestrianMove, 185, 0.77f);

    drawVillageCows();

    drawRiver();
    drawRiverDetails();
    drawRiverRipples();

    drawCityBase();

    drawCitySidewalk();
    drawCityHighway();
    drawRoadBorder();
    drawRoadMarkings();

    drawCityBackgroundTree(20, 205, 0.95f);
    drawCityBackgroundTree(110, 205, 1.00f);
    drawCityBackgroundTree(230, 205, 0.90f);
    drawCityBackgroundTree(320, 205, 1.05f);
    drawCityBackgroundTree(430, 205, 0.92f);
    drawCityBackgroundTree(520, 205, 1.00f);
    drawCityBackgroundTree(620, 205, 0.95f);

    drawCityBackgroundBush(5, 210, 0.85f);
    drawCityBackgroundBush(75, 210, 0.90f);
    drawCityBackgroundBush(150, 210, 0.80f);
    drawCityBackgroundBush(235, 210, 0.88f);
    drawCityBackgroundBush(320, 210, 0.82f);
    drawCityBackgroundBush(405, 210, 0.90f);
    drawCityBackgroundBush(490, 210, 0.84f);
    drawCityBackgroundBush(575, 210, 0.88f);
    drawCityBackgroundBush(650, 210, 0.80f);

    drawAIUBBuilding();
    drawHighRiseBuilding();
    drawFoodCourt();
    drawHospital();

    drawTrafficSignal();
    drawZebraCrossing();

    drawWalkingPerson(cityPersonLeft1, 40, 0.72f);
    drawWalkingPerson(cityPersonLeft2, 40, 0.78f);
    drawWalkingPerson(cityPersonLeft1-500, 40, 0.52f);
    drawWalkingPerson(cityPersonLeft1-520, 40, 0.92f);
    drawWalkingPerson(100+ cityPersonLeft2, 40, 0.98f);

    drawStreetLights();

    drawRiverSideBushes();

    drawWalkingPerson(-100 + pedestrianMove*1.5, 185, 0.75f);
    drawWalkingPerson(350 + pedestrianMove*1.1, 185, 0.68f);
    drawWalkingPerson(-200 + pedestrianMove*1.4, 185, 0.72f);
    drawWalkingPerson(50 + pedestrianMove, 185, 0.72f);
    drawWalkingPerson(200 + pedestrianMove*1.7, 185, 0.72f);
    drawWalkingPerson(-350 + pedestrianMove*1.1, 185, 0.68f);

    drawCityPark();
    drawBridge();
    drawVillageEntryRoad();

    drawVillageGrass(940, 65, 0.50f);
    drawVillageGrass(1090, 64, 0.45f);
    drawVillageGrass(1240, 65, 0.55f);
    drawVillageGrass(1400, 64, 0.48f);
    drawVillageGrass(1540, 65, 0.50f);

    drawWorldTransitionVehicle();

    drawAmbulance(560, 165, 0.70f);

    float reverse1 = 850 - reverseCarMove;
    if (reverse1 > -100)
        drawReverseCityCar(reverse1, 142, 0.70f);

    float reverse2 = 550 - reverseCarMove;
    if (reverse2 > -100)
        drawReverseCityCar(reverse2, 142, 0.70f);

    float car1X = 100 + carMove;
    float car2X = 420 + carMove;
    float car3X = 760 + carMove;

    if (car1X < 850)
        drawCityCar(car1X, 110, 0.75f);

    if (car2X < 840)
        drawCityCar(car2X, 82, 0.65f);

    if (car3X < 850)
        drawCityCar(car3X, 110, 0.72f);

    drawCityBus(-180 + busMove, 82, 0.75f);
    drawBridgeLowerRailing();
    drawBridgeCanopy();


    drawBusStop();

    if (sceneMode == 0)
    {
        drawSun();
    }
    else if (sceneMode == 1)
    {
        drawSun();
    }
    else
    {
        drawMoon();
    }
    drawVillageWelcomeBoard(980, 70, 0.90f);

    drawWalkingPerson(villagePersonLeft1, 55, 0.72f);
    drawWalkingPerson(1420, 55, 0.92f);
    drawWalkingPerson(villagePersonLeft2, 55, 0.87f);

    drawWalkingPerson(130+villagePersonLeft1, 55, 0.72f);
    drawWalkingPerson(250+villagePersonLeft2, 55, 0.97f);

    drawVillageTeaStall(1450, 60, 0.85f);
    drawBullockCart(1220, 165, 0.75f);

    drawRiverBankDecoration(180, -70, 0.80f);
    drawRiverBankDecoration(80, -70, 0.80f);
    drawRiverBankDecoration(250, -70, 0.90f);
    drawRiverBankDecoration(700, -70, 0.70f);
    drawRiverBankDecoration(750, -70, 0.50f);
    drawRiverBankDecoration(920, -70, 0.85f);
    drawRiverBankDecoration(905, -70, 0.75f);
    drawRiverBankDecoration(1250, -70, 0.85f);
    drawRiverBankDecoration(1300, -70, 0.50f);
    drawRiverBankDecoration(1500, -70, 0.85f);
    drawRiverBankDecoration(1540, -70, 0.40f);

    drawWoodenBoat(480 + boatMove, -130, 0.85f);
    drawWoodenBoat(650 + boatMove * 1.5f, -90, 0.85f);
    drawWoodenBoat(250 + boatMove* 2.5f, -170, 0.85f);

    drawForegroundRain();

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
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, updateCloud, 0);
    glutTimerFunc(25, updateRain, 0);
    glutTimerFunc(30, updateWindmill, 0);
    glutTimerFunc(50, updateCow, 0);
    glutTimerFunc(30, updateCar, 0);
    glutTimerFunc(30, updateBus, 0);
    glutTimerFunc(3000, updateTrafficSignal, 0);
    glutTimerFunc(40, updatePaddy, 0);
    glutTimerFunc(40, updatePaddy, 0);
    glutTimerFunc(30, updateBoat, 0);
    glutTimerFunc(30, updateBirds, 0);
    glutTimerFunc(30, updateAirplane, 0);
    glutTimerFunc(400, updateAmbulanceLight, 0);
    glutTimerFunc(30, updateWorldTransition, 0);
    glutTimerFunc(30, updateReverseCar, 0);
    glutTimerFunc(30, updatePedestrian, 0);
    glutTimerFunc(30, updateRiverRipple, 0);

    glutMainLoop();

    return 0;
}
