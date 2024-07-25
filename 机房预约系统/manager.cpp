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
	cout << "请输入添加账号类型" << endl;
	cout << "1 添加学生" << endl;
	cout << "2 添加老师" << endl;
	string filename;//操作文件名
	string tip;//提示id号

	ofstream ofs;
	int select =0;
	cin >> select;
	if (select == 1)
	{
		//添加学生
		filename = student_file;
		tip = "请输入学号";
	}
	else
	{
		filename = teacher_file;
		tip = "请输入职工编号";
	}
	ofs.open(filename, ios::out | ios::app);//利用最佳方式写文件
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	//向文件添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");

	ofs.clear();

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
