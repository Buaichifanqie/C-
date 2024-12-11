#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#if 0
//�����������è���ǹ�����ϵ
//�������
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
//������
class Ameriacn:public Foreigner
{
public:
	string confession() override
	{
		return "������Ҳ�Ҫ��!!!";
	};
};
//������
class French :public Foreigner
{
public:
	string confession() override
	{
		return "�Ҹ���������ǿ��!!!";
	};
};
//��è
class Panda
{
public:
	void recvMessage(string msg)
	{
		cout << msg << endl;
	}
	string sendMessage()
	{
		return string("������ˡ��ǿ�������ˣ�����");
	}
};
//��������
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
	using AbstractChopper::AbstractChopper;//�̳и����ж�������еĹ��캯��
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//������è���ԣ��������ݴ��ݸ���è
		m_panda->recvMessage("������˵"+msg);
	}
	virtual void translateToHuman()
	{
		string msg = m_panda->sendMessage();
		//����è����ת����Ӣ��ٴ��ݸ������
		m_foreigner->setResult("������:" + msg);
	}
};

class FrechChopper : public AbstractChopper
{
public:
	using AbstractChopper::AbstractChopper;//�̳и����ж�������еĹ��캯��
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//������è���ԣ��������ݴ��ݸ���è
		m_panda->recvMessage("������˵:"+msg);
	}
	virtual void translateToHuman()
	{
		string msg = m_panda->sendMessage();
		//����è����ת����Ӣ��ٴ��ݸ������
		m_foreigner->setResult("������:" + msg);
	}
};
#endif

#if 1
//�����������è���Ǽ̳й�ϵ
//�������
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
//������
class Ameriacn :public Foreigner
{
public:
	string confession() override
	{
		return "������Ҳ�Ҫ��!!!";
	};
};
//������
class French :public Foreigner
{
public:
	string confession() override
	{
		return "�Ҹ���������ǿ��!!!";
	};
};
//��è
class Panda
{
public:
	void recvMessage(string msg)
	{
		cout << msg << endl;
	}
	string sendMessage()
	{
		return string("������ˡ��ǿ�������ˣ�����");
	}
};
//��������
class AbstractChopper : public Panda //���Զ��ؼ̳�
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
	using AbstractChopper::AbstractChopper;//�̳и����ж�������еĹ��캯��
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//������è���ԣ��������ݴ��ݸ���è
		recvMessage("������˵" + msg);
	}
	virtual void translateToHuman()
	{
		string msg = sendMessage();
		//����è����ת����Ӣ��ٴ��ݸ������
		m_foreigner->setResult("������:" + msg);
	}
};

class FrechChopper : public AbstractChopper
{
public:
	using AbstractChopper::AbstractChopper;//�̳и����ж�������еĹ��캯��
	virtual void translateToPanda()
	{
		string msg = m_foreigner->confession();
		//������è���ԣ��������ݴ��ݸ���è
		recvMessage("������˵:" + msg);
	}
	virtual void translateToHuman()
	{
		string msg = sendMessage();
		//����è����ת����Ӣ��ٴ��ݸ������
		m_foreigner->setResult("������:" + msg);
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