#include <GL/freeglut.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath> 
#include "Cube.h"
#include "iostream"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int height = 800;
int width = 1200;
bool keys[255];

GLuint TextureId;
int world[32][32][16];

struct Camera
{
    float posX = 0;
    float posY = -10;
    float posZ = 20;
    float rotX = 0;
    float rotY = 0;
} camera;

void textureBinder()
{
    int w, h, comp;
    std::string file = "terrain.png";

    unsigned char * image = stbi_load(file.c_str(), &w, &h, &comp, STBI_rgb_alpha);

    if (image == nullptr)
    {
        std::cout << "Failed to load: " << file.c_str() << std::endl;
    }
    else
    {
        glGenTextures(1, &TextureId);
        glBindTexture(GL_TEXTURE_2D, TextureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(image);
    }
}

void move(float angle, float fac)
{
    camera.posX += cos((camera.rotY + angle) / 180.0f * M_PI) * fac;
    camera.posY += sin((camera.rotY + angle) / 180.0f * M_PI) * fac;
}

void specialKeyPressed(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_DOWN:
        break;
    case GLUT_KEY_RIGHT:
        break;
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_CTRL_L:
        break;
    }
}

void keyboard(unsigned char key, int x, int  y)
{
    if (key == 27) //esc key
      exit(0);
    keys[key] = true;
}

void keyboardUp(unsigned char key, int x, int y)
{
    keys[key] = false;
}

void mouse(int mouseX, int mouseY)
{
    int dx = mouseX - width / 2;
    int dy = mouseY - height / 2;

    if((dx != 0 || dy != 0) && abs(dx) < 100 && abs(dy) < 100)
    {
        camera.rotY += dx / 10.0f;
        camera.rotX += dy / 10.0f;
        glutWarpPointer(width / 2, height / 2);
    }
}

void display()
{
    Cube cube = Cube();

    glClearColor(0.9f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90.0f, width / (float)height, 0.1f, 50.0f);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glRotatef(camera.rotX, 1, 0, 0);
    glRotatef(camera.rotY, 0, 1, 0);
    glTranslatef(camera.posX, camera.posZ, camera.posY);

    textureBinder();
    
    for (int x = 0; x < 32; x++)
    {
        for (int y = 0; y < 32; y++)
        {
            for (int z = 0; z < 16; z++)
            {
                glTranslatef(-x, -y, -z);
                switch(world[x][y][z])
                {
                case -1:
                    break;
                case 1:
                    cube.drawGrassCube(TextureId);
                    break;
                case 2:
                    cube.drawStoneCube(TextureId);
                    break;
                default:
                    break;
                }
                glTranslatef(x, y, z);
            }
        }
    }

    glutSwapBuffers();
}

float lastTime = 0;
void idle()
{
    float currentTime = glutGet(GLUT_ELAPSED_TIME)/1000.0f;
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    const float speed = 3;
    if (keys['a']) move(0, deltaTime*speed);
    if (keys['d']) move(180, deltaTime*speed);
    if (keys['w']) move(90, deltaTime*speed);
    if (keys['s']) move(270, deltaTime*speed);

    glutPostRedisplay();
}


int main(int argc, char* argv[])
{
    for (int x = 0; x < 32; x++)
    {
        for (int y = 0; y < 32; y++)
        {
            for (int z = 0; z < 16; z++)
            {
                if (y == 15) world[x][y][z] = 1;
                else if (y > 15) world[x][y][z] = 2;
                else world[x][y][z] = -1;
            }
        }
    }

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInit(&argc, argv);
    glutCreateWindow("Hello OpenGL");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialKeyPressed);
    glutPassiveMotionFunc(mouse);
    //opengl init

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}