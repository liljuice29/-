#pragma once
#include<iostream>
using namespace std;

//身份抽象的基类
class identity
{
public:
	//操作菜单 纯虚函数
	virtual void opermenu() = 0;
	//用户名
	string name;
	//密码
	string pwd;

};