#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<string>
#include<map>
/*
* ���� �Ժ��������еĺ����źͺ���ͨ���Ž�ģʽ���й���
* 
*/
//��Ա��
struct Person
{
	Person(string name, string job, string ablity, string reward, string beizhu)
	{
		this->name = name;
		this->job = job;
		this->ablity = ablity;
		this->reward = reward;
		this->beizhu = beizhu;
	}
	~Person()
	{
		cout << name << "��������..." << endl;
	}
	string name;
	string job;
	string ablity;
	string reward;
	string beizhu;
};


//����ʵ�ֲ���-�Ŷ�
class AbstractTeam
{
public:
	AbstractTeam(string name):m_name(name){}

	string getTeamName()
	{
		return m_name;
	}
	void addMember(Person* p)
	{
		m_teamMap.insert(make_pair(p->name, p));
	}
	void show()
	{
		cout << m_name << ":"<<endl;
		for (const auto& i : m_teamMap)
		{
			cout << "[name:" << i.second->name
				<< ",job:" << i.second->job
				<< ",abilty:" << i.second->ablity
				<< ",reward:" << i.second->reward
				<< ",beizhu:" << i.second->beizhu
				<<"]"<<endl;
		}
	}

	virtual ~AbstractTeam()
	{
		for (const auto& item : m_teamMap)
		{
			delete item.second;
		}
	}
	virtual void executeTask() = 0;

protected:
	string m_name;
	map < string, Person* > m_teamMap;
};
//��ñ
class CaoMaoTeam : public AbstractTeam
{
	//��Ϊ�ڹ��캯����ʱ��������Ҫ�������֣���������û�д��εĹ��캯�������Կ���ʹ��c++11�ļ̳й��캯��
	using AbstractTeam::AbstractTeam;
	void executeTask() override
	{
		cout << "�ں���ð�գ���Ϊ������������"<<endl;
	}
};
//����
class SmokerTeam : public AbstractTeam
{
	using AbstractTeam::AbstractTeam;
	void executeTask() override
	{
		cout << "Ϊ�����壬������һ���򾡣�����"<<endl;
	}
};

//������󲿷�-��
class AbstractShip
{
public:
	AbstractShip(AbstractTeam* team) : m_team(team) {}
	void show()
	{
		m_team->show();
		m_team->executeTask();
	}
	virtual string getName() = 0;
	virtual void feature() = 0;
	virtual ~AbstractShip() {};
protected:
	AbstractTeam* m_team=nullptr;
};

class Merry :public AbstractShip
{
public:
	using AbstractShip::AbstractShip;
	string getName() override
	{
		return "ǰ����������÷����";
	}
	void feature() override
	{
		cout << getName()
			<< " -- ����Ϊ��ͷ, ��˾�������������Ἲ�����˲�ñһ�" << endl;
	}
};

class HaiJunShip :public AbstractShip
{
public:
	using AbstractShip::AbstractShip;
	string getName() override
	{
		return "�޵к�����";
	}
	void feature() override
	{
		cout << getName() << " -- �����ɺ�¥ʯ����, ���Դ����޷���ľ޴��ڽ�!" << endl;
	}
};

int main()
{
	AbstractTeam* team = new CaoMaoTeam("��ñ������");
	Person* luffy = new Person("·��", "����", "�𽺹�ʵ������", "30�ڱ���", "������");
	Person* zoro = new Person("��¡", "��ʿ", "������", "11��1100����", "·��");
	Person* sanji = new Person("ɽ��", "��ʦ", "���κ�", "10��3200����", "��ɫ");
	Person* nami = new Person("����", "����ʿ", "����+��˹", "3��6600����", "ϲ��Ǯ");
	team->addMember(luffy);
	team->addMember(zoro);
	team->addMember(sanji);
	team->addMember(nami);
	AbstractShip* ship = new Merry(team);
	ship->feature();
	ship->show();

	delete team;
	delete ship;
	cout << "=========================================" << endl;
	// ˹Ħ��Ĵ���
	team = new SmokerTeam("˹Ħ��ĺ�������");
	Person* smoker = new Person("˹Ħ��", "�н�", "ð�̹�ʵ������", "", "������Ѭ����");
	Person* dasiqi = new Person("��˹��", "����", "һ����", "", "����");
	team->addMember(smoker);
	team->addMember(dasiqi);
	ship = new HaiJunShip(team);
	ship->feature();
	ship->show();
	delete team;
	delete ship;

	return 0;
}

