#include "Program.h"

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(MW_INIT_POS_X, MW_INIT_POS_Y);
	glutInitWindowSize(MW_WIDTH, MW_HEIGHT);
	glutCreateWindow("Fun with triangles!");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processKeys);

	glutMainLoop();

	return 1;
}

void paintTraingle(float x_1, float y_1, float x_2, float y_2, Color *color)
{
	glColor3f(color->Red(), color->Green(), color->Blue());
	glBegin(GL_TRIANGLES);
		glVertex3f(x_1, y_1, 0.0f);
		glVertex3f(x_2, y_1, 0.0f);
		glVertex3f(x_1, y_2, 0.0f);
	glEnd();
}

void rotateTraingle(float angle, float displacement_x, float displacement_y, float around_x, float around_y)
{
	//glTranslatef(displacement_x, displacement_y, 0);
	glTranslatef(displacement_x + around_x, displacement_y + around_y, 0);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-around_x - displacement_x, -around_y - displacement_y, 0);
}

void drawAndAnimateTriangle(float angle, float displacement_x, float displacement_y, float x_1, float y_1, float x_2, float y_2, Color *color)
{
	float x_avg = (2 * x_1 + x_2) / 3;
	float y_avg = (2 * y_1 + y_2) / 3;
	glPushMatrix();
	rotateTraingle(angle, displacement_x, displacement_y, x_avg, y_avg);
	paintTraingle(x_1, y_1, x_2, y_2, color);
	glPopMatrix();
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 17.0f,
			  0.0f, 0.0f, 0.0f,
			  0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glRotatef(3 * angleCenter, 0.0f, 0.0f, 1.0f);
		// 4 inner blue
		drawAndAnimateTriangle(-2 * angleObject, displacement, displacement, 0.0f, 0.0f, 1.0f, 1.0f, colorBlue);
		drawAndAnimateTriangle(-2 * angleObject, -displacement, displacement, 0.0f, 0.0f, -1.0f, 1.0f, colorBlue);
		drawAndAnimateTriangle(-2 * angleObject, displacement, -displacement, 0.0f, 0.0f, 1.0f, -1.0f, colorBlue);
		drawAndAnimateTriangle(-2 * angleObject, -displacement, -displacement, 0.0f, 0.0f, -1.0f, -1.0f, colorBlue);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-angleCenter, 0.0f, 0.0f, 1.0f);
		// 4 midlle orange
		drawAndAnimateTriangle(angleObject, 2 * displacement, displacement, 1.0f, 0.0f, 2.0f, 1.0f, colorOrange);
		drawAndAnimateTriangle(angleObject, -displacement, 2 * displacement, 0.0f, 1.0f, -1.0f, 2.0f, colorOrange);
		drawAndAnimateTriangle(angleObject, -2 * displacement, -displacement, -1.0f, 0.0f, -2.0f, -1.0f, colorOrange);
		drawAndAnimateTriangle(angleObject, displacement, -2 * displacement, 0.0f, -1.0f, 1.0f, -2.0f, colorOrange);

		// 4 middle green
		drawAndAnimateTriangle(angleObject, displacement, 2 * displacement, 0.0f, 1.0f, 1.0f, 2.0f, colorGreen);
		drawAndAnimateTriangle(angleObject, -2 * displacement, displacement, -1.0f, 0.0f, -2.0f, 1.0f, colorGreen);
		drawAndAnimateTriangle(angleObject, -displacement, -2 * displacement, 0.0f, -1.0f, -1.0f, -2.0f, colorGreen);
		drawAndAnimateTriangle(angleObject, 2 * displacement, -displacement, 1.0f, 0.0f, 2.0f, -1.0f, colorGreen);

		// 4 outer red
		drawAndAnimateTriangle(angleObject, displacement, 3 * displacement, 0.0f, 2.0f, 1.0f, 3.0f, colorRed);
		drawAndAnimateTriangle(angleObject, 3 * displacement, -displacement, 2.0f, 0.0f, 3.0f, -1.0f, colorRed);
		drawAndAnimateTriangle(angleObject, -displacement, -3 * displacement, 0.0f, -2.0f, -1.0f, -3.0f, colorRed);
		drawAndAnimateTriangle(angleObject, -3 * displacement, displacement, -2.0f, 0.0f, -3.0f, 1.0f, colorRed);

		// 4 outer yellow
		drawAndAnimateTriangle(angleObject, 2 * displacement, 2 * displacement, 1.0f, 1.0f, 2.0f, 2.0f, colorYellow);
		drawAndAnimateTriangle(angleObject, 2 * displacement, -2 * displacement, 1.0f, -1.0f, 2.0f, -2.0f, colorYellow);
		drawAndAnimateTriangle(angleObject, -2 * displacement, -2 * displacement, -1.0f, -1.0f, -2.0f, -2.0f, colorYellow);
		drawAndAnimateTriangle(angleObject, -2 * displacement, 2 * displacement, -1.0f, 1.0f, -2.0f, 2.0f, colorYellow);

		// 4 outer pink
		drawAndAnimateTriangle(angleObject, 3 * displacement, displacement, 2.0f, 0.0f, 3.0f, 1.0f, colorPink);
		drawAndAnimateTriangle(angleObject, displacement, -3 * displacement, 0.0f, -2.0f, 1.0f, -3.0f, colorPink);
		drawAndAnimateTriangle(angleObject, -3 * displacement, -displacement, -2.0f, 0.0f, -3.0f, -1.0f, colorPink);
		drawAndAnimateTriangle(angleObject, -displacement, 3 * displacement, 0.0f, 2.0f, -1.0f, 3.0f, colorPink);
	glPopMatrix();

	
	if (angleObject < 360.0f)
	{
		angleObject += (float)ROTATION_UNIT;
		angleCenter -= (float)ROTATION_UNIT;
	}
	else
	{
		angleObject = 0.0f;
		angleCenter = 360.0f;
	}

	/*
	if (counter < 10)
		displacement += 0.05;
	else if (counter < 20)
		displacement -= 0.05;
	else
		counter = 0;
		
	counter++;
	*/

	glutSwapBuffers();
}

void changeSize(int width, int height)
{
	if (height == 0)
		height = 1;

	float ratio = width * 1.0f / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f, ratio, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void processKeys(unsigned char key, int x, int y)
{
	if (key == ESCAPE_KEY)
		exit(0);
}