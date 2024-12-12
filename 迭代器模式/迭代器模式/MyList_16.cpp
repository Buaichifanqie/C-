#include "MyList_16.h"

// 正向迭代器
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
