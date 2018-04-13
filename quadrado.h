#ifndef QUADRADO_H
#define QUADRADO_H

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#include "ext.h"

class quadrado
{
	public:
		quadrado(){}
		quadrado(coordinate coo,rotation rot,color col,color backcol);
		virtual ~quadrado();
		void addRotation(rotation r);
		void draw();
		void drawBack();
		coordinate getCoordinate(){return coo;}
		rotation getRotation(){return rot;}
		color getColor(){return col;}
		color getBackColor(){return backcol;}
		void setCoordinate(coordinate val){coo = val;}
		void setRotation(rotation val){rot = val;}
		void setColor(color val){col = val;}
		void setBackColor(color val){col = val;}
	protected:
	private:
	    coordinate coo;
	    rotation rot;
	    color col;
	    color backcol;
};

#endif // QUADRADO_H
