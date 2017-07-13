/*************************************************************************
	> File Name: search2t.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月25日 星期四 21时12分46秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string text="yanghongkai";
    //string sought="h";
    //char sought="h";
    char sought='h';
    auto beg=text.begin(), end=text.end();
    auto mid=text.begin()+(end-beg)/2;
    while(mid!=end && *mid!=sought){
        if(sought<*mid)
            end=mid;
        else
            beg=mid+1;
        mid=beg+(end-beg)/2;
    }
    cout<<*mid<<endl;
    return 0;
}






