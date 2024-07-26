#include"student.h"

//默认构造
student::student()
{

}
//有参构造  参数：学号 姓名 密码
student::student(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;
}

//菜单界面
void student::opermenu()
{
	cout << "------------------  欢迎学生登录  ------------------ " << endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               1.申请预约           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                2.查看我的预约      |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               3.查看所有预约       |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                4.取消预约          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                0.注销登录          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "请输入你的选择;" << endl;
 }

//申请预约
void student::applyorder()
{


}
//查看预约
void student::showmyorder()
{

}
//查看所有预约
void student::showallorder()
{

}
//取消预约
void student::cancelorder()
{

}
