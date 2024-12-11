#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#if 0
//适配器类和熊猫类是关联关系
//外国人类
class Foreigner
{
public:
	virtual string confession() = 0;
	void setResult(string res)
	{
		cout << "Panda say:" << res << endl;
	}
	virtual ~Foreigner() {};
};
//美国人
class Ameriacn:public Foreigner
{
public:
	string confession() override
	{
		return "我有罪，我不要脸!!!";
	};
};
//法国人
class French :public Foreigner
{
public:
	string confession() override
	{
		return "我该死，我是强盗!!!";
	};
};
//熊猫
class Panda
{
public:
	void recvMessage(string msg)
	{
		cout << msg << endl;
	}
	string sendMessage()
	{
		return string("不可饶恕的强盗，罪人！！！");
	}
};
//适配器类
class AbstractChopper
{
public:
	AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner){}

	virtual void translateToPanda() = 0;
	virtual void translateToHuman() = 0;
	virtual ~AbstractChopper() {};
protected:
	Panda* m_panda;
	Foreigner* m_foreigner;
};

class EnglishChopper: public AbstractChopper
{
public:
	using AbstractChopper::AbstractChopper;//继承父类中定义的所有的构造函数
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//解析熊猫语言，并将数据传递给熊猫
		m_panda->recvMessage("美国人说"+msg);
	}
	virtual void translateToHuman()
	{
		string msg = m_panda->sendMessage();
		//将熊猫语言转换成英语，再传递给外国人
		m_foreigner->setResult("美国佬:" + msg);
	}
};

class FrechChopper : public AbstractChopper
{
public:
	using AbstractChopper::AbstractChopper;//继承父类中定义的所有的构造函数
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//解析熊猫语言，并将数据传递给熊猫
		m_panda->recvMessage("法国人说:"+msg);
	}
	virtual void translateToHuman()
	{
		string msg = m_panda->sendMessage();
		//将熊猫语言转换成英语，再传递给外国人
		m_foreigner->setResult("法国佬:" + msg);
	}
};
#endif

#if 1
//适配器类和熊猫类是继承关系
//外国人类
class Foreigner
{
public:
	virtual string confession() = 0;
	void setResult(string res)
	{
		cout << "Panda say:" << res << endl;
	}
	virtual ~Foreigner() {};
};
//美国人
class Ameriacn :public Foreigner
{
public:
	string confession() override
	{
		return "我有罪，我不要脸!!!";
	};
};
//法国人
class French :public Foreigner
{
public:
	string confession() override
	{
		return "我该死，我是强盗!!!";
	};
};
//熊猫
class Panda
{
public:
	void recvMessage(string msg)
	{
		cout << msg << endl;
	}
	string sendMessage()
	{
		return string("不可饶恕的强盗，罪人！！！");
	}
};
//适配器类
class AbstractChopper : public Panda //可以多重继承
{
public:
	AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}

	virtual void translateToPanda() = 0;
	virtual void translateToHuman() = 0;
	virtual ~AbstractChopper() {};
protected:
	Foreigner* m_foreigner;
};

class EnglishChopper : public AbstractChopper
{
public:
	using AbstractChopper::AbstractChopper;//继承父类中定义的所有的构造函数
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//解析熊猫语言，并将数据传递给熊猫
		recvMessage("美国人说" + msg);
	}
	virtual void translateToHuman()
	{
		string msg = sendMessage();
		//将熊猫语言转换成英语，再传递给外国人
		m_foreigner->setResult("美国佬:" + msg);
	}
};

class FrechChopper : public AbstractChopper
{
public:
	using AbstractChopper::AbstractChopper;//继承父类中定义的所有的构造函数
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//解析熊猫语言，并将数据传递给熊猫
		recvMessage("法国人说:" + msg);
	}
	virtual void translateToHuman()
	{
		string msg = sendMessage();
		//将熊猫语言转换成英语，再传递给外国人
		m_foreigner->setResult("法国佬:" + msg);
	}
};
#endif


int main()
{
	Foreigner* foreigner = new Ameriacn;
	AbstractChopper* adapter = new EnglishChopper(foreigner);
	adapter->translateToPanda();
	adapter->translateToHuman();
	delete foreigner;
	delete adapter;
	cout << "================================" << endl;
	foreigner = new French;
	adapter = new FrechChopper(foreigner);
	adapter->translateToPanda();
	adapter->translateToHuman();
	delete foreigner;
	delete adapter;
	return 0;
}