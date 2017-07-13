/*************************************************************************
	> File Name: inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月31日 星期三 14时21分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Base{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};
struct Pub_Derv:public Base{
    //正确：派生类能访问protected成员
    int f() {return prot_mem; }
    //错误：private成员对于派生类来说是不可访问的
    char g() {return priv_mem; }
};

struct Priv_Derv:private Base{
    //private 不影响派生类的访问权限
    int f1() const { return prot_mem; }
};

Pub_Derv d1;  //继承自Base的成员是public的
Priv_Derv d2;  //继承自Base的成员是private的 
d1.pub_mem();  //正确：pub_mem在派生类中是public的
d2.pub_mem();  //错误：pub_mem在派生类中是private的

struct Derived_from_Public: public Pub_Derv{
    //正确：Base::prot_mem 在 Pub_Derv 中仍然是protected的
    int use_base() { return prot_mem; }
};
struct Derived_from_Private: public Priv_Derv{
    //错误：Base::prot_mem 在 Priv_Derv 中是private 的
    int use_base() { return prot_mem; }
};














