/*************************************************************************
	> File Name: virtualsNscope.cpp
	> Author: 
	> Mail: 
	> Created Time: Thursday, July 13, 2017 PM03:30:46 CST
 ************************************************************************/

#include<iostream>
using std::cout; using std::endl;

class Base{
public:
    virtual int fcn();
};

int Base::fcn() {cout<<"Base::fcn()"<<endl; return 0;}

class D1:public Base{
public:
    // hides fcn int the Base; this fcn is not virtual 
    // D1 inherits the definition of Base::fcn()
    int fcn(int);
    virtual void f2(); // new virtual function that does not exist in Base
};

int D1::fcn(int) { cout<<"D1::fcn(int)"<<endl; return 0;}
void D1::f2() { cout<<"D1::f2()"<<endl;}

class D2:public D1{
public:
    int fcn(int); // nonvirtual function hides D1::fcn(int)
    int fcn();  // overrieds virtual fcn from Base
    void f2();

};

int D2::fcn(int) {cout<<"D2::fcn(int)"<<endl; return 0;}
int D2::fcn() { cout<<"D2::fcn()"<<endl; return 0; }
void D2::f2() { cout<<"D2::f2()"<<endl; }

int main()
{
    D1 dobj, *dp=&dobj;
    dp->fcn(42);

    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1=&bobj, *bp2=&d1obj, *bp3=&d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    D1 *d1p=&d1obj; D2 *d2p=&d2obj;
    d1p->f2();
    d2p->f2();

    Base *p1=&d2obj; D1 *p2=&d2obj; D1 *p3=&d2obj;
    p2->fcn(42); // statically bound, calls D1::fcn(int)
    p3->fcn(42); // statically bound, calls D2::fcn(int)

    Base *bp=&d1obj; D1 *dp1=&d2obj; D2 *dp2=&d2obj;
    dp1->fcn(10); // static call to D1::fcn(int)
    dp2->fcn(10); // static call to D2::fcn(int)

    return 0;
}


















