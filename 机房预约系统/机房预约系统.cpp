#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalfile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//�������Ա�Ӳ˵�����
void managermenu(identity*& managers)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		managers->opermenu();
		//������ָ��תΪ����ָ�룬���������������ӿ�
		manager* man = (manager*)managers;
		int select = 0;
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addperson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showperson();
		}
		else if (select == 3)//�鿴������Ϣ
		{
			cout << "�鿴����" << endl;
			man->showcomputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanfile();
		}
		else
		{
			delete managers;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}




	}


}


//��¼����  ����һ �����ļ���  ������ �����������
void loginin(string filename, int type)
{
	//����ָ������ָ���������
	identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����֤
		int fid;//���ļ��л�ȡ��id��
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				//���뵽ѧ����ݵ��Ӳ˵�


				return;
			}


		}


	}
	else if (type == 2)
	{
		//��ʦ��֤
		int fid;//���ļ��л�ȡ��id��
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���ȶ�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				//���뵽��ʦ��ݵ��Ӳ˵�


				return;
			}


		}


	}
	else if (type == 3)
	{
		//����Ա��֤
		
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while ( ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���ȶ�
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new manager( name, pwd);
				//���뵽����Ա��ݵ��Ӳ˵�
				managermenu(person);

				return;
			}


		}
	}

	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");

	return;
}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "------------------  ��ӭ��������ԤԼϵͳ  ------------------ " << endl;
		cout << endl << "������������" << endl;
		cout << "\t\t -------------------------------------\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|               1.ѧ��                 |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|                2.��ʦ                |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|               3.����Ա               |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|                0.�˳�                |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t -------------------------------------\n";
		cout << "���������ѡ��;";
		cin >> select;

		switch (select)
		{
		case 1://ѧ��
			loginin(student_file, 1);
			break;
		case 2://��ʦ
			loginin(teacher_file, 2);
			break;
		case 3://����Ա
			loginin(admin_file, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;


		}


	}


	system("pause");
	return 0;








}