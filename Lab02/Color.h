#pragma once
#include <graphics.h>

class Color {
private:
	color_t color;
	int R, G, B;
	//������
	static int count_objects;

public:
	//Ĭ�Ϲ��캯��
	Color();
	//�вι��캯��
	Color(int r, int g, int b);
	Color(const Color& c);
	~Color();

	//setter
	void set_color(color_t color);
	void set_R(int r);
	void set_G(int g);
	void set_B(int b);

	//getter
	color_t get_color();
	int get_R();
	int get_G();
	int get_B();
	static int get_cnt();
};