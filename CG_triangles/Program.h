#pragma once
#include "Color.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define MW_INIT_POS_X 100
#define MW_INIT_POS_Y 100
#define MW_HEIGHT 640
#define MW_WIDTH 640
#define ROTATION_UNIT 0.125f

#define ESCAPE_KEY 27

Color *colorRed = new Color(1.0f, 0.0f, 0.0f);
Color *colorGreen = new Color(0.0f, 1.0f, 0.0f);
Color *colorBlue = new Color(0.0f, 0.0f, 1.0f);
Color *colorOrange = new Color(1.0f, 0.65f, 0.0f);
Color *colorYellow = new Color(1.0f, 1.0f, 0.0f);
Color *colorPink = new Color(1.0f, 0.1f, 0.6f);

float angleCenter = 360.0f;
float angleObject = 0.0f;
float displacement = 0.5f;
unsigned int counter = 0;

void paintTraingle(float x_1, float y_1, float x_2, float y_2, Color *color);
void rotateTraingle(float anglel, float displacement_x, float displacement_y, float around_x, float around_y);
void drawAndAnimateTriangle(float anglel, float displacement_x, float displacement_y, float x_1, float y_1, float x_2, float y_2, Color *color);
void renderScene(void);
void changeSize(int width, int height);
void processKeys(unsigned char key, int x, int y);