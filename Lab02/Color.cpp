#include "color.h"
#include "ege_stream.h"

//初始化
int Color::count_objects = 0;

//默认构造函数
Color::Color() {
	R = 0;
	G = 0;
	B = 0;
	color = EGERGB(R, G, B);
	count_objects++;
}
//有参构造函数
Color::Color(int r, int g, int b) {
	R = r;
	G = g;
	B = b;
	color = EGERGB(R, G, B);
	count_objects++;
}
Color::Color(const Color& c) {
	R = c.R;
	G = c.G;
	B = c.B;
	color = c.color;
	count_objects++;
}
Color::~Color() {
	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Color对象数目：" << count_objects << std::endl;
}

//setter
//设置color后更新R,G,B的值
void Color::set_color(color_t color) {
	this->color = color;
	R = EGEGET_R(color);
	G = EGEGET_G(color);
	B = EGEGET_B(color);
}
//设置R,G,B后同时也更新color的值
void Color::set_R(int r) {
	R = r;
	set_color(EGERGB(R, G, B));
}
void Color::set_G(int g) {
	R = g;
	set_color(EGERGB(R, G, B));
}
void Color::set_B(int b) {
	R = b;
	set_color(EGERGB(R, G, B));
}
//getter
color_t Color::get_color() {
	return color;
}
int Color::get_R() {
	return R;
}
int Color::get_G() {
	return G;
}
int Color::get_B() {
	return B;
}
int Color::get_cnt() {
	return count_objects;
}