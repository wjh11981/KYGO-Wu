#include "Line.h"
#include "ege_stream.h"

int Line::count_objects = 0;

//无参构造函数，初始化为(0,0) (0,100)
Line::Line() {
	p1.set_X(0);
	p1.set_Y(0);

	p2.set_X(0);
	p2.set_Y(100);

	color = new Color();

	//画线段
	int p[4] = { p1.get_X(),p1.get_Y(),p2.get_X(),p2.get_Y() };
	drawlines(1, p);
	count_objects++;
}
//有参构造函数
Line::Line(Point p1, Point p2,Color color) {
	this->p1 = p1;
	this->p2 = p2;
	this->color = new Color(color);
	//画线段
	int p[4] = { p1.get_X(),p1.get_Y(),p2.get_X(),p2.get_Y() };
	setcolor(color.get_color());
	drawlines(1, p);
	count_objects++;
}
Line::Line(const Line& l) {
	p1 = l.p1;
	p2 = l.p2;
	
	//deep copy
	color = new Color();
	color->set_color(l.color->get_color());

	count_objects++;
}
Line::~Line() {

	delete color;

	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Line对象数目：" << count_objects << std::endl;
}
//setter
void Line::set_p1(Point p1) {
	this->p1 = p1;
}
void Line::set_p2(Point p2) {
	this->p2 = p2;
}
void Line::set_color(Color color) {
	this->color = new Color(color);
}

//getter
Point Line::get_p1() {
	return p1;
}
Point Line::get_p2() {
	return p2;
}
Color* Line::get_color() {
	return color;
}
int Line::get_cnt() {
	return count_objects;
}