#pragma once
#include "Point.h"
#include "Color.h"

//线段不是封闭图形，因此并没有继承Close_Figure类
class Line
{
private:
	//两个点的坐标，以及直线颜色
	Point p1, p2;
	Color* color;
	//计数器
	static int count_objects;

public:
	Line();
	Line(Point p1, Point p2, Color color);
	Line(const Line& l);
	~Line();
	//setter
	void set_p1(Point p1);
	void set_p2(Point p2);
	void set_color(Color color);

	//getter
	Point get_p1();
	Point get_p2();
	Color* get_color();
	static int get_cnt();
};

