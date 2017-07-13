/*************************************************************************
	> File Name: fill_ns.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月06日 星期二 10时14分50秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> myvector(8,10);  //myvector: 10 10 10 10  10 10 10 10
    fill_n(myvector.begin(),4,20);        // 20 20 20 20  10 10 10 10
    fill_n(myvector.begin()+3,3,33);      // 20 20 20 33  33 33 10 10

    cout<<"myvector contains:";
    for(vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}






