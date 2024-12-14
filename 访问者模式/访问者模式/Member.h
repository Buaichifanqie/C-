// Member.h
#pragma once
#include <iostream>
#include "Visitor.h"
using namespace std;
// 抽象的成员类
class AbstractMember
{
public:
    AbstractMember(string name) :m_name(name) {}
    string getName()
    {
        return m_name;
    }
    // 接受状态对象的访问
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember() {}
protected:
    string m_name;
};

// 男性成员
class MaleMember : public AbstractMember
{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->maleDoing(this);
    }
};

// 女性成员
class FeMaleMember : public AbstractMember
{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->femaleDoing(this);
    }
};