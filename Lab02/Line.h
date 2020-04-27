#pragma once
#include "Point.h"
#include "Color.h"

//�߶β��Ƿ��ͼ�Σ���˲�û�м̳�Close_Figure��
class Line
{
private:
	//����������꣬�Լ�ֱ����ɫ
	Point p1, p2;
	Color* color;
	//������
	static int count_objects;

public:
	Line();
	Line(Point p1, Point p2, Color color);
	Line(const Line& l);
	~Line();
	//setter
	void set_p1(Point p1);
	void set_p2(Point p2);
	void set_color(Color color);

	//getter
	Point get_p1();
	Point get_p2();
	Color* get_color();
	static int get_cnt();
};

