/*************************************************************************
	> File Name: quote.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月29日 星期一 21时59分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Quote{
public:
    Quote()=default;
    QUote(const string &book, double sales_price): bookNo(book), price(sales_price) {}
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const
    {
        return n*price;
    }
    virtual ~Quote()=default;
private:
    string bookNo;
protected:
    double price=0.0;
};

class Bulk_quote: public Quote{
public:
    Bulk_quote()=default;
    Bulk_quote(const string&, double, size_t, double);Quote(book,p), min_qty(qty), discount(disc) { }
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(size_t) const override;
private:
    size_t min_qty=0;
    double discount=0.0;
};








