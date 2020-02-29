#include"Player.h"
Player::Player():MoveableObject()
{
	position.setX(0),position.setY(0);
	size=0,movement="\0";
}
Player::Player(int X,int Y)
{
	position.setX(X),position.setY(Y);
	size=20,movement="\0";
}
void Player::setSize(int Size)
{
	size=Size;
}
void Player::setMovement(string Movement)
{
	movement=Movement;
}
string Player::getMovement()
{
	return movement;
}
int Player::getPlayerX()
{
	return position.getX();
}
int Player::getPlayerY()
{
	return position.getY();
}
int Player::getSize()
{
	return size;
}
void Player::move()
{
	if(movement=="left")
	{
		int temp=position.getX();
		if(temp>5)
		{
			temp=position.getX();
			temp-=10;
			position.setX(temp);
		}
	}
	else if(movement=="right")
	{
		int temp=position.getX();
		if(temp<995)
		{
			temp=position.getX();
			temp+=10;
			position.setX(temp);
		}
	}
	else if(movement=="up")
	{
		int temp=position.getY();
		if(temp<150)
		{
			temp=position.getY();
			temp+=10;
			position.setY(temp);
		}
	}
	else if(movement=="down")
	{
		int temp=position.getY();
		if(temp>70)
		{
			temp=position.getY();
			temp-=10;
			position.setY(temp);
		}
	}
}
void Player::draw()
{
	DrawSquare(position.getX(),position.getY(),size,colors[MAROON]);
}
Player::~Player()
{
	position.setX(0),position.setY(0);
	size=0;
}
