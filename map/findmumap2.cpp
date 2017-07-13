/*************************************************************************
	> File Name: mumap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月28日 星期日 18时54分39秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main()
{
    multimap<string, string> authors;
    authors.insert({"yhk","li"});
    authors.insert({"yhk","yi"});
    authors.insert({"lym","yhk"});
    authors.insert({"lym","yk"});
    for(const auto &w:authors)
        cout<<w.first<<" : "<<w.second<<endl;
    cout<<"search lym"<<endl;
    string search_item("lym");
    for(auto beg=authors.lower_bound(search_item),end=authors.upper_bound(search_item); beg!=end; ++beg)
        cout<<beg->second<<endl;
    cout<<"equal_range"<<endl;
    for(auto pos=authors.equal_range(search_item); pos.first!=pos.second; ++pos.first)
        cout<<pos.first->second<<endl;
    return 0;
}





