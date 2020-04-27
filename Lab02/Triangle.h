#pragma once
#include "Color.h"
#include "Point.h"
#include "Closed_Figure.h"
//lines��Ϊ�����εı���=3
#define lines 3

class Triangle :public Closed_Figure{
private:
	//��������������ɫ,�Ƿ񽫱����
	Point p1, p2, p3;
	//˽�о�̬��Ա��������¼��Ӧ�Ļ����,ÿ�ε��ù��캯��ʱ��++
	static int count_objects;

public:
	//�޲ι��캯��
	Triangle();
	Triangle(Point P1, Point P2, Point P3, Color fill_colr, Color border_colr);
	//�������캯��
	Triangle(const Triangle& t);
	//��������
	~Triangle();

	virtual void draw();

	//setter
	void set_p1(Point P1);
	void set_p2(Point P2);
	void set_p3(Point P3);

	//getter
	Point get_p1(Point P1);
	Point get_p2(Point P2);
	Point get_p3(Point P3);
	//count_objects��getter����
	static int get_cnt();
};