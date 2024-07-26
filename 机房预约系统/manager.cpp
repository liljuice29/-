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

	//初始化容器 获取文件中老师学生信息
	this->initvector();
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
	string errortip;//错误提示

	ofstream ofs;
	int select =0;
	cin >> select;
	if (select == 1)
	{
		//添加学生
		filename = student_file;
		tip = "请输入学号";
		errortip = "学号重复，请重新输入";
	}
	else
	{
		filename = teacher_file;
		tip = "请输入职工编号";
		errortip = "职工号重复，请重新输入";
	}
	ofs.open(filename, ios::out | ios::app);//利用最佳方式写文件
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = checkrepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}

	}

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

	//调用初始化容器的接口，重新获取文件中的数据
	this->initvector();

}

void printstudent(student& s)
{
	cout << "学号:" << s.id << "  姓名:" << s.name << "  密码:" << s.pwd << endl;
}

void printteacher(teacher& s)
{
	cout << "职工号:" << s.empid << "  姓名:" << s.name << "  密码:" << s.pwd << endl;
}


//查看账号
void manager::showperson()
{
	cout << "请选择查看的内容" << endl;
	cout << "1  学生   2  老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");


}
//查看机房信息
void manager::showcomputer()
{

}
//清空预约记录
void manager::cleanfile()
{

}

//初始化容器
void manager::initvector()
{
	//确保容器清空
	vstu.clear();
	vtea.clear();
	//读取学生信息
	ifstream ifs;
	ifs.open(student_file, ios::in);
	if (!ifs.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd)
	{
		vstu.push_back(s);
	}
	cout << "当前学生数量" << vstu.size() << endl;
	ifs.close();
	//读取老师信息
	ifs.open(teacher_file, ios::in);
	teacher t;
	while (ifs >> t.empid && ifs >> t.name && ifs >> pwd)
	{
		vtea.push_back(t);
	}
	cout << "当前老师数量" << vtea.size() << endl;
	ifs.close();



}

bool manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (id == it->empid)
			{
				return true;
			}
		}

	}
	return false;

}