/*************************************************************************
	> File Name: isstream.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 14时51分12秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    string str="I am a boy";
    istringstream is(str);
    string s;
    while(is>>s)
    {
        cout<<s<<endl;
    }
    return 0;
}



