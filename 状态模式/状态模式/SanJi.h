#pragma once
#include "State.h"

class SanJi
{
public:
    SanJi()  // 构造函数初始化
    {
        m_state = new ForeNoonState();  // 初始化为上午状态
    }

    // 工作函数
    void working()
    {
        if (m_state)  // 确保m_state不为空
        {
            m_state->working(this);  // 调用当前状态的工作函数
        }
    }

    // 切换状态
    void setState(AbstractState* state)
    {
        if (m_state)  // 先判断当前状态是否为空
        {
            delete m_state;  // 删除当前状态
        }
        m_state = state;  // 更新为新的状态
    }

    // 获取时间
    int getClock()
    {
        return m_clock;
    }

    // 设置时间
    void setClock(int clock)
    {
        m_clock = clock;
    }

private:
    int m_clock = 0;  // 当前时间点
    AbstractState* m_state = nullptr;  // 当前状态指针，初始为空
};