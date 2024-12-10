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

// ���幤���࣬����������ͬ���͵Ķ�ħ��ʵ
enum class Type : char { Sheep, Lion, Bat };

class SmileFactory
{
public:
    // ������ħ��ʵ�ķ������������Ͳ���
    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;  // �������洴���ľ������
        switch (type)
        {
        case Type::Sheep:  // ���������̬
            ptr = new SheepSmile;  // ��������̬�Ķ���
            break;
        case Type::Lion:  // �����ʨ����̬
            ptr = new LionSmile;  // ����ʨ����̬�Ķ���
            break;
        case Type::Bat:  // �����������̬
            ptr = new BatSmile;  // ����������̬�Ķ���
            break;
        default:
            break;
        }
        return ptr;  // ���ش����Ķ���ָ��
    }
};

int main()
{
    // ����һ����������
    SmileFactory* factory = new SmileFactory;

    // ͨ����������һ��ʨ����̬�Ķ�ħ��ʵ����
    AbstractSmile* obj = factory->createSmile(Type::Lion);

    // ���þ������ķ���
    obj->transfrom();  // ����
    obj->ability();    // ��ȡ����

    // ʹ����������Ҫ�ͷ��ڴ�
    delete obj;
    delete factory;  // �ͷŹ������ڴ�

    return 0;
}