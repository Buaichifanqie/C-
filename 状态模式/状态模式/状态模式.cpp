#define _CRT_SECURE_NO_WARNINGS
#include"State.h"
#include<iostream>
#include"SanJi.h"
#include<vector>
using namespace std;

void ForeNoonState::working(SanJi* sanji)
{
	//�õ�time
	int time = sanji->getClock();
	//�ж�ʱ���
	if (time < 8)
	{
		cout << "��ǰʱ��<" << time << ">��, ׼�����, ��³�˵ö�ȵ�ţ��..." << endl;
	}
	else if (time > 8 && time < 11)
	{
		cout << "��ǰʱ��<" << time << ">��, ȥ��ͷ����, ����ʳ��..." << endl;
	}
	else
	{
		//�л�����һ��״̬
		sanji->setState(new NoonState);
		sanji->working();
	}
}
void NoonState::working(SanJi* sanji)
{
	//�õ�time
	int time = sanji->getClock();
	//�ж�ʱ���
	if (time < 13)
	{
		cout << "��ǰʱ��<" << time << ">��, ȥ�������緹, ��·�ɶ�������..." << endl;
	}
	else
	{
		//�л�����һ��״̬
		sanji->setState(new AfterNoonState);
		sanji->working();
	}
}
void AfterNoonState::working(SanJi* sanji)
{
	int time = sanji->getClock();
	if (time < 15)
	{
		cout << "��ǰʱ��<" << time << ">��, ׼�������, ���ޱ������������������..." << endl;
	}
	else if (time > 15 && time < 18)
	{
		cout << "��ǰʱ��<" << time << ">��, ���ǰ�ȥ��β����, ����ʳ��..." << endl;
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
		cout << "��ǰʱ��<" << time << ">��, ȥ��������, ����¡��ȵ���..." << endl;
	}
	else
	{
		cout << "��ǰʱ��<" << time << ">��, ������úܸ���, ����˯����..." << endl;
	}
}

int main()
{
	SanJi* sanji = new SanJi;
	// ʱ���
	vector<int> data{ 7, 10, 12, 14, 16, 18, 22 };
	for (const auto& item : data)
	{
		sanji->setClock(item);
		sanji->working();
	}
	delete sanji;

	return 0;
}
