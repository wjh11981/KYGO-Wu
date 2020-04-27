#include "Triangle.h"
#include "ege_stream.h"

//静态成员变量的初始化
int Triangle::count_objects = 0;

//无参构造函数
Triangle::Triangle() {
	p1.set_X(0);
	p1.set_Y(0);

	p2.set_X(100);
	p2.set_Y(100);

	p3.set_X(100);
	p3.set_Y(0);
	isfilled = false;

	fill_color = new Color();
	border_color = new Color();

	count_objects++;
}
Triangle::Triangle(Point P1, Point P2, Point P3, Color fill_colr, Color border_colr) {
	p1 = P1;
	p2 = P2;
	p3 = P3;
	isfilled = true;

	fill_color = new Color(fill_colr);
	border_color = new Color(border_colr);

	count_objects++;
}
//拷贝构造函数的定义
Triangle::Triangle(const Triangle& t) {
	p1 = t.p1;
	p2 = t.p2;
	p3 = t.p3;
	isfilled = t.isfilled;

	//deep copy
	fill_color = new Color();
	fill_color->set_color(t.fill_color->get_color());

	border_color = new Color();
	border_color->set_color(t.border_color->get_color());

	count_objects++;
}
Triangle::~Triangle() {

	/*fill_color和border_color会在Closed_Figure类中delete
	因此，此处就不需要delete了*/

	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Triangle对象数目：" << count_objects << std::endl;
}

void Triangle::draw() {
	//根据三点坐标画三角形，并设置边界和填充颜色
	int p[lines * 4] = { p1.get_X(),p1.get_Y(),p2.get_X(),p2.get_Y(),p2.get_X(),p2.get_Y(),p3.get_X(),p3.get_Y(),p3.get_X(),p3.get_Y(),p1.get_X(),p1.get_Y() };

	setcolor(border_color->get_color());
	drawlines(lines, p);

	setfillcolor(fill_color->get_color());
	//因为重心一定在圆内部,以重心O作为三角形内部的点进行填充，向量OA,OB,OC之和为0
	floodfill((p1.get_X() + p2.get_X() + p3.get_X()) / 3, (p1.get_Y() + p2.get_Y() + p3.get_Y()) / 3, border_color->get_color());
}

//setter
void Triangle::set_p1(Point P1) {
	p1 = P1;
}
void Triangle::set_p2(Point P2) {
	p2 = P2;
}
void Triangle::set_p3(Point P3) {
	p3 = P3;
}

//getter
Point Triangle::get_p1(Point P1) {
	return p1;
}
Point Triangle::get_p2(Point P2) {
	return p2;
}
Point Triangle::get_p3(Point P3) {
	return p3;
}
//count_objects的getter方法
int Triangle::get_cnt() {
	return count_objects;
}