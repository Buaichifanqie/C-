#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

// �����Ʒ��ĸ��ࡪ�������ħ��ʵ�������ࣩ
class AbstractSmile
{
public:
    // ���麯�����������ʵ��
    virtual void transfrom() = 0;  // ������
    virtual void ability() = 0;    // ��ȡ��������
    virtual ~AbstractSmile() {};    // ������������ȷ��ɾ�����������ʱ�ܵ������������������
};

// ����̬�Ķ�ħ��ʵ��
class SheepSmile : public AbstractSmile
{
public:
    // ʵ�ָ�����麯��
    virtual void transfrom() override
    {
        cout << "������ޡ���ɽ����̬..." << endl;
    }

    virtual void ability() override
    {
        cout << "���ֱ۱��ɽ��ǵ���ʽ���������..." << endl;
    }
};

// ʨ����̬�Ķ�ħ��ʵ��
class LionSmile : public AbstractSmile
{
public:
    // ʵ�ָ�����麯��
    virtual void transfrom() override
    {
        cout << "������ޡ���ʨ����̬..." << endl;
    }

    virtual void ability() override
    {
        cout << "�����..." << endl;
    }
};

// ������̬�Ķ�ħ��ʵ��
class BatSmile : public AbstractSmile
{
public:
    // ʵ�ָ�����麯��
    virtual void transfrom() override
    {
        cout << "������ޡ���������̬..." << endl;
    }

    virtual void ability() override
    {
        cout << "�򽣹���..." << endl;
    }
};

// ���幤���࣬����������ͬ���͵Ķ�ħ��ʵ������������
class AbstractFactory
{
public:
    // ������ħ��ʵ�ķ������������Ͳ���
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() { };
};

// ����ɽ���ħ��ʵ�Ĺ���
class SheepFactory : public AbstractFactory
{
public:
    // ������ħ��ʵ�ķ���������һ��ɽ����̬�Ķ�ħ��ʵ����
    virtual AbstractSmile* createSmile() override
    {
        return new SheepSmile;
    }

    virtual ~SheepFactory()
    {
        cout << "SheepFactory��������..." << endl;
    }
};

// ����ʨ�Ӷ�ħ��ʵ�Ĺ���
class LionFactory : public AbstractFactory
{
public:
    // ������ħ��ʵ�ķ���������һ��ʨ����̬�Ķ�ħ��ʵ����
    virtual AbstractSmile* createSmile() override
    {
        return new LionSmile;
    }

    virtual ~LionFactory()
    {
        cout << "LionFactory��������..." << endl;
    }
};

// ���������ħ��ʵ�Ĺ���
class BatFactory : public AbstractFactory
{
public:
    // ������ħ��ʵ�ķ���������һ��������̬�Ķ�ħ��ʵ����
    virtual AbstractSmile* createSmile() override
    {
        return new BatSmile;
    }

    virtual ~BatFactory()
    {
        cout << "BatFactory��������..." << endl;
    }
};

int main()
{
    // ����һ��������������ѡ������ʨ�Ӷ�ħ��ʵ�Ĺ���
    AbstractFactory* factory = new LionFactory;

    // ͨ����������һ��ʨ����̬�Ķ�ħ��ʵ����
    AbstractSmile* obj = factory->createSmile();

    // ���þ������ķ���
    obj->transfrom();  // ����
    obj->ability();    // ��ȡ����

    // ʹ����������Ҫ�ͷ��ڴ�
    delete obj;    // ɾ����ħ��ʵ����
    delete factory;  // ɾ����������

    return 0;
}