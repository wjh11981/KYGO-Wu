#pragma once
#include <graphics.h>

class Point {
private:
	int x, y;
	//������
	static int count_objects;

public:
	//�޲ι��캯��
	Point();
	//�вι��캯��
	Point(int x, int y);
	Point(const Point& p);
	~Point();

	//setter
	void set_X(int x);
	void set_Y(int y);

	//getter
	int get_X();
	int get_Y();
	static int get_cnt();
};