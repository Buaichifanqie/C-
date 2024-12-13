#include "NewsAgency.h"
#include<iostream>
#include"Observer.h"
using namespace std;

void BaGua::notify(string msg)
{
	cout << "���������籨ֽ�Ķ�����һ����<" << m_list.size() << ">��" << endl;
	//ͨ���۲��߸�������
	for (const auto& item : m_list)
	{
		item->update(msg);
	}

}

void Morgans::notify(string msg)
{
	cout << "Ħ��˹�����籨ֽ�Ķ�����һ����<" << m_list.size() << ">��" << endl;
	for (const auto& item : m_list)
	{
		item->update(msg);
	}
}

void NewsAgency::attach(Observer* ob)
{
	m_list.push_back(ob);
}

void NewsAgency::detach(Observer* ob)
{
	m_list.remove(ob);
}
