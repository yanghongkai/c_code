/*************************************************************************
	> File Name: rw.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 08时48分45秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream in; //ifstream 读文件（ofstream写文件)
    string filename; //建议将文件名定义为string类型
    getline(cin,filename,'\n'); //获取文件名

    in.open(filename); //不加打开方式则默认以in打开

    if(!in)
    {
        cerr<<"打开文件出错!"<<endl;
        return 1;
    }
    char ch;
    while(!in.eof()) //当未到达文件末尾
    {
        in.read(&ch,1); //参数一是接收字符的指针，参数二是接收字符个数
        cout<<ch; //输出读取的字符
    }
    in.close();


}






