// Member.h
#pragma once
#include <iostream>
#include "Visitor.h"
using namespace std;
// ����ĳ�Ա��
class AbstractMember
{
public:
    AbstractMember(string name) :m_name(name) {}
    string getName()
    {
        return m_name;
    }
    // ����״̬����ķ���
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember() {}
protected:
    string m_name;
};

// ���Գ�Ա
class MaleMember : public AbstractMember
{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->maleDoing(this);
    }
};

// Ů�Գ�Ա
class FeMaleMember : public AbstractMember
{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->femaleDoing(this);
    }
};