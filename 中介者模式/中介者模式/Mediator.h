#pragma once
using namespace std;
#include<string>
#include<map>
//���������
class Country;
//�н�����Ļ���
class MediatorOrg
{
public:
	void addMember(Country* country);
	virtual void declare(string msg, Country* country, string name) = 0;
	virtual ~MediatorOrg(){}
protected:
	map<string, Country*>m_countryMap;
};

//��������
class WorldGovt:public MediatorOrg
{
public:
	void declare(string msg, Country* country, string name);
};


//������
class GeMingJun :public MediatorOrg
{
public:
	void declare(string msg, Country* country, string name);
};

