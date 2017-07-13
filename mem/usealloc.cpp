/*************************************************************************
	> File Name: usealloc.cpp
	> Author: 
	> Mail: 
	> Created Time: Wednesday, July 05, 2017 PM08:17:03 CST
 ************************************************************************/

#include<string>
using std::string;

#include<memory>
using std::allocator;

#include<cstddef>
using std::size_t;

#include<iostream>
using std::cout; using std::endl;

#include<fstream>
using std::ifstream;

int main()
{
    const size_t n=100;
    allocator<string> alloc;
    string *p=alloc.allocate(n);  // allocate n unconstructed strings

    string *q=p;
    alloc.construct(q++,string()); // *q is the empty string
    cout<<*(q-1)<<endl;

    alloc.construct(q++,string(10,'c'));
    cout<<*(q-1)<<endl;

    alloc.construct(q++,string("hi"));
    cout<<*(q-1)<<endl;

    cout<<"*p:"<<endl;
    cout<<*p<<endl;

    while(q!=p)
        alloc.destroy(--q);  // free the strings we actually allocated
    alloc.deallocate(p,n);  // return the memory we allocated

    p=alloc.allocate(n);
    string s;
    q=p;
    ifstream in("data/storyDataFile");
    while(in>>s && q!=p+n)
        alloc.construct(q++,s);
    size_t size=q-p;

    cout<<"read "<<size<<" strings"<<endl;

    for(q=p+size-1;q!=p;--q)
        alloc.destroy(q);
    alloc.deallocate(p,n);

    in.close();
    in.open("data/storyDataFile");
    p=new string[n];
    q=p;
    while(in>>s && q!=p+n)
        *q++=s;
    size=q-p;

    cout<<"read "<<size<<" strings"<<endl;
    delete[] p;  // p points to an array; must remember to use delete[]

    return 0;
}












