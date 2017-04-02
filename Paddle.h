#ifndef blakeim_edu_jmu_cs_paddle_h
#define blakeim_edu_jmu_cs_paddle_h

#include "Sprite.h"

class Paddle: public Sprite
{
	public:
		Paddle();
		void handleTick();
		void keyPressed(unsigned char key, int x, int y);
		void handleColision();

	private:
		double speed;
		double paddleX;
		double paddleY;
		double paddleZ;
		void drawPart(double x, double y, double z);
		double size;
};


#endif
