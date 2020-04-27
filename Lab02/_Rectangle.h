#pragma once
#include "Color.h"
#include "Point.h"
#include "Closed_Figure.h"

//����Rectangle���������ì�ܣ����ǰ�����_
class _Rectangle : public Closed_Figure{
private:
	//���Ͻ�����,���½�����
	Point left_top;
	Point right_bottom;
	//˽�о�̬��Ա��������¼��Ӧ�Ļ����,ÿ�ε��ù��캯��ʱ��++
	static int count_objects;

public:
	//�޲ι��캯��
	_Rectangle();
	
	_Rectangle(Point left_t, Point right_b, Color fill_colr, Color border_colr);

	//�������캯��
	_Rectangle(const _Rectangle& r);
	//��������
	~_Rectangle();

	//���麯�������������
	virtual void draw();

	//setter
	void set_left_top(Point left_t);
	void set_right_bottom(Point right_b);

	//getter
	Point get_left_top();
	Point get_right_bottom();
	//count_objects��getter����
	static int get_cnt();
};