#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalfile.h"

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







};