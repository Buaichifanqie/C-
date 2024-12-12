#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����Ĺ����߽ڵ�
enum class RequestType :char { QingJia, ZhangXin, CiZhi };//ǿ����ö����Ϊָ����char��������һ��ռ3���ֽ�
class AbstractManager
{
public:
	void setNext(AbstractManager* next)
	{
		m_next = next;
	}
	virtual void handleRequest(RequestType type) = 0;
	~AbstractManager() {}
protected:
	AbstractManager* m_next = nullptr;

};

//�ײ������
class Manager:public AbstractManager
{
public:
	virtual void handleRequest(RequestType type) override
	{
        switch (type)
        {
        case RequestType::QingJia:
            cout << "���: ͬ����٣��ú���Ϣ~~~" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "��н: ����ҵ���ʾһ������CEO..." << " ====> ";
            m_next->handleRequest(type);
            break;
        case RequestType::CiZhi:
            cout << "��ְ: �Ҹ������ϼ���Ӧһ��..." << " ====> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
	}
};

//CEO
class CEO :public AbstractManager
{
public:
    virtual void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "���: ͬ�����, �²�Ϊ��..." << endl;
            break;
        case RequestType::ZhangXin:
            cout << "��н: �㹤�ʲ�����, ���������ȯ��..." << endl;
            break;
        case RequestType::CiZhi:
            cout << "��ְ: ����ҵ����������ϰ�..." << " ====> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

//BOSS
class Boss : public AbstractManager
{
public:
    void handleRequest(RequestType type)
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "���: ֻ�й�������ʵ��������ֵ����ȥ�úü��ظ�λ������" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "��н: Ǯ��������֮��, Ҫ���������!!!" << endl;
            break;
        case RequestType::CiZhi:
            cout << "��ְ: ����˹����������ļ�, ��ΰ�������, �´α�������!!!" << endl;
            break;
        default:
            break;
        }
    }
};

//�ύ�������
class DaCongMing
{
public:
    void request(RequestType type, AbstractManager* manger)
    {
        manger->handleRequest(type);
    }
};

int main()
{
    Manager* manager = new Manager;
    CEO* ceo = new CEO;
    Boss* boss = new Boss;
    manager->setNext(ceo);
    ceo->setNext(boss);

    //����Ա��ʵ��
    DaCongMing* boy = new DaCongMing;
    cout << "========== �������ͷ��˾��Ҫ�� ==========" << endl;
    boy->request(RequestType::QingJia, manager);
    boy->request(RequestType::ZhangXin, manager);
    boy->request(RequestType::CiZhi, manager);
    cout << "========== �����Խ����CEO��Ҫ�� ==========" << endl;
    boy->request(RequestType::QingJia, ceo);
    boy->request(RequestType::ZhangXin, ceo);
    boy->request(RequestType::CiZhi, ceo);
    cout << "========== �����ֱ����BOSS��Ҫ�� ==========" << endl;
    boy->request(RequestType::QingJia, boss);
    boy->request(RequestType::ZhangXin, boss);
    boy->request(RequestType::CiZhi, boss);
    delete boy;
    delete manager;
    delete ceo;
    delete boss;
	return 0;
}
