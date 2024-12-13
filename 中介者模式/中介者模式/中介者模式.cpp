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
		string str = msg + "[����:" + country->getName() + "]";
		m_countryMap[name]->setMessage(str);
	}
}

void GeMingJun::declare(string msg, Country* country, string name)
{
	string str = msg + "[����:" + country->getName() + "]";
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
    // ��������
    WorldGovt* world = new WorldGovt;
    Alabasta* alaba = new Alabasta(world);
    Dressrosa* dresa = new Dressrosa(world);
    // ����������ӳ�Ա
    world->addMember(alaba);
    world->addMember(dresa);
    // ����������Ա����
    alaba->declare("����˹������������, ����ҹ��������, �������˵��!!!", dresa->getName());
    dresa->declare("�����˶����Ҷล������������, �����ϼ�, ��!!!", alaba->getName());
    cout << "======================================" << endl;
    // ������
    GeMingJun* geming = new GeMingJun;
    Lulusia* lulu = new Lulusia(geming);
    Kamabaka* kama = new Kamabaka(geming);
    geming->addMember(lulu);
    geming->addMember(kama);
    lulu->declare("�Ҳ�, �ҵĹ��ұ���ķ������!!!", lulu->getName());

    delete world;
    delete alaba;
    delete dresa;
    delete geming;
    delete lulu;
    delete kama;
    return 0;


	return 0;
}
