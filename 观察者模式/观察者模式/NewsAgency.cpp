#include "NewsAgency.h"
#include<iostream>
#include"Observer.h"
using namespace std;

void BaGua::notify(string msg)
{
	cout << "八卦新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << endl;
	//通过观察者更新数据
	for (const auto& item : m_list)
	{
		item->update(msg);
	}

}

void Morgans::notify(string msg)
{
	cout << "摩根斯新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << endl;
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
