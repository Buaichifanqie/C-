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

//����
class Soldier66 : public GermaSoldier
{
public:
	GermaSoldier* clone()override
	{
		return new Soldier66(*this);
	}
	string whoAmI()
	{
		return "����Soldier66��ʿ��������";
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
		return "����Soldier67��ʿ��������";
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
//��ʱ������ǳ������Ҫע��ǳ��������Щ���⣬Ҫ����ǳ�������⣬
// ������Ҫ��ʾ�����¶��忽�����캯�����ٶ�������������캯����ʱ��ʹ������ķ�ʽ����newһ����ڴ�


