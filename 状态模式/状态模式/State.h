#pragma once

class SanJi;
//״̬��Ļ���
class AbstractState
{
public:
	virtual void working(SanJi* sanji) = 0;
	virtual ~AbstractState(){}
};

//����״̬
class ForeNoonState :public AbstractState
{
public:
	void working(SanJi* sanji) override;
};

//����״̬
class NoonState :public AbstractState
{
public:
	void working(SanJi* sanji) override;
};

//����״̬
class AfterNoonState :public AbstractState
{
public:
	void working(SanJi* sanji) override;
};

//����״̬
class EveningNoonState :public AbstractState
{
public:
	void working(SanJi* sanji) override;
};
