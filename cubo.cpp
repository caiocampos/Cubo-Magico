#include "cubo.h"

cubo::~cubo()
{
	quads.clear();
}

void cubo::initializer()
{
	color vcolor[] = {color(255,0,0),color(255,255,255),color(255,255,0),color(0,255,0),color(255,127,0),color(0,0,255)};
	int i = 0, col;
	double rot_y;
	// direita laranja
	quads.push_back(quadrado(coordinate(-2,2,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(0,2,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(2,2,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(-2,0,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(0,0,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(2,0,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(-2,-2,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(0,-2,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(2,-2,0),rotation(90,0,0),vcolor[4],color(++i,0,0)));
	// esquerda azul
	quads.push_back(quadrado(coordinate(-2,2,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(0,2,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(2,2,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(-2,0,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(0,0,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(2,0,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(-2,-2,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(0,-2,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	quads.push_back(quadrado(coordinate(2,-2,0),rotation(270,0,0),vcolor[5],color(++i,0,0)));
	//outros lados
	for(rot_y = 0, col = 0; rot_y < 360; rot_y += 90, col++)
	{
		quads.push_back(quadrado(coordinate(-2,2,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(0,2,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(2,2,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(-2,0,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(0,0,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(2,0,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(-2,-2,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(0,-2,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
		quads.push_back(quadrado(coordinate(2,-2,0),rotation(0,rot_y,0),vcolor[col],color(++i,0,0)));
	}
}

void cubo::draw()
{
    for(unsigned int i = 0; i < quads.size(); i++)
        quads[i].draw();
}

void cubo::drawBack()
{
    for(unsigned int i = 0; i < quads.size(); i++)
        quads[i].drawBack();
}

quadrado * cubo::findByBackColor(color col)
{
    for(unsigned int i = 0; i < quads.size(); i++)
        if(quads[i].getBackColor().equals(col))
            return &(quads[i]);
    return NULL;
}

void cubo::rotateup(quadrado quad)
{
	unsigned int i;
	if(quad.getCoordinate().x == 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().x == 90);
			else if(quads[i].getRotation().x == 270);
			else if(quads[i].getCoordinate().x == quad.getCoordinate().x)
				quads[i].addRotation(rotation(0,-2,0));
        }
        return;
	}
	if(quad.getCoordinate().x > 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().x == 90)
				quads[i].addRotation(rotation(0,-2,0));
			else if(quads[i].getRotation().x == 270);
			else if(quads[i].getCoordinate().x == quad.getCoordinate().x)
				quads[i].addRotation(rotation(0,-2,0));
        }
		return;
	}
	if(quad.getCoordinate().x < 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().x == 270)
				quads[i].addRotation(rotation(0,-2,0));
			else if(quads[i].getRotation().x == 90);
			else if(quads[i].getCoordinate().x == quad.getCoordinate().x)
				quads[i].addRotation(rotation(0,-2,0));
        }
		return;
	}
}

void cubo::rotatedown(quadrado quad)
{
	unsigned int i;
	if(quad.getCoordinate().x == 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().x == 90);
			else if(quads[i].getRotation().x == 270);
			else if(quads[i].getCoordinate().x == quad.getCoordinate().x)
				quads[i].addRotation(rotation(0,2,0));
        }
		return;
	}
	if(quad.getCoordinate().x > 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().x == 90)
				quads[i].addRotation(rotation(0,2,0));
			else if(quads[i].getRotation().x == 270);
			else if(quads[i].getCoordinate().x == quad.getCoordinate().x)
				quads[i].addRotation(rotation(0,2,0));
        }
		return;
	}
	if(quad.getCoordinate().x < 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().x == 270)
				quads[i].addRotation(rotation(0,2,0));
			else if(quads[i].getRotation().x == 90);
			else if(quads[i].getCoordinate().x == quad.getCoordinate().x)
				quads[i].addRotation(rotation(0,2,0));
        }
		return;
	}
}

void cubo::rotateleft(quadrado quad)
{
	unsigned int i;
	if(quad.getCoordinate().y == 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().y == 90);
			else if(quads[i].getRotation().y == 270);
			else if(quads[i].getRotation().y == 180)
			{
				if(quads[i].getCoordinate().y == -quad.getCoordinate().y)
					quads[i].addRotation(rotation(2,0,0));
			}
			else if(quads[i].getCoordinate().y == quad.getCoordinate().y)
				quads[i].addRotation(rotation(-2,0,0));
        }
		return;
	}
	if(quad.getCoordinate().y > 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().y == 270)
				quads[i].addRotation(rotation(0,0,-2));
			else if(quads[i].getRotation().y == 90);
			else if(quads[i].getRotation().y == 180)
			{
				if(quads[i].getCoordinate().y == -quad.getCoordinate().y)
					quads[i].addRotation(rotation(2,0,0));
			}
			else if(quads[i].getCoordinate().y == quad.getCoordinate().y)
				quads[i].addRotation(rotation(-2,0,0));
        }
		return;
	}
	if(quad.getCoordinate().y < 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().y == 90)
				quads[i].addRotation(rotation(0,0,2));
			else if(quads[i].getRotation().y == 270);
			else if(quads[i].getRotation().y == 180)
			{
				if(quads[i].getCoordinate().y == -quad.getCoordinate().y)
					quads[i].addRotation(rotation(2,0,0));
			}
			else if(quads[i].getCoordinate().y == quad.getCoordinate().y)
				quads[i].addRotation(rotation(-2,0,0));
        }
		return;
	}
}

void cubo::rotateright(quadrado quad)
{
	unsigned int i;
	if(quad.getCoordinate().y == 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().y == 90);
			else if(quads[i].getRotation().y == 270);
			else if(quads[i].getRotation().y == 180)
			{
				if(quads[i].getCoordinate().y == -quad.getCoordinate().y)
					quads[i].addRotation(rotation(-2,0,0));
			}
			else if(quads[i].getCoordinate().y == quad.getCoordinate().y)
				quads[i].addRotation(rotation(2,0,0));
        }
		return;
	}
	if(quad.getCoordinate().y > 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().y == 270)
				quads[i].addRotation(rotation(0,0,2));
			else if(quads[i].getRotation().y == 90);
			else if(quads[i].getRotation().y == 180)
			{
				if(quads[i].getCoordinate().y == -quad.getCoordinate().y)
					quads[i].addRotation(rotation(-2,0,0));
			}
			else if(quads[i].getCoordinate().y == quad.getCoordinate().y)
				quads[i].addRotation(rotation(2,0,0));
        }
		return;
	}
	if(quad.getCoordinate().y < 0)
	{
		for(i = 0; i < quads.size(); i++)
        {
            if(quads[i].getRotation().y == 90)
				quads[i].addRotation(rotation(0,0,-2));
			else if(quads[i].getRotation().y == 270);
			else if(quads[i].getRotation().y == 180)
			{
				if(quads[i].getCoordinate().y == -quad.getCoordinate().y)
					quads[i].addRotation(rotation(-2,0,0));
			}
			else if(quads[i].getCoordinate().y == quad.getCoordinate().y)
				quads[i].addRotation(rotation(2,0,0));
        }
		return;
	}
}
