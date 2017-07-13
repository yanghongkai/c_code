/*************************************************************************
	> File Name: Account.cpp
	> Author: 
	> Mail: 
	> Created Time: Thursday, July 13, 2017 PM01:18:48 CST
 ************************************************************************/

#include<string>
using std::string;
#include"Account.h"

# define static data and function members
const string Account::accountType("Savings Account");
double Account::interestRate=initRate();

void Account::rate(double newRate)
{
    interestRate=newRate;
}











