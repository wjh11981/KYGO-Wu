#pragma once
#include <graphics.h>

class Environment_Controler {
private:
	int lenth, width;
	//������
	static int count_objects;

public:
	//�޲ι��캯��
	Environment_Controler();
	//�вι��캯��
	Environment_Controler(int lenth, int width);
	Environment_Controler(const Environment_Controler& e);
	~Environment_Controler();
	void set_lenth(int l);
	void set_width(int w);

	int get_lenth();
	int get_width();
	static int get_cnt();
};
