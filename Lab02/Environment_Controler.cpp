#include "Environment_Controler.h"
#include "ege_stream.h"

int Environment_Controler::count_objects = 0;

//无参构造函数
Environment_Controler::Environment_Controler() {
	lenth = 600;
	width = 600;
	
	initgraph(600, 600, 0);
	setbkcolor(WHITE);
	count_objects++;
}
//有参构造函数
Environment_Controler::Environment_Controler(int lenth, int width) {
	this->lenth = lenth;
	this->width = width;
	initgraph(lenth, width, 0);
	setbkcolor(WHITE);
	count_objects++;

};
Environment_Controler::Environment_Controler(const Environment_Controler& e) {
	lenth = e.lenth;
	width = e.width;
	count_objects++;

}

Environment_Controler::~Environment_Controler() {
	
	count_objects--;

	//在EGE中输出
	EgeStream::BasicEgeStream egeout;
	EgeStream::BasicEgeStream egein;
	egeout << "Evironment_Controler对象数目：" << count_objects << std::endl;

	getch();
	closegraph();
}

void Environment_Controler::set_lenth(int l) {
	lenth = l;
}
void Environment_Controler::set_width(int w) {
	width = w;
}

int Environment_Controler::get_lenth() {
	return lenth;
}
int Environment_Controler::get_width() {
	return width;
}
int Environment_Controler::get_cnt() {
	return count_objects;
}