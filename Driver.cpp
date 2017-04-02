#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Stage.h"

static Stage main_stage;
static GLint delay;

/*
 keyboard call back
*/
void keyboard(unsigned char key, int x, int y)
{
	//escape key pressed then quit
	if(key == 27) exit(0);
	else main_stage.keyPressed(key, x, y);
}

/*
 iteratively set the parameters
 for the bricks and add them 
 to the stage
*/ 
void addBricks()
{
	double x,y,z;
	delay = 20;
	double randR, randB, randG;
	randR = ((double) rand() / double(RAND_MAX));
	randB = ((double) rand() / double(RAND_MAX));
	randG = ((double) rand() / double(RAND_MAX)); 
	x = -0.99;
	y = 0.99;
	z = 0.0;

	for(int i = 1; i <= 25; i++)
	{
		for(int i = 1; i <= 250; i++)
		{
			main_stage.addSprite(new Brick(x,y,z,randR,randB,randG));
		
			x += 0.080;

			if(i % 25 == 0)
			{
				y -= 0.080;
				x = -0.99;

			}
			randR = ((double) rand() / double(RAND_MAX));
			randB = ((double) rand() / double(RAND_MAX));
			randG = ((double) rand() / double(RAND_MAX)); 
		}
		
		x = -0.99;
		y = 0.99;
		z -= 0.080;
	}
}

/*
 adds the paddle to the
 stage
*/
void addPaddle()
{
	main_stage.addSprite(new Paddle());
}

/*
 adds the ball to the
 stage as a main actor
*/
void addBall()
{
	main_stage.addMainActor(new Ball());
}

/*
 display call back
*/
void display()
{	
	main_stage.paint();
}

/*
 timer call back
*/
void timer(int value)
{
	main_stage.onTimer();

	glutTimerFunc(delay, timer, 1);
}

/*
 adds the components
 and sets the states
 for the GL environment
*/
int main (int argc, char ** argv)
{
	addBricks();
	addBall();
	addPaddle();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Stage");
	glutFullScreen();
	//glutReshapeFunc(&main_stage->reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(delay,timer,0);

	main_stage.start();
}
