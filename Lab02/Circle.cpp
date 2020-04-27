#include "Circle.h"
#include "ege_stream.h"


//��̬��Ա�����ĳ�ʼ��
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
//�������캯��������
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
	/*fill_color��border_color����Closed_Figure����delete
	��ˣ��˴��Ͳ���Ҫdelete��*/

	count_objects--;

	//��EGE�����
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Circle������Ŀ��" << count_objects << std::endl;
}

void Circle::draw() {
	//��Բ�����ñ߽�������ɫ
	setcolor(border_color->get_color());
	circle(center.get_X(), center.get_Y(), r);

	setfillcolor(fill_color->get_color());
	//��Բ��������Ϊ�ڲ���������
	floodfill(center.get_X(), center.get_Y(), border_color->get_color());
}

//����Բ������
void Circle::set_center(Point Center){
	center = Center;
}
//���ð뾶
void Circle::set_r(int R) {
	r = R;
}

//��ȡԲ������
Point Circle::get_center() {
	return center;
}
//��ȡ�뾶
int Circle::get_r() {
	return r;
}
//count_objects��getter����
int Circle::get_cnt() {
	return count_objects;
}