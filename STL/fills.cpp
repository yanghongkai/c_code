/*************************************************************************
	> File Name: fills.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月06日 星期二 09时57分19秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> myvector(8); //myvector: 0 0 0 0  0 0 0 0
    fill(myvector.begin(), myvector.begin()+4, 5); // 5 5 5 5  0 0 0 0
    fill(myvector.begin()+3, myvector.end()-2, 8); // 5 5 5 8  8 8 0 0 

    cout<<"myvector contains:";
    for(vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}













