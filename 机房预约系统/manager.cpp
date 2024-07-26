#include"manager.h"

//Ĭ�Ϲ���
manager::manager()
{

}
//�вι���
manager::manager(string name, string pwd)
{//��ʼ������Ա��Ϣ
	this->name = name;
	this->pwd = pwd;

	//��ʼ������ ��ȡ�ļ�����ʦѧ����Ϣ
	this->initvector();
}

//�˵�����
void manager::opermenu()
{
	cout << "------------------  ��ӭ����Ա��¼  ------------------ " << endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               1.����˺�           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                2.�鿴�˺�          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               3.�鿴����           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                4.��ռ�¼          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|                0.ע����¼          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "���������ѡ��;" << endl;
}
//����˺�
void manager::addperson()
{
	cout << "����������˺�����" << endl;
	cout << "1 ���ѧ��" << endl;
	cout << "2 �����ʦ" << endl;
	string filename;//�����ļ���
	string tip;//��ʾid��
	string errortip;//������ʾ

	ofstream ofs;
	int select =0;
	cin >> select;
	if (select == 1)
	{
		//���ѧ��
		filename = student_file;
		tip = "������ѧ��";
		errortip = "ѧ���ظ�������������";
	}
	else
	{
		filename = teacher_file;
		tip = "������ְ�����";
		errortip = "ְ�����ظ�������������";
	}
	ofs.open(filename, ios::out | ios::app);//������ѷ�ʽд�ļ�
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

	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	//���ļ��������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.clear();

	//���ó�ʼ�������Ľӿڣ����»�ȡ�ļ��е�����
	this->initvector();

}

void printstudent(student& s)
{
	cout << "ѧ��:" << s.id << "  ����:" << s.name << "  ����:" << s.pwd << endl;
}

void printteacher(teacher& s)
{
	cout << "ְ����:" << s.empid << "  ����:" << s.name << "  ����:" << s.pwd << endl;
}


//�鿴�˺�
void manager::showperson()
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1  ѧ��   2  ��ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ����" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");


}
//�鿴������Ϣ
void manager::showcomputer()
{

}
//���ԤԼ��¼
void manager::cleanfile()
{

}

//��ʼ������
void manager::initvector()
{
	//ȷ���������
	vstu.clear();
	vtea.clear();
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(student_file, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
		return;
	}
	student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd)
	{
		vstu.push_back(s);
	}
	cout << "��ǰѧ������" << vstu.size() << endl;
	ifs.close();
	//��ȡ��ʦ��Ϣ
	ifs.open(teacher_file, ios::in);
	teacher t;
	while (ifs >> t.empid && ifs >> t.name && ifs >> pwd)
	{
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ����" << vtea.size() << endl;
	ifs.close();



}

bool manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
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
		//�����ʦ
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