#pragma once
using namespace std;
#include<string>
#include<list>
class Observer;
//�����߻���
class NewsAgency
{
public:
	//��Ӷ�����
	void attach(Observer* ob);
	//ɾ��������
	void detach(Observer* ob);
	//֪ͨ������
	virtual void notify(string msg) = 0;
	virtual ~NewsAgency() {}
protected:
	list<Observer*>m_list;
};


//���������ࡪ��Ħ��˹
class Morgans:public NewsAgency
{
public:
	//֪ͨ������
	void notify(string msg) override;
};

//���������ࡪ������������
class BaGua :public NewsAgency
{
public:
	//֪ͨ������
	void notify(string msg) override;
};

