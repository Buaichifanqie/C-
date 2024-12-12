#pragma once
#include "MyList.h"
// 抽象的迭代器类
class Iterator
{
public:
    Iterator(MyList* mylist) : m_list(mylist) {}
    Node* current()
    {
        return m_current;
    }
    virtual Node* first() = 0;
    virtual Node* next() = 0;
    virtual bool isDone() = 0;
    virtual ~Iterator() {}
protected:
    MyList* m_list = nullptr;
    Node* m_current = nullptr;
};

class ForwardIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node* first() override
    {
        m_current = m_list->head();
        return m_current;
    }
    Node* next() override
    {
        m_current = m_current->next;
        return m_current;
    }
    bool isDone() override
    {
        return m_current == m_list->tail()->next;
    }
};

// 逆向迭代器
class ReverseIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node* first() override
    {
        m_current = m_list->tail();
        return m_current;
    }
    Node* next() override
    {
        m_current = m_current->prev;
        return m_current;
    }
    bool isDone() override
    {
        return m_current == m_list->head()->prev;
    }
};
