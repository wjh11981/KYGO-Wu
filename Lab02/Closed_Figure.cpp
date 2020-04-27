#include "Closed_Figure.h"
#include "ege_stream.h"

//初始化
int Closed_Figure::count_objects = 0;

//创建子类对象时，会自动调用父类的无参构造函数
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

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Closed_Figure对象数目：" << count_objects << std::endl;
}

//设置填充颜色
void Closed_Figure::set_fill_color(Color fill_colr) {
	fill_color = new Color(fill_colr);
}
//设置边界颜色
void Closed_Figure::set_border_color(Color border_colr) {
	border_color = new Color(border_colr);
}
//设置填充状态
void Closed_Figure::set_isfilled(bool is) {
	isfilled = is;
}

//获取填充颜色
Color* Closed_Figure::get_fill_color() {
	return fill_color;
}
//获取边界颜色
Color* Closed_Figure::get_border_color() {
	return border_color;
}
//获取填充状态
bool Closed_Figure::get_isfilled() {
	return isfilled;
}
int Closed_Figure::get_cnt() {
	return count_objects;
}