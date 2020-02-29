#ifndef PLAYER_H_
#define PLAYER_H_
#include"util.h"
#include<string>
#include"MoveableObject.h"
class Player:public MoveableObject
{
	protected:
	int size;
	string movement;
	public:
	Player();
	Player(int,int);
	void setSize(int);
	void setMovement(string);
	string getMovement();
	int getPlayerX();
	int getPlayerY();
	int getSize();
	void move();
	void draw();
	~Player();
};
#endif
