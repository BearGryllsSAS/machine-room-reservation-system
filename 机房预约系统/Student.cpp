#include"Student.h"
#include"GlobalFile.h"
#include"OrderFile.h"
#include <iomanip>
#include<fstream>
#include<iostream>
using namespace std;
/*在源文件中写另外一个函数的声明还是在头文件*/
/*通常情况下，你应该在"b.cpp"的源文件中包含"a.h"头文件，因为只有在实现文件中需要使用"a.h"头文件的内容。
如果你在"b.h"中包含"a.h"，并且在另一个源文件中包含了"b.h"，那么编译器会将"a.h"头文件包含两次，这可能会导致编译错误。
另外，包含头文件的最佳位置是实现文件的顶部，因为这样可以确保它们在编译时只包含一次。*/

/*创建了一个"a.h"的头文件,在"a.cpp"源文件的实现中,源文件要写"a.h"吗?不写编译器知道吗*/
/*在"a.cpp"源文件中需要写上#include "a.h"以便让编译器知道该源文件依赖于"a.h"头文件，
否则编译器将无法解析该头文件中的定义，导致编译错误。
虽然有些编译器可能会自动查找头文件，但是最好还是要写上头文件的引用，以保证代码的可移植性和清晰性。*/

/*包含头文件的顺序*/
/*包含头文件的顺序是很重要的。
通常，你应该首先包含当前实现文件需要的头文件，然后是其它的系统或库头文件。
这样可以确保它们按正确的顺序包含，从而避免一些潜在的编译错误。*/

/*在.h头文件中写了"#include<iostream>",在.cpp源文件中还要写吗*/
/*在.cpp源文件中也需要写#include<iostream>，
因为头文件(.h文件)和源文件(.cpp文件)是两个不同的文件，需要分别包含所需的头文件。
在头文件中包含头文件主要是为了让使用该头文件的文件可以访问该头文件所包含的内容。
在源文件中包含头文件主要是为了让源文件可以访问该头文件所包含的内容。
因此，需要在每个需要使用该头文件的文件中都进行包含。*/

/*创建了一个"a.h"的头文件,在"a.cpp"源文件的实现中,源文件要写"a.h"吗?不写编译器知道吗*/
/*在"a.cpp"源文件中需要写上#include "a.h"以便让编译器知道该源文件依赖于"a.h"头文件，
否则编译器将无法解析该头文件中的定义，导致编译错误。
虽然有些编译器可能会自动查找头文件，但是最好还是要写上头文件的引用，以保证代码的可移植性和清晰性。*/

//构造函数与析构函数
Student::Student()
{
	//空参构造函数的实现
}
Student::Student(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	//创建对象时初始化机房容器
	this->initVector();
}
Student::~Student()
{
	//若没有在堆区new出来的对象,则不在这里写delet
}

//重写父类抽象函数,展示菜单界面
void Student::operMenu() //不用再写virtual,函数定义时已经写过
{
	//每次使用到这个界面时都显示机房数量
	cout << "当前机房数量:" << v_Com.size() << endl;
	
	cout << "欢迎学生代表：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作:";
}

/*学生具体功能的实现*/
//申请预约-- - 预约机房
void Student::applyOrder()
{
	//目前只提供简单的预约功能,不管冲突(已经更新)
	//实际上还是对文件进行操作,提示用户输入信息,然后将信息写入文件

	//判断是否有机房,若没有,则提示后直接返回
	if (v_Com.size() == 0)
	{
		cout << "当前没有机房,无法预约!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//打开预约文件并判断文件是否存在
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::app); //追加的方式
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}

	flag:
	//下面没有对输入进行正确的判断,以后再说(已经更新)
	//时间
	string date;
	cout << "要预约的时间(周一 周二 周三 周四 周五):";
	while (true)
	{
		cin >> date;
		if (date == "周一" || date == "周二" || date == "周三" || date == "周四" || date == "周五")
		{
			break;
		}
		else
		{
			cout << "输入有误,请重新输入要预约的时间(周一 周二 周三 周四 周五):";
		}
	}
	
	//时间段
	string time;
	cout << "要预约的时间段(上午 下午):";
	while (true)
	{
		cin >> time;
		if (time == "上午" || time == "下午")
		{
			break;
		}
		else
		{
			cout << "输入有误,请重新输入要预约的时间段(上午 下午):";
		}
	}

	//机房
	int computerRoom;
	int index = 1;
	cout << "机房信息如下:" << endl;
	for (vector<Computer>::iterator it = v_Com.begin(); it != v_Com.end(); it++)
	{
		cout << index++ << "、" << "编号:" << it->number << " " << "数量:" << it->number << endl;
	}
	cout << "要预约的机房号:";
	while (true)
	{
		cin >> computerRoom;
		while (cin.fail())
		{
			/*使用cin.fail()函数来判断用户是否输入了一个整数。
		如果用户输入了非整数值，则cin.fail()函数返回true，这时可以清空输入流，并提示用户重新输入id。*/
		// 如果用户输入的不是整数
			cin.clear();  // 清空输入流的状态标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清空输入缓冲区
			cout << "输入有误,请重新输入要预约的机房号:";
			cin >> computerRoom;
		}
		if (computerRoom > 0 && computerRoom < index)
		{
			break;
		}
		else
		{
			cout << "输入有误,请重新输入要预约的机房号:";
		}
	}

	//预约状态
	string status = "审核中";

	//若存在完全相同的预约则提示,无法重复预约
	OrderFile of; //创建OrderFile对象
	if (of.orderCount != 0) //若预约容器中有记录
	{
		int i;
		for (i = 0; i < of.orderCount; i++) //循环遍历预约容器
		{
			if (atoi(of.m_Order[i]["学号"].c_str()) == this->id) //存在与自己id相同的预约记录
			{
				if (of.m_Order[i]["时间"] == date && of.m_Order[i]["时间段"] == time && of.m_Order[i]["状态"] == status)
				{
					//若已经存在相同时间,相同状态的预约记录
					cout << "已经存在相同的预约记录,请选择(1.重新预约 2.取消预约);";
					
					int select;
					while (true)
					{
						cin >> select;
						while (cin.fail())
						{
							/*使用cin.fail()函数来判断用户是否输入了一个整数。
						如果用户输入了非整数值，则cin.fail()函数返回true，这时可以清空输入流，并提示用户重新输入id。*/
						// 如果用户输入的不是整数
							cin.clear();  // 清空输入流的状态标志
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清空输入缓冲区
							cout << "输入有误,请重新请选择(1.重新预约 2.取消预约);";
							cin >> select;
						}

						if (select == 1)
						{
							goto flag;
						}
						else if(select==2)
						{
							cout << "取消预约成功!" << endl;
							system("pause");
							system("cls");
							return;
						}
						else
						{
							cout << "输入有误,请重新请选择(1.重新预约 2.取消预约);";
						}
					}
				}
			}
		}
	}

	//将信息录入文件中
	ofs << "学号:" << this->id << " ";
	ofs << "姓名:" << this->name << " ";
	ofs << "时间:" << date << " ";
	ofs << "时间段:" << time << " ";
	ofs << "机房:" << computerRoom << " ";
	ofs << "状态:" << status << endl;
	
	//关闭文件
	ofs.close();

	/*更新预约信息
	这里用不到,将预约记录写入文件就好,没有更改预约容器中的信息
	所以当审核预约或者取消预约,要改变预约容器中的信息时才调用函数更新文件
	*/
	
	//提示预约成功
	cout << "预约成功,请等待老师审核" << endl;
	system("pause");
	system("cls");
}

//查看自身的预约-- - 查看自己的预约状态
void Student::showMyOrder()
{
	//其实就是创建OrderFile对象,调用这个对象的预约容器进行遍历的过程
	OrderFile of;
	if (of.orderCount == 0)
	{
		cout << "当前没有预约!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	int i;
	
	for (i = 0; i < of.orderCount; i++) //遍历f中的map容器
	{
		//存在bug,会输入所有预约信息(已经解决,原因是:再空参构造那里未及时清空OrderFile中m容器)
		//若是本人的学号
		/*具体来说，of.m_order[i]是一个map，表示第i条预约记录。
		of.m_order[i]["学号"]表示第i条预约记录中学生学号这个键对应的值，即预约的学生的学号。
		atoi(of.m_orderData[i]["stuId"].c_str())表示将该值从字符串类型转换成整型，然后与当前学生的ID比较。
		如果两个ID相等，则说明这条预约记录是当前学生预约的，应该输出。*/
		if (atoi(of.m_Order[i]["学号"].c_str()) == this->id)
		{
			if (index == 1)
			{
				cout << "您的预约预约如下:" << endl;
			}

			cout << setw(5) << index++ << "、" << setw(5)
				<< "时间:" << setw(5) << of.m_Order[i]["时间"] << setw(20)
				<< "时间段:" << setw(5) << of.m_Order[i]["时间段"] << setw(20)
				<< "机房:" << setw(5) << of.m_Order[i]["机房"] << setw(20)
				<< "状态:" << setw(5) << of.m_Order[i]["状态"] << endl;
		}
	}

	if (index == 1)
	{
		cout << "当前没有预约!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		system("pause");
		system("cls");
		return;
	}
}

//看所有预约-- - 查看全部预约信息以及预约状态
void Student::showAllOrder()
{
	//创建OrderFile对象
	OrderFile of;
	if (of.orderCount == 0)
	{
		cout << "当前没有预约!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	int i;

	cout << "所有预约如下:" << endl;
	for (i = 0; i < of.orderCount; i++) //遍历f中的map容器
	{
		cout << setw(5) << index++ << "、" << setw(5)
			<< "学号:" << setw(5) << of.m_Order[i]["学号"] << setw(9)
			<< "姓名:" << setw(8) << of.m_Order[i]["姓名"] << setw(9)
			<< "时间:" << setw(8) << of.m_Order[i]["时间"] << setw(9)
			<< "时间段:" << setw(8) << of.m_Order[i]["时间段"] << setw(9)
			<< "机房:" << setw(8) << of.m_Order[i]["机房"] << setw(9)
			<< "状态:" << setw(8) << of.m_Order[i]["状态"] << endl;
	}

	system("pause");
	system("cls");
	return;
}

//取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
void Student::cancelOrder()
{
	//创建OrderFile对象
	OrderFile of;
	if (of.orderCount == 0)
	{
		cout << "当前没有预约!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	int i;
	//定义一个容器存放当前学生预约记录所在位置
	vector<int> v_Index;

	for (i = 0; i < of.orderCount; i++) //遍历f中的map容器
	{
		//存在bug,会输入所有预约信息(已经解决,原因是:空参构造时未及时清空OrderFile中m容器)
		//若是本人的学号
		/*具体来说，of.m_order[i]是一个map，表示第i条预约记录。
		of.m_order[i]["学号"]表示第i条预约记录中学生学号这个键对应的值，即预约的学生的学号。
		atoi(of.m_orderData[i]["stuId"].c_str())表示将该值从字符串类型转换成整型，然后与当前学生的ID比较。
		如果两个ID相等，则说明这条预约记录是当前学生预约的，应该输出。*/
		if (atoi(of.m_Order[i]["学号"].c_str()) == this->id) //找到自己的预约记录
		{
			if (of.m_Order[i]["状态"] == "审核中" || of.m_Order[i]["状态"] == "通过") //预约失败的和已经取消记录不得取消
			{
				v_Index.push_back(i); //存放当前学生可取消的预约记录所在位置
				index++;
			}
		}
	}

	////测试
	//for (int x = 0; x < v_Index.size(); x++)
	//{
	//	cout << "------------------------" << endl;
	//	cout << v_Index[x] << endl;
	//	cout << v_Index[0] << endl;
	//	cout << "---------------------" << endl;
	//}

	if (index == 1)
	{
		cout << "当前没有可以取消的预约!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else //存在可取消的预约
	{
		//初始化index
		index = 1;

		cout << "可取消的预约如下:" << endl;
		for (i = 0; i < v_Index.size(); i++)
		{
			cout << setw(5) << index++ << "、" << setw(5)
				<< "时间:" << setw(5) << of.m_Order[v_Index[i]]["时间"] << setw(20)
				<< "时间段:" << setw(5) << of.m_Order[v_Index[i]]["时间段"] << setw(20)
				<< "机房:" << setw(5) << of.m_Order[v_Index[i]]["机房"] << setw(20)
				<< "状态:" << setw(5) << of.m_Order[v_Index[i]]["状态"] << endl;
		}

		int select;
		cout << "要取消的预约(0 不取消):";
		while (true)
		{
			cin >> select;
			while (cin.fail())
			{
				/*使用cin.fail()函数来判断用户是否输入了一个整数。
			如果用户输入了非整数值，则cin.fail()函数返回true，这时可以清空输入流，并提示用户重新输入id。*/
			// 如果用户输入的不是整数
				cin.clear();  // 清空输入流的状态标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清空输入缓冲区
				cout << "输入有误,请重新输入要取消的预约(0 不取消):";
				cin >> select;
			}

			if (0 <= select && select <= v_Index.size())
			{
				if (select == 0)
				{
					cout << "已经不取消预约!" << endl;
					system("pause");
					system("cls");
					return;
				}
				break;
			}
			else
			{
				cout << "输入有误,请重新输入要取消的预约(0 不取消):";
			}
		}

		//将预约信息修改
		//of.m_Order[v_Index[select - 1]]["预约"] = "已取消"; md又是文字错误!!!!!!!!!!!好多次了
		of.m_Order[v_Index[select - 1]]["状态"] = "已取消";

		//测试
		/*for (int j = 0; j < of.m_Order.size(); j++)
		{
			cout << of.m_Order[j]["预约"] << " " << endl;
		}*/
		//容器确实已经修改,但是文件未能更新

		//将容器信息更新到文件中
		of.updateOrder();
	
		//提示用户
		cout << "预约已经成功取消!" << endl;

		system("pause");
		system("cls");
		return;
	}
}

//注销登录-- - 退出登录
void Student::exitStudent(string name)
{
	cout << "欢迎" << "学生" << name << "下次使用, 再见!" << endl;
	system("pause");
	system("cls");
}

//初始化机房容器的函数
void Student::initVector()
{
	//每次调用时先清空容器
	v_Com.clear();

	//打开机房文件
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//创建机房对象
	Computer c;

	while (ifs >> c.number && ifs >> c.count) //将从文件中读取的信息录入number count中
	{
		v_Com.push_back(c);
	}
	
	//关闭文件
	ifs.close();

	return;
}
