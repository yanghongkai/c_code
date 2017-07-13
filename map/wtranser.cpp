/*************************************************************************
	> File Name: wtranser.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月28日 星期日 21时08分58秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;


map<string, string> buildMap(ifstream &map_file)
{
    map<string,string> trans_map;
    string key;
    string value;
    //读取第一个单词存入key中，行中剩余内容存入value
    while(map_file>>key && getline(map_file,value))
        if(value.size()>1)
            trans_map[key]=value.substr(1);//跳过前导空格
        else
            throw runtime_error("no rule for "+key);
    return trans_map;

}

const string & transform(const string &s, const map<string,string> &m)
{
    auto map_it=m.find(s);
    if(map_it!=m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map=buildMap(map_file);
    string text;
    while(getline(input,text)){
        istringstream stream(text);
        string word;
        bool firstword=true;
        while(stream>>word){
            if(firstword)
                firstword=false;
            else
                cout<< " ";
            cout<<transform(word,trans_map);
        }
        cout<<endl;
    }
}

int main()
{
    ifstream map_file("transfer.txt");
    ifstream input("input.txt");
    word_transform(map_file,input);
    return 0;
}













