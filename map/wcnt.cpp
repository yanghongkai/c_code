/*************************************************************************
	> File Name: wcnt.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 20时49分01秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    map<string,size_t> word_count;
    set<string> exclude={"The","a","or"};
    string word; 
    while(cin>>word && word!="EOS")
        if(exclude.find(word)==exclude.end())
            ++word_count[word];
    for(const auto &w: word_count)
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)? " times" : " time") <<endl;
    return 0;
}




