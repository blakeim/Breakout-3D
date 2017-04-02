#include "Brick.h"

Brick::Brick(GLfloat inx, GLfloat iny, GLfloat inz, double inr, double ing, double inb)
{
	size = 0.075;

	maxX = inx + size;
	maxY = iny + size;
	maxZ = inz + size;
	minX = inx - size;
	minY = iny - size;
	minZ = inz - size;

	x = inx;
	y = iny;
	z = inz;
	r = inr;
	g = ing;
	b = inb;

	destroyed = false;
	coliding = false;

}

/*
 called on timerTicked
 set necessary states and
 build the sprite
 for ball and brick check collisions
*/
void Brick::handleTick()
{
	if(coliding)handleColision();

	if(!destroyed)
	{
	glLoadIdentity();
	glTranslatef(x,y,z);
	glColor3f(r,g,b);
	glutSolidCube(size);
	}
		
}

/*
 handle the colision of two objects
 colision is detected in parent class
 destroy bricks, bounce balls
*/
void Brick::handleColision()
{
	destroyed = true; //stop it from drawing
	maxX = 999; //move the bounding box
	minX = 999; //'destroying' the brick
	coliding = false;
}
