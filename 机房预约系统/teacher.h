#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

class teacher :public identity
{
public:
	//Ĭ�Ϲ���
	teacher();
	//�вι���
	teacher(int emid, string name, string pwd);
	//�˵�����
	virtual void opermenu();

	//�鿴����ԤԼ
	void showallorder();
	//���ԤԼ
	void validorder();


	//ְ����
	int empid;

};