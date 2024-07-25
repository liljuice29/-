#include<iostream>
using namespace std;

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

			break;
		case 2://老师

			break;
		case 3://管理员

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