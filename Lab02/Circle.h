#pragma once
#include "Color.h"
#include "Point.h"
#include "Closed_Figure.h"

class Circle :public Closed_Figure {
private:
	//Բ�����꣬�뾶����ɫ,�Ƿ񽫱����
	Point center;
	int r;
	//˽�о�̬��Ա��������¼��Ӧ�Ļ����,ÿ�ε��ù��캯��ʱ��++
	static int count_objects;

public:
	Circle();
	Circle(Point Center, int R, Color fill_colr, Color border_colr);
	//�������캯��
	Circle(const Circle& c);
	//��������
	~Circle();
	
	virtual void draw();

	//setter
	void set_center(Point Center);
	void set_r(int R);

	//getter
	Point get_center();
	int get_r();
	//count_objects��getter����
	static int get_cnt();
};