#pragma once
#include<iostream>
using namespace std;
#include"globalfile.h"
#include<fstream>
#include<map>

class orderfile
{
public:
	//���캯��
	orderfile();

	//����ԤԼ��¼
	void updateorder();

	//��¼ԤԼ����
	int size;

	//��¼����ԤԼ��Ϣ������  key��ʾ��¼����  val��ʾ�����¼��ֵ����Ϣ
	map<int, map<string, string>> orderdata;



};