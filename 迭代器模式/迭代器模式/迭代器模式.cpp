#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include"MyList.h"
#include "MyList_16.h"
#include<iostream>
using namespace std;
int main()
{
    vector<string> nameList{
        "烬", "奎因", "杰克", "福兹·弗", "X·德雷克",
        "黑色玛利亚", "笹木", "润媞", "佩吉万",
        "一美", "二牙", "三鬼", "四鬼", "五鬼",
        "六鬼", "七鬼", "八茶", "九忍","十鬼"
    };
    MyList mylist;
    for (int i = 0; i < nameList.size(); ++i)
    {
        mylist.pushBack(nameList.at(i));
    }
    // 遍历
    Iterator* it = mylist.getIterator(true);
    cout << "检阅开始, 凯多: 同志们辛苦啦~~~~~" << endl;
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: 为老大服务!!! " << endl;
    }
    cout << endl;
    delete it;
    return 0;
}

