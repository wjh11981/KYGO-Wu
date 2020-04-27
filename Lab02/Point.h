#pragma once
#include <graphics.h>

class Point {
private:
	int x, y;
	//计数器
	static int count_objects;

public:
	//无参构造函数
	Point();
	//有参构造函数
	Point(int x, int y);
	Point(const Point& p);
	~Point();

	//setter
	void set_X(int x);
	void set_Y(int y);

	//getter
	int get_X();
	int get_Y();
	static int get_cnt();
};