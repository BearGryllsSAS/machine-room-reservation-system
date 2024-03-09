#include"OrderFile.h"
#include"GlobalFile.h"
#include<fstream>
using namespace std;


OrderFile::OrderFile()
{
	/*空参构造的作用是每次创建OerderFile对象时,都让对象中的map初始化,
	即从文件中读取信息,更新到map中.同时对信息进行修改,
	因为一开始读出来的时"学号:1"这样的形式,我们要把它分开为"学号" "1"(去掉省略号)
	key中放"学号" value中放"1" 这样就可以通过key找到value
	*/

	//先清空容器 ??暂定,也许不用(用)
	this->m_Order.clear();

	//打开要读取的预约文件
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << ORDER_FILE << "打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string id; //学号
	string name; //姓名
	string date; //时间
	string time; //时间段
	string computerRoom; //机房
	string status; //状态

	//初始化预约条数为0
	this->orderCount = 0;

	//创建一个map容器,存放从文件中读取出来的键值对
	map<string, string> m;
	//将读取出来的信息分割,分别放到key value中,再放入m中,最后连同orderCount放入大map中
	string key;
	string value;
	int pos = -1;
	
	while (ifs >> id && ifs >> name && ifs >> date && ifs >> time && ifs >> computerRoom && ifs >> status)
	{
		//测试是否能将信息拿出来
		//cout << id << " " << name << " " << date << " " << time << " " << computerRoom << " " << status << endl;

		//每一轮都必须清空m容器,防止上一轮残留导致大map容器出错
		m.clear();

		//id 学号:1
		//找到":"的位置
		pos = id.find(":"); //字符串的位置索引从0开始
		if (pos == -1)
		{
			cout << "id出错!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//进行截断
		key = id.substr(0, pos); //从下标为0开始,截取长度为pos+1的字符串
		value = id.substr(pos + 1); //从下为pos+1开始,截取到末尾
		//将id的信息放入m中
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); 另一种插入方法
		//m.insert(key) 只插键不插值

		//这里先复制粘贴,以后可以定义函数


		//name 姓名:zhangsan
		//找到":"的位置
		pos = name.find(":"); //字符串的位置索引从0开始
		if (pos == -1)
		{
			cout << "name出错!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//进行截断
		key = name.substr(0, pos); //从下标为0开始,截取长度为pos+1的字符串
		value = name.substr(pos + 1); //从下为pos+1开始,截取到末尾
		//将id的信息放入m中
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); 另一种插入方法
		//m.insert(key) 只插键不插值


		//date 时间:周一
		//找到":"的位置
		pos = date.find(":"); //字符串的位置索引从0开始
		if (pos == -1)
		{
			cout << "date出错!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//进行截断
		key = date.substr(0, pos); //从下标为0开始,截取长度为pos+1的字符串
		value = date.substr(pos + 1); //从下为pos+1开始,截取到末尾
		//将id的信息放入m中
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); 另一种插入方法
		//m.insert(key) 只插键不插值


		//time 时间段:上午
		//找到":"的位置
		pos = time.find(":"); //字符串的位置索引从0开始
		if (pos == -1)
		{
			cout << "time出错!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//进行截断
		key = time.substr(0, pos); //从下标为0开始,截取长度为pos+1的字符串
		value = time.substr(pos + 1); //从下为pos+1开始,截取到末尾
		//将id的信息放入m中
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); 另一种插入方法
		//m.insert(key) 只插键不插值


		//computerRoom 机房:1
		//找到":"的位置
		pos = computerRoom.find(":"); //字符串的位置索引从0开始
		if (pos == -1)
		{
			cout << "computerRoom出错!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//进行截断
		key = computerRoom.substr(0, pos); //从下标为0开始,截取长度为pos+1的字符串
		value = computerRoom.substr(pos + 1); //从下为pos+1开始,截取到末尾
		//将id的信息放入m中
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); 另一种插入方法
		//m.insert(key) 只插键不插值


		//status 状态:审核中
		//找到":"的位置
		pos = status.find(":"); //字符串的位置索引从0开始
		if (pos == -1)
		{
			cout << "status出错!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//进行截断
		key = status.substr(0, pos); //从下标为0开始,截取长度为pos+1的字符串
		value = status.substr(pos + 1); //从下为pos+1开始,截取到末尾
		//将id的信息放入m中
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); 另一种插入方法
		//m.insert(key) 只插键不插值


		//将count和m放入大map中
		this->m_Order.insert(make_pair(this->orderCount, m));

		//预约数量++
		this->orderCount++;

	}

	//关闭文件,非常重要
	ifs.close();

	return;
	//测试map是否有东西
	/*for (map<int, map<string, string>>::iterator it = m_Order.begin(); it != m_Order.end(); it++)
	{
		cout << "value:" << it->first << endl;

		for (map<string, string>::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
		{
			cout << itt->first << ":" << itt->second << " ";

		}
		
		cout << endl;
		cout << endl;
	}*/

}

//将map中的信息写入文件中
void OrderFile::updateOrder()
{
	/*以后审核预约就创建OrderFile对象,调用对象的map,直接修改status值,完成审核的同时要更新文件*/


	//容器中没有记录
	if (this->orderCount == 0)
	{
		cout << "当前容器中没有预约,无法写入文件!" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //trunc 若文件中有信息,先删除
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//将容器中的信息写进文件中
	for (int i = 0; i < this->orderCount; i++)
	{
		//通过key找到value
		ofs << "学号:" << this->m_Order[i]["学号"] << " ";
		ofs << "姓名:" << this->m_Order[i]["姓名"] << " ";
		ofs << "时间:" << this->m_Order[i]["时间"] << " ";
		ofs << "时间段:" << this->m_Order[i]["时间段"] << " ";
		ofs << "机房:" << this->m_Order[i]["机房"] << " ";
		ofs << "状态:" << this->m_Order[i]["状态"] << endl;
	}
		
	//关闭文件
	ofs.close();

	return;
}

//清空预约记录
void OrderFile::clearOrder()
{
	//管理员调用,用来清空所有预约

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //trunc 若文件中有信息,先删除
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//关闭文件
	ofs.close();

	return;
}