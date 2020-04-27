#pragma once
#include "Color.h"
#include "Point.h"
#include "Closed_Figure.h"

//由于Rectangle与库中名称矛盾，因此前面加上_
class _Rectangle : public Closed_Figure{
private:
	//左上角坐标,右下角坐标
	Point left_top;
	Point right_bottom;
	//私有静态成员变量，记录对应的活动对象,每次调用构造函数时则++
	static int count_objects;

public:
	//无参构造函数
	_Rectangle();
	
	_Rectangle(Point left_t, Point right_b, Color fill_colr, Color border_colr);

	//拷贝构造函数
	_Rectangle(const _Rectangle& r);
	//析构函数
	~_Rectangle();

	//纯虚函数在子类的声明
	virtual void draw();

	//setter
	void set_left_top(Point left_t);
	void set_right_bottom(Point right_b);

	//getter
	Point get_left_top();
	Point get_right_bottom();
	//count_objects的getter函数
	static int get_cnt();
};