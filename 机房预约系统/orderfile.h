#pragma once
#include<iostream>
using namespace std;
#include"globalfile.h"
#include<fstream>
#include<map>

class orderfile
{
public:
	//构造函数
	orderfile();

	//更新预约记录
	void updateorder();

	//记录预约条数
	int size;

	//记录所有预约信息的容器  key表示记录条数  val表示具体记录键值对信息
	map<int, map<string, string>> orderdata;



};