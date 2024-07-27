#include"student.h"

//Ĭ�Ϲ���
student::student()
{

}
//�вι���  ������ѧ�� ���� ����
student::student(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(computer_file, ios::in);
	computerroom com;
	while (ifs >> com.comid && ifs >> com.maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();

}

//�˵�����
void student::opermenu()
{
	cout << "------------------  ��ӭѧ����¼  ------------------ " << endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               1.����ԤԼ           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                2.�鿴�ҵ�ԤԼ      |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               3.�鿴����ԤԼ       |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                4.ȡ��ԤԼ          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                0.ע����¼          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "���������ѡ��;" << endl;
 }

//����ԤԼ
void student::applyorder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ʱ��" << endl;
	cout << "1 ��һ" << endl;
	cout << "2 �ܶ�" << endl;
	cout << "3 ����" << endl;
	cout << "4 ����" << endl;
	cout << "5 ����" << endl;
	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "��������" << endl;
	}
	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1 ,����" << endl;
	cout << "2 ,����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "��������" << endl;
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << vcom[i].comid << "�Ż�������Ϊ" << vcom[i].maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "��������" << endl;

	}
	cout << "ԤԼ�ɹ��������" << endl;
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
//�鿴�ҵ�ԤԼ
void student::showmyorder()
{
	orderfile of;
	if (of. size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (this->id == atoi(of.orderdata[i]["stuid"].c_str()))
		{
			cout << "ԤԼ���ڣ���" << of.orderdata[i]["date"]<<"  ";
			cout << "ʱ��Σ�" << (of.orderdata[i]["interval"]=="1"?"����":"����")<<"  ";
			cout << "�����ţ�" << of.orderdata[i]["roomid"]<<"  ";
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
		

	}
	
		
	
	system("pause");
	system("cls");


}
//�鿴����ԤԼ
void student::showallorder()
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
//ȡ��ԤԼ
void student::cancelorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	int index = 1;
	vector<int>v;
	for (int i = 0; i < of.size; i++)
	{
		//���ж�������ѧ��
		if (this->id == atoi(of.orderdata[i]["stuid"].c_str()))
		{
			//��ɸѡ״̬
			if (of.orderdata[i]["status"] == "1" || of.orderdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ",";
				cout << "ԤԼ����:��" << of.orderdata[i]["date"];
				cout << "ʱ���:"<<(of.orderdata[i]["status"] == "1" ? "����" : "����");
				cout << "�������:" << of.orderdata[i]["roomid"];
				string status = "״̬ :";
				if (of.orderdata[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.orderdata[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;

			}

		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}




		}
		cout << "�������������²���" << endl;
	}
	system("oayse");
	system("cls");

}
