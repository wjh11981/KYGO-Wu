#include "Circle.h"
#include "Color.h"
#include "Environment_Controler.h"
#include "Point.h"
#include "_Rectangle.h"
#include "Triangle.h"
#include "ege_stream.h"
#include "Line.h"
#include <iostream>

using namespace std;

void show() {

	//��ʼ������
	Environment_Controler E{ 1400,1000 };

	//��EGE�д��������
	rectangle(1000, 0, 1390, 1000);
	EgeStream::BasicEgeStream egeout(1010, 10);
	EgeStream::BasicEgeStream egein(1010, 10);
	egeout << "��໭��ߴ�:1000��1000  (���л���Ӣ�����뷨����)"<< endl;

	//����ͼ��
	while (1) {
		egeout << "��ѡ����Ҫ���Ƶ�ͼ�Σ�" << endl;
		int flag;
		egeout << "1->Բ    2->������    3->����    4->��" << endl;
		egein >> flag;

		switch (flag) {

			//��Բ
		case 1: {

			egeout << "��ֱ�����Բ������Ͱ뾶�����빲3λ��" << endl;
			int x, y, r;
			egein >> x >> y >> r;

			egeout << "��ֱ����������ɫ�ͱ߽���ɫ��RGBֵ�����빲6λ��" << endl;
			int r1, g1, b1, r2, g2, b2;
			egein >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;

			//����ָ�룬����draw����
			Circle* C = new Circle{ Point{x,y},r,Color{r1,g1,g2},Color{r2,g2,b2} };
			C->draw();
			//����draw����֮����delete,��ʱdelete��ֱ�ӵ��û������������
			delete C;

			break;

		}
			  //��������
		case 2: {

			egeout << "��ֱ����������ε������������꣨���빲6λ��" << endl;
			int x1, y1, x2, y2, x3, y3;
			egein >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

			egeout << "��ֱ����������ɫ�ͱ߽���ɫ��RGBֵ�����빲6λ��" << endl;
			int r1, g1, b1, r2, g2, b2;
			egein >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
			
			//����ָ�룬����draw����
			Triangle* T = new Triangle{ Point{x1,y1},Point{x2,y2},Point{x3,y3},Color{r1,g1,b1},Color{r2,g2,b2} };
			T->draw();
			//delete
			delete T;
			
			break;

		}
			  //������
		case 3: {

			egeout << "��ֱ�����������ϽǺ����½ǵ����꣨���빲4λ��" << endl;
			int x1, y1, x2, y2;
			egein >> x1 >> y1 >> x2 >> y2;

			egeout << "��ֱ����������ɫ�ͱ߽���ɫ��RGBֵ�����빲6λ��" << endl;
			int r1, g1, b1, r2, g2, b2;
			egein >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
			
			//����ָ�룬����draw����
			_Rectangle* R = new _Rectangle{ Point{x1,y1},Point{x2,y2},Color{r1,g1,b1},Color{r2,g2,b2} };
			R->draw();
			//delete
			delete R;
			
			break;
			
		}
			  //���߶�
		case 4: {

			egeout << "��ֱ������߶����˵����꣨���빲4λ��" << endl;
			int x1, y1, x2, y2;
			egein >> x1 >> y1 >> x2 >> y2;

			egeout << "�������߶���ɫ��RGBֵ�����빲3λ��" << endl;
			int r, g, b;
			egein >> r >> g >> b;

			Line L{ Point{x1,y1},Point{x2,y2},Color{r,g,b} };

			break;

		}
		}
		//����
		egeout << "�Ƿ�����" << endl;
		egeout << "1->yes    2->no" << endl;
		int flag1;
		egein >> flag1;
		if (flag1 == 1) {
			cleardevice();
			//�������ɳ�ʼ�����
			rectangle(1000, 0, 1390, 1000);
			EgeStream::BasicEgeStream egeout(1010, 10);
			EgeStream::BasicEgeStream egein(1010, 10);
			egeout << "��໭��ߴ�:1000��1000  (���л���Ӣ�����뷨)" << endl;

		}
	}
}


int main(){
	show();
	system("pause");
	return 0;
}
