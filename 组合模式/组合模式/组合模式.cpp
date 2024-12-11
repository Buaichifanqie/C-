#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<string>
//����ڵ�ĳ�����
class AbstarctTeam
{
public:
	AbstarctTeam(string name) : m_name(name){}
	string getName()
	{
		return m_name;
	}
	void setParent(AbstarctTeam* team)
	{
		m_parent = team;
	}
	AbstarctTeam* getParent()
	{
		return m_parent;
	}
	//�麯��
	virtual bool hasChild()
	{
		return false;
	}
	virtual void addChild(AbstarctTeam* node){}
	virtual void removeChild(AbstarctTeam* node){}

	virtual void fight() = 0;
	virtual void display() = 0;

	virtual ~AbstarctTeam() {};

protected:
	string m_name;
	AbstarctTeam* m_parent = nullptr;
};
//Ҷ�ӽڵ���
class LeafTeam : public AbstarctTeam
{
public:
	using AbstarctTeam::AbstarctTeam;
	void fight()override
	{
		cout << m_parent->getName() + m_name + "��ں��ӵĴ�Ա���н������ⲫս..." << endl;
	}
	void display()override
	{
		cout << "����" << m_parent->getName() << "������" << m_name << endl;
	}
	~LeafTeam()
	{
		cout << "����" << m_parent->getName() << "������" << m_name
			<< ", ս���Ѿ�����, �ݰ�..." << endl;
	}

};
//�����߽ڵ���
class ManagerTeam : public AbstarctTeam
{
public:
    using AbstarctTeam::AbstarctTeam;
    void fight() override
    {
        cout << m_name + "�ͺں��ӵĶ�ħ��ʵ������ս��!!!" << endl;
    }
    void addChild(AbstarctTeam* node) override
    {
        node->setParent(this);
        m_children.push_back(node);
    }
    void removeChild(AbstarctTeam* node) override
    {
        node->setParent(nullptr);
        m_children.remove(node);
    }
    bool hasChild()
    {
        return true;
    }
    list<AbstarctTeam*> getChildren()
    {
        return m_children;
    }
    void display()
    {
        string info = string();
        for (const auto item : m_children)
        {
            if (item == m_children.back())
            {
                info += item->getName();
            }
            else
            {
                // ���ȼ�: + > +=
                info += item->getName() + ", ";
            }
        }
        cout << m_name + "�Ĵ����ǡ�" << info << "��" << endl;
    }
    ~ManagerTeam()
    {
        cout << "���ǡ�" << m_name << "��ս������, �ݰ�..." << endl;
    }
private:
    list<AbstarctTeam*> m_children;
};

// �ڴ��ͷ�
void gameover(AbstarctTeam* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root && root->hasChild())
    {
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root);
        list<AbstarctTeam*> children = team->getChildren();
        for (const auto item : children)
        {
            gameover(item);
        }
    }
    delete root;
}

// �ͺں���ս��
void fighting()
{
    vector<string> nameList = {
        "����������", "���о��ֲ�", "�˱�ˮ��", "����ŷ������",
        "������������", "�ޱ�������", "Լ�������Ǵ���"
    };
    // ���ڵ�
    ManagerTeam* root = new ManagerTeam("��ñ������");
    for (int i = 0; i < nameList.size(); ++i)
    {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->addChild(child);
        if (i == nameList.size() - 1)
        {
            // �����һ����������Ӵ���
            for (int j = 0; j < 9; ++j)
            {
                LeafTeam* leaf = new LeafTeam("��" + to_string(j + 1) + "����");
                child->addChild (leaf);
                leaf->fight();
                leaf->display();
            }
            child->fight();
            child->display();
        }
    }
    root->fight();
    root->display();

    cout << "====================================" << endl;
    gameover(root);
}

int main()
{
    fighting();
    return 0;
}
