#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

//ѧ����
class student :public identity
{
public:
	//Ĭ�Ϲ���
	student();
	//�вι���  ������ѧ�� ���� ����
	student(int id, string name, string pwd);

	//�˵�����
	virtual void opermenu();

	//����ԤԼ
	void applyorder();
	//�鿴ԤԼ
	void showmyorder();
	//�鿴����ԤԼ
	void showallorder();
	//ȡ��ԤԼ
	void cancelorder();
	 
	 

	//ѧ��ѧ��
	int id;



};