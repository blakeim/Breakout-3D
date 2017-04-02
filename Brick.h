#ifndef blakeim_edu_jmu_cs_brick_h
#define blakeim_edu_jmu_cs_brick_h


#include "Sprite.h"

class Brick: public Sprite
{
	public:
		Brick(GLfloat inx, GLfloat iny, GLfloat inz, double inr, double ing, double inb);
		void handleTick();
		void handleColision();

	private:
		//GLfloat SIZE = 0.5;
		GLfloat x; 
		GLfloat y; 
		GLfloat z; 
		double r; 
		double g; 
		double b;
		double size;
		bool destroyed;
};


#endif
