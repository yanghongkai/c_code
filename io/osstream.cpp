/*************************************************************************
	> File Name: osstream.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 15时54分09秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ostringstream ostr1;
    ostringstream ostr2;

    ostr1<<"ostr1"<<2012<<endl;
    cout<<ostr1.str();

    return 0;
}







