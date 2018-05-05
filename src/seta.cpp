#include "seta.h"

seta::seta(int dir, coordinate coo, rotation rot, color col, color backcol)
{
    this->dir = dir;
    this->coo = coo;
    this->rot = rot;
    this->col = col;
    this->backcol = backcol;
}

seta::~seta()
{
    dir = 0;
    coo.x = coo.y = coo.z = 0;
    rot.x = rot.y = 0;
    col.r = col.g = col.b = 0;
    backcol.r = backcol.g = backcol.b = 0;
}

void seta::draw()
{
    glPushMatrix();
    glRotated(rot.y, 1, 0, 0);
    glRotated(rot.x, 0, 1, 0);
    glRotated(rot.z, 0, 0, 1);
    glTranslated(coo.x, coo.y, 3.5);
    glColor3ub(col.r, col.g, col.b);
    glRotated(dir * 90, 0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.5, 0.2, 0);
    glVertex3f(0.7, 0.2, 0);
    glVertex3f(0.7, -0.2, 0);
    glVertex3f(0.5, -0.2, 0);
    glVertex3f(0.7, 0, 0);
    glVertex3f(0.7, 0.4, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0.7, -0.4, 0);
    glEnd();
    glPopMatrix();
}

void seta::drawBack()
{
    glPushMatrix();
    glRotated(rot.y, 1, 0, 0);
    glRotated(rot.x, 0, 1, 0);
    glRotated(rot.z, 0, 0, 1);
    glTranslated(coo.x, coo.y, 4);
    glColor3ub(backcol.r, backcol.g, backcol.b);
    glRotated(dir * 90, 0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.5, 0.2, 0);
    glVertex3f(0.7, 0.2, 0);
    glVertex3f(0.7, -0.2, 0);
    glVertex3f(0.5, -0.2, 0);
    glVertex3f(0.7, 0, 0);
    glVertex3f(0.7, 0.4, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0.7, -0.4, 0);
    glEnd();
    glPopMatrix();
}
