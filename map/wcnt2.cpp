/*************************************************************************
	> File Name: wcnt2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月27日 星期六 11时02分20秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main()
{
    //统计每个单词在输入中出现次数的一种更烦琐的方法
    map<string, size_t> word_count;
    string word;
    while(cin>>word && word!="EOS"){
        auto ret=word_count.insert({word,1});
        if(!ret.second)
            ++ret.first->second;

    }
    for(const auto &w:word_count)
        cout<<w.first<<" occurs "<<w.second<< "times"<<endl;
    return 0;
}





