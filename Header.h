#pragma once
#include"Classes.h"
#include"Header1.h"
class vehicle;
class Player
{
	string name;
	vehicle* v;//association 
	int type;
	int score;
	int l_ammo;
	int m_ammo;
	bool bot;
	int key;
	int key2;
public:
	void setv();
	Player()
	{
		score = 0;
		m_ammo = 3;
		l_ammo = 1;
		v = NULL;
	}
	vehicle* getv() { return v; }
	int gettype() { return type; }
	void settype(int t) { type = t; }


	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}


	int getScore() {
		return this->score;
	}
	void setScore(int score) {
		this->score = score;
	}
	int getface() {
		return this->key;
	}
	void setface(int score) {
		this->key = score;
	}
	int getface2() {
		return this->key2;
	}
	void setface2(int score) {
		this->key2 = score;
	}


	int getL_ammo() {
		return this->l_ammo;
	}
	void setL_ammo(int l_ammo) {
		this->l_ammo = l_ammo;
	}


	int getM_ammo() {
		return this->m_ammo;
	}
	void setM_ammo(int m_ammo) {
		this->m_ammo = m_ammo;
	}


	bool getBot() {
		return this->bot;
	}
	void setBot(bool bot) {
		this->bot = bot;
	}
	void shoot_l();
	void shoot_m();
	void shoot();




};