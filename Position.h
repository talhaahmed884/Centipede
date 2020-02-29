#ifndef POSITION_H_
#define POSITION_H_
class Position
{
	protected:
	int x;
	int y;
	public:
	Position();
	Position(int,int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	~Position();
};
#endif
