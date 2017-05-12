#include <GL/freeglut.h>
#include <math.h>

int height = 800;
int width = 1200;

int cubeCount = 1;

bool isOrtho = false;
bool isWireFrame = false;

float middelCubeX = 0;
float middelCubeY = 0;

float behindCubeR = 0;
float behindCubeG = 0;
float behindCubeB = 0;

float rotation = 0;

void drawCube()
{
	glBegin(GL_QUADS);
	// top
	if(cubeCount != 4) glColor3f(1.0f, 0.0f, 0.0f);
	else glColor3f(behindCubeR, behindCubeG, behindCubeB);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// front
	if(cubeCount != 4)glColor3f(0.0f, 1.0f, 0.0f);
	else glColor3f(behindCubeR, behindCubeG, behindCubeB);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// right
	if (cubeCount != 4)glColor3f(0.0f, 0.0f, 1.0f);
	else glColor3f(behindCubeR, behindCubeG, behindCubeB);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// left
	if (cubeCount != 4)glColor3f(0.0f, 0.0f, 0.5f);
	else glColor3f(behindCubeR, behindCubeG, behindCubeB);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// bottom
	if (cubeCount != 4)glColor3f(0.5f, 0.0f, 0.0f);
	else glColor3f(behindCubeR, behindCubeG, behindCubeB);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// back
	if (cubeCount != 4)glColor3f(0.0f, 0.5f, 0.0f);
	else glColor3f(behindCubeR, behindCubeG, behindCubeB);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	cubeCount++;
}

void reshape(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, w, h);
}

void specialKeyPressed(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			middelCubeY += 0.1;
			break;
		case GLUT_KEY_DOWN:
			middelCubeY -= 0.1;
			break;
		case GLUT_KEY_RIGHT:
			middelCubeX += 0.1;
			break;
		case GLUT_KEY_LEFT:
			middelCubeX -= 0.1;
			break;
		case GLUT_KEY_CTRL_L:
			isWireFrame = !isWireFrame;
			break;
	}
}

void keyboard(unsigned char key, int x, int  y)
{
	if (key == 27) //esc key
		exit(0);
	else if (key == 32) //spacebar
		isOrtho = !isOrtho;
}

void mouse(int mouseX, int mouseY)
{
	behindCubeR = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	behindCubeG = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	behindCubeB = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void display()
{
	cubeCount = 1;

	glClearColor(0.9f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (!isOrtho) gluPerspective(90.0f, width / (float)height, 0.1f, 50.0f);
	else glOrtho(-8.0, 8.0,-8.0,8.0, 0, 30.0);

	glMatrixMode(GL_MODELVIEW);

	if (isWireFrame) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glLoadIdentity();
	gluLookAt(0, 5, 5,
		0, 0, 0,
		0, 1, 0);

	glPushMatrix();
	glTranslatef(-2, 0, 0);
	glRotatef(rotation, 1, 0, 0); //rotate x
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(middelCubeX, middelCubeY, 0);
	glRotatef(rotation, 0, 1, 0); //rotate y
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(rotation, 0, 0, 1); //rotate z
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -2); //places cube behind the other three
	drawCube();
	glPopMatrix();

	glutSwapBuffers();
}


int lastTime = 0;
void idle()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = (currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;

	rotation += deltaTime * 180;

	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutInit(&argc, argv);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyPressed);
	glutPassiveMotionFunc(mouse);
	//opengl init

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 0;
}