/*************************************************************************
	> File Name: vect.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月25日 星期四 10时06分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a(10,0);    //大小为10初值为0的向量a
    cin>>a[2];
    cin>>a[5];
    cin>>a[6];

    for(size_t i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
    vector<int>::iterator it;
    for(it=a.begin(); it!=a.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    vector<vector<int>> b(10,vector<int>(5,0));
    //对部分数据进行输入
    cin>>b[1][1];
    cin>>b[2][2];
    cin>>b[3][3];

    int m,n;
    for(m=0; m<b.size(); m++)
    {
        for(n=0;n<b[m].size();n++)
            cout<<b[m][n]<<" ";
        cout<<endl;
    }
    cout<<endl;

    return 0;
}






