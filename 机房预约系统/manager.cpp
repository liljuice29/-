#include"manager.h"

//默认构造
manager::manager()
{

}
//有参构造
manager::manager(string name, string pwd)
{//初始化管理员信息
	this->name = name;
	this->pwd = pwd;
}

//菜单界面
void manager::opermenu()
{
	cout << "------------------  欢迎管理员登录  ------------------ " << endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               1.添加账号           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                2.查看账号          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               3.查看机房           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                4.清空记录          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                0.注销登录          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "请输入你的选择;" << endl;
}
//添加账号
void manager::addperson()
{

}
//查看账号
void manager::showperson()
{

}
//查看机房信息
void manager::showcomputer()
{

}
//清空预约记录
void manager::cleanfile()
{

}
