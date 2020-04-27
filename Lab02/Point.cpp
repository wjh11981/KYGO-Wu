#include "Point.h"
#include "ege_stream.h"

int Point::count_objects = 0;

//�޲ι��캯��
Point::Point() {
	x = 0;
	y = 0;
	count_objects++;
}
//�вι��캯��
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

	//��EGE�����
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Point������Ŀ��" << count_objects << std::endl;
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