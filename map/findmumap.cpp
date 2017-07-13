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
    auto entries=authors.count(search_item);
    auto iter=authors.find(search_item);
    while(entries){
        cout<<iter->second<<endl;
        ++iter;
        --entries;
    }
    return 0;
}





