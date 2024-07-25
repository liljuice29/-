#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

//学生类
class student :public identity
{
public:
	//默认构造
	student();
	//有参构造  参数：学号 姓名 密码
	student(int id, string name, string pwd);

	//菜单界面
	virtual void opermenu();

	//申请预约
	void applyorder();
	//查看预约
	void showmyorder();
	//查看所有预约
	void showallorder();
	//取消预约
	void cancelorder();
	 
	 

	//学生学号
	int id;



};