/*************************************************************************
	> File Name: v_erase.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月06日 星期二 16时21分17秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec={0,1,2,3,4,5,6,7,8,9};
    auto elem=vec.erase(vec.begin(),vec.begin()+5);
    cout<<*elem<<endl;
    for(auto it=vec.begin(); it!=vec.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}













