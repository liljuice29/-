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
