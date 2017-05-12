#include "Cube.h"
float spriteSize = 1.0f;

void Cube::drawGrassCube(GLuint textureId)
{
    GLfloat row = 1.0 / 16;
    GLfloat column = 1.0 / 16;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);

    // top
    glTexCoord2f(0 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(column, row); glVertex3f(0, 0, -1);
    glTexCoord2f(0 * column, row); glVertex3f(-1, 0, -1);

    // front
    glTexCoord2f(3 * column, row); glVertex3f(0, -1, 0);
    glTexCoord2f(3 * column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(4 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(4 * column, row); glVertex3f(-1, -1, 0);

    // right
    glTexCoord2f(3 * column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(4 * column, 0 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(4 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(3 * column, row); glVertex3f(0, -1, 0);

    // left
    glTexCoord2f(4 * column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(3 * column, row); glVertex3f(-1, -1, 0);
    glTexCoord2f(3 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(4 * column, 0 * row); glVertex3f(-1, 0, -1);

    // bottom
    glTexCoord2f(2 * column, 0 * row); glVertex3f(0, -1, -1);
    glTexCoord2f(3 * column, 0 * row); glVertex3f(-1, -1, -1);
    glTexCoord2f(3 * column, row); glVertex3f(-1, -1, 0);
    glTexCoord2f(2 * column, row); glVertex3f(0, -1, 0);

    // back
    glTexCoord2f(4 * column, 0 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(4 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(3 * column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(3 * column, 0 * row); glVertex3f(-1, 0, -1);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Cube::drawStoneCube(GLuint textureId)
{
    GLfloat row = 1.0 / 16;
    GLfloat column = 1.0 / 16;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);

    // top
    glTexCoord2f(column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(2 * column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(2 * column, row); glVertex3f(0, 0, -1);
    glTexCoord2f(column, row); glVertex3f(-1, 0, -1);

    // front
    glTexCoord2f(column, row); glVertex3f(0, -1, 0);
    glTexCoord2f(column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(2 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(2 * column, row); glVertex3f(-1, -1, 0);

    // right
    glTexCoord2f(column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(2 * column, 0 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(2 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(column, row); glVertex3f(0, -1, 0);

    // left
    glTexCoord2f(2 * column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(column, row); glVertex3f(-1, -1, 0);
    glTexCoord2f(column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(2 * column, 0 * row); glVertex3f(-1, 0, -1);

    // bottom
    glTexCoord2f(column, 0 * row); glVertex3f(0, -1, -1);
    glTexCoord2f(2 * column, 0 * row); glVertex3f(-1, -1, -1);
    glTexCoord2f(2 * column, row); glVertex3f(-1, -1, 0);
    glTexCoord2f(column, row); glVertex3f(0, -1, 0);

    // back
    glTexCoord2f(2 * column, 0 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(2 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(column, 0 * row); glVertex3f(-1, 0, -1);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Cube::drawWaterCube(GLuint textureId)
{
    GLfloat row = 1.0 / 16;
    GLfloat column = 1.0 / 16;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);

    // top
    glTexCoord2f(14 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(15 * column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(15 * column, row); glVertex3f(0, 0, -1);
    glTexCoord2f(14 * column, row); glVertex3f(-1, 0, -1);

    // front
    glTexCoord2f(14 * column, row); glVertex3f(0, -1, 0);
    glTexCoord2f(14 * column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(15 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(15 * column, row); glVertex3f(-1, -1, 0);

    // right
    glTexCoord2f(14 * column, 0 * row); glVertex3f(0, 0, 0);
    glTexCoord2f(15 * column, 0 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(15 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(14 * column, row); glVertex3f(0, -1, 0);

    // left
    glTexCoord2f(15 * column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(14 * column, row); glVertex3f(-1, -1, 0);
    glTexCoord2f(14 * column, 0 * row); glVertex3f(-1, 0, 0);
    glTexCoord2f(15 * column, 0 * row); glVertex3f(-1, 0, -1);

    // bottom
    glTexCoord2f(14 * column, 0 * row); glVertex3f(0, -1, -1);
    glTexCoord2f(15 * column, 0 * row); glVertex3f(-1, -1, -1);
    glTexCoord2f(15 * column, row); glVertex3f(-1, -1, 0);
    glTexCoord2f(14 * column, row); glVertex3f(0, -1, 0);

    // back
    glTexCoord2f(15 * column, 0 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(15 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(14 * column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(14 * column, 0 * row); glVertex3f(-1, 0, -1);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Cube::drawSandCube(GLuint textureId)
{
    GLfloat row = 1.0 / 16;
    GLfloat column = 1.0 / 16;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);

    // top
    glTexCoord2f(2 * column, row); glVertex3f(-1, 0, 0);
    glTexCoord2f(3 * column, row); glVertex3f(0, 0, 0);
    glTexCoord2f(3 * column, 2 * row); glVertex3f(0, 0, -1);
    glTexCoord2f(2 * column, 2 * row); glVertex3f(-1, 0, -1);

    // front
    glTexCoord2f(2 * column, 2 * row); glVertex3f(0, -1, 0);
    glTexCoord2f(2 * column, row); glVertex3f(0, 0, 0);
    glTexCoord2f(3 * column, row); glVertex3f(-1, 0, 0);
    glTexCoord2f(3 * column, 2 * row); glVertex3f(-1, -1, 0);

    // right
    glTexCoord2f(2 * column, row); glVertex3f(0, 0, 0);
    glTexCoord2f(3 * column, row); glVertex3f(0, 0, -1);
    glTexCoord2f(3 * column, 2 * row); glVertex3f(0, -1, -1);
    glTexCoord2f(2 * column, 2 * row); glVertex3f(0, -1, 0);

    // left
    glTexCoord2f(3 * column, 2 * row); glVertex3f(-1, -1, -1);
    glTexCoord2f(2 * column, 2 * row); glVertex3f(-1, -1, 0);
    glTexCoord2f(2 * column, row); glVertex3f(-1, 0, 0);
    glTexCoord2f(3 * column, row); glVertex3f(-1, 0, -1);

    // bottom
    glTexCoord2f(2 * column, row); glVertex3f(0, -1, -1);
    glTexCoord2f(3 * column, row); glVertex3f(-1, -1, -1);
    glTexCoord2f(3 * column, 2 * row); glVertex3f(-1, -1, 0);
    glTexCoord2f(2 * column, 2 * row); glVertex3f(0, -1, 0);

    // back
    glTexCoord2f(3 * column, row); glVertex3f(0, 0, -1);
    glTexCoord2f(3 * column, 2 * row); glVertex3f(0, -1, -1);
    glTexCoord2f(2 * column, 2 * row); glVertex3f(-1, -1, -1);
    glTexCoord2f(2 * column, row); glVertex3f(-1, 0, -1);

    glEnd();
}



