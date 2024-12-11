#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<string>
#include<map>
/*
* 需求 对海贼世界中的海贼团和海军通过桥接模式进行管理
* 
*/
//成员类
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
		cout << name << "被析构了..." << endl;
	}
	string name;
	string job;
	string ablity;
	string reward;
	string beizhu;
};


//定义实现部分-团队
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
//草帽
class CaoMaoTeam : public AbstractTeam
{
	//因为在构造函数的时候我们需要传入名字，可是子类没有带参的构造函数，所以可以使用c++11的继承构造函数
	using AbstractTeam::AbstractTeam;
	void executeTask() override
	{
		cout << "在海上冒险，成为海贼王！！！"<<endl;
	}
};
//海军
class SmokerTeam : public AbstractTeam
{
	using AbstractTeam::AbstractTeam;
	void executeTask() override
	{
		cout << "为了正义，将海贼一网打尽！！！"<<endl;
	}
};

//定义抽象部分-船
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
		return "前进————梅利号";
	}
	void feature() override
	{
		cout << getName()
			<< " -- 船首为羊头, 在司法岛化身船精灵舍己救下了草帽一伙！" << endl;
	}
};

class HaiJunShip :public AbstractShip
{
public:
	using AbstractShip::AbstractShip;
	string getName() override
	{
		return "无敌海军号";
	}
	void feature() override
	{
		cout << getName() << " -- 船底由海楼石建造, 可以穿过无风带的巨大炮舰!" << endl;
	}
};

int main()
{
	AbstractTeam* team = new CaoMaoTeam("草帽海贼团");
	Person* luffy = new Person("路飞", "船长", "橡胶果实能力者", "30亿贝里", "爱吃肉");
	Person* zoro = new Person("索隆", "剑士", "三刀流", "11亿1100万贝里", "路痴");
	Person* sanji = new Person("山治", "厨师", "隐形黑", "10亿3200万贝里", "好色");
	Person* nami = new Person("娜美", "航海士", "天候棒+宙斯", "3亿6600万贝里", "喜欢钱");
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
	// 斯摩格的船队
	team = new SmokerTeam("斯摩格的海军部队");
	Person* smoker = new Person("斯摩格", "中将", "冒烟果实能力者", "", "爱吃烟熏鸡肉");
	Person* dasiqi = new Person("达斯琪", "大佐", "一刀流", "", "近视");
	team->addMember(smoker);
	team->addMember(dasiqi);
	ship = new HaiJunShip(team);
	ship->feature();
	ship->show();
	delete team;
	delete ship;

	return 0;
}

