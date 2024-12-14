#pragma once

class MaleMember;
class FeMaleMember;
//��Ϊ��Ӧ�Ļ���
class AbstractAction
{
public:
	//�����˷���
	virtual void maleDoing(MaleMember* male)=0;
	//��Ů�˷���
	virtual void femaleDoing(FeMaleMember* female)=0;
	virtual ~AbstractAction() {}
};

//Anger
class Anger:public AbstractAction
{
public:
	//�����˷���
	void maleDoing(MaleMember* male)override;
	//��Ů�˷���
	void femaleDoing(FeMaleMember* female)override;
	void fight();
	void warning();
};

//Horror
class Horror :public AbstractAction
{
public:
	//�����˷���
	void maleDoing(MaleMember* male)override;
	//��Ů�˷���
	void femaleDoing(FeMaleMember* female)override;
	void help();
	void thinking();
};
