#include "Ball.h"
#include <math.h>

/*
 A ball that bounces off of objects
 If the ball leaves the field of view
 (hits the edge) it will bounce
*/
Ball::Ball()
{
	//position
	xs = -0.05;
	ys = -0.05;
	zs = -3.0;
	//trajectory
	tx = -0.05;
	ty = 1.0;
	tz = -3.0;
	
 

	x = xs; 	//has to start at
	y = ys;		//innitial possition 
	z = zs;     //theres some skipping

	//other stuff
	stepSize = 0.00025; //speed
	lambda = 0;
	//determine subtract/add for deltas
	stepControlY = 1;  
	stepControlX = 1;
	stepControlZ = 1;
	coliding = false;
	size = 0.025;

	//bounding dimensions
	minX = xs - size;
	maxX = xs + size;
	minY = ys - size;
	maxY = ys + size;
	minZ = zs - size;
	maxZ = zs + size;
}

/*
 called on timerTicked
 set necessary states and
 build the sprite
 for ball and brick check collisions
*/
void Ball::handleTick()
{	
	//check collisions before moving
	if(coliding)
	{
		handleColision();
	}

	dx = (xs * lambda + tx * lambda);
	dy = (ys * lambda + ty * lambda);
	dz = (zs * lambda + tz * lambda);
	
	x += dx * stepControlX;
	y += dy * stepControlY;
	z += dz * stepControlZ;

	//check edge collisions/top collision
	if(x >= 1.0 || x <= -1.0)
		handleColision();
	if(z >= -1.5 || z <= -3.2)
		handleColision();
	if(y >= 1.0)
		handleColision();


	//if the ball goes too low
	//reset it (mostly for demo)
	if(y <= -2.5) 
	{
	x = xs;
	y = ys;
	z = zs;
	}

	glLoadIdentity();
	glTranslatef(x,y,z);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(size,16,16);
	
	//move the bounding dimensions
	minX = x - size;
	maxX = x + size;
	minY = y - size;
	maxY = y + size;
	minZ = z - size;
	maxZ = z + size;

	lambda += (stepSize);
}

/*
 handle the colision of two objects
 colision is detected in parent class
 destroy bricks, bounce balls
*/
void Ball::handleColision()
{
	//stepControl *= -1;
	double px,py,pz;

	//handle various reflection cases
	if(x >= 1.0 || x <= -1.0)
	{
		stepControlX *= -1;
	}
	if(z >= -1.5 || z <= -3.2)
	{
		stepControlZ *= -1;
	}
	else
		stepControlY *= -1;


	//move the ball immediately
	dx = (xs * lambda + tx * lambda); //stops it from getting stuck 
	dy = (ys * lambda + ty * lambda); //the paddle
	dz = (zs * lambda + tz * lambda);
	x += dx * stepControlX;
	y += dy * stepControlY;
	z += dz * stepControlZ;
	
	lambda = 0.0;
	coliding = false;
}
