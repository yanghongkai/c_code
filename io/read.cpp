/*************************************************************************
	> File Name: read.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 09时42分49秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main()
{
    char buffer[256];
    ifstream in("test.txt");
    if(!in.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }
    while(!in.eof())
    {
        in.getline(buffer,100);
        cout<<buffer<<endl;
    }
    return 0;
}




