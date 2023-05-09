#pragma once
#include<iostream>
#include"util.h"
#include<string>
#include"Header.h"
#include"Header2.h"
using namespace std;




class Game
{
	Player P[2];
	Map M[3];
	int level;
	bool menu;
	bool settings;
	bool level1;
	bool level2;
	bool level3;
	bool win_scr;
public:
	Game()
	{
		menu = true;
		level1 = false;
		level2 = false;
		level3 = false;
		win_scr = false;
	}
	Player* getP() {
		return this->P;
	}
	


	Map* getM() {
		return this->M;
	}
	
	int getLevel() {
		return this->level;
	}
	void setLevel(int level) {
		this->level = level;
	}
	bool getMenu() {
		return this->menu;
	}
	void setMenu(bool menu) {
		this->menu = menu;
	}
	bool getset() {
		return this->settings;
	}
	void setset(bool menu) {
		this->settings = menu;
	}


	bool getLevel1() {
		return this->level1;
	}
	void setLevel1(bool level1) {
		this->level1 = level1;
	}


	bool getLevel2() {
		return this->level2;
	}
	void setLevel2(bool level2) {
		this->level2 = level2;
	}


	bool getLevel3() {
		return this->level3;
	}
	void setLevel3(bool level3) {
		this->level3 = level3;
	}


	bool getWin_scr() {
		return this->win_scr;
	}
	void setWin_scr(bool win_scr) {
		this->win_scr = win_scr;
	}



};
class vehicle
{
public:
	virtual void draw(Player &P, int xI, int yI,int i) = 0;//pure virtual func
};

class Tank :public vehicle//inheeritnce
{
public:
	void draw(Player& P, int xI, int yI,int i)//polymorphism
	{
		if(i==0)
		{
			if (P.getface() == GLUT_KEY_RIGHT )
			{
				cout << "right" << endl;
				DrawRectangle(xI, yI, 20, 10, colors[WHITE]);
				DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
				DrawRectangle(xI, yI + 20, 20, 10, colors[WHITE]);
			}
			if (P.getface() == GLUT_KEY_LEFT )
			{
				cout << "Left" << endl;
				DrawRectangle(xI + 20, yI, 20, 10, colors[WHITE]);
				DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
				DrawRectangle(xI + 20, yI + 20, 20, 10, colors[WHITE]);
			}
			else if (P.getface() == GLUT_KEY_UP)
			{
				DrawRectangle(xI, yI, 10, 20, colors[WHITE]);
				DrawRectangle(xI + 10, yI, 10, 40, colors[DARK_GREEN]);
				DrawRectangle(xI + 20, yI, 10, 20, colors[WHITE]);
			}
			else if (P.getface() == GLUT_KEY_DOWN )
			{
				DrawRectangle(xI, yI + 20, 10, 20, colors[WHITE]);
				DrawRectangle(xI + 10, yI, 10, 40, colors[DARK_GREEN]);
				DrawRectangle(xI + 20, yI + 20, 10, 20, colors[WHITE]);
			}
		}
		else
		{
			if (P.getface()  == 'd')
			{
				cout << "right" << endl;
				DrawRectangle(xI, yI, 20, 10, colors[WHITE]);
				DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
				DrawRectangle(xI, yI + 20, 20, 10, colors[WHITE]);
			}
			if (P.getface()  == 'a')
			{
				cout << "Left" << endl;
				DrawRectangle(xI + 20, yI, 20, 10, colors[WHITE]);
				DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
				DrawRectangle(xI + 20, yI + 20, 20, 10, colors[WHITE]);
			}
			else if (P.getface() == 'w')
			{
				DrawRectangle(xI, yI, 10, 20, colors[WHITE]);
				DrawRectangle(xI + 10, yI, 10, 40, colors[DARK_GREEN]);
				DrawRectangle(xI + 20, yI, 10, 20, colors[WHITE]);
			}
			else if (P.getface()  == 's')
			{
				DrawRectangle(xI, yI + 20, 10, 20, colors[WHITE]);
				DrawRectangle(xI + 10, yI, 10, 40, colors[DARK_GREEN]);
				DrawRectangle(xI + 20, yI + 20, 10, 20, colors[WHITE]);
			}
		}

		glutPostRedisplay();
	}
};
class plane :public vehicle
{
public:
	void draw(Player& P,int xI,int yI,int i)
	{
		if (P.getface() == GLUT_KEY_RIGHT || P.getface() == 'd')
		{
			DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
			DrawRectangle(xI + 15, yI - 5, 10, 40, colors[DARK_GREEN]);

		}
		else if (P.getface() == GLUT_KEY_LEFT || P.getface() == 'a')
		{
			DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
			DrawRectangle(xI + 15, yI - 5, 10, 40, colors[DARK_GREEN]);

		}
		else if (P.getface() == GLUT_KEY_UP || P.getface() == 'w')
		{
			DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
			DrawRectangle(xI + 15, yI - 5, 10, 40, colors[DARK_GREEN]);

		}
		else if (P.getface() == GLUT_KEY_DOWN || P.getface() == 's')
		{
			DrawRectangle(xI, yI + 10, 40, 10, colors[DARK_GREEN]);
			DrawRectangle(xI + 15, yI - 5, 10, 40, colors[DARK_GREEN]);

		}

		glutPostRedisplay();

	}

};
class helicopter :public vehicle
{
public:
	void draw(Player &P,int xI,int yI,int i)
	{
		if (P.getface() == GLUT_KEY_RIGHT || P.getface() == 'd')
		{
			DrawRoundRect(xI, yI, 30, 40, colors[GREEN]);

		}
		else if (P.getface() == GLUT_KEY_LEFT || P.getface() == 'a')
		{
			DrawRoundRect(xI, yI, 30, 40, colors[GREEN]);

		}
		else if (P.getface() == GLUT_KEY_UP || P.getface() == 'w')
		{
			DrawRoundRect(xI, yI, 30, 40, colors[GREEN]);

		}
		else if (P.getface() == GLUT_KEY_DOWN || P.getface() == 's')
		{
			DrawRoundRect(xI, yI, 30, 40, colors[GREEN]);

		}

		glutPostRedisplay();
	}
};
