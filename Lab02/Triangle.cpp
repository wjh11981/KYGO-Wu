#include "Triangle.h"
#include "ege_stream.h"

//��̬��Ա�����ĳ�ʼ��
int Triangle::count_objects = 0;

//�޲ι��캯��
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
//�������캯���Ķ���
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

	/*fill_color��border_color����Closed_Figure����delete
	��ˣ��˴��Ͳ���Ҫdelete��*/

	count_objects--;

	//��EGE�����
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Triangle������Ŀ��" << count_objects << std::endl;
}

void Triangle::draw() {
	//�����������껭�����Σ������ñ߽�������ɫ
	int p[lines * 4] = { p1.get_X(),p1.get_Y(),p2.get_X(),p2.get_Y(),p2.get_X(),p2.get_Y(),p3.get_X(),p3.get_Y(),p3.get_X(),p3.get_Y(),p1.get_X(),p1.get_Y() };

	setcolor(border_color->get_color());
	drawlines(lines, p);

	setfillcolor(fill_color->get_color());
	//��Ϊ����һ����Բ�ڲ�,������O��Ϊ�������ڲ��ĵ������䣬����OA,OB,OC֮��Ϊ0
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
//count_objects��getter����
int Triangle::get_cnt() {
	return count_objects;
}