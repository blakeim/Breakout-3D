
#ifndef blakeim_edu_jmu_cs_ball_h
#define blakeim_edu_jmu_cs_ball_h

#include "Sprite.h"

class Ball: public Sprite
{
	public:
		Ball();
		void handleTick();
		void handleColision();

	private:
		double x,y,z,stepSize;
		double tx,ty,tz; //trajectory points
		double lambda;
		double xs,ys,zs;
		int stepControlX, stepControlY, stepControlZ;
		double size;
		double dx,dy,dz;
};


#endif
