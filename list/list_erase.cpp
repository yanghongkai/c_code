/*************************************************************************
	> File Name: list_erase.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月06日 星期二 16时04分23秒
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> lst={0,1,2,3,4,5,6,7,8,9};
    auto it=lst.begin();
    while(it!=lst.end())
        if(*it%2)
            it=lst.erase(it); //为奇数删除此元素
        else
            ++it;

    for(auto it=lst.begin(); it!=lst.end(); ++it)
        cout<<*it<< " ";
    cout<<endl;
    return 0;
}







