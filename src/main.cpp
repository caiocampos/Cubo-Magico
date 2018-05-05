#include <cstdlib>
#include <cstdio>

#include "cubo.h"
#include "seta.h"

#define render 1
#define click 2

using namespace std;

enum vals
{
    null, selected, rotup, rotdown, rotleft, rotright
};

vals state = null;
float ang_x = 0, ang_y = 0;
cubo c;
quadrado * q = NULL;
int rot;
vector<seta> setas;
int mousex, mousey;
int mode = render;

void keys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
    }
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        ang_x++;
        break;
    case GLUT_KEY_UP:
        ang_y++;
        break;
    case GLUT_KEY_LEFT:
        ang_x--;
        break;
    case GLUT_KEY_DOWN:
        ang_y--;
        break;
    }
    glutPostRedisplay();
}

void changeSize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double) w / (double) h, 1.0, 200);
    gluLookAt(0, 0, 30, 0, 0, 0, 0, 1, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    mousex = x;
    mousey = y;
    mode = click;
}

void select()
{
    GLint viewport[4];
    GLubyte pixel[3];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glReadPixels(mousex, viewport[3] - mousey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, (void *) pixel);
    if (pixel[0] != 0)
    {
        q = c.findByBackColor(color(pixel[0], pixel[1], pixel[2]));
        if (!q) return;
        setas.clear();
        setas.push_back(seta(0, q->getCoordinate(), q->getRotation(), color(255, 0, 255), color(0, 1, 0)));
        setas.push_back(seta(1, q->getCoordinate(), q->getRotation(), color(255, 0, 255), color(0, 2, 0)));
        setas.push_back(seta(2, q->getCoordinate(), q->getRotation(), color(255, 0, 255), color(0, 3, 0)));
        setas.push_back(seta(3, q->getCoordinate(), q->getRotation(), color(255, 0, 255), color(0, 4, 0)));
        state = selected;
    }
    else if (pixel[1] != 0)
    {
        if (!q) return;
        if (pixel[1] == 1)
        {
            setas.clear();
            state = rotright;
        }
        if (pixel[1] == 2)
        {
            setas.clear();
            state = rotdown;
        }
        if (pixel[1] == 3)
        {
            setas.clear();
            state = rotleft;
        }
        if (pixel[1] == 4)
        {
            setas.clear();
            state = rotup;
        }
    }
    else
    {
        setas.clear();
        q = NULL;
        state = null;
    }
}

void drawCube()
{
    if (mode == render)
    {
        switch (state)
        {
        case selected:
            for (int j = 0; j < 4; j++) setas[j].draw();
            break;
        case rotup:
            if (rot < 45)
            {
                c.rotateup(*q);
                rot++;
            }
            else
            {
                state = null;
                rot = 0;
            }
            break;
        case rotdown:
            if (rot < 45)
            {
                c.rotatedown(*q);
                rot++;
            }
            else
            {
                state = null;
                rot = 0;
            }
            break;
        case rotleft:
            if (rot < 45)
            {
                c.rotateleft(*q);
                rot++;
            }
            else
            {
                state = null;
                rot = 0;
            }
            break;
        case rotright:
            if (rot < 45)
            {
                c.rotateright(*q);
                rot++;
            }
            else
            {
                state = null;
                rot = 0;
            }
            break;
        case null: break;
        }
        c.draw();
        glutSwapBuffers();
    }
    else
    {
        switch (state)
        {
        case selected:
            for (int j = 0; j < 4; j++) setas[j].drawBack();
            c.drawBack();
            select();
            break;
        case null:
            c.drawBack();
            select();
            break;
        case rotup: break;
        case rotdown: break;
        case rotleft: break;
        case rotright: break;
        }
        mode = render;
    }
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0, 0, 0, 0);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-ang_x, 0, 1, 0);
    glRotatef(-ang_y, 1, 0, 0);
    drawCube();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("cubo magico");
    initRendering();
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutKeyboardFunc(keys);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
