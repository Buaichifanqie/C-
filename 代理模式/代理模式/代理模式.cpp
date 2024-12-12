#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
//������Ļ���
class Communication
{
public:
	virtual void communication() = 0;
	virtual ~Communication() {};
};
//����
class Speaker:public Communication
{
public:
	virtual void communication()
	{
		cout << "��ʼ˵��..." << endl;
		cout << "ͨ��ʱ������һЩ�еı���仯..." << endl;
	}
};
//������
// �绰��
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
    // �ж��Ƿ��Ѿ���ʼͨ����
    bool isStart()
    {
        return m_isStart;
    }
    void communication() override
    {
        if (isStart())
        {
            // �õ�ͨ�������Ժͱ�����Ϣ, ������ģ��
            cout << "�绰�濪ʼʵʱģ��ͨ���ߵ����Ժͱ���..." << endl;
            m_speaker->communication();
        }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

int main()
{
    //ֱ�ӽ���
    Communication* speaker = new Speaker;
    speaker->communication();
    delete speaker;
    cout << "+========================================+" << endl;
    //ͨ���绰�潻��
    speaker = new DenDenMushi;
    speaker->communication();
    delete speaker; 
	return 0;
}
