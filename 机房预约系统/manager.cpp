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

	ofstream ofs;
	int select =0;
	cin >> select;
	if (select == 1)
	{
		//���ѧ��
		filename = student_file;
		tip = "������ѧ��";
	}
	else
	{
		filename = teacher_file;
		tip = "������ְ�����";
	}
	ofs.open(filename, ios::out | ios::app);//������ѷ�ʽд�ļ�
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

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

}
//�鿴�˺�
void manager::showperson()
{

}
//�鿴������Ϣ
void manager::showcomputer()
{

}
//���ԤԼ��¼
void manager::cleanfile()
{

}
