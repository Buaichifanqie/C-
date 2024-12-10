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

// 定义工厂类，用于生产不同类型的恶魔果实
enum class Type : char { Sheep, Lion, Bat };

class SmileFactory
{
public:
    // 创建恶魔果实的方法，接受类型参数
    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;  // 用来保存创建的具体对象
        switch (type)
        {
        case Type::Sheep:  // 如果是羊形态
            ptr = new SheepSmile;  // 创建羊形态的对象
            break;
        case Type::Lion:  // 如果是狮子形态
            ptr = new LionSmile;  // 创建狮子形态的对象
            break;
        case Type::Bat:  // 如果是蝙蝠形态
            ptr = new BatSmile;  // 创建蝙蝠形态的对象
            break;
        default:
            break;
        }
        return ptr;  // 返回创建的对象指针
    }
};

int main()
{
    // 创建一个工厂对象
    SmileFactory* factory = new SmileFactory;

    // 通过工厂创建一个狮子形态的恶魔果实对象
    AbstractSmile* obj = factory->createSmile(Type::Lion);

    // 调用具体对象的方法
    obj->transfrom();  // 变身
    obj->ability();    // 获取能力

    // 使用完对象后需要释放内存
    delete obj;
    delete factory;  // 释放工厂的内存

    return 0;
}