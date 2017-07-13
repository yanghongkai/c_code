/*************************************************************************
	> File Name: readline.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 16时19分46秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("test.txt");
    string line;

    if(!in.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }

    while(!in.eof())
    {
        if(getline(in,line))
        {
               cout<<line<<endl;
        }
    }

    return 0;
}




