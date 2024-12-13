#pragma once
#include<string>
#include<iostream>
#include"NewsAgency.h"
using namespace std;
//抽象的观察者类
class Observer
{
public:
	//和发布者类进行关联——可以通过构造函数实现
		//写在函数体内部叫赋值，下面是初始化（初始化列表，效率更高）
	Observer(NewsAgency* news, string name) : m_news(news), m_name(name)
	{
		m_news->attach(this);
	}
	//和发布者解除关联
	void unsubscribe()
	{
		m_news->detach(this);
	}
	//更新消息
	virtual void update(string msg) = 0;
	virtual ~Observer() {}
protected:
	NewsAgency* m_news;
	string m_name;
};

//观察者子类————龙
class Longs:public Observer
{
public:
	using Observer::Observer;
	//更新消息
	void update(string msg)override
	{
		cout << "@@@路飞的老爸革命军龙收到消息: " << msg << endl;
	}
};

//观察者子类————香克斯
class Shanks :public Observer
{
public:
	using Observer::Observer;
	//更新消息
	void update(string msg)override
	{
		cout << "@@@路飞的引路人香克斯收到消息: " << msg << endl;
	}
};

//观察者子类————巴托洛米奥
class Batuo :public Observer
{
public:
	using Observer::Observer;
	//更新消息
	void update(string msg)override
	{
		cout << "@@@路飞的头号粉丝巴托洛米奥收到消息: " << msg << endl;
	}
};

