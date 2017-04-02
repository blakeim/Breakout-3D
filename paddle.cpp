#include "Paddle.h"


/*
 A paddle, moved by the user
*/
Paddle::Paddle()
{
	paddleY = -1.5;
	paddleX = -0.75;
	paddleZ = -2.385;

	//size of parts
	size = 0.05;

	//bounding dimensions
	minX = paddleX - size; //must be set initially
	maxX = paddleX + size; //or collisions are 
	minY = paddleY - size; //slightly broken
	maxY = paddleY + size;
	minZ = paddleZ - size;
	maxZ = paddleZ + size;
}

/*
 called on timerTicked
 set necessary states and
 build the sprite
 for ball and brick check collisions
*/
void Paddle::handleTick()
{
	//initial positions
	double x = paddleX; //same-thing
	double y = paddleY;
	double z = paddleZ;

	//paddle is only one level
	maxY = y + size; //so Y doesn't
	minY = y - size; //depend on parts
	
	//change the state to build the parts
	for(int i = 0; i < 9; i++)
	{
		drawPart(x,y,z);
		
		//change the state for each part
		switch(i)
		{
		case 0:
			x += 0.05; //draw the cube to the right of the middle
			maxX = x + size;
			break;
		case 1:
			x -= 0.10; //to the left of the middle
			minX = x - size;
			break;
		case 2:
			x = paddleX; //directly behind the middle
			z += 0.05;
			maxZ = z + size;
			break;
		case 3:
			x += 0.05; //directly behind the right
			break;
		case 4:
			x -= 0.10; //directly behind the left
			break;
		case 5:
			x = paddleX; //directly in front of the middle
			z -= 0.10;
			minZ = z - size;
			break;
		case 6:
			x += 0.05; //directly in front the right
			break;
		case 7:
			x -= 0.10; //directly in front the left
			break;
		default:
			break;
		}
	}

}

/*
 handle the colision of two objects
 colision is detected in parent class
 destroy bricks, bounce balls
*/
void Paddle::handleColision()
{
	//boop
}

void Paddle::keyPressed(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'a':
		if(paddleX > -0.95) paddleX -= 0.05;
		break;
	case 'w':
		if(paddleZ > -3.00) paddleZ -= 0.05;
		break;
	case 's':
		if(paddleZ < -2.00) paddleZ += 0.05;
		break;
	case 'd':
		if(paddleX < 0.95) paddleX += 0.05;
		break;
	}
}

/*
	builds a single part of the paddle,
	one cube didn't use display lists
	because the bounding box logic
	needed to accompany the drawing
	and this way was easier to write
*/
void Paddle::drawPart(double x, double y, double z)
{
	glLoadIdentity();
	glTranslatef(x,y,z);
	glColor3f(0.0, 1.0, 1.0);
	glutSolidCube(size);
}
