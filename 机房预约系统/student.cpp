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


}
//�鿴ԤԼ
void student::showmyorder()
{

}
//�鿴����ԤԼ
void student::showallorder()
{

}
//ȡ��ԤԼ
void student::cancelorder()
{

}
