#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//սʿ�Ļ���
class Soldier
{
public:
	Soldier() {}
	Soldier(string name) :m_name(name) {}
	string getName()
	{
		return m_name;
	}
	virtual void fight() = 0;
	virtual ~Soldier() {}
protected:
	string m_name=string();
};

//�ں���
class Teach : public Soldier
{
public:
	using Soldier::Soldier;

	void fight()
	{
		cout << m_name << "�������˵������͸߳�������ս��..." << endl;
	}
};

//��ħ��ʵ����
class DevilFruit :public Soldier
{
public:
	void enchantment(Soldier* soldier)
	{
		m_soldier = soldier;
		m_name = soldier->getName();
	}

protected:
	Soldier* m_soldier=nullptr;
};
//������ʵ
class DarkFruit : public DevilFruit
{
public:
	//ֻ�����¸���Ĵ��麯�����ܱ��һ��ʵ���������ǳ�����
	void fight()override
	{
		m_soldier->fight();
		// ʹ�õ�ǰ��ħ��ʵ������
		cout << m_soldier->getName()
			<< "���˰�����ʵ, ����ӵ�кڶ�һ��������������..." << endl;
		warning();
	}
private:
	void warning()
	{
		cout << m_soldier->getName()
			<< "��Ҫע��: ���˰�����ʵ, ����Ԫ�ػ�֮���ܶ�ܹ����������������˺�!" << endl;
	}
};
//�����ʵ
class QuakeFruit : public DevilFruit
{
public:
	//ֻ�����¸���Ĵ��麯�����ܱ��һ��ʵ���������ǳ�����
	void fight()override
	{
		m_soldier->fight();
		// ʹ�õ�ǰ��ħ��ʵ������
		cout << m_soldier->getName()
			<< "���������ʵ, ����������ռ�������, �ݻ�Ŀ��...!" << endl;
	}
};
// �����ʵ
class PieFruit : public DevilFruit
{
public:
	void fight() override
	{
		m_soldier->fight();
		cout << m_soldier->getName()
			<< "���˴����ʵ, ��ô������...!" << endl;
		ability();
	}

	void ability()
	{
		cout << "��ǿ���� -- �����ʵ���Խ���������ɴ��, �����Լ��Ͷ��ѻ�Ѫ..." << endl;
	}
};

int main()
{
	Soldier* soldier = new Teach;
	DarkFruit* dark = new DarkFruit;
	QuakeFruit* quake = new QuakeFruit;
	PieFruit* pie = new PieFruit;
	// �ں��ӳ��˰�����ʵ
	dark->enchantment(soldier);
	// �ں����ֳ��������ʵ
	quake->enchantment(dark);
	// �ں����ֳ��˴����ʵ
	pie->enchantment(quake);
	// ս��
	pie->fight();
	delete soldier;
	delete dark;
	delete quake;
	delete pie;
	return 0;
}
