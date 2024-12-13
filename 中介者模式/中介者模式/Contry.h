#pragma once
#include<iostream>
#include"Mediator.h"
using namespace std;
//�н��߻���
class Country
{
public:
    Country(MediatorOrg* mediator) : m_org(mediator) {}
	virtual void declare(string msg, string country) = 0;
	virtual void setMessage(string msg) = 0;
	virtual string getName() = 0;
	virtual ~Country(){}
protected:
	MediatorOrg* m_org;//Ҫ�û���������Ϊ�����Ǹ�����Ҳ��������������
};

// ������˹̹
class Alabasta : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "������˹̹�õ�����Ϣ: " << msg << endl;
    }
    string getName() override
    {
        return "������˹̹";
    }
};

// ����˹����
class Dressrosa : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "����˹�����õ�����Ϣ: " << msg << endl;
    }
    string getName() override
    {
        return "����˹����";
    }
};

// ¶¶��������
class Lulusia : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "¶¶���ǵõ�����Ϣ: " << msg << endl;
    }
    string getName() override
    {
        return "¶¶����";
    }
};

// ����Ϳ�����
class Kamabaka : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "����Ϳ��õ�����Ϣ: " << msg << endl;
    }
    string getName() override
    {
        return "����Ϳ�";
    }
};
