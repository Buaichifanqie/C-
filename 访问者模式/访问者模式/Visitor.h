#pragma once

class MaleMember;
class FeMaleMember;
//行为对应的基类
class AbstractAction
{
public:
	//被男人访问
	virtual void maleDoing(MaleMember* male)=0;
	//被女人访问
	virtual void femaleDoing(FeMaleMember* female)=0;
	virtual ~AbstractAction() {}
};

//Anger
class Anger:public AbstractAction
{
public:
	//被男人访问
	void maleDoing(MaleMember* male)override;
	//被女人访问
	void femaleDoing(FeMaleMember* female)override;
	void fight();
	void warning();
};

//Horror
class Horror :public AbstractAction
{
public:
	//被男人访问
	void maleDoing(MaleMember* male)override;
	//被女人访问
	void femaleDoing(FeMaleMember* female)override;
	void help();
	void thinking();
};
