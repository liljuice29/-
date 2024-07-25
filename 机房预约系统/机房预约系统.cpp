#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalfile.h"
using namespace std;

//登录功能  参数一 操作文件名  参数二 操作身份类型
void loginin(string filename, int type)
{
	//父类指针用于指向子类对象
	identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生验证
	}
	else if (type == 2)
	{
		//老师验证
	}
	else if (type == 3)
	{
		//管理员验证
	}

	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");

	return;
}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "------------------  欢迎来到机房预约系统  ------------------ " << endl;
		cout << endl << "请输入你的身份" << endl;
		cout << "\t\t -------------------------------------\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|               1.学生                 |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|                2.老师                |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|               3.管理员               |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|                0.退出                |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t -------------------------------------\n";
		cout << "请输入你的选择;";
		cin >> select;

		switch (select)
		{
		case 1://学生
			loginin(student_file, 1);
			break;
		case 2://老师
			loginin(teacher_file, 2);
			break;
		case 3://管理员
			loginin(admin_file, 3);
			break;
		case 0://退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;


		}


	}


	system("pause");
	return 0;








}