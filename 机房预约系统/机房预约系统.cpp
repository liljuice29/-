#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalfile.h"
using namespace std;

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
	}
	else if (type == 2)
	{
		//��ʦ��֤
	}
	else if (type == 3)
	{
		//����Ա��֤
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