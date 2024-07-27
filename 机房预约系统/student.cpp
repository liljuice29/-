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

	//初始化机房信息
	ifstream ifs;
	ifs.open(computer_file, ios::in);
	computerroom com;
	while (ifs >> com.comid && ifs >> com.maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();

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
	cout << "机房开放时间为周一到周五" << endl;
	cout << "请输入申请时间" << endl;
	cout << "1 周一" << endl;
	cout << "2 周二" << endl;
	cout << "3 周三" << endl;
	cout << "4 周四" << endl;
	cout << "5 周五" << endl;
	int date = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误" << endl;
	}
	cout << "请输入申请预约的时间段" << endl;
	cout << "1 ,上午" << endl;
	cout << "2 ,下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误" << endl;
	}
	cout << "请选择机房" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << vcom[i].comid << "号机房容量为" << vcom[i].maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误" << endl;

	}
	cout << "预约成功，审核中" << endl;
	ofstream ofs;
	ofs.open(order_file, ios::app);
	ofs << "date:" << date << "  ";
	ofs << "interval:" << interval << "  ";
	ofs << "stuid:" << this->id << "  ";
	ofs << "stuname:" << this->name << " ";
	ofs << "roomid:" << room << "  ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");




}
//查看我的预约
void student::showmyorder()
{
	orderfile of;
	if (of. size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (this->id == atoi(of.orderdata[i]["stuid"].c_str()))
		{
			cout << "预约如期：周" << of.orderdata[i]["date"]<<"  ";
			cout << "时间段：" << (of.orderdata[i]["interval"]=="1"?"上午":"下午")<<"  ";
			cout << "机房号：" << of.orderdata[i]["roomid"]<<"  ";
			string status = "状态";
			//1审核中 2已预约 -1预约失败 0取消预约
			if (of.orderdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.orderdata[i]["status"] == "2")
			{
				status += "预约成功";
			}

			else if (of.orderdata[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else 
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
		

	}
	
		
	
	system("pause");
	system("cls");


}
//查看所有预约
void student::showallorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << ",";
			cout << "预约如期：周" << of.orderdata[i]["date"] << "  ";
			cout << "时间段：" << (of.orderdata[i]["interval"] == "1" ? "上午" : "下午") << "  ";
			cout << "学号：" << of.orderdata[i]["stuid"] << "  ";
			cout << "姓名：" << of.orderdata[i]["stuname"] << "  ";
			cout << "机房号：" << of.orderdata[i]["roomid"] << "  ";
			string status = "状态";
			//1审核中 2已预约 -1预约失败 0取消预约
			if (of.orderdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.orderdata[i]["status"] == "2")
			{
				status += "预约成功";
			}

			else if (of.orderdata[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		

	}

	system("pause");
	system("cls");



}
//取消预约
void student::cancelorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	int index = 1;
	vector<int>v;
	for (int i = 0; i < of.size; i++)
	{
		//先判断是自身学号
		if (this->id == atoi(of.orderdata[i]["stuid"].c_str()))
		{
			//再筛选状态
			if (of.orderdata[i]["status"] == "1" || of.orderdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ",";
				cout << "预约日期:周" << of.orderdata[i]["date"];
				cout << "时间段:"<<(of.orderdata[i]["status"] == "1" ? "上午" : "下午");
				cout << "机房编号:" << of.orderdata[i]["roomid"];
				string status = "状态 :";
				if (of.orderdata[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.orderdata[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;

			}

		}
	}

	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.orderdata[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "已取消预约" << endl;
				break;
			}




		}
		cout << "输入有误，请重新操作" << endl;
	}
	system("oayse");
	system("cls");

}
