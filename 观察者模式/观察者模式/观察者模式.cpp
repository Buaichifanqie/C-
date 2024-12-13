#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"NewsAgency.h"
#include"Observer.h"

int main()
{
	//发布者
	NewsAgency* new1 = new Morgans;
	NewsAgency* new2 = new BaGua;
	//观察者（订阅者）
	Longs* mylong = new Longs(new1,"龙");
	Batuo* batuo = new Batuo(new2,"巴托");
	Shanks* shanks = new Shanks(new1, "香客思");
	//由发布者推送消息
	new1->notify("蒙奇·D·路飞成为新世界的新的四皇之一, 赏金30亿贝里!!!");
	cout << "======================================" << endl;
	new2->notify("女帝汉库克想要嫁给路飞, 给路飞生猴子, 哈哈哈...");

	delete new1;
	delete new2;
	delete mylong;
	delete shanks;
	delete batuo;

	return 0;
}