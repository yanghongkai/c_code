/*************************************************************************
	> File Name: sstrem.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 16时05分30秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
    string line;
    vector<string>words;
    string word;
    
    ifstream in("test.txt");
    if(!in.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }
    while(!in.eof())
    {
        if(getline(in,line))
        {
            stringstream ss(line); //explict construct

            while(ss>>word)
                words.push_back(word);
        }
    }

    //vector<string>::iterator it=words.begin();
    auto it=words.begin();
    while(it!=words.end())
        cout<<*it++<<endl;

    return 0;
}





