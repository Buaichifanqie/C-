#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����ϵͳ
class CokeSystem
{
public:
    void immitCoke()
    {
        cout << "ʨ����ԭ��<����>�Ѿ�ע�����..." << endl;
    }
};

// ����ת��ϵͳ
class EnergySystem
{
public:
    void energyConvert()
    {
        cout << "�Ѿ������еĿ���ת��Ϊ������..." << endl;
    }
};

// Ŀ������ϵͳ
class AimLockSystem
{
public:
    void aimLock()
    {
        cout << "�Ѿ���׼����������Ŀ��..." << endl;
    }
};

// ��ũ�ڷ���ϵͳ
class Cannon
{
public:
    void cannonFire()
    {
        cout << "ʨ����������Ŀ�꿪��..." << endl;
    }
};

// �������ȶ�ϵͳ
class WindCannon
{
public:
    void windCannonFire()
    {
        cout << "��������ڵ����������ȶ�����..." << endl;
    }
};

// �ϲ�ӿ�
class LionCannon
{
public:
    LionCannon()
    {
        m_coke = new CokeSystem;
        m_energy = new EnergySystem;
        m_aimLock = new AimLockSystem;
        m_cannon = new Cannon;
        m_windCannon = new WindCannon;
    }
    ~LionCannon()
    {
        delete m_coke;
        delete m_energy;
        delete m_aimLock;
        delete m_cannon;
        delete m_windCannon;
    }
    // ��׼������Ŀ��
    void aimAndLock()
    {
        m_coke->immitCoke();
        m_energy->energyConvert();
        m_aimLock->aimLock();
    }
    // ����
    void fire()
    {
        m_cannon->cannonFire();
        m_windCannon->windCannonFire();
    }
private:
    CokeSystem* m_coke = nullptr;
    EnergySystem* m_energy = nullptr;
    AimLockSystem* m_aimLock = nullptr;
    Cannon* m_cannon = nullptr;
    WindCannon* m_windCannon = nullptr;
};

int main()
{
    // ����ʨ����
    LionCannon* lion = new LionCannon;
    lion->aimAndLock();
    lion->fire();
    delete lion;
    return 0;
}