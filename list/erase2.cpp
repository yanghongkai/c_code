/*************************************************************************
	> File Name: erase2.cpp
	> Author: 
	> Mail: 
	> Created Time: Friday, July 07, 2017 PM03:50:42 CST
 ************************************************************************/

#include<string>
using std::string;

#include<list>
using std::list;

#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::endl;

int main()
{
    int temp[]={0,1,2,3,4,5,6,7,8,9};
    list<int> lst(temp, temp+sizeof(temp)/sizeof(*temp));

    // print the initial values in lst
    cout<<"initial list: ";
    for(list<int>::const_iterator it=lst.begin(); it!=lst.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;

    // erase the odd elements in lst
    list<int>::iterator it=lst.begin();
    while(it!=lst.end())
        if(*it%2)
            it=lst.erase(it);
        else
            ++it;

    // print the current contents of lst
    cout<<"after erasing odd elements from lst: ";
    for(list<int>::const_iterator it=lst.begin(); it!=lst.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;


    return 0;
}











