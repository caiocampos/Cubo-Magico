#ifndef SETA_H
#define SETA_H

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#include "ext.h"

class seta
{
private:
    int dir;
    coordinate coo;
    rotation rot;
    color col;
    color backcol;

public:

    seta()
    {
    }
    seta(int dir, coordinate coo, rotation rot, color col, color backcol);
    virtual ~seta();
    void draw();
    void drawBack();

    int GetDirection()
    {
        return dir;
    }

    coordinate GetCoordinate()
    {
        return coo;
    }

    rotation GetRotation()
    {
        return rot;
    }

    color GetColor()
    {
        return col;
    }

    color GetBackColor()
    {
        return col;
    }

    void SetDirection(int val)
    {
        dir = val;
    }

    void SetCoordinate(coordinate val)
    {
        coo = val;
    }

    void SetRotation(rotation val)
    {
        rot = val;
    }

    void SetColor(color val)
    {
        col = val;
    }

    void SetBackColor(color val)
    {
        backcol = val;
    }
};

#endif // SETA_H
