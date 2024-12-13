#define _CRT_SECURE_NO_WARNINGS
#include"State.h"
#include<iostream>
#include"SanJi.h"
#include<vector>
using namespace std;

void ForeNoonState::working(SanJi* sanji)
{
	//得到time
	int time = sanji->getClock();
	//判断时间点
	if (time < 8)
	{
		cout << "当前时间<" << time << ">点, 准备早餐, 布鲁克得多喝点牛奶..." << endl;
	}
	else if (time > 8 && time < 11)
	{
		cout << "当前时间<" << time << ">点, 去船头钓鱼, 储备食材..." << endl;
	}
	else
	{
		//切换到另一个状态
		sanji->setState(new NoonState);
		sanji->working();
	}
}
void NoonState::working(SanJi* sanji)
{
	//得到time
	int time = sanji->getClock();
	//判断时间点
	if (time < 13)
	{
		cout << "当前时间<" << time << ">点, 去厨房做午饭, 给路飞多做点肉..." << endl;
	}
	else
	{
		//切换到另一个状态
		sanji->setState(new AfterNoonState);
		sanji->working();
	}
}
void AfterNoonState::working(SanJi* sanji)
{
	int time = sanji->getClock();
	if (time < 15)
	{
		cout << "当前时间<" << time << ">点, 准备下午茶, 给罗宾和娜美制作爱心甜点..." << endl;
	}
	else if (time > 15 && time < 18)
	{
		cout << "当前时间<" << time << ">点, 和乔巴去船尾钓鱼, 储备食材..." << endl;
	}
	else
	{
		sanji->setState(new EveningNoonState);
		sanji->working();
	}
}

void EveningNoonState::working(SanJi* sanji)
{
	int time = sanji->getClock();
	if (time < 19)
	{
		cout << "当前时间<" << time << ">点, 去厨房做晚饭, 让索隆多喝点汤..." << endl;
	}
	else
	{
		cout << "当前时间<" << time << ">点, 今天过得很高兴, 累了睡觉了..." << endl;
	}
}

int main()
{
	SanJi* sanji = new SanJi;
	// 时间点
	vector<int> data{ 7, 10, 12, 14, 16, 18, 22 };
	for (const auto& item : data)
	{
		sanji->setClock(item);
		sanji->working();
	}
	delete sanji;

	return 0;
}
