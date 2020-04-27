#include "Circle.h"
#include "ege_stream.h"


//静态成员变量的初始化
int Circle::count_objects = 0;

Circle::Circle() {
	r = 100;
	isfilled = false;
	center.set_X(300);
	center.set_Y(200);

	fill_color = new Color();
	border_color = new Color();

	count_objects++;
}

Circle::Circle(Point Center, int R, Color fill_colr, Color border_colr) {
	center = Center;
	r = R;
	isfilled = true;

	fill_color = new Color(fill_colr);
	border_color = new Color(border_colr);

	count_objects++;
}
//拷贝构造函数的声明
Circle::Circle(const Circle& c) {
	center = c.center;
	r = c.r;
	isfilled = c.isfilled;

	//deep copy
	fill_color = new Color();
	fill_color->set_color(c.fill_color->get_color());

	border_color = new Color();
	border_color->set_color(c.border_color->get_color());

	count_objects++;
}

Circle::~Circle() {
	/*fill_color和border_color会在Closed_Figure类中delete
	因此，此处就不需要delete了*/

	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Circle对象数目：" << count_objects << std::endl;
}

void Circle::draw() {
	//画圆，设置边界和填充颜色
	setcolor(border_color->get_color());
	circle(center.get_X(), center.get_Y(), r);

	setfillcolor(fill_color->get_color());
	//以圆心坐标作为内部点进行填充
	floodfill(center.get_X(), center.get_Y(), border_color->get_color());
}

//设置圆心坐标
void Circle::set_center(Point Center){
	center = Center;
}
//设置半径
void Circle::set_r(int R) {
	r = R;
}

//获取圆心坐标
Point Circle::get_center() {
	return center;
}
//获取半径
int Circle::get_r() {
	return r;
}
//count_objects的getter方法
int Circle::get_cnt() {
	return count_objects;
}