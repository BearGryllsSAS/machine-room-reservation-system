#include"Teacher.h"
#include"OrderFile.h"
#include <iomanip>
#include<vector>
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
Teacher::Teacher()
{
	//空参构造函数的实现
}
Teacher::Teacher(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;
}
Teacher::~Teacher()
{
	//若没有在堆区new出来的对象,则不在这里写delet
}

//重写父类抽象函数,展示菜单界面
void Teacher::operMenu() //不用再写virtual,函数定义时已经写过
{
	cout << "欢迎教师：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作:";
}

/*老师具体功能的实现*/
//查看所有预约-- - 查看全部预约信息以及预约状态
void Teacher::showAllOrder()
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

//审核预约-- - 对学生的预约进行审核
void Teacher::validOrder()
{
	//审核中的预约可以审核

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
	//定义一个容器存放可审核的预约的位置
	vector<int> v_Index;

	for (i = 0; i < of.m_Order.size(); i++)
	{
		if (of.m_Order[i]["状态"] == "审核中")
		{
			index++;
			v_Index.push_back(i);
		}
	}
	
	if (index == 1)
	{
		cout << "当前没有可审核的预约!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else //有可审核的预约
	{
		index = 1;

		cout << "可审核的预约如下:" << endl;
		for (i = 0; i < v_Index.size(); i++)
		{
			cout << setw(5) << index++ << "、" << setw(5)
				<< "学号:" << setw(5) << of.m_Order[v_Index[i]]["学号"] << setw(9)
				<< "姓名:" << setw(8) << of.m_Order[v_Index[i]]["姓名"] << setw(9)
				<< "时间:" << setw(8) << of.m_Order[v_Index[i]]["时间"] << setw(9)
				<< "时间段:" << setw(8) << of.m_Order[v_Index[i]]["时间段"] << setw(9)
				<< "机房:" << setw(8) << of.m_Order[v_Index[i]]["机房"] << setw(9)
				<< "状态:" << setw(8) << of.m_Order[v_Index[i]]["状态"] << endl;
		}

		int select;
		cout << "要审核的预约(0 取消审核):";
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
				cout << "输入有误,请重新输入要审核的预约(0 取消审核):";
				cin >> select;
			}

			if (0 <= select && select <= v_Index.size())
			{
				if (select == 0)
				{
					cout << "已经不审核预约!" << endl;
					system("pause");
					system("cls");
					return;
				}
				break;
			}
			else
			{
				cout << "输入有误,请重新输入要审核的预约(0 不取消):";
			}
		}

		string result;
		cout << "输入审核结果(通过 不通过):";
		while (true)
		{
			cin >> result;

			if (result == "通过" || result == "不通过")
			{
				break;
			}
			else
			{
				cout << "输入有误,请重新输入审核结果(通过 不通过):";
			}
		}

		//这里没有对select result判断,以后再说(程序里很多都是) 已经完成

		of.m_Order[v_Index[select - 1]]["状态"] = result;

		//更新 将容器信息写入文件
		of.updateOrder();

		cout << "审核成功!" << endl;
		system("pause");
		system("cls");
		return;

	}
}

//注销登录-- - 退出登录
void Teacher::exitTeacher(string name)
{
	cout << "欢迎" << "老师" << name << "下次使用, 再见!" << endl;
	system("pause");
	system("cls");
}