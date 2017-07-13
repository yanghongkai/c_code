/*************************************************************************
	> File Name: copync.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月06日 星期二 09时27分24秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int myints[]={10,20,30,40,50,60,70};
    vector<int> myvector;
    myvector.resize(7);
    copy_n(myints,7,myvector.begin());
    cout<<"myvector contains:";
    for(vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}












