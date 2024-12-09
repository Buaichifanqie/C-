#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

#if 0
//饿汉模式->定义类时创建单例对象
// 定义一个单例模式的类 TaskQueue
class TaskQueue
{
public:
    // 第二种删除拷贝构造函数和赋值运算符，避免外部创建该类对象
    TaskQueue(const TaskQueue& t) = delete;  // 禁用拷贝构造函数
    TaskQueue& operator=(const TaskQueue& t) = delete;  // 禁用赋值运算符
    // 获取唯一实例的静态函数
    static TaskQueue* getInstance()
    {
        return m_taskQ;  // 返回静态成员 m_taskQ
    }
    // 打印成员函数，用于测试
    void print()
    {
        cout << "我是一个单例对象的成员函数..." << endl;
    }
private:
    // 第一种：将构造函数设置为私有，外部无法直接创建对象
    TaskQueue() = default;  // 私有构造函数
    // 静态成员变量，存储类的唯一实例
    static TaskQueue* m_taskQ;
};

// 静态成员变量的定义，初始化唯一的实例
TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

# if 0
//懒汉模式->什么时候使用这个单例对象，我们在使用的时候再创建对应的实例
// 定义一个单例模式的类 TaskQueue
class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        TaskQueue* queue = m_taskQ.load();//通过原子变量加载内部实例
        if (queue == nullptr)
        {
            // m_mutex.lock();  // 加锁: 方式1
            lock_guard<mutex> locker(m_mutex);  // 加锁: 方式2
            queue = m_taskQ.load();
            if (queue == nullptr)
            {
                queue = new TaskQueue;
                m_taskQ.store(queue);//保存到原子变量
            }
            // m_mutex.unlock();
        }
        return queue;
    }

    void print()
    {
        cout << "hello, world!!!" << endl;
    }
private:
    TaskQueue() = default;
    static atomic<TaskQueue*> m_taskQ;
    static mutex m_mutex;
};
atomic<TaskQueue*> TaskQueue::m_taskQ;
mutex TaskQueue::m_mutex;

int main()
{
    TaskQueue* queue = TaskQueue::getInstance();
    queue->print();
    return 0;
}

#endif

#if 0
//懒汉模式->什么时候使用这个单例对象，我们在使用的时候再创建对应的实例
// 使用静态的局部变量解决线程安全问题->编译器必须支持C++11
// 定义一个单例模式的类 TaskQueue
class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        static TaskQueue task;//属于全局数据区（默认值都为0 所以只要数据为0都算没有初始化）
        return &task;
    }

    void print()
    {
        cout << "hello, world!!!" << endl;
    }
private:
    TaskQueue() = default;
};

int main()
{
    TaskQueue* queue = TaskQueue::getInstance();
    queue->print();
    return 0;
}
#endif


#if 1
//饿汉模式->定义类时创建单例对象
//写一个任务队列
class TaskQueue
{
public:
    TaskQueue(const TaskQueue& t) = delete; 
    TaskQueue& operator=(const TaskQueue& t) = delete;  
    static TaskQueue* getInstance()
    {
        return m_taskQ;  
    }
    void print()
    {
        cout << "我是一个单例对象的成员函数..." << endl;
    }
    //判断任务队列是否为空
    bool isEmpty()
    {
        lock_guard<mutex> locker(m_mutex);//管理互斥锁，自动加锁当函数析构时自动解锁
        bool flag = m_data.empty();
        return flag;
    }
    //添加任务
    void addTask(int node)
    {
        lock_guard<mutex> locker(m_mutex);
        m_data.push(node);
    }
    //删除任务
    bool popTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (m_data.empty())
        {
            return false;
        }
        m_data.pop();
        return true;
    }
    //取出一个任务队列（不删除）
    int taketask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (m_data.empty())
        {
            return -1;
        }
        int data = m_data.front();
        return data;
    }
private:
    TaskQueue() = default;  
    static TaskQueue* m_taskQ;
    //定义任务队列(唯一实例)
    queue<int>m_data;
    mutex m_mutex;//保护共享资源m_data
};
TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

int main()
{
    TaskQueue* taskQ = TaskQueue::getInstance();
    //生产者
    thread t1([=]()
        {
            for (int i = 0; i < 10; i++)
            {
                taskQ->addTask(i + 100);
                cout << "+++ push data:" << i + 100 << ",thread Id----------" << this_thread::get_id() << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
            }

        });
    //消费者
    thread t2([=]()
        {
            this_thread::sleep_for(chrono::milliseconds(100));
            while(!taskQ->isEmpty())
            {
                int num=taskQ->taketask();
                cout << "+++ take data:" << num << ",thread Id++++++++++++++" << this_thread::get_id() << endl;
                taskQ->popTask();
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        });
    t1.join();//阻塞线程
    t2.join();
    return 0;
}