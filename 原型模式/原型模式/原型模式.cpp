#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class GermaSoldier
{
public:
	virtual GermaSoldier* clone() = 0;
	virtual string whoAmI() = 0;
	virtual ~GermaSoldier() {};
};

//子类
class Soldier66 : public GermaSoldier
{
public:
	GermaSoldier* clone()override
	{
		return new Soldier66(*this);
	}
	string whoAmI()
	{
		return "我是Soldier66的士兵！！！";
	}

};

class Soldier67 : public GermaSoldier
{
public:
	GermaSoldier* clone()override
	{
		return new Soldier67(*this);
	}
	string whoAmI()
	{
		return "我是Soldier67的士兵！！！";
	}

};
int main()
{
	GermaSoldier* obj = new Soldier66;
	GermaSoldier* soldier = obj->clone();
	cout << soldier->whoAmI();
	cout << endl;
	delete obj;
	delete soldier;

	obj = new Soldier67;
	soldier = obj->clone();
	cout << soldier->whoAmI();
	delete obj;
	delete soldier;
	return 0;
}
//此时代码是浅拷贝，要注意浅拷贝会有些问题，要想解决浅拷贝问题，
// 我们需要显示的重新定义拷贝构造函数，再定义这个拷贝构造函数的时候使用深拷贝的方式重新new一块堆内存


