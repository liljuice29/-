#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

class teacher :public identity
{
public:
	//默认构造
	teacher();
	//有参构造
	teacher(int emid, string name, string pwd);
	//菜单界面
	virtual void opermenu();

	//查看所有预约
	void showallorder();
	//审核预约
	void validorder();


	//职工号
	int empid;

};