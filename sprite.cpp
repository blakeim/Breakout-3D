#include "Sprite.h"


/*
 does nothing in parent
*/
void Sprite::keyPressed(unsigned char key, int x, int y)
{
}

/*
 invoke timer events
 handled by children
*/
void Sprite::timerTicked()
{
	glPushMatrix();
	handleTick();
	glPopMatrix();
}

/*
 detect colisions
 return true if this colides 
 with s, false otherwise
*/
bool Sprite::colides(Sprite* s)
{
	if((minX <= s->maxX && minX >= s->minX) 
		|| (maxX <= s->maxX && maxX >= s->minX))
			if((minY <= s->maxY && minY >= s->minY) 
				|| (maxY <= s->maxY && maxY >= s->minY))
					if((minZ <= s->maxZ && minZ >= s->minZ) 
						|| (maxZ <= s->maxZ && maxZ >= s->minZ))
						{
							return true;
						}
	return false;
}
