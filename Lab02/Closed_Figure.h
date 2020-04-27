#pragma once
#include "Color.h"

//抽象类
class Closed_Figure
{
protected:
	//公共属性
	Color* fill_color;
	Color* border_color;
	bool isfilled;
	//计数器
	static int count_objects;

public:
	//构造函数
	Closed_Figure();
	Closed_Figure(Color fill_colr, Color border_colr, bool is);
	Closed_Figure(const Closed_Figure& c);
	~Closed_Figure();

	//纯虚函数draw()
	virtual void draw() = 0;
	//setter
	void set_fill_color(Color fill_colr);
	void set_border_color(Color border_colr);
	void set_isfilled(bool is);
	//getter
	Color* get_fill_color();
	Color* get_border_color();
	bool get_isfilled();
	//获取计数
	static int get_cnt();
};

