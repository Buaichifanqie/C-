#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象的管理者节点
enum class RequestType :char { QingJia, ZhangXin, CiZhi };//强类型枚举因为指定是char类型所以一共占3个字节
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

//底层管理者
class Manager:public AbstractManager
{
public:
	virtual void handleRequest(RequestType type) override
	{
        switch (type)
        {
        case RequestType::QingJia:
            cout << "请假: 同意请假，好好休息~~~" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "涨薪: 这个我得请示一下咱们CEO..." << " ====> ";
            m_next->handleRequest(type);
            break;
        case RequestType::CiZhi:
            cout << "辞职: 我给你向上级反应一下..." << " ====> ";
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
            cout << "请假: 同意请假, 下不为例..." << endl;
            break;
        case RequestType::ZhangXin:
            cout << "涨薪: 你工资不少了, 给你个购物券吧..." << endl;
            break;
        case RequestType::CiZhi:
            cout << "辞职: 这个我得问问咱们老板..." << " ====> ";
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
            cout << "请假: 只有工作才能实现人生价值，回去好好坚守岗位！！！" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "涨薪: 钱财乃身外之物, 要视其如粪土!!!" << endl;
            break;
        case RequestType::CiZhi:
            cout << "辞职: 巴洛克工作社就是你的家, 这次把你留下, 下次别再提了!!!" << endl;
            break;
        default:
            break;
        }
    }
};

//提交请求的类
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

    //创建员工实例
    DaCongMing* boy = new DaCongMing;
    cout << "========== 大聪明向顶头上司提要求 ==========" << endl;
    boy->request(RequestType::QingJia, manager);
    boy->request(RequestType::ZhangXin, manager);
    boy->request(RequestType::CiZhi, manager);
    cout << "========== 大聪明越级找CEO提要求 ==========" << endl;
    boy->request(RequestType::QingJia, ceo);
    boy->request(RequestType::ZhangXin, ceo);
    boy->request(RequestType::CiZhi, ceo);
    cout << "========== 大聪明直接找BOSS提要求 ==========" << endl;
    boy->request(RequestType::QingJia, boss);
    boy->request(RequestType::ZhangXin, boss);
    boy->request(RequestType::CiZhi, boss);
    delete boy;
    delete manager;
    delete ceo;
    delete boss;
	return 0;
}
