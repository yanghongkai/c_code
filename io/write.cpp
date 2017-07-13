/*************************************************************************
	> File Name: write.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 09时34分34秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream out("out.txt");
    if (out.is_open())
    {
        out<<"This is a line.\n";
        out<<"This is another line.\n";
        out.close();
    }
    return 0;
}




