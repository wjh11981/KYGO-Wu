#include "Closed_Figure.h"
#include "ege_stream.h"

//��ʼ��
int Closed_Figure::count_objects = 0;

//�����������ʱ�����Զ����ø�����޲ι��캯��
Closed_Figure::Closed_Figure() {

	count_objects++;

}
Closed_Figure::Closed_Figure(Color fill_colr, Color border_colr, bool is) {
	
	fill_color = new Color(fill_colr);
	border_color = new Color(border_colr);
	
	isfilled = is;

	count_objects++;
}
Closed_Figure::Closed_Figure(const Closed_Figure& c) {

	isfilled = c.isfilled;

	//deep copy
	fill_color = new Color();
	fill_color->set_color(c.fill_color->get_color());

	border_color = new Color();
	border_color->set_color(c.border_color->get_color());

	count_objects++;
}
Closed_Figure::~Closed_Figure() {

	delete fill_color;

	delete border_color;

	count_objects--;

	//��EGE�����
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Closed_Figure������Ŀ��" << count_objects << std::endl;
}

//���������ɫ
void Closed_Figure::set_fill_color(Color fill_colr) {
	fill_color = new Color(fill_colr);
}
//���ñ߽���ɫ
void Closed_Figure::set_border_color(Color border_colr) {
	border_color = new Color(border_colr);
}
//�������״̬
void Closed_Figure::set_isfilled(bool is) {
	isfilled = is;
}

//��ȡ�����ɫ
Color* Closed_Figure::get_fill_color() {
	return fill_color;
}
//��ȡ�߽���ɫ
Color* Closed_Figure::get_border_color() {
	return border_color;
}
//��ȡ���״̬
bool Closed_Figure::get_isfilled() {
	return isfilled;
}
int Closed_Figure::get_cnt() {
	return count_objects;
}