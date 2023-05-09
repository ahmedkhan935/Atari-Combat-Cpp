#pragma once
class obstacle
{
	int x;
	int y;
	int L;
	int W;
public:

	int getX() {
		return this->x;
	}
	void setX(int x) {
		this->x = x;
	}


	int getY() {
		return this->y;
	}
	void setY(int y) {
		this->y = y;
	}


	int getL() {
		return this->L;
	}
	void setL(int L) {
		this->L = L;
	}


	int getW() {
		return this->W;
	}
	void setW(int W) {
		this->W = W;
	}

};