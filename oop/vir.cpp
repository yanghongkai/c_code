/*************************************************************************
	> File Name: vir.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月29日 星期一 21时48分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Quote{
public:
    string isbn() const;
    virtual double net_price(size_t n) const;
};

class Bulk_quote:public Quote{
public:
    double net_price(size_t) const override;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret=item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}

//basic的类型是Quote; buld的类型是Bulk_quote
print_total(cout,basic,20);
print_total(cout,bulk,20);











