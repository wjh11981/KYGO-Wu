#pragma once
#include "Color.h"

//������
class Closed_Figure
{
protected:
	//��������
	Color* fill_color;
	Color* border_color;
	bool isfilled;
	//������
	static int count_objects;

public:
	//���캯��
	Closed_Figure();
	Closed_Figure(Color fill_colr, Color border_colr, bool is);
	Closed_Figure(const Closed_Figure& c);
	~Closed_Figure();

	//���麯��draw()
	virtual void draw() = 0;
	//setter
	void set_fill_color(Color fill_colr);
	void set_border_color(Color border_colr);
	void set_isfilled(bool is);
	//getter
	Color* get_fill_color();
	Color* get_border_color();
	bool get_isfilled();
	//��ȡ����
	static int get_cnt();
};

