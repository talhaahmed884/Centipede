#include"ScoreBoard.h"
ScoreBoard::ScoreBoard()
{
	score=0,noOfLives=3;
}
ScoreBoard::ScoreBoard(int Lives,int Score)
{
	noOfLives=Lives;
	score=Score;
}
void ScoreBoard::setNooflives(int Lives)
{
	noOfLives=Lives;
}
void ScoreBoard::setScore(int Score)
{
	score+=Score;
}
int ScoreBoard::getNooflives()
{
	return noOfLives;
}
int ScoreBoard::getScore()
{
	return score;
}
void ScoreBoard::draw()
{
	stringstream tostr;
	tostr.clear();
	DrawLine(50, 60, 950, 60, 3, colors[BLUE]);
	tostr<<score;
	DrawString(2250, 65, 5, 5, tostr.str(), colors[YELLOW]);
	int temp=50;
	for(int a=0;a<noOfLives;a++)
	{
		DrawSquare(temp, 30, 20, colors[SILVER]);
		temp+=30;
	}
}
