#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"NewsAgency.h"
#include"Observer.h"

int main()
{
	//������
	NewsAgency* new1 = new Morgans;
	NewsAgency* new2 = new BaGua;
	//�۲��ߣ������ߣ�
	Longs* mylong = new Longs(new1,"��");
	Batuo* batuo = new Batuo(new2,"����");
	Shanks* shanks = new Shanks(new1, "���˼");
	//�ɷ�����������Ϣ
	new1->notify("���桤D��·�ɳ�Ϊ��������µ��Ļ�֮һ, �ͽ�30�ڱ���!!!");
	cout << "======================================" << endl;
	new2->notify("Ů�ۺ������Ҫ�޸�·��, ��·��������, ������...");

	delete new1;
	delete new2;
	delete mylong;
	delete shanks;
	delete batuo;

	return 0;
}