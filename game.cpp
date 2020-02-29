//============================================================================
// Name        : Centipede
// Author      : Talha Ahmed
// Version     : v2.0
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================
#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include"Board.h"
#include"util.h"
#include"Player.cpp"
#include"Position.cpp"
#include"GameObject.cpp"
#include"MoveableObject.h"
#include"Bomb.cpp"
#include"Mushroom.cpp"
#include"ScoreBoard.cpp"
#include"Segment.cpp"
#include"MagicSeg.cpp"
#include"LazySeg.cpp"
#include"Flea.cpp"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void SetCanvasSize(int width, int height)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
Board *b;
Player player(70,70);
Bomb bomb;
Mushroom mushroom;
ScoreBoard scoreboard;
Segment segment(10,990);
Flea flea;
void GameDisplay()
{
	glClearColor(0, 0,0,0);
	glClear (GL_COLOR_BUFFER_BIT);
	for(int a=0;a<1000;a+=10)
	{
		for(int b=0;b<1000;b+=10)
		{
			DrawLine(a, b, 1000, b, 1, colors[GREEN]);
			DrawLine(a,b,a,1000,1,colors[GREEN]);
		}
	}
	player.draw();
	bomb.draw();
	mushroom.draw();
	bomb.destroyMushroom(mushroom.getMushroomposition(),mushroom.getCount(),mushroom.getHit(),mushroom.getScore());
	scoreboard.setScore(mushroom.getScore());
	scoreboard.draw();
	segment.draw();
	segment.move();
	segment.avoidMuhsrooms(mushroom.getMushroomposition(),mushroom.getCount());
	flea.draw();
	glutPostRedisplay();
	glutSwapBuffers();
}
void NonPrintableKeys(int key, int x, int y)
{
	if (key	== GLUT_KEY_LEFT)
	{
		player.setMovement("left");
		player.move();
	}
	else if (key== GLUT_KEY_RIGHT)
	{
		player.setMovement("right");
		player.move();
	}
	else if (key== GLUT_KEY_UP)
	{
		player.setMovement("up");
		player.move();
	}
	else if (key== GLUT_KEY_DOWN)
	{
		player.setMovement("down");
		player.move();
	}
	glutPostRedisplay();
}
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key==27)
	{
		exit(1);
	}
	if (key=='b' || key=='B')
	{
		if(bomb.getBomb_check()=="off")
		{
			bomb.setBombposition(player.getPlayerX()+9, player.getPlayerY()+20);
			bomb.setBomb_check("on");
		}
	}
	glutPostRedisplay();
}
void Timer(int m)
{
	glutTimerFunc(1000.0, Timer, 0);
}
void MousePressedAndMoved(int x, int y)
{
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	glutPostRedisplay();
}
void MouseClicked(int button, int state, int x, int y)
{
	if (button==GLUT_LEFT_BUTTON)
	{

	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
	}
	glutPostRedisplay();
}
int main(int argc, char*argv[])
{
	//temp[0]=new Mushroom;
	b = new Board(60, 60);
	int width = 1000, height = 1000;
	b->InitalizeBoard(width, height);
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("Centipede");
	SetCanvasSize(width, height);
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);
	glutMotionFunc(MousePressedAndMoved);
	glutMainLoop();
	return 1;
}
#endif
