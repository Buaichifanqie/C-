#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>
#include<vector>

//��ʷ����¼��
class History
{
public:
	History(string msg):m_msg(msg){}
	string getHistory()
	{
		return m_msg;
	}
private:
	string m_msg;
};

//����
class JiaoPenJi
{
public:
	void setState(string msg)
	{
		m_msg = msg;
	}

	string getState()
	{
		return m_msg;
	}

	void beiDaddyDa()
	{
		cout << "���輦�����Ӻݺݵ���������, ���ڳ���������֮ǰ�����ϵ���Щ����: " << endl;
	}
	History* saveHistory()
	{
		return new History(m_msg);
	}
	void getStateFromHistory(History* history)
	{
		m_msg = history->getHistory();
	}
private:
	string m_msg;
};

//��¼��
class Recorder
{
public:
	void addHistory(int index, History* history)
	{
		m_history.insert(make_pair(index, history));
	}
	History* getHistory(int index)
	{
		if (m_history.find(index) != m_history.end())
		{
			return m_history[index];
		}
		return nullptr;
	}
private:
	map<int, History*>m_history;
};

int main()
{
	vector<string> msg{
		"������͵���й�����ҽ!!!",
		"�����Ϸ������ֻ�ս��!!!",
		"�������Ͼ�����ɱ!!!!",
		"����������Ⱥ���͵��㵺���й�������!!!",
		"������731���ӵ�ϸ������������!!!",
		"�����϶��ҹ���Ů����������Ϊ!!!",
		"�����ϴ��й��Ӷ�������ڼƵ���Դ��������Ƶ�����!!!",
		"�Ҹɵ������¶���������, ���ǲ�����......"
	};
	JiaoPenJi* jiaopenji = new JiaoPenJi;
	Recorder* recorder = new Recorder;
	//��С�ձ������м�¼����
	for (int i = 0; i < msg.size(); i++)
	{
		jiaopenji->setState(msg.at(i));//һ����˵��[]Ч�ʸ��ߣ���������Ҫ������ֵ���и��ӵļ�����ߵ�������Ҫ����Ƿ�Խ��ʱ��
		//���õ�������Ĭ����.at()���������뾡�ܺ������������bug��[]���ʺ϶Գ���Ч��Ҫ��Ƚϸߵĳ�����
		recorder->addHistory(i, jiaopenji->saveHistory());
	}
	jiaopenji->beiDaddyDa();
	for (int i = 0; i < msg.size(); i++)
	{
		jiaopenji->getStateFromHistory(recorder->getHistory(i));
		cout << "-------" << jiaopenji->getState() << endl;
	}
	return 0;
}