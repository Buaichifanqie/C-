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

