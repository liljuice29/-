#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"orderfile.h"
class teacher :public identity
{
public:
	//Ĭ�Ϲ���
	teacher();
	//�вι���
	teacher(int emipd, string name, string pwd);
	//�˵�����
	virtual void opermenu();

	//�鿴����ԤԼ
	void showallorder();
	//���ԤԼ
	void validorder();


	//ְ����
	int empid;

};