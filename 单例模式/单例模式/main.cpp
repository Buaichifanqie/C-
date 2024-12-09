#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

#if 0
//����ģʽ->������ʱ������������
// ����һ������ģʽ���� TaskQueue
class TaskQueue
{
public:
    // �ڶ���ɾ���������캯���͸�ֵ������������ⲿ�����������
    TaskQueue(const TaskQueue& t) = delete;  // ���ÿ������캯��
    TaskQueue& operator=(const TaskQueue& t) = delete;  // ���ø�ֵ�����
    // ��ȡΨһʵ���ľ�̬����
    static TaskQueue* getInstance()
    {
        return m_taskQ;  // ���ؾ�̬��Ա m_taskQ
    }
    // ��ӡ��Ա���������ڲ���
    void print()
    {
        cout << "����һ����������ĳ�Ա����..." << endl;
    }
private:
    // ��һ�֣������캯������Ϊ˽�У��ⲿ�޷�ֱ�Ӵ�������
    TaskQueue() = default;  // ˽�й��캯��
    // ��̬��Ա�������洢���Ψһʵ��
    static TaskQueue* m_taskQ;
};

// ��̬��Ա�����Ķ��壬��ʼ��Ψһ��ʵ��
TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

# if 0
//����ģʽ->ʲôʱ��ʹ�������������������ʹ�õ�ʱ���ٴ�����Ӧ��ʵ��
// ����һ������ģʽ���� TaskQueue
class TaskQueue
{
public:
    // = delete ����������, Ҳ���Խ������Ȩ������Ϊ˽��
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        TaskQueue* queue = m_taskQ.load();//ͨ��ԭ�ӱ��������ڲ�ʵ��
        if (queue == nullptr)
        {
            // m_mutex.lock();  // ����: ��ʽ1
            lock_guard<mutex> locker(m_mutex);  // ����: ��ʽ2
            queue = m_taskQ.load();
            if (queue == nullptr)
            {
                queue = new TaskQueue;
                m_taskQ.store(queue);//���浽ԭ�ӱ���
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
//����ģʽ->ʲôʱ��ʹ�������������������ʹ�õ�ʱ���ٴ�����Ӧ��ʵ��
// ʹ�þ�̬�ľֲ���������̰߳�ȫ����->����������֧��C++11
// ����һ������ģʽ���� TaskQueue
class TaskQueue
{
public:
    // = delete ����������, Ҳ���Խ������Ȩ������Ϊ˽��
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        static TaskQueue task;//����ȫ����������Ĭ��ֵ��Ϊ0 ����ֻҪ����Ϊ0����û�г�ʼ����
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
//����ģʽ->������ʱ������������
//дһ���������
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
        cout << "����һ����������ĳ�Ա����..." << endl;
    }
    //�ж���������Ƿ�Ϊ��
    bool isEmpty()
    {
        lock_guard<mutex> locker(m_mutex);//�����������Զ���������������ʱ�Զ�����
        bool flag = m_data.empty();
        return flag;
    }
    //�������
    void addTask(int node)
    {
        lock_guard<mutex> locker(m_mutex);
        m_data.push(node);
    }
    //ɾ������
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
    //ȡ��һ��������У���ɾ����
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
    //�����������(Ψһʵ��)
    queue<int>m_data;
    mutex m_mutex;//����������Դm_data
};
TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

int main()
{
    TaskQueue* taskQ = TaskQueue::getInstance();
    //������
    thread t1([=]()
        {
            for (int i = 0; i < 10; i++)
            {
                taskQ->addTask(i + 100);
                cout << "+++ push data:" << i + 100 << ",thread Id----------" << this_thread::get_id() << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
            }

        });
    //������
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
    t1.join();//�����߳�
    t2.join();
    return 0;
}