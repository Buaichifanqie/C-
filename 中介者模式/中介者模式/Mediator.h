#pragma once
using namespace std;
#include<string>
#include<map>
//声明类存在
class Country;
//中介者类的基类
class MediatorOrg
{
public:
	void addMember(Country* country);
	virtual void declare(string msg, Country* country, string name) = 0;
	virtual ~MediatorOrg(){}
protected:
	map<string, Country*>m_countryMap;
};

//世界政府
class WorldGovt:public MediatorOrg
{
public:
	void declare(string msg, Country* country, string name);
};


//革命军
class GeMingJun :public MediatorOrg
{
public:
	void declare(string msg, Country* country, string name);
};

