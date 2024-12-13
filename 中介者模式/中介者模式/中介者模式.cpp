#define _CRT_SECURE_NO_WARNINGS
#include"Mediator.h"
#include"Contry.h"
#include<iostream>
using namespace std;

void MediatorOrg::addMember(Country* country)
{
	m_countryMap.insert(make_pair(country->getName(), country));
}

void WorldGovt::declare(string msg, Country* country, string name)
{
	if (m_countryMap.find(name) != m_countryMap.end())
	{
		string str = msg + "[来自:" + country->getName() + "]";
		m_countryMap[name]->setMessage(str);
	}
}

void GeMingJun::declare(string msg, Country* country, string name)
{
	string str = msg + "[来自:" + country->getName() + "]";
	for (const auto& item : m_countryMap)
	{
		if (item.second == country)
		{
			continue;
		}
		item.second->setMessage(str);
	}
}

int main()
{
    // 世界政府
    WorldGovt* world = new WorldGovt;
    Alabasta* alaba = new Alabasta(world);
    Dressrosa* dresa = new Dressrosa(world);
    // 世界政府添加成员
    world->addMember(alaba);
    world->addMember(dresa);
    // 世界政府成员发声
    alaba->declare("德雷斯罗萨倒卖军火, 搞得我国连年打仗, 必须给个说法!!!", dresa->getName());
    dresa->declare("天龙人都和我多弗朗明哥做生意, 你算老几, 呸!!!", alaba->getName());
    cout << "======================================" << endl;
    // 革命军
    GeMingJun* geming = new GeMingJun;
    Lulusia* lulu = new Lulusia(geming);
    Kamabaka* kama = new Kamabaka(geming);
    geming->addMember(lulu);
    geming->addMember(kama);
    lulu->declare("我草, 我的国家被伊姆毁灭了!!!", lulu->getName());

    delete world;
    delete alaba;
    delete dresa;
    delete geming;
    delete lulu;
    delete kama;
    return 0;


	return 0;
}
