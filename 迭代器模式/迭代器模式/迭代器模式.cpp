#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include"MyList.h"
#include "MyList_16.h"
#include<iostream>
using namespace std;
int main()
{
    vector<string> nameList{
        "��", "����", "�ܿ�", "���ȡ���", "X�����׿�",
        "��ɫ������", "�Gľ", "��q", "�弪��",
        "һ��", "����", "����", "�Ĺ�", "���",
        "����", "�߹�", "�˲�", "����","ʮ��"
    };
    MyList mylist;
    for (int i = 0; i < nameList.size(); ++i)
    {
        mylist.pushBack(nameList.at(i));
    }
    // ����
    Iterator* it = mylist.getIterator(true);
    cout << "���Ŀ�ʼ, ����: ͬ־��������~~~~~" << endl;
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: Ϊ�ϴ����!!! " << endl;
    }
    cout << endl;
    delete it;
    return 0;
}

