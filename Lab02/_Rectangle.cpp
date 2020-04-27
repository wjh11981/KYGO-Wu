#include "_Rectangle.h"
#include "ege_stream.h"

//��̬��Ա�����ĳ�ʼ��
int _Rectangle::count_objects = 0;

//�޲ι��캯��
_Rectangle::_Rectangle() {
	//Ĭ�����Ͻ�����Ϊ(0��0)
	left_top.set_X(0);
	left_top.set_Y(0);
	//���Ͻ�����Ϊ(20��10)
	right_bottom.set_X(20);
	right_bottom.set_Y(10);
	isfilled = false;

	fill_color = new Color();
	border_color = new Color();
	//ÿ�ε��ù��캯�������ʹ������++
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
//�������캯����ʵ��
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
	/*fill_color��border_color����Closed_Figure����delete
	��ˣ��˴��Ͳ���Ҫdelete��*/
	count_objects--;

	//��EGE�����
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "_Rectangle������Ŀ��" << count_objects << std::endl;
}

void _Rectangle::draw() {
	//�������Ͻǣ����½����껭���Σ������ñ߽�������ɫ
	setcolor(border_color->get_color());
	rectangle(left_top.get_X(), left_top.get_Y(), right_bottom.get_X(), right_bottom.get_Y());

	setfillcolor(fill_color->get_color());
	floodfill(left_top.get_X() + 1, left_top.get_Y() + 1, border_color->get_color());
}

//setter
//�������Ͻǵ�����
void _Rectangle::set_left_top(Point left_t) {
	left_top = left_t;
}
//�������½ǵ�����
void _Rectangle::set_right_bottom(Point right_b) {
	right_bottom = right_b;
}

//getter
//��ȡ���Ͻǵ�����
Point _Rectangle::get_left_top() {
	return left_top;
}
//��ȡ���½ǵ�����
Point _Rectangle::get_right_bottom() {
	return right_bottom;
}
//count_objects��getter����
int _Rectangle::get_cnt() {
	return count_objects;
}