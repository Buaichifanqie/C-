#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<map>

// ���崬��ص���

// ������������ص���

// �������ࡪ���������첻ͬ���Ĵ�

// ����ɣ��ŵĴ�
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

// ����÷���ŵĴ�
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

// ������������
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

// ����ɣ��ŵĴ�������
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
        m_sunny->addParts("�����������ǵ�");
    }

    void buildWeapon() override
    {
        m_sunny->addParts("ʨ����");
    }
    void buildEngine() override
    {
        m_sunny->addParts("����������ȼ��");
    }

    void buildInterior() override
    {
        m_sunny->addParts("�ǳ�����������");
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
        m_merry->assemble("����������ľ��", "����");
    }

    void buildWeapon() override
    {
        m_merry->assemble("���Ŵ���", "����");
    }
    void buildEngine() override
    {
        m_merry->assemble("������", "����ϵͳ");
    }

    void buildInterior() override
    {
        m_merry->assemble("�ǳ�����������", "����");
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

// �����������
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }

    // ��Լ��
    void buildSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // ��׼��
    void buildStandardShip()
    {
        buildSimpleShip();
        m_builder->buildWeapon();
    }
    // ������
    void buildRegalShip()
    {
        buildStandardShip();
        m_builder->buildInterior();
    }

private:
    ShipBuilder* m_builder = nullptr;
};

// ���Դ���
// ����ɣ���
void builderSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    // ��Լ��
    builder->reset();
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    // ������
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

// ����÷����
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // ��Լ��
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* ship = builder->getMerry();
    ship->showParts();
    delete ship;

    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    ship = builder->getMerry();
    ship->showParts();
    delete ship;

    // ������
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
