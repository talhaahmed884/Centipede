#include"Mushroom.h"
Mushroom::Mushroom()
{
	count=30;
	width=20,height=10;
	position=new Position[count];
	for(int a=0;a<count;a++)
	{
		int tempX1=GetRandInRange(20,1000);
		int tempY1=GetRandInRange(170,1000);
		if(tempX1%10!=0)
		{
			int temp=tempX1%10;
			temp=10-temp;
			tempX1+=temp;
			if(tempX1>1000)
			{
				tempX1-=10;
			}
			else if(tempX1<20)
			{
				tempX1+=10;
			}
		}
		if(tempY1%10!=0)
		{
			int temp=tempY1%10;
			temp=10-temp;
			tempY1+=temp;
			if(tempY1>1000)
			{
				tempY1-=10;
			}
			else if(tempY1<100)
			{
				tempY1+=10;
			}
		}
		position[a].setX(tempX1);
		position[a].setY(tempY1);
	}
	hit=new int[count];
	score=0;
}
Mushroom::Mushroom(int Count,int Width, int Height)
{
	count=Count;
	width=Width,height=Height;
	position=new Position[count];
	for(int a=0;a<count;a++)
	{
		int tempX1=GetRandInRange(20,1000);
		int tempY1=GetRandInRange(170,1000);
		if(tempX1%10!=0)
		{
			int temp=tempX1%10;
			temp=10-temp;
			tempX1+=temp;
			if(tempX1>1000)
			{
				tempX1-=10;
			}
			else if(tempX1<20)
			{
				tempX1+=10;
			}
		}
		if(tempY1%10!=0)
		{
			int temp=tempY1%10;
			temp=10-temp;
			tempY1+=temp;
			if(tempY1>1000)
			{
				tempY1-=10;
			}
			else if(tempY1<100)
			{
				tempY1+=10;
			}
		}
		position[a].setX(tempX1);
		position[a].setY(tempY1);
	}
	hit=new int [Count];
	score=0;
}
void Mushroom::draw()
{
	for(int a=0;a<count;a++)
	{
		DrawRectangle(position[a].getX(), position[a].getY(), width, height, colors[BLUE]);
	}
}
int &Mushroom::getCount()
{
	return count;
}
int &Mushroom::getScore()
{
	return score;
}
Position *&Mushroom::getMushroomposition()
{
	return position;
}
int *&Mushroom::getHit()
{
	return hit;
}
