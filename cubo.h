#ifndef CUBO_H
#define CUBO_H

#include <vector>

#include "quadrado.h"

class cubo
{
	public:
		cubo(){initializer();}
		virtual ~cubo();
		void draw();
		void drawBack();
		quadrado * findByBackColor(color col);
		void rotateup(quadrado quad);
		void rotatedown(quadrado quad);
		void rotateleft(quadrado quad);
		void rotateright(quadrado quad);
		//void mix();
	protected:
	private:
	    std::vector<quadrado> quads;
		void initializer();
};

#endif // CUBO_H
