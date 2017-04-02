#include "Stage.h"

/*
 constructor for a stage object
 sets some lighting stuff
*/
Stage::Stage()
{
	light0Position[0] = 0.0; 
	light0Position[1] = 0.0;
	light0Position[2] = 1.0;
	light0Position[3] = 1.0;

	colorWhite[0] = 1.0;
	colorWhite[1] = 1.0;
	colorWhite[2] = 1.0;
	colorWhite[3] = 1.0;

	size = 0;
}

/*
 destructor for stage
*/
Stage::~Stage()
{
	//do this later, delete all sprites
	//since ending the stage means ending
	//the game, is that necessary?
}

/*
 adds sprites to the stage
*/
void Stage::addSprite(Sprite* s)
{
	if(size < MAX_SPRITES)
	{
		sprite[size] = s;
		size++;
	}
}

/*
 initialize the states for lighting
 shading and the view projection
*/
void Stage::init()
{

	glShadeModel(GL_SMOOTH);

	//lighting
	GLfloat lightingmodelAmbeint[] = {0.2,0.2,0.2,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightingmodelAmbeint);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, colorWhite);
	glLightfv(GL_LIGHT0, GL_SPECULAR, colorWhite);

	//enable the lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	//do the view transform
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90.0, 0.75, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(-0.75,-1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);
}

/*
 keyboard callback
*/
void Stage::keyPressed(unsigned char key, int x, int y)
{
	//little trick could use something
	//similar to main to indicate the listening
	//sprite
	sprite[size - 1]->keyPressed(key, x, y);
}

/*
 timer callback
 clears the stage, checks colisions
 and invokes all sprites handleTicks
*/
void Stage::onTimer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	collision();

	for(int i = 0; i < size; i++)
		sprite[i]->timerTicked();
	
	//glLoadIdentity();
	glutPostRedisplay();
}

/*
 draws the stage
*/
void Stage::paint()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	glutSwapBuffers();
}

/*
 reshape/size the stage
 and the objects in it
*/
void Stage::reshape(int width, int height)
{
	//since we're full-screening maybe don't do
	//anything here, but keep this stub here
	//so that we can learn from our mistakes
	//not resizing the graphics is sloppy
}

/*
 initialize the stage
 and start the render-loop
*/
void Stage::start()
{
	init();
	glutMainLoop();
}

/*
 iterate through each sprite
 and see if its coliding
 with the main actor
*/
void Stage::collision()
{
	for(int i = 0; i < size; i++)
	{
		if(i != main)
		{
			if(sprite[main]->colides(sprite[i]))
			{	
				sprite[main]->coliding = true;
				sprite[i]->coliding = true;
				//size = 0;
			}
		}
	}
}

/*
 adds an actor that will be the
 one coliding with everyone
 cheeky bit of optimization
 to keep from having to iterate 
 through everything n times.
*/
void Stage::addMainActor(Sprite* s)
{
	main = size;
	addSprite(s);
}
