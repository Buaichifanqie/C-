#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<string>
//定义节点的抽象类
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
	//虚函数
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
//叶子节点类
class LeafTeam : public AbstarctTeam
{
public:
	using AbstarctTeam::AbstarctTeam;
	void fight()override
	{
		cout << m_parent->getName() + m_name + "与黑胡子的船员进行近距离肉搏战..." << endl;
	}
	void display()override
	{
		cout << "我是" << m_parent->getName() << "下属的" << m_name << endl;
	}
	~LeafTeam()
	{
		cout << "我是" << m_parent->getName() << "下属的" << m_name
			<< ", 战斗已经结束, 拜拜..." << endl;
	}

};
//管理者节点类
class ManagerTeam : public AbstarctTeam
{
public:
    using AbstarctTeam::AbstarctTeam;
    void fight() override
    {
        cout << m_name + "和黑胡子的恶魔果实能力者战斗!!!" << endl;
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
                // 优先级: + > +=
                info += item->getName() + ", ";
            }
        }
        cout << m_name + "的船队是【" << info << "】" << endl;
    }
    ~ManagerTeam()
    {
        cout << "我是【" << m_name << "】战斗结束, 拜拜..." << endl;
    }
private:
    list<AbstarctTeam*> m_children;
};

// 内存释放
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

// 和黑胡子战斗
void fighting()
{
    vector<string> nameList = {
        "俊美海贼团", "巴托俱乐部", "八宝水军", "艾迪欧海贼团",
        "咚塔塔海贼团", "巨兵海贼团", "约塔玛利亚大船团"
    };
    // 根节点
    ManagerTeam* root = new ManagerTeam("草帽海贼团");
    for (int i = 0; i < nameList.size(); ++i)
    {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->addChild(child);
        if (i == nameList.size() - 1)
        {
            // 给最后一个番队添加子船队
            for (int j = 0; j < 9; ++j)
            {
                LeafTeam* leaf = new LeafTeam("第" + to_string(j + 1) + "番队");
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
