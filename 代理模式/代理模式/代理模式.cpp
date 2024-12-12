#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
//代理类的基类
class Communication
{
public:
	virtual void communication() = 0;
	virtual ~Communication() {};
};
//子类
class Speaker:public Communication
{
public:
	virtual void communication()
	{
		cout << "开始说话..." << endl;
		cout << "通话时发生了一些列的表情变化..." << endl;
	}
};
//代理类
// 电话虫
class DenDenMushi : public Communication
{
public:
    DenDenMushi()
    {
        m_isStart = true;
        m_speaker = new Speaker;
    }
    ~DenDenMushi()
    {
        if (m_speaker != nullptr)
        {
            delete m_speaker;
        }
    }
    // 判断是否已经开始通话了
    bool isStart()
    {
        return m_isStart;
    }
    void communication() override
    {
        if (isStart())
        {
            // 得到通话者语言和表情信息, 并加以模仿
            cout << "电话虫开始实时模仿通话者的语言和表情..." << endl;
            m_speaker->communication();
        }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

int main()
{
    //直接交流
    Communication* speaker = new Speaker;
    speaker->communication();
    delete speaker;
    cout << "+========================================+" << endl;
    //通过电话虫交流
    speaker = new DenDenMushi;
    speaker->communication();
    delete speaker; 
	return 0;
}
