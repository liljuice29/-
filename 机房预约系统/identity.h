#pragma once
#include<iostream>
using namespace std;
#include"globalfile.h"
#include"computerroom.h"
#include<vector>
//��ݳ���Ļ���
class identity
{
public:
	//�����˵� ���麯��
	virtual void opermenu() = 0;
	//�û���
	string name;
	//����
	string pwd;

};