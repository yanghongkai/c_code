/*************************************************************************
	> File Name: v_last.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月07日 星期三 09时43分16秒
 ************************************************************************/

#include<iostream>
#include<vector>

int main()
{
    std::vector<size_t> vec{0,1,2,3,4,5};
    std::vector<size_t>::iterator it=vec.end()-1;
    std::cout<<*it<<std::endl;
    std::cout<<vec.back()<<std::endl;
    std::cout<<vec[vec.size()-1]<<std::endl;
    return 0;

}







