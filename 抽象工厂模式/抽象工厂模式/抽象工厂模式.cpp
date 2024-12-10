#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// ����
class ShipBody
{
public:
    virtual string getBody() = 0;
    virtual ~ShipBody() {};
};

// ľͷ����
class WoodBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("��ľͷ���Ĵ���...");
    }
};

// ��������
class IronBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("�ø������Ĵ���...");
    }
};

// �ϳɽ�������
class MetalBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("�úϳɽ������Ĵ���...");
    }
};

// ����
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {};
};

// �ֶ�����
class Human : public Engine
{
public:
    string getEngine() override
    {
        return "������ʽ���������ֶ�...";
    }
};

// ��ȼ������
class Diesel : public Engine
{
public:
    string getEngine() override
    {
        return "������ʽ����������ȼ��...";
    }
};

// �˷�Ӧ����
class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return "������ʽ���������˷�Ӧ...";
    }
};

// ����
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {};
};

// ǹ
class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("������ǹ...");
    }
};

// ��
class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("��������...");
    }
};

// ����
class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�����Ǽ���...");
    }
};

// ��
class Ship
{
public:
    Ship(ShipBody* body, Engine* engine, Weapon* weapon) :
        m_body(body), m_engine(engine), m_weapon(weapon) {}

    ~Ship()
    {
        delete m_body;
        delete m_weapon;
        delete m_engine;
    }

    string getProperty()
    {
        // ������ĸ�������
        string info = m_body->getBody() + " " + m_engine->getEngine() + " " + m_weapon->getWeapon();
        return info;
    }

private:
    ShipBody* m_body;
    Engine* m_engine;
    Weapon* m_weapon;
};

// �����ࡪ�����󹤳�
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {};
};

// �������͹���
class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Human, new Gun);
        cout << "�������ͣ�����" << endl;
        return ship;
    }
};

// ��׼���͹���
class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Diesel, new Cannon);
        cout << "��׼���ͣ�����" << endl;
        return ship;
    }
};

// �콢���͹���
class UitimataFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Nuclear, new Laser);
        cout << "�콢���ͣ�����" << endl;
        return ship;
    }
};

int main()
{
    // �����콢���͵Ĺ���
    AbstractFactory* factory = new UitimataFactory;
    // ������
    Ship* ship = factory->createShip();
    // �����������
    cout << ship->getProperty() << endl;
    // �����ڴ�
    delete ship;
    delete factory;

    return 0;
}