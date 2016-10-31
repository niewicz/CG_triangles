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

void rotateTraingle(float displacement_x, float displacement_y)
{
	glTranslatef(-displacement_x, -displacement_y, 0);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(displacement_x, displacement_y, 0);
}

void drawAndAnimateTriangle(float displacement_x, float displacement_y, float x_1, float y_1, float x_2, float y_2, Color *color)
{
	glPushMatrix();
	rotateTraingle(displacement_x, displacement_y);
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
		glRotatef(-3 * angle, 0.0f, 0.0f, 1.0f);
		// 4 inner blue
		drawAndAnimateTriangle(displacement, displacement, 0.0f, 0.0f, 1.0f, 1.0f, colorBlue);
		drawAndAnimateTriangle(-displacement, displacement, 0.0f, 0.0f, -1.0f, 1.0f, colorBlue);
		drawAndAnimateTriangle(displacement, -displacement, 0.0f, 0.0f, 1.0f, -1.0f, colorBlue);
		drawAndAnimateTriangle(-displacement, -displacement, 0.0f, 0.0f, -1.0f, -1.0f, colorBlue);
	glPopMatrix();

	glPushMatrix();
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		// 4 midlle orange
		drawAndAnimateTriangle(2 * displacement, displacement, 1.0f, 0.0f, 2.0f, 1.0f, colorOrange);
		drawAndAnimateTriangle(-displacement, 2 * displacement, 0.0f, 1.0f, -1.0f, 2.0f, colorOrange);
		drawAndAnimateTriangle(-2 * displacement, -displacement, -1.0f, 0.0f, -2.0f, -1.0f, colorOrange);
		drawAndAnimateTriangle(displacement, -2 * displacement, 0.0f, -1.0f, 1.0f, -2.0f, colorOrange);

		// 4 middle green
		drawAndAnimateTriangle(displacement, 2 * displacement, 0.0f, 1.0f, 1.0f, 2.0f, colorGreen);
		drawAndAnimateTriangle(-2 * displacement, displacement, -1.0f, 0.0f, -2.0f, 1.0f, colorGreen);
		drawAndAnimateTriangle(-displacement, -2 * displacement, 0.0f, -1.0f, -1.0f, -2.0f, colorGreen);
		drawAndAnimateTriangle(2 * displacement, -displacement, 1.0f, 0.0f, 2.0f, -1.0f, colorGreen);

		// 4 outer red
		drawAndAnimateTriangle(displacement, 3 * displacement, 0.0f, 2.0f, 1.0f, 3.0f, colorRed);
		drawAndAnimateTriangle(3 * displacement, -displacement, 2.0f, 0.0f, 3.0f, -1.0f, colorRed);
		drawAndAnimateTriangle(-displacement, -3 * displacement, 0.0f, -2.0f, -1.0f, -3.0f, colorRed);
		drawAndAnimateTriangle(-3 * displacement, displacement, -2.0f, 0.0f, -3.0f, 1.0f, colorRed);

		// 4 outer yellow
		drawAndAnimateTriangle(2 * displacement, 2 * displacement, 1.0f, 1.0f, 2.0f, 2.0f, colorYellow);
		drawAndAnimateTriangle(2 * displacement, -2 * displacement, 1.0f, -1.0f, 2.0f, -2.0f, colorYellow);
		drawAndAnimateTriangle(-2 * displacement, -2 * displacement, -1.0f, -1.0f, -2.0f, -2.0f, colorYellow);
		drawAndAnimateTriangle(-2 * displacement, 2 * displacement, -1.0f, 1.0f, -2.0f, 2.0f, colorYellow);

		// 4 outer pink
		drawAndAnimateTriangle(3 * displacement, displacement, 2.0f, 0.0f, 3.0f, 1.0f, colorPink);
		drawAndAnimateTriangle(displacement, -3 * displacement, 0.0f, -2.0f, 1.0f, -3.0f, colorPink);
		drawAndAnimateTriangle(-3 * displacement, -displacement, -2.0f, 0.0f, -3.0f, -1.0f, colorPink);
		drawAndAnimateTriangle(-displacement, 3 * displacement, 0.0f, 2.0f, -1.0f, 3.0f, colorPink);
	glPopMatrix();

	if (angle < 360)
		angle += (float)ROTATION_UNIT;
	else
	{
		angle = 0.0f;
		if (counter < 10)
			displacement += 0.03f;
		else if (counter < 20)
			displacement -= 0.03f;
		else
			counter = 0;
		counter++;
	}

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