#include"orderfile.h"

//构造函数
orderfile::orderfile()
{
	ifstream ifs;
	ifs.open(order_file, ios::in);

	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string status;
	this->size = 0;

	while (ifs>>date&&ifs>>interval&&ifs>>stuid&&ifs>>stuname&&ifs>>roomid&&ifs>>status)
	{
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuid.find(":");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//将小map容器放到更大的容器中
		this->orderdata.insert(make_pair(this->size, m));
		this->size++;
	}
	ifs.close();


}

//更新预约记录
void orderfile::updateorder()
{
	if (this->size == 0)
	{
		return;
	}

	ofstream ofs(order_file, ios::out | ios::trunc);
	for (int i = 0; i < this->size; i++)
	{
		ofs << "date:" << this->orderdata[i]["date"] << "  ";
		ofs << "interval:" << this->orderdata[i]["interval"] << "  ";
		ofs << "stuid:" << this->orderdata[i]["stuid"] << "  ";
		ofs << "stuname:" << this->orderdata[i]["stuname"] << "  ";
		ofs << "roomid:" << this->orderdata[i]["roomid"] << "  ";
		ofs << "status:" << this->orderdata[i]["status"] << endl;;
	}

	ofs.close();
}