#include "Point.h"
#include "ege_stream.h"

int Point::count_objects = 0;

//无参构造函数
Point::Point() {
	x = 0;
	y = 0;
	count_objects++;
}
//有参构造函数
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
	count_objects++;
}
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	count_objects++;
}
Point::~Point() {
	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Point对象数目：" << count_objects << std::endl;
}
//setter
void Point::set_X(int x) {
	this->x = x;
}
void Point::set_Y(int y) {
	this->y = y;
}
//getter
int Point::get_X() {
	return x;
}
int Point::get_Y() {
	return y;
}
int Point::get_cnt() {
	return count_objects;
}