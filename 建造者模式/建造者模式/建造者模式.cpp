#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<map>

// 定义船相关的类

// 定义生成器相关的类

// 管理这类————建造不同规格的船

// 定义桑尼号的船
class SunnyShip
{
public:
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << " ";
        }
        cout << endl;
    }

private:
    vector<string> m_parts;
};

// 定义梅利号的船
class MerryShip
{
public:
    void assemble(string name, string parts)
    {
        m_parts.insert(make_pair(parts, name));
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item.first << ":" << item.second << " ";
        }
        cout << endl;
    }

private:
    map<string, string> m_parts;
};

// 定义生成器类
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildEngine() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder() {}
};

// 定义桑尼号的船构建器
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }

    void reset() override
    {
        m_sunny = new SunnyShip;
    }
    SunnyShip* getSunnyShip()
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }

    void buildBody() override
    {
        m_sunny->addParts("船体是神树亚当");
    }

    void buildWeapon() override
    {
        m_sunny->addParts("狮吼炮");
    }
    void buildEngine() override
    {
        m_sunny->addParts("可乐驱动内燃机");
    }

    void buildInterior() override
    {
        m_sunny->addParts("非常豪华的内饰");
    }

    ~SunnyBuilder()
    {
        if (m_sunny)
        {
            delete m_sunny;
        }
    }

private:
    SunnyShip* m_sunny;
};

class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }

    void reset() override
    {
        m_merry = new MerryShip;
    }
    MerryShip* getMerry()
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }

    void buildBody() override
    {
        m_merry->assemble("船体是优质木材", "船体");
    }

    void buildWeapon() override
    {
        m_merry->assemble("四门大炮", "武器");
    }
    void buildEngine() override
    {
        m_merry->assemble("蒸汽机", "动力系统");
    }

    void buildInterior() override
    {
        m_merry->assemble("非常豪华的内饰", "内饰");
    }

    ~MerryBuilder()
    {
        if (m_merry)
        {
            delete m_merry;
        }
    }

private:
    MerryShip* m_merry;
};

// 定义管理者类
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }

    // 简约型
    void buildSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // 标准型
    void buildStandardShip()
    {
        buildSimpleShip();
        m_builder->buildWeapon();
    }
    // 豪华型
    void buildRegalShip()
    {
        buildStandardShip();
        m_builder->buildInterior();
    }

private:
    ShipBuilder* m_builder = nullptr;
};

// 测试代码
// 建造桑尼号
void builderSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    // 简约型
    builder->reset();
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

// 建造梅利号
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // 简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* ship = builder->getMerry();
    ship->showParts();
    delete ship;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    ship = builder->getMerry();
    ship->showParts();
    delete ship;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    ship = builder->getMerry();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

int main()
{
    builderSunny();
    cout << "=====================================" << endl;
    builderMerry();
}
