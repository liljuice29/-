#include"teacher.h"

//Ĭ�Ϲ���
teacher::teacher()
{

}
//�вι���
teacher::teacher(int emipd, string name, string pwd)
{
	this->empid = empid;
	this->name = name;
	this->pwd = pwd;
}
//�˵�����
void teacher::opermenu()
{
	cout << "------------------  ��ӭ��ʦ��¼  ------------------ " << endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               1.�鿴����ԤԼ       |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               2.���ԤԼ           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               0.ע����¼           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "���������ѡ��;" << endl;
 }

//�鿴����ԤԼ
void teacher::showallorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << ",";
		cout << "ԤԼ���ڣ���" << of.orderdata[i]["date"] << "  ";
		cout << "ʱ��Σ�" << (of.orderdata[i]["interval"] == "1" ? "����" : "����") << "  ";
		cout << "ѧ�ţ�" << of.orderdata[i]["stuid"] << "  ";
		cout << "������" << of.orderdata[i]["stuname"] << "  ";
		cout << "�����ţ�" << of.orderdata[i]["roomid"] << "  ";
		string status = "״̬";
		//1����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
		if (of.orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}

		else if (of.orderdata[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;


	}

	system("pause");
	system("cls");

}
//���ԤԼ
void teacher::validorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�����ԤԼ��¼����" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.orderdata[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ", ";
			cout << "ԤԼ���ڣ���" << of.orderdata[i]["date"] << "  ";
			cout << "ʱ��Σ�" << (of.orderdata[i]["interval"] == "1" ? "����" : "����") << "  ";
			cout << "ѧ�ţ�" << of.orderdata[i]["stuid"] << "  ";
			cout << "������" << of.orderdata[i]["stuname"] << "  ";
			cout << "�����ţ�" << of.orderdata[i]["roomid"] << "  ";
			cout << "״̬�������" << endl;
		}


	}

	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;//����ԤԼ�����¼
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
				cout << "��������˽��" << endl;
				cout << "1,ͨ�� 2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.orderdata[v[select - 1]]["status"] = "-1";
				}
				of.updateorder();
				cout << "������" << endl;
				break;
			}



		}
		cout << "������������������" << endl;

	}

	system("pause");
	system("cls");

}