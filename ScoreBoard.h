#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include"GameObject.h"
#include"util.h"
#include<sstream>
#include<string>
using namespace std;
class ScoreBoard:public GameObject
{
	protected:
	int noOfLives;
	int score;
	public:
	ScoreBoard();
	ScoreBoard(int,int);
	void setNooflives(int);
	void setScore(int);
	int getNooflives();
	int getScore();
	void draw();
};
#endif
