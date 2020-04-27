#pragma once
#include "Color.h"
#include "Point.h"
#include "Closed_Figure.h"
//lines作为三角形的边数=3
#define lines 3

class Triangle :public Closed_Figure{
private:
	//三个点的坐标和颜色,是否将被填充
	Point p1, p2, p3;
	//私有静态成员变量，记录对应的活动对象,每次调用构造函数时则++
	static int count_objects;

public:
	//无参构造函数
	Triangle();
	Triangle(Point P1, Point P2, Point P3, Color fill_colr, Color border_colr);
	//拷贝构造函数
	Triangle(const Triangle& t);
	//析构函数
	~Triangle();

	virtual void draw();

	//setter
	void set_p1(Point P1);
	void set_p2(Point P2);
	void set_p3(Point P3);

	//getter
	Point get_p1(Point P1);
	Point get_p2(Point P2);
	Point get_p3(Point P3);
	//count_objects的getter函数
	static int get_cnt();
};