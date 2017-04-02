#ifndef blakeim_edu_jmu_cs_sprite_h
#define blakeim_edu_jmu_cs_sprite_h

#include "GL/glut.h"

class Sprite
{
public:
	virtual void handleTick() = 0;

	virtual void keyPressed(unsigned char key, int x, int y);

			bool colides(Sprite* s);

			void timerTicked();

	double minX,minY,minZ;
	double maxX,maxY,maxZ;
	bool coliding;
	char * type;
};
#endif
