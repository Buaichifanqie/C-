#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>
#include<vector>

//历史备忘录类
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

//鬼子
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
		cout << "脚盆鸡被兔子狠狠地揍了又揍, 终于承认了它们之前不承认的这些罪行: " << endl;
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

//记录者
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
		"不承认偷了中国的中医!!!",
		"不承认发动了侵华战争!!!",
		"不承认南京大屠杀!!!!",
		"不承认琉球群岛和钓鱼岛是中国的领土!!!",
		"不承认731部队的细菌和人体试验!!!",
		"不承认对我国妇女做出畜生行为!!!",
		"不承认从中国掠夺的数以亿计的资源和数以万计的文物!!!",
		"我干的龌龊事儿罄竹难书, 就是不承认......"
	};
	JiaoPenJi* jiaopenji = new JiaoPenJi;
	Recorder* recorder = new Recorder;
	//把小日本的罪行记录下来
	for (int i = 0; i < msg.size(); i++)
	{
		jiaopenji->setState(msg.at(i));//一般来说用[]效率更高，尤其是需要对索引值进行复杂的计算或者单纯不需要检查是否越界时。
		//更好的做法是默认用.at()，这样代码尽管很慢但不会产生bug；[]更适合对程序效率要求比较高的场景。
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