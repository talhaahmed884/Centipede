#ifndef BOMB_H_
#define BOMB_H_
#include"MoveableObject.h"
#include<string>
#include"util.h"
using namespace std;
class Bomb:public MoveableObject
{
	protected:
	string bomb_check;
	public:
	Bomb();
	Bomb(int,int,string);
	void setBomb_check(string);
	string getBomb_check();
	void setBombposition(int,int);
	void draw();
	void move(){};
	void destroyMushroom(Position *&,int&,int*&,int&);
};
#endif
