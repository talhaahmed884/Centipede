#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include"GameObject.h"
#include"util.h"
#include<iostream>
using namespace std;
class Mushroom:public GameObject
{
	protected:
	int count;
	Position *position;
	int width,height;
	int *hit;
	int score;
	public:
	Mushroom();
	Mushroom(int,int,int);
	virtual Position *&getMushroomposition();
	int &getCount();
	void draw();
	int &getScore();
	int *&getHit();
};
#endif
