#ifndef _BOARD_H_
#define _BOARD_H_
#include <GL/glut.h>
#include <iostream>
#include "util.h"
using namespace std;
class Board
{
	private:
	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;
	public:
	static const int BOARD_X = 17;
	static const int BOARD_Y = 14;
	int board_array[BOARD_Y][BOARD_X];
	Board(int xsize = 8, int ysize = 8);
	~Board(void);
	void InitalizeBoard(int, int);
	void Draw();
	static int GetBoardX()
	{
		return BOARD_X;
	}
	static int GetBoardY()
	{
		return BOARD_Y;
	}
	int GetMidX()
	{
		return BOARD_X * xcellsize / 2.0;
	}
	int GetMidY()
	{
		return BOARD_Y * ycellsize / 2.0;
	}
	int GetCellSize()
	{
		return xcellsize;
	}
	void GetInitRandomPosition(int &x, int &y)
	{
		x = GetRandInRange(50, width - 50);
		y = GetRandInRange(50, height - 50);
	}
	int GetWidth()
	{
		return width;
	}
	int GetHeight()
	{
		return height;
	}
	void GetInitTextPosition(int &x, int &y);
};
#endif
