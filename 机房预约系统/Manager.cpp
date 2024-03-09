#include"Manager.h"
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

//在这里进行头文件中所有的函数实现
//构造函数与析构函数
Manager::Manager()
{
	//空参构造函数的实现
}
Manager::Manager(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	//调用init,使每次创建管理员对象时,都能从文件中获取老师学生信息放入容器
	this->initVector();

	////登录时提示人数
	//cout << "当前学生人数:" << v_Stu.size() << endl;
	//cout << "当前老师人数:" << v_Tea.size() << endl;

	////测试容器
	//for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
	//{
	//	cout << it->id << " " << it->name << " " << it->password << endl;
	//}

	////老师容器出错
	//for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
	//{
	//	cout << it->id << " " << it->name << " " << it->password << endl;
	//}
}
Manager::~Manager()
{
	//若没有在堆区new出来的对象,则不在这里写delet
}

//重写父类抽象函数,展示菜单界面
void Manager::operMenu() //不用再写virtual,函数定义时已经写过
{
	//每次用到此界面时都提示数量
	cout << "当前学生人数:" << v_Stu.size() << endl;
	cout << "当前老师人数:" << v_Tea.size() << endl;
	cout << "当前机房数量:" << v_Com.size() << endl;

	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作:";
}

/*管理员具体功能的实现*/
//*添加账号-- - 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
void Manager::addPerson()
{
	string fileName;
	string id_Tip;
	string id_Error_Tip;
	string ok_Tip;
	string error_Tip;

	int select;
	
	while (true)
	{
		cout << "请输入要添加的账号(1.学生 2.老师):";
		cin >> select;

		if (select == 1)
		{
			//添加学生账号
			fileName = STUDENT_FILE;
			id_Tip = "请输入学号:";
			id_Error_Tip = "输入有误,请重新输入学号:";
			ok_Tip = "学生添加成功!";
			error_Tip = "学生添加失败!";
			break;
		}
		else if (select == 2)
		{
			//添加老师账号
			fileName = TEACHER_FILE;
			id_Tip = "请输入职工号:";
			id_Error_Tip = "输入有误,请重新输入职工号:";
			ok_Tip = "老师添加成功!";
			error_Tip = "老师添加失败!";
			break;
		}
		else
		{
			cout << "输入有误,请重新输入!" << endl;
		}
	}
		
	//创建相应的文件流,打开文件,把输入的信息写入文件中,并判断文件是否打开成功
	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app); //以追加的方式写入文件.注意是|
	if (!ofs.is_open())
	{
		cout << fileName << "文件打开失败!" << endl;
		system("puase");
		system("cls");
		return;
	}
	
	flag:
	//提醒用户输入信息,并录入文件中(注意:查重操作另外定义函数做,这里先不做查重)
	//输入id
	int id;
	cout << id_Tip;
	cin >> id;
	while (cin.fail())
	{
		/*使用cin.fail()函数来判断用户是否输入了一个整数。
	如果用户输入了非整数值，则cin.fail()函数返回true，这时可以清空输入流，并提示用户重新输入id。*/
	// 如果用户输入的不是整数
		cin.clear();  // 清空输入流的状态标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清空输入缓冲区
		cout << id_Error_Tip;
		cin >> id;
	}
	//输入姓名
	string name;
	cout << "请输入姓名:";
	cin >> name;
	//输入密码
	string password;
	cout << "请输入密码:";
	cin >> password;

	//根据id去重
	//存在bug,连续添加时,无法去重(容器未能即使更新) 已经解决
	if (repeat(fileName, select, id)==1)
	{
		//存在重复id
		int select_1;
		while (true)
		{
			cout << "存在此id,是否要重新添加(1.是 2.否):";
			cin >> select_1;
			while (cin.fail())
			{
				/*使用cin.fail()函数来判断用户是否输入了一个整数。
			如果用户输入了非整数值，则cin.fail()函数返回true，这时可以清空输入流，并提示用户重新输入id。*/
			// 如果用户输入的不是整数
				cin.clear();  // 清空输入流的状态标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清空输入缓冲区
				cout << "输入有误,是否要重新添加(1.是 2.否):" << endl;
				cin >> select_1;
			}

			if (select_1 == 1)
			{
				goto flag;
			}
			else if (select_1 == 2)
			{
				cout << "取消添加账号成功!" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "输入有误,请重新输入!" << endl;
			}
		}
	}
	else if (repeat(fileName, select, id) == 0)
	{
		//文件打开失败
		cout << fileName << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		//这里先让他退出,以后可升级
		return;
	}

	//将输入的信息录入文件
	ofs << id << " " << name << " " << password << endl;

	//关闭文件
	ofs.close();
	
	//每次添加成功(即将要添加的信息写入文件)后及时更新容器(从文件中读取信息到容器中)
	this->initVector();

	//提示添加成功
	cout << ok_Tip << endl;
	system("pause");
	system("cls");
	return;
}

//* 查看账号-- - 可以选择查看学生或教师的全部信息
void Manager::showPerson()
{
	/*主要的操作就是对容器进行遍历*/
	int index = 1;

	int select;
	cout << "请输入要查看的类型(1.学生 2.老师 3.所有):";
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
			cout << "输入有误,请重新输入要查看的类型(1.学生 2.老师 3.所有):";
			cin >> select;
		}

		if (select == 1)
		{
			if (v_Stu.size() == 0)
			{
				cout << "当前没有学生!" << endl;
				system("pause");
				system("cls");
				return;
			}

			cout << "学生信息如下:" << endl;
			//查看学生
			for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
			{
				cout << setw(5) << index++ << "、" << "学号:" << setw(3) << it->id << setw(10) << "姓名:" << setw(10) << it->name << setw(10) << "密码:" << setw(5) << it->password << endl;
			}

			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)
		{

			if (v_Tea.size() == 0)
			{
				cout << "当前没有老师1!" << endl;
				system("pause");
				system("cls");
				return;
			}

			//查看老师
			cout << "老师信息如下:" << endl;
			//查看老师
			for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
			{
				cout << setw(5) << index++ << "、" << "职工号:" << setw(3) << it->id << setw(10) << "姓名:" << setw(10) << it->name << setw(10) << "密码:" << setw(5) << it->password << endl;
			}

			system("pause");
			system("cls");
			return;
		}
		else if (select == 3)
		{
			//学生老师都看

			if (v_Stu.size() == 0)
			{
				cout << "当前没有学生!" << endl;
			}
			else
			{
				//查看学生
				cout << "学生信息如下:" << endl;
				for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
				{
					cout << setw(5) << index++ << "、" << "学号:" << setw(3) << it->id << setw(10) << "姓名:" << setw(10) << it->name << setw(10) << "密码:" << setw(5) << it->password << endl;
				}
			}
			
			//重新初始化标记为1
			index = 1;

			if (v_Tea.size() == 0)
			{
				cout << "当前没有老师!" << endl;
				return;
			}
			else
			{
				//查看老师
				cout << "老师信息如下:" << endl;
				for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
				{
					cout << setw(5) << index++ << "、" << "职工号:" << setw(3) << it->id << setw(10) << "姓名:" << setw(10) << it->name << setw(10) << "密码:" << setw(5) << it->password << endl;
				}

				system("pause");
				system("cls");
				return;
			}
		}
		else
		{
			cout << "输入有误,请从新输入要查看的类型(1.学生 2.老师 3.所有):";
		}
	}
}

//* 查看机房-- - 查看所有机房的信息
void Manager::showComputer()
{
	int index = 1;

	//对机房容器进行遍历
	if (v_Com.size() == 0)
	{
		cout << "当前没有机房!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "机房信息如下:" << endl;
		for (vector<Computer>::iterator it = v_Com.begin(); it != v_Com.end(); it++)
		{
			cout << setw(5) << index++ << "、" << "机房编号:" << setw(5) << it->number << setw(20) << "机房数量:" << setw(5) << it->count << endl;

		}
		system("pause");
		system("cls");
		return;
	}
}

//* 清空预约-- - 清空所有预约记录
void Manager::cleanFile()
{
	//当前还没有预约,先不写.等写好学生的函数实现后再来补充

	OrderFile of;
	if (of.m_Order.size() == 0)
	{
		cout << "当前没有预约,无法清空!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string select;
	cout << "是否确定清空所有预约(是 否):";
	
	while (true)
	{
		cin >> select;

		if (select == "是")
		{
			//of.m_Order.clear();

			of.clearOrder();

			cout << "清空预约成功!" << endl;
			system("pause");
			system("cls");
			return;

		}
		else if (select == "否")
		{
			cout << "已取消清空预约!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入有误,请重新确定是否清空所有预约(是 否):";
		}
	}
}

//* 注销登录-- - 退出登录
void Manager::exitManager(string name)
{
	cout << "欢迎" << "管理员" << name << "下次使用, 再见!" << endl;
	system("pause");
	system("cls");
}

//* 初始化学生和老师和机房的容器(从文件中读取信息到容器中)
/*这个函数会从学生和老师文件中读取信息,
并将信息放入容器中,
方便后面去重操作的判断,
后面去重是只需要遍历容器读取信息就行
*/
void Manager::initVector()
{
	//马上对容器清空,否则会有残留,非常重要
	v_Stu.clear();
	v_Tea.clear();
	v_Com.clear();
	
	ifstream ifs;
	
	//对学生操作
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) //好像有bug,以后再研究
	{
		cout <<STUDENT_FILE<< "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}
	/*将学生文件中的数据一次一行存入vector中的方法:
	1.创建一个学生对象s
	2.读取文件,将文件内容写入s的成员对象中
	3.将s放入vector中
	*/
	//创建学生对象
	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password) //将文件中的信息给别赋给id name pwd,遇到换行暂时停止
	{
		//将s放入容器中
		v_Stu.push_back(s);
	}
	//关闭文件,非常重要(不关闭文件容易出错,去重操作出错)
	/*每个文件应该在使用完毕后及时关闭。
	如果你不关闭第一个文件，那么在打开第二个文件时可能会出现问题，例如读取到错误的数据或者无法打开文件。
	请记住，在操作文件时，一定要注意及时关闭文件流，以防止出现潜在的错误
	*/
	ifs.close();

	//对老师操作
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << TEACHER_FILE << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}
	/*将学生文件中一整行的数据存入一次行存入vector中的方法:
	1.创建一个学生对象s
	2.读取文件,将文件内容写入s的成员对象中
	3.将s放入vector中
	*/
	//创建老师对象
	Teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.password) //将文件中的信息给别赋给id name pwd,遇到换行暂时停止
	{
		//将s放入容器中
		v_Tea.push_back(t);
	}
	//关闭文件,非常重要(不关闭文件容易出错,去重操作出错)
	ifs.close();

	//对机房操作
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//创建机房对象
	Computer c;
	while (ifs >> c.number && ifs >> c.count) //将文件中的信息分别赋给cout number,遇到换行暂时停止
	{
		//将c存入容器
		v_Com.push_back(c);
	}
	//关闭文件,非常重要(不关闭文件容易出错,去重操作出错)
	ifs.close();
}

//* 添加一个int类型的函数,用来判断文件中是否已经有要添加的id
int Manager::repeat(string fileName, int select, int id)
{
	//虽然能完成去重操作,但是一开始文件不存在的话,整个程序还是会出很大问题,这里先不研究(返回值改为int,应该能解决了)
	if (select == 1)
	{
		//对学生去重
		ifstream ifs;
		ifs.open(fileName, ios::in);
		if (!ifs.is_open())
		{
			return 0;//存在bug?
		}
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
		{
			//文件中已经存在此id
			if (it->id == id)
			{
				ifs.close();
				return 1;
			}
		}
		ifs.close();
		//文件中未存在此id
		return 2;
	}
	else
	{
		//对老师去重
		ifstream ifs;
		ifs.open(fileName, ios::in);
		if (!ifs.is_open())
		{
			return 0; //存在bug?
		}
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			//文件中已经存在此id
			if (it->id == id)
			{
				ifs.close();
				return 1;
			}
		}
		ifs.close();
		//文件中未存在此id
		return 2;
	}
}