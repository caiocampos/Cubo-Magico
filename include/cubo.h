#ifndef CUBO_H
#define CUBO_H

#include <vector>

#include "quadrado.h"

class cubo
{
private:
    std::vector<quadrado> quads;
    void initializer();

public:

    cubo()
    {
        initializer();
    }
    virtual ~cubo();
    void draw();
    void drawBack();
    quadrado * findByBackColor(color col);
    void rotateup(quadrado quad);
    void rotatedown(quadrado quad);
    void rotateleft(quadrado quad);
    void rotateright(quadrado quad);
};

#endif // CUBO_H
