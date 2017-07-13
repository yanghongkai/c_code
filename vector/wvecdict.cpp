/*************************************************************************
	> File Name: wvecdict.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月25日 星期四 10时43分54秒
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
    vector<float> wvec;
    string word;
    float val;

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
            stringstream ss(line);
            ss>>word;
            while(ss>>val)
                wvec.push_back(val);
        }
    }

    cout<<"word: "<<word<<endl;
    for(auto it=wvec.begin(); it!=wvec.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    return 0;
}











