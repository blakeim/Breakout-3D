#ifndef blakeim_edu_jmu_cs_Stage_h
#define blakeim_edu_jmu_cs_Stage_h

#include <stdlib.h>
#include "GL/glut.h"
#include "Sprite.h"
#define MAX_SPRITES 125100

class Stage
{

public:
	Stage();
	void addSprite(Sprite* s);
	void keyPressed(unsigned char key, int x, int y);
	void mouseClicked(int button, int state, int x, int y, int id);
	void onTimer();
	void paint();
	void reshape(int width, int height);
	void start();
	void addMainActor(Sprite* s);
	~Stage();

private:
	int size;
	int main;
	GLfloat light0Position[4];
	GLfloat colorWhite[4];
	Sprite* sprite[MAX_SPRITES];
	void collision();

	void init();
};
#endif
