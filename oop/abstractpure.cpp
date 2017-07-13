/*************************************************************************
	> File Name: abstractpure.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月31日 星期三 10时45分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

//用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote:public Quote{
public:
    Disc_quote()=default;
    Disc_quote(const string& book, double price, size_t qty, double disc):Quote(book,price),quantity(qty),discount(disc) { }
    double net_price(size_t) const=0;
protected:
    size_t quantity=0; //折扣适用的购买量
    double discount=0.0; //表示折扣的小数值
};

//当同一书籍的销售量超过某个值时启用折扣
//折扣的值是一个小于1的正的小数值，以此来降低正常销售价格
class Bulk_quote:public Disc_quote{
public:
    Bulk_quote()=default;
    Bulk_quote(const string& book, double price, size_t qty, double disc):Disc_quote(book,price,qty,disc) { }
    //覆盖基类中的函数版本以实现一种新的折扣策略
    double net_price(size_t) const override;
};




