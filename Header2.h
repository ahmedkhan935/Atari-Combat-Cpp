#pragma once
#include"Header1.h"
class obstacle;
class Map
{
	obstacle* o;
	int no;
public:
	Map()
	{
		o = nullptr;
	}
	obstacle* getO() {
		if (o == nullptr)
			alloc();
		return this->o;
	}
	void alloc()
	{
		o = new obstacle[no];
	}
	void setO(obstacle* o) {
		this->o = o;
	}


	int getNo() {
		return this->no;
	}
	void setNo(int no) {
		this->no = no;
	}
	~Map()
	{
		delete[] o;
	}


};