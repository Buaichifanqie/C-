#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

// 定义产品类的父类——人造恶魔果实（抽象类）
class AbstractSmile
{
public:
    // 纯虚函数，子类必须实现
    virtual void transfrom() = 0;  // 变身方法
    virtual void ability() = 0;    // 获取能力方法
    virtual ~AbstractSmile() {};    // 虚析构函数，确保删除派生类对象时能调用派生类的析构函数
};

// 羊形态的恶魔果实类
class SheepSmile : public AbstractSmile
{
public:
    // 实现父类的虚函数
    virtual void transfrom() override
    {
        cout << "变成人兽——山羊形态..." << endl;
    }

    virtual void ability() override
    {
        cout << "将手臂变成山羊角的招式——巨羊角..." << endl;
    }
};

// 狮子形态的恶魔果实类
class LionSmile : public AbstractSmile
{
public:
    // 实现父类的虚函数
    virtual void transfrom() override
    {
        cout << "变成人兽——狮子形态..." << endl;
    }

    virtual void ability() override
    {
        cout << "喷火球..." << endl;
    }
};

// 蝙蝠形态的恶魔果实类
class BatSmile : public AbstractSmile
{
public:
    // 实现父类的虚函数
    virtual void transfrom() override
    {
        cout << "变成人兽——蝙蝠形态..." << endl;
    }

    virtual void ability() override
    {
        cout << "万剑归宗..." << endl;
    }
};

// 定义工厂类，用于生产不同类型的恶魔果实————父类
class AbstractFactory
{
public:
    // 创建恶魔果实的方法，接受类型参数
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() { };
};

// 生产山羊恶魔果实的工厂
class SheepFactory : public AbstractFactory
{
public:
    // 创建恶魔果实的方法，返回一个山羊形态的恶魔果实对象
    virtual AbstractSmile* createSmile() override
    {
        return new SheepSmile;
    }

    virtual ~SheepFactory()
    {
        cout << "SheepFactory被析构了..." << endl;
    }
};

// 生产狮子恶魔果实的工厂
class LionFactory : public AbstractFactory
{
public:
    // 创建恶魔果实的方法，返回一个狮子形态的恶魔果实对象
    virtual AbstractSmile* createSmile() override
    {
        return new LionSmile;
    }

    virtual ~LionFactory()
    {
        cout << "LionFactory被析构了..." << endl;
    }
};

// 生产蝙蝠恶魔果实的工厂
class BatFactory : public AbstractFactory
{
public:
    // 创建恶魔果实的方法，返回一个蝙蝠形态的恶魔果实对象
    virtual AbstractSmile* createSmile() override
    {
        return new BatSmile;
    }

    virtual ~BatFactory()
    {
        cout << "BatFactory被析构了..." << endl;
    }
};

int main()
{
    // 创建一个工厂对象，这里选择生产狮子恶魔果实的工厂
    AbstractFactory* factory = new LionFactory;

    // 通过工厂创建一个狮子形态的恶魔果实对象
    AbstractSmile* obj = factory->createSmile();

    // 调用具体对象的方法
    obj->transfrom();  // 变身
    obj->ability();    // 获取能力

    // 使用完对象后需要释放内存
    delete obj;    // 删除恶魔果实对象
    delete factory;  // 删除工厂对象

    return 0;
}