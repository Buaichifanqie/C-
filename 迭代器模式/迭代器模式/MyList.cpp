#include "MyList.h"
#include "Iterator.h"

Node* MyList::insert(Node* item, string data)
{
    Node* node = nullptr;
    if (item == m_head)
    {
        node = pushFront(data);
    }
    else
    {
        node = new Node(data);
        node->next = item;
        node->prev = item->prev;
        // 重新连接
        item->prev->next = node;
        item->prev = node;
        m_count++;
    }
    return node;
}

Node* MyList::pushFront(string data)
{
    Node* node = new Node(data);
    // 空链表
    if (m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    m_count++;
    return node;
}

Node* MyList::pushBack(string data)
{
    Node* node = new Node(data);
    // 空链表
    if (m_tail == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}

Iterator* MyList::getIterator(bool isReverse)
{
    Iterator* iterator = nullptr;
    if (isReverse)
    {
        iterator = new ReverseIterator(this);
    }
    else
    {
        iterator = new ForwardIterator(this);
    }
    return iterator;
}
