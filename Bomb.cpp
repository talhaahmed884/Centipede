#include"Bomb.h"
Bomb::Bomb()
{
	position.setX(0),position.setY(0),bomb_check="off";
}
Bomb::Bomb(int X, int Y,string Check)
{
	position.setX(X),position.setY(Y),bomb_check="off";
}
void Bomb::setBomb_check(string check)
{
	bomb_check=check;
}
void Bomb::setBombposition(int X,int Y)
{
	position.setX(X),position.setY(Y);
}
string Bomb::getBomb_check()
{
	return bomb_check;
}
void Bomb::draw()
{
	if(position.getY()>=1000)
	{
		bomb_check="off";
	}
	if(bomb_check=="on")
	{
		DrawLine(position.getX(), position.getY(), position.getX(), position.getY()+55, 3, colors[BLUE]);
		int temp=position.getY();
		temp+=20;
		position.setY(temp);
	}
}
void Bomb::destroyMushroom(Position *&Mushroom, int &Count, int*&hit,int &score)
{
	score=0;
	if(bomb_check=="on")
	{
		for(int a=0;a<Count;a++)
		{
			int tempX=position.getX(),tempY=position.getY();
			if((tempX>=Mushroom[a].getX()-10 && tempX<=Mushroom[a].getX()+20) && (tempY>=Mushroom[a].getY()-10) && tempY<=Mushroom[a].getY()+10)
			{
				bomb_check="off";
				position.setX(-10),position.setY(-10);
				hit[a]++;
				if(hit[a]>=2)
				{
					for(int b=a;b<Count-1;b++)
					{
						Mushroom[b].setX(Mushroom[b+1].getX());
						Mushroom[b].setY(Mushroom[b+1].getY());
					}
					Count--;
					hit[a]=0;
					score+=1;
				}
			}
		}
	}
}
