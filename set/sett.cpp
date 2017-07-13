/*************************************************************************
	> File Name: sett.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月27日 星期六 10时34分33秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
    set<int> iset={0,1,2,3,4,5,6,7,8,9};
    set<int>::iterator set_it=iset.begin();
    if(set_it!=iset.end()){
        cout<<*set_it<<endl;
    }

    vector<int> ivec={2,4,6,8,2,4,6,8};
    set<int> set2;
    set2.insert(ivec.cbegin(),ivec.cend());
    set2.insert({1,3,5,7,1,3,5,7});

    for(set<int>::iterator set_it=set2.begin(); set_it!=set2.end(); ++set_it)
        cout<<*set_it<<endl;


    return 0;
}










