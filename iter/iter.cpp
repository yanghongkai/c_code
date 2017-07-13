/*************************************************************************
	> File Name: iter.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月25日 星期四 20时37分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s("Hello World!");
    for (auto it=s.begin(); it!=s.end() && !isspace(*it); ++it)
        *it=toupper(*it);
    for(auto c:s)
        cout<<c;
    cout<<endl;
    return 0;
}





