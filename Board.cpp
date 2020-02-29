#include "Board.h"
#include <cstdio>
enum BoardParts
{
	NILL, S_BRICK, G_BRICK, R_BRICK
};
Board::~Board(void)
{
}
void Board::InitalizeBoard(int w, int h)
{
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			board_array[i][j] = NILL;
		}
	}
}
Board::Board(int xsize, int ysize)
{
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;
}
void Board::Draw()
{
	glColor3f(0, 0, 1);
	glPushMatrix();
	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize)
	{
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize))
		{
			switch (board_array[i][j])
			{
				case NILL:
					break;
				case S_BRICK:
					DrawRectangle(x - 10, y, ycellsize, xcellsize,
					colors[SLATE_GRAY]);
					break;
				case G_BRICK:
					DrawRectangle(x - 10, y, ycellsize, xcellsize,
					colors[LIGHT_GREEN]);
					break;
				case R_BRICK:
					DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
					break;
			}
		}
	}
	glPopMatrix();
}
void Board::GetInitTextPosition(int &x, int &y)
{
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
