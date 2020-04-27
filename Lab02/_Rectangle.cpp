#include "_Rectangle.h"
#include "ege_stream.h"

//静态成员变量的初始化
int _Rectangle::count_objects = 0;

//无参构造函数
_Rectangle::_Rectangle() {
	//默认左上角坐标为(0，0)
	left_top.set_X(0);
	left_top.set_Y(0);
	//右上角坐标为(20，10)
	right_bottom.set_X(20);
	right_bottom.set_Y(10);
	isfilled = false;

	fill_color = new Color();
	border_color = new Color();
	//每次调用构造函数，则会使计数器++
	count_objects++;
}

_Rectangle::_Rectangle(Point left_t, Point right_b, Color fill_colr, Color border_colr) {
	left_top = left_t;
	right_bottom = right_b;

	isfilled = true;

	fill_color = new Color(fill_colr);
	border_color = new Color(border_colr);

	count_objects++;
}
//拷贝构造函数的实现
_Rectangle::_Rectangle(const _Rectangle& r) {
	left_top = r.left_top;
	right_bottom = r.right_bottom;

	isfilled = r.isfilled;
	//deep copy
	fill_color = new Color();
	fill_color->set_color(r.fill_color->get_color());
	
	border_color = new Color();
	border_color->set_color(r.border_color->get_color());

	count_objects++;
}
_Rectangle::~_Rectangle() {
	/*fill_color和border_color会在Closed_Figure类中delete
	因此，此处就不需要delete了*/
	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "_Rectangle对象数目：" << count_objects << std::endl;
}

void _Rectangle::draw() {
	//根据左上角，右下角坐标画矩形，并设置边界和填充颜色
	setcolor(border_color->get_color());
	rectangle(left_top.get_X(), left_top.get_Y(), right_bottom.get_X(), right_bottom.get_Y());

	setfillcolor(fill_color->get_color());
	floodfill(left_top.get_X() + 1, left_top.get_Y() + 1, border_color->get_color());
}

//setter
//设置左上角点坐标
void _Rectangle::set_left_top(Point left_t) {
	left_top = left_t;
}
//设置右下角点坐标
void _Rectangle::set_right_bottom(Point right_b) {
	right_bottom = right_b;
}

//getter
//获取左上角点坐标
Point _Rectangle::get_left_top() {
	return left_top;
}
//获取右下角点坐标
Point _Rectangle::get_right_bottom() {
	return right_bottom;
}
//count_objects的getter方法
int _Rectangle::get_cnt() {
	return count_objects;
}