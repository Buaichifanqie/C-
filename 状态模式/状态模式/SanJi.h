#pragma once
#include "State.h"

class SanJi
{
public:
    SanJi()  // ���캯����ʼ��
    {
        m_state = new ForeNoonState();  // ��ʼ��Ϊ����״̬
    }

    // ��������
    void working()
    {
        if (m_state)  // ȷ��m_state��Ϊ��
        {
            m_state->working(this);  // ���õ�ǰ״̬�Ĺ�������
        }
    }

    // �л�״̬
    void setState(AbstractState* state)
    {
        if (m_state)  // ���жϵ�ǰ״̬�Ƿ�Ϊ��
        {
            delete m_state;  // ɾ����ǰ״̬
        }
        m_state = state;  // ����Ϊ�µ�״̬
    }

    // ��ȡʱ��
    int getClock()
    {
        return m_clock;
    }

    // ����ʱ��
    void setClock(int clock)
    {
        m_clock = clock;
    }

private:
    int m_clock = 0;  // ��ǰʱ���
    AbstractState* m_state = nullptr;  // ��ǰ״ָ̬�룬��ʼΪ��
};