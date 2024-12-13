#pragma once
#include<string>
#include<iostream>
#include"NewsAgency.h"
using namespace std;
//����Ĺ۲�����
class Observer
{
public:
	//�ͷ���������й�����������ͨ�����캯��ʵ��
		//д�ں������ڲ��и�ֵ�������ǳ�ʼ������ʼ���б�Ч�ʸ��ߣ�
	Observer(NewsAgency* news, string name) : m_news(news), m_name(name)
	{
		m_news->attach(this);
	}
	//�ͷ����߽������
	void unsubscribe()
	{
		m_news->detach(this);
	}
	//������Ϣ
	virtual void update(string msg) = 0;
	virtual ~Observer() {}
protected:
	NewsAgency* m_news;
	string m_name;
};

//�۲������ࡪ��������
class Longs:public Observer
{
public:
	using Observer::Observer;
	//������Ϣ
	void update(string msg)override
	{
		cout << "@@@·�ɵ��ϰָ��������յ���Ϣ: " << msg << endl;
	}
};

//�۲������ࡪ���������˹
class Shanks :public Observer
{
public:
	using Observer::Observer;
	//������Ϣ
	void update(string msg)override
	{
		cout << "@@@·�ɵ���·�����˹�յ���Ϣ: " << msg << endl;
	}
};

//�۲������ࡪ�������������װ�
class Batuo :public Observer
{
public:
	using Observer::Observer;
	//������Ϣ
	void update(string msg)override
	{
		cout << "@@@·�ɵ�ͷ�ŷ�˿�������װ��յ���Ϣ: " << msg << endl;
	}
};

