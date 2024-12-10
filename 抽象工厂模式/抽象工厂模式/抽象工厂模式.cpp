#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 船体
class ShipBody
{
public:
    virtual string getBody() = 0;
    virtual ~ShipBody() {};
};

// 木头船体
class WoodBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("用木头做的船体...");
    }
};

// 钢铁船体
class IronBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("用钢铁做的船体...");
    }
};

// 合成金属船体
class MetalBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("用合成金属做的船体...");
    }
};

// 引擎
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {};
};

// 手动引擎
class Human : public Engine
{
public:
    string getEngine() override
    {
        return "动力方式————手动...";
    }
};

// 内燃机引擎
class Diesel : public Engine
{
public:
    string getEngine() override
    {
        return "动力方式————内燃机...";
    }
};

// 核反应引擎
class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return "动力方式————核反应...";
    }
};

// 武器
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {};
};

// 枪
class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("武器是枪...");
    }
};

// 炮
class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("武器是炮...");
    }
};

// 激光
class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return string("武器是激光...");
    }
};

// 船
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
        // 输出船的各个属性
        string info = m_body->getBody() + " " + m_engine->getEngine() + " " + m_weapon->getWeapon();
        return info;
    }

private:
    ShipBody* m_body;
    Engine* m_engine;
    Weapon* m_weapon;
};

// 工厂类——抽象工厂
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {};
};

// 基础类型工厂
class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Human, new Gun);
        cout << "基础类型！！！" << endl;
        return ship;
    }
};

// 标准类型工厂
class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Diesel, new Cannon);
        cout << "标准类型！！！" << endl;
        return ship;
    }
};

// 旗舰类型工厂
class UitimataFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Nuclear, new Laser);
        cout << "旗舰类型！！！" << endl;
        return ship;
    }
};

int main()
{
    // 创建旗舰类型的工厂
    AbstractFactory* factory = new UitimataFactory;
    // 创建船
    Ship* ship = factory->createShip();
    // 输出船的属性
    cout << ship->getProperty() << endl;
    // 清理内存
    delete ship;
    delete factory;

    return 0;
}