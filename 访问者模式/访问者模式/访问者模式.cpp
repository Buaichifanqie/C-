#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Visitor.h"
#include"Member.h"
#include<list>
#include<vector>
using namespace std;

void Anger::maleDoing(MaleMember* male)
{
	cout << "���ǲ�ñ�����ŵ�" << male->getName() << endl;
	fight();
}

void Anger::femaleDoing(FeMaleMember* female)
{
    cout << "���ǲ�ñ�����ŵ�" << female->getName() << endl;
    warning();
}

void Anger::warning()
{
    cout << "��ҿ��ӣ��ҿ춥��ס��, ��Ҫ����!!!" << endl;
}

void Anger::fight()
{
    cout << "ֻҪ�����ž͵ø���һ�Ѫս����!!!" << endl;
}

void Horror::maleDoing(MaleMember* male)
{
    cout << "���ǲ�ñ�����ŵ�" << male->getName() << endl;
    thinking();
}

void Horror::femaleDoing(FeMaleMember* female)
{
    cout << "���ǲ�ñ�����ŵ�" << female->getName() << endl;
    help();
}

void Horror::help()
{
    cout << "�������̫����, ̫������, ��Ⱦ��ҡ�����" << endl;
}

void Horror::thinking()
{
    cout << "�ø���ͬ����һ�鹥������һ�, ��Ȼ�����򲻹�ѽ!!!" << endl;
}


// ��ñ��
class CaoMaoTeam
{
public:
    CaoMaoTeam()
    {
        m_actions.push_back(new Anger);
        m_actions.push_back(new Horror);
    }
    void add(AbstractMember* member)
    {
        m_members.push_back(member);
    }
    void remove(AbstractMember* member)
    {
        m_members.remove(member);
    }
    void display()
    {
        for (const auto& item : m_members)
        {
            int index = rand() % 2;
            item->accept(m_actions[index]);
        }
    }
    ~CaoMaoTeam()
    {
        for (const auto& item : m_members)
        {
            delete item;
        }
        for (const auto& item : m_actions)
        {
            delete item;
        }
    }
private:
    list<AbstractMember*> m_members;
    vector<AbstractAction*> m_actions;
};
int main()
{
    srand(time(NULL));
    vector<string> names{
        "·��", "��¡","ɽ��", "�ǰ�", "������", "������", "��³��"
    };
    CaoMaoTeam* caomao = new CaoMaoTeam;
    for (const auto& item : names)
    {
        caomao->add(new MaleMember(item));
    }
    caomao->add(new FeMaleMember("����"));
    caomao->add(new FeMaleMember("�ޱ�"));
    caomao->display();
    delete caomao;
    return 0;
}