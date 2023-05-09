//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include"..\..\Assignment\Q4\Assignment 2_Q4\Shape.h"
#include<Windows.h>
#include<GL/freeglut.h>
//#include<GL/GL.h>
#include<GL/glew.h>
#include<mmsystem.h>
#include"Classes.h"
#include<fstream>
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
string* arr;
int* arr2;
bool gen = true;
int ptx1 = 200;
int pty1 = 200;
int ptx2 = 800;
int pty2 = 200;
int x_b2, y_b2, x_b3, y_b3;

int pty3 = 650;
int ptx3 = 350;
int ptx4 =350 ;
int pty4 =200 ;
int ptx5 = 150;
int pty5 = 200;
int ptx6 = 900;
int pty6 = 200;
int ptx7 = 350;
int pty7 = 750;
int ptx8 = 350;
int pty8 = 100;

int score = 0;
int score2 = 0;
Game G;
bool gen2 = true;
Player bot[2];
void Player::setv()
{
	if (type == 1)
		v = new Tank();
	else if (type == 2)
		v = new plane();
	else
		v = new helicopter();
}
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

string scores(int n)
{
	return "Score " + to_string(n);
}
string scores2(int n)
{
	return "Score 2" + to_string(n);
}
double xI , yI;


double x_0, y_0 ;
double x_b , y_b ;
void b3_shoot()
{
	static int coor_X;
	static int bounce = 0;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;

	if (bot[1].getface2() == 'r')
	{
		bounce = 0;
		coor_X = x_b3 + 10;
		coor_Y = y_b3 + 10;
		bot[1].setface2('a');

		if (bot[1].getface() == 'd')
		{
			cout << "FIRE" << endl;
			x1 = true;
			x2 = false;
			y1 = false;
			y2 = false;

			DrawCircle(coor_X + 60, coor_Y, 5, colors[RED]);

		}
		else if (bot[1].getface() == 'a')
		{
			x2 = true;
			x1 = false;
			y1 = false;
			y2 = false;
			coor_X -= 60;
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
		else if (bot[1].getface() == 'w')
		{
			y1 = true;
			x2 = false;
			x1 = false;
			y2 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y + 60, 5, colors[RED]);
		}
		else if (bot[1].getface() == 's')
		{
			y2 = true;
			x2 = false;
			y1 = false;
			x1 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (x2)
		{

			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x2 = false;
				return;
			}

			if (!(overlap))
			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x2 = false;
				x1 = true;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			if ((S1.overlapping(S)))
			{
				score++;

				y1 = false;
				return;
			}

			if (!(overlap))

			{
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);




			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				y2 = false;
				return;
			}
			if (!(overlap))
			{

				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);
			}
			else
			{
				y2 = false;
				y1 = true;
				bounce++;
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);

			}
		}
	}
	glutPostRedisplay();
}
void b2_shoot()
{
	static int coor_X;
	static int bounce = 0;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;

	if (bot[0].getface2() == 'r')
	{
		bounce = 0;
		coor_X = x_b2 + 10;
		coor_Y = y_b2 + 10;
		bot[0].setface2('a');

		if (bot[0].getface() == 'd')
		{
			cout << "FIRE" << endl;
			x1 = true;
			x2 = false;
			y1 = false;
			y2 = false;

			DrawCircle(coor_X + 60, coor_Y, 5, colors[RED]);

		}
		else if (bot[0].getface() == 'a')
		{
			x2 = true;
			x1 = false;
			y1 = false;
			y2 = false;
			coor_X -= 60;
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
		else if (bot[0].getface() == 'w')
		{
			y1 = true;
			x2 = false;
			x1 = false;
			y2 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y + 60, 5, colors[RED]);
		}
		else if (bot[0].getface() == 's')
		{
			y2 = true;
			x2 = false;
			y1 = false;
			x1 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (x2)
		{

			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x2 = false;
				return;
			}

			if (!(overlap))
			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x2 = false;
				x1 = true;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			if ((S1.overlapping(S)))
			{
				score++;

				y1 = false;
				return;
			}

			if (!(overlap))

			{
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);




			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				y2 = false;
				return;
			}
			if (!(overlap))
			{

				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);
			}
			else
			{
				y2 = false;
				y1 = true;
				bounce++;
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);

			}
		}
	}
	glutPostRedisplay();
}
void b_shoot()
{
	static int coor_X;
	static int bounce = 0;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;

	if (G.getP()[1].getface2() == 'r')
	{
		bounce = 0;
		coor_X = x_b + 10;
		coor_Y = y_b + 10;
		G.getP()[1].setface2('a');

		if (G.getP()[1].getface() == 'd')
		{
			cout << "FIRE" << endl;
			x1 = true;
			x2 = false;
			y1 = false;
			y2 = false;

			DrawCircle(coor_X + 60, coor_Y, 5, colors[RED]);

		}
		else if (G.getP()[1].getface() == 'a')
		{
			x2 = true;
			x1 = false;
			y1 = false;
			y2 = false;
			coor_X -= 60;
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
		else if (G.getP()[1].getface() == 'w')
		{
			y1 = true;
			x2 = false;
			x1 = false;
			y2 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y + 60, 5, colors[RED]);
		}
		else if (G.getP()[1].getface() == 's')
		{
			y2 = true;
			x2 = false;
			y1 = false;
			x1 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (x2)
		{

			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x2 = false;
				return;
			}

			if (!(overlap))
			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x2 = false;
				x1 = true;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			if ((S1.overlapping(S)))
			{
				score++;

				y1 = false;
				return;
			}

			if (!(overlap))

			{
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);




			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				y2 = false;
				return;
			}
			if (!(overlap))
			{

				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);
			}
			else
			{
				y2 = false;
				y1 = true;
				bounce++;
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);

			}
		}
	}
	glutPostRedisplay();
}
//Player bot[2];
void move_bot2()
{
	b2_shoot();
	if (x_b2 == xI)
	{
		if (yI > y_b2)
		{
			bot[0].setface('w');
			bot[0].setface2('r');
			b2_shoot();
			x_b2++;
			return;

		}
		else
		{
			bot[0].setface('s');
			bot[0].setface2('r');
			b2_shoot();
			x_b2--;
			return;
		}

	}
	if (y_b2 == yI)
	{
		if (xI > x_b2)
		{
			bot[0].setface('d');
			bot[0].setface2('r');
			b2_shoot();
			y_b2++;
			return;

		}
		else
		{
			bot[0].setface('a');
			bot[0].setface2('r');
			b2_shoot();
			y_b2++;
			return;
		}

	}
	int i = -99;
	int y = -99;
	if (x_b2 - xI > y_b2 - yI)
	{
		srand(time(0));
		i = rand() % 2;
		if (i)
		{
			x_b2 -= 2;
			bot[0].setface('d');
		}

		else
		{
			x_b2 += 2;
			bot[0].setface('a');
		}
	}
	else
	{
		srand(time(0));
		y = rand() % 2;
		if (y)
		{
			y_b2 += 2;
			bot[0].setface('w');

		}
		else
		{
			y_b2 -= 2;
			bot[0].setface('s');
		}
	}
	if (x_b2 > 950)
		x_b2 = 20;
	else if (x_b2 < 20)
		x_b2 = 800;
	if (y_b2 > 800)
		y_b2 = 10;
	else if (y_b2 < 10)
		y_b2 = 750;
	Shape S1(2, x_b2, y_b2, 30, 40, 0, 0, 0);
	Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
	Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
	Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
	Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
	Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

	Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

	Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
	Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

	bool overlap = false;
	if (G.getLevel1())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
	else if (G.getLevel2())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
	else if (G.getLevel3())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
	while (overlap)
	{
		if (y == -99)
		{
			if (i)
			{
				x_b2 += 2;
				bot[0].setface('d');
			}

			else
			{
				x_b2 -= 2;
				bot[0].setface('a');
			}
		}
		else
		{
			if (y)
			{
				y_b2 += 2;
				bot[0].setface('w');

			}
			else
			{
				y_b2 -= 2;
				bot[0].setface('s');
			}
		}
		Shape S1(2, x_b2, y_b2, 30, 40, 0, 0, 0);
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if (G.getLevel2())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
		else if (G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));



	}
}

void move_bot3()
{
	b3_shoot();
	if (x_b3 == xI)
	{
		if (yI > y_b3)
		{
			bot[0].setface('w');
			bot[0].setface2('r');
			b3_shoot();
			x_b3++;
			return;

		}
		else
		{
			bot[0].setface('s');
			bot[0].setface2('r');
			b3_shoot();
			x_b3--;
			return;
		}

	}
	if (y_b3 == yI)
	{
		if (xI> x_b3)
		{
			bot[0].setface('d');
			bot[0].setface2('r');
			b3_shoot();
			y_b3++;
			return;

		}
		else
		{
			bot[0].setface('a');
			bot[0].setface2('r');
			b3_shoot();
			y_b3++;
			return;
		}

	}
	int i = -99;
	int y = -99;
	if (x_b3 - xI > y_b3 - yI)
	{
		srand(time(0));
		i = rand() % 2;
		if (i)
		{
			x_b3 -= 3;
			bot[0].setface('d');
		}

		else
		{
			x_b3 += 3;
			bot[0].setface('a');
		}
	}
	else
	{
		srand(time(0));
		y = rand() % 2;
		if (y)
		{
			y_b3 -= 3;
			bot[0].setface('w');

		}
		else
		{
			y_b3 += 3;
			bot[0].setface('s');
		}
	}
	if (x_b3 > 950)
		x_b3 = 20;
	else if (x_b3 < 20)
		x_b3 = 800;
	if (y_b3 > 800)
		y_b3 = 10;
	else if (y_b3 < 10)
		y_b3 = 750;
	Shape S1(2, x_b3, y_b3, 30, 40, 0, 0, 0);
	Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
	Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
	Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
	Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
	Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

	Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

	Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
	Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

	bool overlap = false;
	if (G.getLevel1())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
	else if (G.getLevel2())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
	else if (G.getLevel3())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
	while (overlap)
	{
		if (y == -99)
		{
			if (i)
			{
				x_b3 +=3;
				bot[0].setface('d');
			}

			else
			{
				x_b3 -= 3;
				bot[0].setface('a');
			}
		}
		else
		{
			if (y)
			{
				y_b3 += 3;
				bot[0].setface('w');

			}
			else
			{
				y_b3 -= 3;
				bot[0].setface('s');
			}
		}
		Shape S1(2, x_b3, y_b3, 30, 40, 0, 0, 0);
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if (G.getLevel2())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
		else if (G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));



	}
}
void move_bot(int m = 0)
{
	b_shoot();
	if (x_b == xI)
	{
		if (yI > y_b)
		{
			G.getP()[1].setface('w');
			G.getP()[1].setface2('r');
			b_shoot();
			x_b++;
			return;

		}
		else
		{
			G.getP()[1].setface('s');
			G.getP()[1].setface2('r');
			b_shoot();
			x_b--;
			return;
		}

	}
	if (y_b == yI)
	{
		if (xI > x_b)
		{
			G.getP()[1].setface('d');
			G.getP()[1].setface2('r');
			b_shoot();
			y_b++;
			return;

		}
		else
		{
			G.getP()[1].setface('a');
			G.getP()[1].setface2('r');
			b_shoot();
			y_b++;
			return;
		}

	}
	int i=-99;
	int y = -99;
	if (x_b - xI > y_b - yI)
	{
		srand(time(0));
		 i = rand() % 2;
		 if (i)
		 {
			 x_b += 1;
			 G.getP()[1].setface('d');
		 }

		 else
		 {
			 x_b -= 1;
			 G.getP()[1].setface('a');
		 }
	}
	else
	{
		srand(time(0));
		 y= rand() % 2;
		 if (y)
		 {
			 y_b += 1;
			 G.getP()[1].setface('w');

		 }
		 else
		 {
			 y_b -= 1;
			 G.getP()[1].setface('s');
		 }
	}
	if (x_b > 950)
		x_b = 20;
	else if (x_b < 20)
		x_b = 800;
	if (y_b > 800)
		y_b = 10;
	else if (y_b < 10)
		y_b = 750;
	Shape S1(2, x_b, y_b, 30, 40, 0, 0, 0);
	Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
	Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
	Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
	Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
	Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

	Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

	Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
	Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

	bool overlap = false;
	if (G.getLevel1())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
	else if (G.getLevel2())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
	else if (G.getLevel3())
		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
	while (overlap)
	{
		if (y ==-99)
		{
			if (i)
			{
				x_b += 1;
				G.getP()[1].setface('d');
			}

			else
			{
				x_b -= 1;
				G.getP()[1].setface('a');
			}
		}
		else
		{
			if (y)
			{
				y_b += 1;
				G.getP()[1].setface('w');
			
			}
			else
			{
				y_b -= 1;
				G.getP()[1].setface('s');
			}
		}
		Shape S1(2, x_b, y_b, 30, 40, 0, 0, 0);
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if (G.getLevel2())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
		else if (G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


	
	}
	
	//glutTimerFunc(1000000000000, move_bot, 10000000000);
}

void menu()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Up
	DrawString(100, 800, "Welcome to Combat by AHMED RAZA", colors[RED]);
	DrawString(400, 400, "LEADERBOARD", colors[RED]);
	DrawString(400, 450, "TWO PLAYER", colors[RED]);
	DrawString(400, 500, "ONE PLAYER", colors[RED]);

	glutSwapBuffers();
}
void leaderboard()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Up
	ifstream file("name.txt");
	ifstream file2("score.txt");
	string x;
	int i = 0,i2=0;
	while (getline(file, x))
	{
		i++;
	}
	while (getline(file2, x))
	{
		i2++;
	}
	file.close();
	file2.close();
	 arr= new string[i];
	arr2 = new int[i2];
	fstream file3("name.txt");
	fstream file4("score.txt");
	
	int j = 0;
	int num = 0;
	string no;
	while (getline(file3, x) && j<i)
	{
		file4 >> no ;
		arr[j] = x;
		arr2[j] = stoi(no);
		j++;
		

	}
	file3.close();
	file4.close();
	for (int l = 0; l < i; l++)
	{
		for (int o = l+1; o < i; o++)
		{
			if (arr2[l] < arr2[o])
			{
				int temp = arr2[l];
				arr2[l] = arr2[o];
				arr2[o] = temp;
				string temp2 = arr[l];
				arr[l] = arr[o];
				arr[o] = temp2;
			}
		}
	}
	int high[10] = { 0 };
	string highs[10] = { "name" };
	for (int u = 0; u < 9 && u<i; u++)
	{
		high[u] = arr2[u];
		highs[u] = arr[u];

	}
	string x1 = highs[0] + "\t" + to_string(high[0]);
	string x2 = highs[1] + "\t" + to_string(high[1]);
	string x3 = highs[2] + "\t" + to_string(high[2]);
	string x4 = highs[3] + "\t" + to_string(high[3]);
	string x5 = highs[4] + "\t" + to_string(high[4]);
	string x6 = highs[5] + "\t" + to_string(high[5]);
	string x7 = highs[6] + "\t" + to_string(high[6]);
	string x8 = highs[7] + "\t" + to_string(high[7]);
	string x9 = highs[8] + "\t" + to_string(high[8]);
	string x10 = highs[9] + "\t" + to_string(high[9]);

	DrawString(350, 200, x1);
	DrawString(350, 250, x2);
	DrawString(350, 300, x3);
	DrawString(350, 350, x4);
	DrawString(350, 400, x5);
	DrawString(350, 450, x6);
	DrawString(350, 500, x7);
	DrawString(350, 550, x8);
	DrawString(350, 600, x9);
	DrawString(350, 650, x10);
	

	glutSwapBuffers();
}
void shoot()
{
	static int bounce = 0;
	static int coor_X;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;
	

	if (G.getP()[0].getface2() == ' ')
	{
		PlaySound(TEXT("mixkit-game-success-alert-2039.wav"), NULL, SND_ASYNC);

		coor_X = xI+10;
		coor_Y = yI+10;
		bounce = 0;
		G.getP()[0].setface2('a');
		
		if (G.getP()[0].getface() == GLUT_KEY_RIGHT)
		{
			cout << "FIRE" << endl;
			x1 = true;
			x2 = false;
			y1 = false;
			y2 = false;
			
			DrawCircle(coor_X + 60, coor_Y, 5, colors[RED]);

		}
		else if (G.getP()[0].getface() == GLUT_KEY_LEFT)
		{
			x2 = true;
			x1 = false;
			y1 = false;
			y2 = false;
			cout << "FIRE" << endl;
			DrawCircle(coor_X , coor_Y, 5, colors[RED]);
		}
		else if (G.getP()[0].getface() == GLUT_KEY_UP)
		{
			y1 = true;
			x2 = false;
			x1 = false;
			y2 = false;
		
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y + 60, 5, colors[RED]);
		}
		else if (G.getP()[0].getface() == GLUT_KEY_DOWN)
		{
			y2 = true;
			x2 = false;
			y1 = false;
			x1 = false;
			
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())

				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S))||(S1.overlapping(s))|| (S1.overlapping(botext))||(S1.overlapping(botext2)))
			{
				score2++;
				x1 = false;
				return;

			}


			if (!(overlap))
			{
				
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X , coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if(bounce<=3)
					DrawCircle(coor_X, coor_Y, 5, colors[RED]);
				return;

				
			}
		}
		else if (x2)
		{
			Shape S1(2, coor_X - 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2++;
				x2 = false;
				return;

			}

			if (!(overlap))

			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = true;
				x2 = false;
				coor_X += 1;
				if(bounce<4)
					DrawCircle(coor_X, coor_Y, 5, colors[RED]);
				return;
			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X , coor_Y+1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);

			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2++;
				y1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y , 5, colors[RED]);
				return;
			}
		}
		else if(y2)
		{
			Shape S1(2, coor_X, coor_Y - 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2++;
				y2 = false;
				return;

			}

			if (!(overlap))

			{
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				y2 = false;
				y1 = true;

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 5, colors[RED]);
				return;
			}
		}
	}
	glutPostRedisplay();
	
	//Timer(10);
}
void shoot_m()
{
	static int bounce = 0;
	static int coor_X;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;
	//static int i = 1;

	
	
		if (G.getP()[0].getface2() == 'm')
		{
			coor_X = xI + 10;
			coor_Y = yI + 10;
			bounce = 0;
			G.getP()[0].setface2('a');

			if (G.getP()[0].getface() == GLUT_KEY_RIGHT)
			{
				cout << "FIRE" << endl;
				x1 = true;
				x2 = false;
				y1 = false;
				y2 = false;

				DrawCircle(coor_X + 60, coor_Y, 15, colors[RED]);

			}
			else if (G.getP()[0].getface() == GLUT_KEY_LEFT)
			{
				x2 = true;
				x1 = false;
				y1 = false;
				y2 = false;
				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else if (G.getP()[0].getface() == GLUT_KEY_UP)
			{
				y1 = true;
				x2 = false;
				x1 = false;
				y2 = false;

				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y + 60, 15, colors[RED]);
			}
			else if (G.getP()[0].getface() == GLUT_KEY_DOWN)
			{
				y2 = true;
				x2 = false;
				y1 = false;
				x1 = false;

				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
		}

	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);

			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2++;
				score2++;
				score2++;
				score2++;
				x1 = false;
				return;

			}


			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce <= 3)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
				return;


			}
		}
		else if (x2)
		{
			Shape S1(2, coor_X - 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);

			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);

			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2 += 4;
				x2 = false;
				return;

			}

			if (!(overlap))

			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = true;
				x2 = false;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);

			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2 += 4;
				y1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y - 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2 += 4;
				y2 = false;
				return;

			}

			if (!(overlap))

			{
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y2 = false;
				y1 = true;

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
	}
	glutPostRedisplay();

	//Timer(10);
}
void shoot2_m()
{
	static int bounce = 0;
	static int coor_X;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;
	static int i = 1;



	if (G.getP()[1].getface2() == 'q' || (G.getP()[1].getface2() == 'e') )
	{
		coor_X = x_0 + 10;
		coor_Y = y_0 + 10;
		bounce = 0;
		G.getP()[1].setface2('a');

		if (G.getP()[1].getface() =='d')
		{
			cout << "FIRE" << endl;
			x1 = true;
			x2 = false;
			y1 = false;
			y2 = false;

			DrawCircle(coor_X + 60, coor_Y, 15, colors[RED]);

		}
		else if (G.getP()[1].getface() == 'a')
		{
			x2 = true;
			x1 = false;
			y1 = false;
			y2 = false;
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 15, colors[RED]);
		}
		else if (G.getP()[1].getface() == 'w')
		{
			y1 = true;
			x2 = false;
			x1 = false;
			y2 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y + 60, 15, colors[RED]);
		}
		else if (G.getP()[1].getface() == 's')
		{
			y2 = true;
			x2 = false;
			y1 = false;
			x1 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 15, colors[RED]);
		}
	}

	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score2++;
				score2++;
				score2++;
				score2++;
				x1 = false;
				return;

			}


			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce <= 3)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
				return;


			}
		}
		else if (x2)
		{
			Shape S1(2, coor_X - 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score2 += 4;
				x2 = false;
				return;

			}

			if (!(overlap))

			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = true;
				x2 = false;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score2 += 4;
				y1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y - 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score2 += 4;
				y2 = false;
				return;

			}

			if (!(overlap))

			{
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y2 = false;
				y1 = true;

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
	}
	glutPostRedisplay();

	//Timer(10);
}
int l1 = 1;
void shoot_l()
{
	static int bounce = 0;
	static int coor_X;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;
	//static int i = 1;

	if(l1++<2)
	{
		if (G.getP()[0].getface2() == 'l')
		{
			coor_X = xI + 10;
			coor_Y = yI + 10;
			bounce = 0;
			G.getP()[0].setface2('a');

			if (G.getP()[0].getface() == GLUT_KEY_RIGHT)
			{
				cout << "FIRE" << endl;
				x1 = true;
				x2 = false;
				y1 = false;
				y2 = false;

				DrawCircle(coor_X + 60, coor_Y, 15, colors[RED]);

			}
			else if (G.getP()[0].getface() == GLUT_KEY_LEFT)
			{
				x2 = true;
				x1 = false;
				y1 = false;
				y2 = false;
				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else if (G.getP()[0].getface() == GLUT_KEY_UP)
			{
				y1 = true;
				x2 = false;
				x1 = false;
				y2 = false;

				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y + 60, 15, colors[RED]);
			}
			else if (G.getP()[0].getface() == GLUT_KEY_DOWN)
			{
				y2 = true;
				x2 = false;
				y1 = false;
				x1 = false;

				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2++;
				score2++;
				score2++;
				score2++;
				x1 = false;
				return;

			}


			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce <= 3)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
				return;


			}
		}
		else if (x2)
		{
			Shape S1(2, coor_X - 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2 += 4;
				x2 = false;
				return;

			}

			if (!(overlap))

			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = true;
				x2 = false;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);

			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2 += 4;
				y1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y - 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			Shape botext(2, x_b2, y_b2, 30, 40, 0, 0, 0);
			Shape botext2(2, x_b3, y_b3, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) || (S1.overlapping(s)) || (S1.overlapping(botext)) || (S1.overlapping(botext2)))
			{
				score2 += 4;
				y2 = false;
				return;

			}

			if (!(overlap))

			{
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y2 = false;
				y1 = true;

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
	}
	glutPostRedisplay();

	//Timer(10);
}
int l2 = 1;
void shoot2_l()
{
	static int bounce = 0;
	static int coor_X;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;
	static int i = 1;

	if (l2++ < 2)
	{
		if (G.getP()[1].getface2() == 'e' || (G.getP()[1].getface2() == 'q') )
		{
			coor_X = x_0 + 10;
			coor_Y = y_0 + 10;
			bounce = 0;
			G.getP()[1].setface2('a');

			if (G.getP()[1].getface() == 'd')
			{
				cout << "FIRE" << endl;
				x1 = true;
				x2 = false;
				y1 = false;
				y2 = false;

				DrawCircle(coor_X + 60, coor_Y, 15, colors[RED]);

			}
			else if (G.getP()[1].getface() == 'a')
			{
				x2 = true;
				x1 = false;
				y1 = false;
				y2 = false;
				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else if (G.getP()[1].getface() == 'w')
			{
				y1 = true;
				x2 = false;
				x1 = false;
				y2 = false;

				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y + 60, 15, colors[RED]);
			}
			else if (G.getP()[1].getface() == 's')
			{
				y2 = true;
				x2 = false;
				y1 = false;
				x1 = false;

				cout << "FIRE" << endl;
				DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, xI,yI, 30, 40, 0, 0, 0);
			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)) )//|| (S1.overlapping(s)))
			{
				score++;
				score++;
				score++;
				score++;
				x1 = false;
				return;

			}


			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if (bounce <= 3)
					DrawCircle(coor_X, coor_Y, 10, colors[RED]);
				return;


			}
		}
		else if (x2)
		{
			Shape S1(2, coor_X - 1, coor_Y, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score += 4;
				x2 = false;
				return;

			}

			if (!(overlap))

			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = true;
				x2 = false;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X, coor_Y + 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			//Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score += 4;
				y1 = false;
				return;

			}

			if (!(overlap))
			{

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y - 1, 15, 15, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
		//	Shape s(2, x_b, y_b, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))// || (S1.overlapping(s)))
			{
				score += 4;
				y2 = false;
				return;

			}

			if (!(overlap))

			{
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
			}
			else
			{
				bounce++;
				y2 = false;
				y1 = true;

				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y, 15, colors[RED]);
				return;
			}
		}
	}
	glutPostRedisplay();

	//Timer(10);
}


bool flag = true;
int i1 = 3;

int i2 = 3;
int j2 = 0;
int i3 = 3;
int j3 = 0;
int i2_1 = 3;
int i2_2 = 3;
int i2_3 = 3;

/*
 * Main Canvas drawing function.
 * */
void shoot2()
{
	static int coor_X;
	static int bounce = 0;
	static int coor_Y;
	static bool x1 = false;
	static bool y1 = false;
	static bool x2 = false;
	static bool y2 = false;

	if (G.getP()[1].getface2() == 'r')
	{
		PlaySound(TEXT("mixkit - magical - coin - win - 1936.wav"), NULL, SND_ASYNC);

		bounce = 0;
		coor_X = x_0 + 10;
		coor_Y = y_0 + 10;
		G.getP()[1].setface2('a');

		if (G.getP()[1].getface() == 'd')
		{
			cout << "FIRE" << endl;
			x1 = true;
			x2 = false;
			y1 = false;
			y2 = false;

			DrawCircle(coor_X + 60, coor_Y, 5, colors[RED]);

		}
		else if (G.getP()[1].getface() == 'a')
		{
			x2 = true;
			x1 = false;
			y1 = false;
			y2 = false;
			coor_X -= 60;
			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
		else if (G.getP()[1].getface() == 'w')
		{
			y1 = true;
			x2 = false;
			x1 = false;
			y2 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y + 60, 5, colors[RED]);
		}
		else if (G.getP()[1].getface() == 's')
		{
			y2 = true;
			x2 = false;
			y1 = false;
			x1 = false;

			cout << "FIRE" << endl;
			DrawCircle(coor_X, coor_Y, 5, colors[RED]);
		}
	}
	else
	{
		if (x1)
		{
			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
				if ((S1.overlapping(S)))
			{
				score++;
				x1 = false;
				return;
				
			}

			if (!(overlap))
			{

				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X + 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x1 = false;
				x2 = true;
				coor_X -= 1;
				if(bounce<4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);


			}
		}
		else if (x2)
		{

			Shape S1(2, coor_X + 1, coor_Y, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				x2 = false;
				return;
			}

			if (!(overlap))
			{

				coor_X -= 1;
				if (bounce < 4)
					DrawCircle(coor_X - 10, coor_Y, 5, colors[RED]);
			}
			else
			{
				bounce++;
				x2 = false;
				x1 = true;
				coor_X += 1;
				if (bounce < 4)
					DrawCircle(coor_X +10, coor_Y ,5, colors[RED]);


			}
		}
		else if (y1)
		{
			Shape S1(2, coor_X , coor_Y+1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);

			if ((S1.overlapping(S)))
			{
				score++;
				
				y1 = false;
				return;
			}

			if (!(overlap))

			{
				coor_Y += 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);
			}
			else
			{
				bounce++;
				y1 = false;
				y2 = true;
				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X , coor_Y-10, 5, colors[RED]);




			}
		}
		else if (y2)
		{
			Shape S1(2, coor_X, coor_Y + 1, 5, 5, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			Shape S(2, xI, yI, 30, 40, 0, 0, 0);
			if ((S1.overlapping(S)))
			{
				score++;
				y2 = false;
				return;
			}
			if (!(overlap))
			{

				coor_Y -= 1;
				if (bounce < 4)
					DrawCircle(coor_X, coor_Y - 10, 5, colors[RED]);
			}
			else
			{
				y2 = false;
				y1 = true;
				bounce++;
				coor_Y += 1;
				if(bounce<4)
					DrawCircle(coor_X, coor_Y + 10, 5, colors[RED]);

			}
		}
	}
	glutPostRedisplay();
}
void random()
{
	srand(time(0));
	static int i =1;
	static int xcoor;
	static int ycoor;
	static int catchs = true;
	if(catchs)
	{
		if (i-- > 0)
		{
			Shape S1(2, rand() % 750, rand() % 950, 30, 40, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);
			bool overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
			while (overlap)
			{
				S1.setX(rand() % 750);
				S1.setY(rand() % 950);
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

			}
			xcoor = S1.getX();
			ycoor = S2.getY();
			DrawCircle(xcoor, ycoor, 5, colors[WHITE]);
		}
		else
		{
			Shape S(2, xcoor, ycoor, 30, 40, 0, 0, 0);
			Shape S1(2, xI, yI, 30, 40, 0, 0, 0);
			Shape S2(2, x_0, y_0, 30, 40, 0, 0, 0);
			if (S.overlapping(S1))
			{
				if (G.getLevel1())
					i1++;
				else if (G.getLevel2())
					i2++;
				else
					i3++;
				catchs = false;
			}
			else if (S.overlapping(S2))
			{
				if (G.getLevel1())
					i2_3++;
				else if (G.getLevel2())
					i2_2++;
				else
					i2_1++;
				catchs = false;
			}
			else
				DrawCircle(xcoor, ycoor, 5, colors[WHITE]);
			
		}
	}


}
bool gen3 = true,gen4=true,gen5=true,gen6=true;

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	static int j0 = 0;
	if (G.getLevel1())
	{
		srand(time(0));
		if (rand() % 2)
			random();
		G.setLevel2(false);
		G.setLevel3(false);
		G.getM()[0].setNo(4);
		G.getM()[0].alloc();
		G.getM()[0].getO()[0].setX(ptx1);
		G.getM()[0].getO()[0].setY(pty1);
		G.getM()[0].getO()[1].setX(ptx2);
		G.getM()[0].getO()[1].setY(pty2);
		G.getM()[0].getO()[2].setX(ptx3);
		G.getM()[0].getO()[2].setY(pty3);
		G.getM()[0].getO()[3].setX(ptx4);
		G.getM()[0].getO()[3].setY(pty4);
		G.getP()[0].setL_ammo(1);
		G.getP()[0].setM_ammo(2);


		DrawString(50, 800, scores(score), colors[MISTY_ROSE]);
		DrawString(500, 800, scores2(score2), colors[MISTY_ROSE]);


		DrawRectangle(ptx2, pty2, 10, 400, colors[WHITE]);
		DrawRectangle(ptx3, pty3, 300, 10, colors[WHITE]);
		DrawRectangle(ptx4, pty4, 300, 10, colors[WHITE]);


		DrawLine(0, 0, 0, 800, 10);
		DrawLine(0, 0, 1020, 0, 10);
		DrawLine(1020, 0, 1020, 800, 10);
		DrawLine(0, 800, 1020, 800);
		DrawRectangle(ptx1, pty1, 10, 400, colors[WHITE]);

		//drawCar();
		//vehicle* v = G.getP()[0].getv();
		//v->draw(G, xI, yI);
		G.getP()[0].getv()->draw(G.getP()[0], xI, yI, 0);

		if (!gen)
			shoot();
		if ((!(gen3)) && i1 > 0)
		{



			shoot_m();
			//i1--;
		}
		if ((!(gen4)))
		{
			shoot_l();

		}
		if (G.getP()[1].getBot())
		{

			//if(j0++<1)
			move_bot();
			//	cout << x_b << "   " << y_b<<endl;
			G.getP()[1].getv()->draw(G.getP()[1], x_b, y_b, 1);
		}
		else

			G.getP()[1].getv()->draw(G.getP()[1], x_0, y_0, 1);

		if (!gen2)
			shoot2();
		if (!gen5 && i2_3 > 0)
		{
			//gen5 = true;
			shoot2_m();
			//i2_3--;

		}
		if (!gen6)
			shoot2_l();
		if (score >= 10)
		{
			
			//DrawString(400, 400, 10, 10, "PLAYER 2 WINS");
			G.setLevel1(false);
			//if (G.getP()[1].getBot())
				//G.setLevel2(true);
			//else
			G.setWin_scr(true);
			G.getP()[0].setScore(score2);
		}
		if (score2 >= 10)
		{    	
			G.setLevel1(false);

			if (G.getP()[1].getBot())
			{
				G.setLevel2(true);
				score = 0;
				score2 = 0;
			}

			else
				G.setWin_scr(true);


		}
	}
		else if (G.getWin_scr())
		{
			if (score >= 10)
			{
				DrawString(400, 400, "PLAYER 2 WINS");
				DrawString(400, 500, "PRESS P TO PLAY AGAIN");
				score = 0;
				score2 = 0;

				i2 = 3;
				i1 = 3;
				i3 = 3;
				i2_1 = 3;
				i2_2 = 3; 
				i2_3 = 3;
				l1 = 1;
				l2 = 1;
			}
			else
			{
				score = 0;
				score2 = 0;

				DrawString(400, 400, "PLAYER 1 WINS");
				DrawString(400, 500, "PRESS P TO PLAY AGAIN");
				i2 = 3;
				i1 = 3;
				i3 = 3;
				i2_1 = 3;
				i2_2 = 3;
				i2_3 = 3;
				l1 = 1;
				l2 = 1;
			}
		}
		else if (G.getLevel2())
		{
			if (rand() % 2)
				random();
			G.setLevel1(false);
			G.setLevel3(false);

			G.getM()[0].setNo(6);
			G.getM()[0].alloc();
			G.getM()[0].getO()[0].setX(ptx1);
			G.getM()[0].getO()[0].setY(pty1);
			G.getM()[0].getO()[1].setX(ptx2);
			G.getM()[0].getO()[1].setY(pty2);
			G.getM()[0].getO()[2].setX(ptx3);
			G.getM()[0].getO()[2].setY(pty3);
			G.getM()[0].getO()[3].setX(ptx4);
			G.getM()[0].getO()[3].setY(pty4);
			G.getM()[0].getO()[4].setX(ptx5);
			G.getM()[0].getO()[4].setY(pty5);
			G.getM()[0].getO()[5].setX(ptx6);
			G.getM()[0].getO()[5].setY(pty6);


			DrawString(50, 800, scores(score), colors[MISTY_ROSE]);
			DrawString(500, 800, scores2(score2), colors[MISTY_ROSE]);


			DrawRectangle(ptx2, pty2, 10, 400, colors[WHITE]);
			DrawRectangle(ptx3, pty3, 300, 10, colors[WHITE]);
			DrawRectangle(ptx4, pty4, 300, 10, colors[WHITE]);
			DrawRectangle(ptx5, pty5, 10, 400, colors[WHITE]);
			DrawRectangle(ptx6, pty6, 10, 400, colors[WHITE]);


			DrawLine(0, 0, 0, 800, 10);
			DrawLine(0, 0, 1020, 0, 10);
			DrawLine(1020, 0, 1020, 800, 10);
			DrawLine(0, 800, 1020, 800);
			DrawRectangle(ptx1, pty1, 10, 400, colors[WHITE]);
			if (G.getP()[1].getBot() && score2<10)
			{
				bot[0].settype(G.getP()[1].gettype());
				bot[0].setv();
				bot[0].getv()->draw(bot[0],x_b2,y_b2,1);
				

			}

			//drawCar();
			//vehicle* v = G.getP()[0].getv();
			//v->draw(G, xI, yI);
			G.getP()[0].getv()->draw(G.getP()[0], xI, yI, 0);
			if ((!(gen3)) && i2 > 0)
			{
				//gen3 = true;
				shoot_m();
				//i2--;
				//G.getP()[0].setM_ammo((G.getP()[0].getM_ammo()) - 1);
			}
			if ((!(gen4)))
			{
				shoot_l();
				//G.getP()[0].setL_ammo(G.getP()[0].getL_ammo() - 1);
			}

			if (!gen)
				shoot();
			if (G.getP()[1].getBot())
			{

				//	static int i = 0;
				move_bot2();
				move_bot();
				//	//	cout << x_b << "   " << y_b<<endl;
				G.getP()[1].getv()->draw(G.getP()[1], x_b, y_b, 1);
			}
			else

				G.getP()[1].getv()->draw(G.getP()[1], x_0, y_0, 1);


			if (!gen2)
				shoot2();
			if (!gen5 && i2_2 > 0)
			{
				//gen5 = true;
				shoot2_m();
				//i2_2--;

			}
			if (!gen6)
				shoot2_l();
			if (score >= 10)
			{
				//DrawString(400, 400, 10, 10, "PLAYER 2 WINS");
				G.setLevel2(false);
				G.setWin_scr(true);
				G.getP()[0].setScore(G.getP()[0].getScore() + score2);
			}
			if (score2 >= 10)
			{
				
				G.setLevel2(false);
				if (G.getP()[1].getBot())
				{
					G.setLevel2(true);
					score = 0;
					score2 = 0;
				}

				else
					G.setWin_scr(true);
			}


		}
		else if (G.getLevel3())
		{
			if (rand() % 2)
				random();
			G.setLevel2(false);
			G.setLevel1(false);

			G.getM()[0].setNo(8);
			G.getM()[0].alloc();
			G.getM()[0].getO()[0].setX(ptx1);
			G.getM()[0].getO()[0].setY(pty1);
			G.getM()[0].getO()[1].setX(ptx2);
			G.getM()[0].getO()[1].setY(pty2);
			G.getM()[0].getO()[2].setX(ptx3);
			G.getM()[0].getO()[2].setY(pty3);
			G.getM()[0].getO()[3].setX(ptx4);
			G.getM()[0].getO()[3].setY(pty4);
			G.getM()[0].getO()[4].setX(ptx5);
			G.getM()[0].getO()[4].setY(pty5);
			G.getM()[0].getO()[5].setX(ptx6);
			G.getM()[0].getO()[5].setY(pty6);
			G.getM()[0].getO()[6].setX(ptx7);
			G.getM()[0].getO()[6].setY(pty7);
			G.getM()[0].getO()[7].setX(ptx8);
			G.getM()[0].getO()[7].setY(pty8);


			DrawString(50, 800, scores(score), colors[MISTY_ROSE]);
			DrawString(500, 800, scores2(score2), colors[MISTY_ROSE]);


			DrawRectangle(ptx2, pty2, 10, 400, colors[WHITE]);
			DrawRectangle(ptx3, pty3, 300, 10, colors[WHITE]);
			DrawRectangle(ptx4, pty4, 300, 10, colors[WHITE]);
			DrawRectangle(ptx5, pty5, 10, 400, colors[WHITE]);
			DrawRectangle(ptx6, pty6, 10, 400, colors[WHITE]);
			DrawRectangle(ptx7, pty7, 300, 10, colors[WHITE]);
			DrawRectangle(ptx8, pty8, 300, 10, colors[WHITE]);


			DrawLine(0, 0, 0, 800, 10);
			DrawLine(0, 0, 1020, 0, 10);
			DrawLine(1020, 0, 1020, 800, 10);
			DrawLine(0, 800, 1020, 800);
			DrawRectangle(ptx1, pty1, 10, 400, colors[WHITE]);

			//drawCar();
			//vehicle* v = G.getP()[0].getv();
			//v->draw(G, xI, yI);
			G.getP()[0].getv()->draw(G.getP()[0], xI, yI, 0);
			if (G.getP()[1].getBot() && score2<20)
			{
				if(score2<10)
				{
					bot[0].settype(G.getP()[1].gettype());
					bot[0].setv();
					bot[0].getv()->draw(bot[1], x_b3, y_b3, 1);
					bot[1].settype(G.getP()[1].gettype());
					bot[1].setv();
					bot[1].getv()->draw(bot[1], x_b3, y_b3, 1);
				}
				else
				{
					bot[1].getv()->draw(bot[1], x_b3, y_b3, 1);
				}


			}

			if (!gen)
				shoot();
			if ((!(gen4)))
			{
				shoot_l();
				//G.getP()[0].setL_ammo(G.getP()[0].getL_ammo() - 1);
			}
			if (G.getP()[1].getBot())
			{
				//int i = 0;
				//if (j3++ < 1)
				move_bot2();
				move_bot3();
				move_bot();
				////	cout << x_b << "   " << y_b<<endl;
				G.getP()[1].getv()->draw(G.getP()[1], x_b, y_b, 1);
			}
			else
				G.getP()[1].getv()->draw(G.getP()[1], x_0, y_0, 1);
			if ((!(gen3) && i3 > 0))
			{
				//gen3 = true;
				shoot_m();
				//i3--;
				G.getP()[0].setM_ammo((G.getP()[0].getM_ammo()) - 1);
			}

			if (!gen2)
				shoot2();
			if (!gen5 && i2_1 > 0)
			{
				//gen5 = true;
				shoot2_m();
				//i2_1--;

			}
			if (!gen6)
				shoot2_l();
			if (score >= 10)
			{
				//DrawString(400, 400, 10, 10, "PLAYER 2 WINS");
				G.setLevel3(false);
				G.setWin_scr(true);
				G.getP()[0].setScore(G.getP()[0].getScore() + score2);
				score = 0;
				score2 = 0;

			}
			if (score2 >= 10)
			{
				

				G.setLevel3(false);
				G.setWin_scr(true);
			}

		}
	
	cout << i1 << endl << i2 << endl << i3 << endl  << i2_1 << endl << i2_2 << endl << i2_3 << endl << gen << gen2 << gen3 << gen4 << gen5 << gen6 << endl;
	glutSwapBuffers(); // do not modify this line..

}
void settings()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(200, 300, "PLAYER 1 SELECT VEHICLE");
	DrawString(200, 350, "P for PLANE");
	DrawString(200, 400, "T for TANK");
	DrawString(200, 450, "P for HELIKOPTER");
	glutSwapBuffers(); // do not modify this line..



}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if (xI - 10 < 0)
		{
			xI = 980;
		}

		Shape S1(2, xI-30, yI , 30, 40,0,0,0);
		Shape S2(2, ptx2, pty2, 400, 10,0,0,0);
		Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
		Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
		Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
		Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

		Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

		Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
		Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

		bool overlap = false;
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if(G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) ||(S1.overlapping(S9))||(S1.overlapping(S10)));
		else if(G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10))||(S1.overlapping(S7))||(S1.overlapping(S8)));


		if(!(overlap))
		{
			//	cout << "COORR " << xI << endl << yI << endl;
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			if (!(S1.overlapping(S)))

			{
				xI -= 10;
				G.getP()[0].setface(key);

			}
			else
			{
				srand(time(0));
				G.getP()[0].setScore(++score2);
				srand(time(0));

				x_0 = rand() % 750;
				y_0 = rand() % 950;
				Shape S5(2, x_0, y_0, 30, 40, 0, 0, 0);
				if (G.getLevel1())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
				else if (G.getLevel2())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
				else if (G.getLevel3())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				while (overlap)
				{
					S5.setX(rand() % 750);
					S5.setY(rand() % 950);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				}
				x_0 = S5.getX();
				y_0 = S5.getY();

			}

		}
		
			

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (xI + 10 > 1000)
		{
			xI = 10;
		}

		Shape S1(2, xI + 10, yI , 30, 40, 0, 0, 0);
		Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
		Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
		Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
		Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
		Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

		Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

		Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
		Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

		bool overlap = false;
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if (G.getLevel2())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
		else if (G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


		if (!(overlap)) {
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			if (!(S1.overlapping(S)))
			{
				xI += 10;
				G.getP()[0].setface(key);
			}
			else
			{
				srand(time(0));
				G.getP()[0].setScore(++score2);
				srand(time(0));

				x_0 = rand() % 750;
				y_0 = rand() % 950;
				Shape S5(2, x_0, y_0, 30, 40, 0, 0, 0);
				if (G.getLevel1())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
				else if (G.getLevel2())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
				else if (G.getLevel3())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				while (overlap)
				{
					S5.setX(rand() % 750);
					S5.setY(rand() % 950);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				}
				x_0 = S5.getX();
				y_0 = S5.getY();

			}
		}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if (yI + 10 > 800)
		{
			yI = 10;
		}

		Shape S1(2, xI , yI + 10, 30, 40, 0, 0, 0);
		Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
		Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
		Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
		Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
		Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

		Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

		Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
		Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

		bool overlap = false;
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if (G.getLevel2())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
		else if (G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


		if (!(overlap)) {
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			if (!(S1.overlapping(S)))

			{
				yI += 10;
				G.getP()[0].setface(key);
			}
			else
			{
				srand(time(0));
				G.getP()[0].setScore(++score2);
				srand(time(0));

				x_0 = rand() % 750;
				y_0 = rand() % 950;
				Shape S5(2, x_0, y_0, 30, 40, 0, 0, 0);
				if (G.getLevel1())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
				else if (G.getLevel2())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
				else if (G.getLevel3())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				while (overlap)
				{
					S5.setX(rand() % 750);
					S5.setY(rand() % 950);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				}
				x_0 = S5.getX();
				y_0 = S5.getY();
			}

		}
	}
	
	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (yI - 10 < 0)
		{
			yI = 780;
		}

		Shape S1(2, xI , yI-10, 30, 40, 0, 0, 0);
		Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
		Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
		Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
		Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
		Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

		Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

		Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
		Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

		bool overlap = false;
		if (G.getLevel1())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
		else if (G.getLevel2())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
		else if (G.getLevel3())
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


		if (!(overlap)) {
			Shape S(2, x_0, y_0, 30, 40, 0, 0, 0);
			if (!(S1.overlapping(S)))

			{
				yI -= 10;

				G.getP()[0].setface(key);
			}
			else
			{
				srand(time(0));
				G.getP()[0].setScore(++score2);
				srand(time(0));

				x_0 = rand() % 750;
				y_0 = rand() % 950;
				Shape S5(2, x_0, y_0, 30, 40, 0, 0, 0);
				if (G.getLevel1())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
				else if (G.getLevel2())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
				else if (G.getLevel3())
					overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				while (overlap)
				{
					S5.setX(rand() % 750);
					S5.setY(rand() % 950);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

				}
				x_0 = S5.getX();
				y_0 = S5.getY();
			}


		}
	}
	
	
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		ofstream file;
		file.open("name.txt",ios_base::app);
		ofstream file2;
		file2.open("score.txt",ios_base::app);
		string x = G.getP()[0].getName() +"\n";
		file << x;
		string x2= to_string(G.getP()[0].getScore()) + "\n";
		file2 << x2;
		file.close();
		file2.close();
		exit(1); // exit the program when escape key is pressed.
	}
	if (key == 'e')
	{
		gen5 = false;
		if (G.getLevel1())
			i2_3--;
		else if (G.getLevel2())
			i2_2--;
		else
			i2_1--;

		G.getP()[1].setface2(key);

	}
	if (key == 'q')
	{

		gen6 = false;
		G.getP()[1].setface2(key);

	}

	if (key == 'l')
	{
		if (G.getMenu())
		{

			
				glutDisplayFunc(leaderboard);
			//}

		}
		gen4 = false;
		G.getP()[0].setface2(key);
	}
	if (key == 'w')
	{
		if (!(G.getP()[1].getBot()))
		{
			if (y_0 + 10 > 800)
			{
				y_0 = 10;
			}

			Shape S1(2, x_0, y_0 + 10, 30, 40, 0, 0, 0);

			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			if (!(overlap)) {
				Shape S(2, xI, yI, 30, 40, 0, 0, 0);
				if (!(S1.overlapping(S)))
				{
					y_0 += 10;
					G.getP()[1].setface(key);
				}
				else
				{
					srand(time(0));

					xI = rand() % 750;
					yI = rand() % 950;
					Shape S5(2, xI, yI, 30, 40, 0, 0, 0);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					while (overlap)
					{
						S5.setX(rand() % 750);
						S5.setY(rand() % 950);
						if (G.getLevel1())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
						else if (G.getLevel2())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
						else if (G.getLevel3())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					}
					xI = S5.getX();
					yI = S5.getY();

					G.getP()[1].setScore(++score);
				}
			}
		}

	}
	if (key == 's')
	{
		if (!(G.getP()[1].getBot()))
		{
			if (y_0 - 10 < 0)
				y_0 = 780;
			Shape S1(2, x_0, y_0 - 10, 30, 40, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			if (!(overlap)) {
				Shape S(2, xI, yI, 30, 40, 0, 0, 0);
				if (!(S1.overlapping(S)))

				{

					y_0 -= 10;
					G.getP()[1].setface(key);
				}
				else
				{
					srand(time(0));

					xI = rand() % 750;
					yI = rand() % 950;
					Shape S5(2, xI, yI, 30, 40, 0, 0, 0);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					while (overlap)
					{
						S5.setX(rand() % 750);
						S5.setY(rand() % 950);
						if (G.getLevel1())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
						else if (G.getLevel2())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
						else if (G.getLevel3())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					}
					xI = S5.getX();
					yI = S5.getY();

					G.getP()[1].setScore(++score);
				}
			}
		}


	}
	if (key == 'a')
	{
		if (!(G.getP()[1].getBot()))
		{
			if (x_0 - 10 < 0)
				x_0 = 980;
			Shape S1(2, x_0 - 30, y_0, 30, 40, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			if (!(overlap)) {
				Shape S(2, xI, yI, 30, 40, 0, 0, 0);
				if (!(S1.overlapping(S)))
				{


					x_0 -= 10;
					G.getP()[1].setface(key);
				}
				else
				{
					srand(time(0));

					xI = rand() % 750;
					yI = rand() % 950;
					Shape S5(2, xI, yI, 30, 40, 0, 0, 0);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					while (overlap)
					{
						S5.setX(rand() % 750);
						S5.setY(rand() % 950);
						if (G.getLevel1())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
						else if (G.getLevel2())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
						else if (G.getLevel3())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					}
					xI = S5.getX();
					yI = S5.getY();

					G.getP()[1].setScore(++score);
				}
			}
		}
	}
	if (key == 'd')
	{
		if(!(G.getP()[1].getBot()))
		{
			if (x_0 + 10 > 1000)
				x_0 = 10;
			Shape S1(2, x_0 + 10, y_0, 30, 40, 0, 0, 0);
			Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
			Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
			Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
			Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
			Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

			Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

			Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
			Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

			bool overlap = false;
			if (G.getLevel1())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
			else if (G.getLevel2())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
			else if (G.getLevel3())
				overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));


			if (!(overlap)) {
				Shape S(2, xI, yI, 30, 40, 0, 0, 0);
				if (!(S1.overlapping(S)))

				{

					x_0 += 10;
					G.getP()[1].setface(key);
				}
				else
				{
					srand(time(0));

					xI = rand() % 750;
					yI = rand() % 950;
					Shape S5(2, xI, yI, 30, 40, 0, 0, 0);
					if (G.getLevel1())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
					else if (G.getLevel2())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
					else if (G.getLevel3())
						overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					while (overlap)
					{
						S5.setX(rand() % 750);
						S5.setY(rand() % 950);
						if (G.getLevel1())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)));
						else if (G.getLevel2())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)));
						else if (G.getLevel3())
							overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

					}
					xI = S5.getX();
					yI = S5.getY();

					G.getP()[1].setScore(++score);
				}
			}
		}
	}
	if (key == 'r')
	{
		gen2 = false;
		G.getP()[1].setface2(key);
	}
	if (key == 'm')
	{
		cout << "hi" << endl;
		gen3 = false;
		if (G.getLevel1())
			i1--;
		else if (G.getLevel2())
			i2--;
		else
			i3--;
		G.getP()[0].setface2(key);
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if (key == 'P' || key == 'p')
	{
		if (G.getset() && G.getP()[0].getv()==NULL)
		{
			G.getP()[0].settype(2);
			G.getP()[0].setv();
		}
		else if (G.getset() && G.getP()[1].getv() == NULL)
		{  
			G.getP()[1].settype(2);
			G.getP()[1].setv();
			G.setset(false);
			if (G.getP()[0].getBot())
				G.setLevel1(true);
			else
				G.setLevel2(true);
			glutDisplayFunc(GameDisplay);
		}
		if (G.getWin_scr())
		{
			G.setLevel1(true);
			G.setWin_scr(false);
			score = 0;
			score2 = 0;
			xI = 10;
			yI = 30;
			x_0 = 900;
			y_0 = 30;
		}
	}
	if ( key=='O'||key == 'o')
	{
		
		G.setMenu(false);
		G.setset(true);
		G.getP()[1].setBot(true);
		glutDisplayFunc(settings);
	}
	if (key == ' ')
	{
		gen = false;
		G.getP()[0].setface2(key);

	}
	if (key == 't')
	{
		if (G.getMenu())
		{
			G.getP()[1].setBot(false);
			
			G.setMenu(false);
			G.setset(true);
			glutDisplayFunc(settings);

		}
		else if (G.getset() && G.getP()[0].getv() == NULL)
		{
			G.getP()[0].settype(1);
			G.getP()[0].setv();

		}
		else if (G.getset() && G.getP()[1].getv() == NULL)
		{
			G.getP()[1].settype(1);
			G.getP()[1].setv();
			G.setset(false);
			if (G.getP()[1].getBot())
				G.setLevel1(true);
			else
				G.setLevel3(true);
			glutDisplayFunc(GameDisplay);
		}
	}
	if (key == 'h')
	{
		if (G.getset() && G.getP()[0].getv() == NULL)
		{
			G.getP()[0].settype(3);
			G.getP()[0].setv();
		}
		else if (G.getset() && G.getP()[1].getv() == NULL)
		{
			G.getP()[1].settype(3);
			G.getP()[1].setv();
			G.setset(false);
			G.setLevel1(true);
			glutDisplayFunc(GameDisplay);
		}
	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	if(G.getP()[1].getBot())
	// implement your functionality here
	{
		move_bot();
		b_shoot();
		// once again we tell the library to call our Timer function after next 1000/FPS
	}
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*g
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	bool overlap = false;
	srand(time(0));
	x_0 = rand() % 750;
	y_0 = rand() % 950;
	y_b = rand() % 750;
	xI = rand() % 750;
	yI = rand() % 950;
	y_b2 = rand() % 750;
	x_b2 = rand() % 950;
	y_b3 = rand() % 750;
	x_b3 = rand() % 950;


	x_b = rand() % 950;
	Shape S1(2, x_0, y_0 + 10, 30, 40, 0, 0, 0);
	Shape b1(2, x_b2, y_b2 + 10, 30, 40, 0, 0, 0);

	Shape b2(2, x_b3, y_b3 + 10, 30, 40, 0, 0, 0);

	Shape S2(2, ptx2, pty2, 400, 10, 0, 0, 0);
	Shape S3(2, ptx1, pty1, 400, 10, 0, 0, 0);
	Shape S10(2, ptx6, pty6, 400, 10, 0, 0, 0);
	Shape S9(2, ptx5, pty5, 400, 10, 0, 0, 0);
	Shape S4(2, ptx3, pty3, 10, 300, 0, 0, 0);

	Shape S7(2, ptx7, pty7, 10, 300, 0, 0, 0);

	Shape S8(2, ptx8, pty8, 10, 300, 0, 0, 0);
	Shape S6(2, ptx4, pty4, 10, 300, 0, 0, 0);

		overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));
	srand(time(0));
	
	while (overlap)
	{
		S1.setX(rand() % 750);
		S1.setY(rand() % 950);
		
			overlap = ((S1.overlapping(S2)) || (S1.overlapping(S3)) || (S1.overlapping(S4)) || (S1.overlapping(S6)) || (S1.overlapping(S9)) || (S1.overlapping(S10)) || (S1.overlapping(S7)) || (S1.overlapping(S8)));

	}
	x_0 = S1.getX();
	y_0 = S1.getY();
	y_b = S1.getX();
	x_b = S1.getY();
	
		overlap = ((S2.overlapping(S1)) || (S2.overlapping(S3)) || (S2.overlapping(S4)) || (S2.overlapping(S6)) || (S2.overlapping(S9)) || (S2.overlapping(S10)) || (S2.overlapping(S7)) || (S2.overlapping(S8)));
		while (overlap)
	{
		S2.setX(rand() % 750);
		S2.setY(rand() % 950);
		
			overlap = ((S2.overlapping(S1)) || (S2.overlapping(S3)) || (S2.overlapping(S4)) || (S2.overlapping(S6)) || (S2.overlapping(S9)) || (S2.overlapping(S10)) || (S2.overlapping(S7)) || (S2.overlapping(S8)));

	}

	xI = S2.getX();
	yI = S2.getY();

	string x;
	cout << "enter name" << endl;
	cin >> x;
	G.getP()[0].setName(x);
	G.getM()[0].setNo(4) ;
	G.getM()[0].alloc();
	G.getP()[1].setBot(false);
	G.getP()[0].setScore(0);
	bool menuu = true;
	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("KOMBAT by Ahmad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(menu);
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	//if(G.getP()[1].getBot())
		//glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	delete[] arr;
	delete[]arr2;

	return 0;
}
#endif /* RushHour_CPP_ */
