#pragma once
#include "Color.h"
#include "Point.h"
#include "Closed_Figure.h"

class Circle :public Closed_Figure {
private:
	//圆心坐标，半径和颜色,是否将被填充
	Point center;
	int r;
	//私有静态成员变量，记录对应的活动对象,每次调用构造函数时则++
	static int count_objects;

public:
	Circle();
	Circle(Point Center, int R, Color fill_colr, Color border_colr);
	//拷贝构造函数
	Circle(const Circle& c);
	//析构函数
	~Circle();
	
	virtual void draw();

	//setter
	void set_center(Point Center);
	void set_r(int R);

	//getter
	Point get_center();
	int get_r();
	//count_objects的getter函数
	static int get_cnt();
};