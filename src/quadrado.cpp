#include "quadrado.h"

quadrado::quadrado(coordinate coo, rotation rot, color col, color backcol)
{
    this->coo = coo;
    this->rot = rot;
    this->col = col;
    this->backcol = backcol;
}

quadrado::~quadrado()
{
    coo.x = coo.y = coo.z = 0;
    rot.x = rot.y = rot.z = 0;
    col.r = col.g = col.b = 0;
    backcol.r = backcol.g = backcol.b = 0;
}

void quadrado::addRotation(rotation r)
{
    rot.x += r.x;
    if (rot.x > 360) rot.x -= 360;
    if (rot.x < 0) rot.x += 360;
    rot.y += r.y;
    if (rot.y > 360) rot.y -= 360;
    if (rot.y < 0) rot.y += 360;
    rot.z += r.z;
    if (rot.z > 360) rot.z -= 360;
    if (rot.z < 0) rot.z += 360;
}

void quadrado::draw()
{
    glPushMatrix();
    glRotated(rot.y, 1, 0, 0);
    glRotated(rot.x, 0, 1, 0);
    glRotated(rot.z, 0, 0, 1);
    glTranslated(coo.x, coo.y, 3);
    glColor3ub(col.r, col.g, col.b);
    glBegin(GL_QUADS);
    glVertex3f(-0.95, -0.95, 0);
    glVertex3f(-0.95, 0.95, 0);
    glVertex3f(0.95, 0.95, 0);
    glVertex3f(0.95, -0.95, 0);
    glEnd();
    glPopMatrix();
}

void quadrado::drawBack()
{
    glPushMatrix();
    glRotated(rot.y, 1, 0, 0);
    glRotated(rot.x, 0, 1, 0);
    glRotated(rot.z, 0, 0, 1);
    glTranslated(coo.x, coo.y, 3);
    glColor3ub(backcol.r, backcol.g, backcol.b);
    glBegin(GL_QUADS);
    glVertex3f(-0.95, -0.95, 0);
    glVertex3f(-0.95, 0.95, 0);
    glVertex3f(0.95, 0.95, 0);
    glVertex3f(0.95, -0.95, 0);
    glEnd();
    glPopMatrix();
}
