#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalfile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerroom.h"
class manager :public identity
{
public:
	//Ĭ�Ϲ���
	manager();
	//�вι���
	manager(string name, string pwd);
	//�˵�����
	virtual void opermenu();
	//����˺�
	void addperson();
	//�鿴�˺�
	void showperson();
	//�鿴������Ϣ
	void showcomputer();
	//���ԤԼ��¼
	void cleanfile();

	//��ʼ������
	void initvector();

	//ѧ������
	vector<student>vstu;
	//��ʦ����
	vector<teacher>vtea;

	//����ظ�
	bool checkrepeat(int id, int type);

	//������Ϣ
	vector<computerroom>vcom;


};