#include"GlobalFile.h"
#include"Person.h"
#include"Student.h"
#include"Manager.h"
#include"Teacher.h"
#include<iostream>
#include<fstream>
using namespace std;

//身份验证
void authenticate(string fileName, int select);
//身份验证中,用到的验证登录的函数
void verification(string fileName, int select, string error_Tip, int id, string name, string password);
//管理员登录界面
void managerMenu(Person*& p);
//学生登录界面
void studentMenu(Person*& p);
//老师登录界面
void teacherMenu(Person*& p);

int main()
{
	int select;

	while (true)
	{
		// cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|								 |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择:";

		cin >> select;

		switch (select)
		{
		case 1: //学生代表
			authenticate(STUDENT_FILE, 1);
			break;
		
		case 2: //老师
			authenticate(TEACHER_FILE,2);
			break;
		
		case 3: //管 理 员
			authenticate(MANAGER_FILE,3);
			break;

		case 4: //聊天室
			system("pause");
			break;

		case 0: //退出
			cout << "欢迎下次使用,再见!" << endl;
			system("pause");
			exit(0);
			break;
		
		default: //其他
			cout << "输入有误,请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	
	}

	return 0;
}

//身份验证
/*
在所有的头文件与源文件框架完成后, 定义一个验证登录的函数,
main函数中case 1 2 3都会调用此函数,进行身份验证,当输入的id和密码
都正确后,才能进入相应对象的菜单界面(此时又是另一套相应的函数)

根据main中传过来的值, 进行身份验证登录
这个传过来的值一个是文件名,一个是select
1.select方便确认我们是要验证哪个身份
2.文件名方便进行身份验证(此身份不存在或验证失败)
*/
void authenticate(string fileName, int select)
{
	//创建文件流,从传入的文件名中读取文件
	/*执行 ifstream ifs(fileName, ios::in); 代码时，会打开 fileName 指定的文件，并且将文件和 ifs 对象进行关联。
	因此，ifs 对象已经打开了指定的文件。
	需要注意的是，如果打开文件失败，ifs 对象的状态会被设置为错误状态，
	需要使用 fail() 或 bad() 成员函数来检查文件是否成功打开。
	另外，需要注意的是，虽然 ifs 对象已经打开了文件，但并不会立即从文件中读取数据。
	只有在需要从文件中读取数据时，才会进行读取操作。*/
	/*ifstream ifs(fileName, ios::in); 和 ifstream ifs; ifs.open(fileName, ios::in);
	两种方式都可以用来打开文件并创建一个输入文件流对象。
	不同之处在于，ifstream ifs(fileName, ios::in); 是在对象创建的同时就打开文件，
	而 ifstream ifs; ifs.open(fileName, ios::in); 是先创建对象，再通过调用 open 成员函数打开文件。
	如果文件打开成功，两种方式都可以使用 ifs 对象从文件中读取数据。
	但如果文件打开失败，则两种方式都需要使用 fail() 或 bad()或ifs.is_open() 成员函数来检查文件状态。
	需要注意的是，在使用 open 成员函数打开文件之前，必须先创建 ifstream 对象。
	因此，如果使用 ifstream ifs; 定义对象时，需要调用 open 函数来打开文件。*/
	/*判断文件是否成功读取或写入，可以使用 eof() 和 good() 成员函数。
	eof() 是 ios 类的成员函数，用于检查流对象是否已经到达文件末尾。
	如果流对象已经到达文件末尾，则返回 true，否则返回 false。

	good() 是 ios 类的成员函数，用于检查流对象是否处于可读可写状态。
	如果流对象没有发生任何错误，则返回 true，否则返回 false。
	一般情况下，当读取文件时，可以使用 while (!ifs.eof()) 循环读取文件的每一行数据，
	并在每次读取数据后使用 if (ifs.good()) 来检查读取操作是否成功。如果读取操作失败，
	程序就可以根据具体情况进行相应的错误处理。

	在写入文件时，可以使用 if (ofs.good()) 来检查写入操作是否成功，
	如果写入操作失败，程序就可以根据具体情况进行相应的错误处理。*/
	ifstream ifs;
	ifs.open(fileName, ios::in); //ios::in即使不写也没事,默认就是
	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << fileName << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.close();

	//设置一些提示,方便下面使用
	string id_Tip;
	string id_Error_Tip;
	string error_Tip;
	if (select == 1)
	{
		id_Tip = "请输入学号:";
		id_Error_Tip = "输入无效，请重新输入学号:";
		error_Tip = "学生验证登录失败!";
	}
	else if (select == 2)
	{
		id_Tip = "请输入职工号:";
		id_Error_Tip = "输入无效，请重新输入职工号:";
		error_Tip = "教师验证登录失败!";
	}
	else
	{
		id_Tip = "请输入管理员号:";
		id_Error_Tip = "输入无效，请重新输入管理员号:";
		error_Tip = "管理员验证登录失败!";
	}

	//提示用户输入
	//id
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
	//name
	string name;
	cout << "请输入姓名:";
	cin >> name;
	//password
	string password;
	cout << "请输入密码:";
	cin >> password;

	//定义函数,根据用户输入的信息,对三个对象分别进行验证
	verification(fileName, select, error_Tip, id, name, password);
}

//身份验证中,用到的验证登录的函数
void verification(string fileName, int select, string error_Tip, int id, string name, string password)
{
	//定义Person类型的p指针,身份验证成功后,创建对象传入下一级函数
	Person* p = NULL;

	//打开文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << fileName << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//定义三个变量,存放从文件中读取的数据,然后与用户输入的数据比较
	int f_Id;
	string f_Name;
	string f_Password;

	//开始读文件
	/*一行一行读,当读到末尾遇到换行符时,代表一个while循环读成功
	读的过程中,遇到分隔符(空格等)时,前一个变量就读取成功,然后到下一个变量读取
	*/
	while (ifs >> f_Id && ifs >> f_Name && ifs >> f_Password)
	{
		if (f_Id == id && f_Name == name && f_Password == password) //当id和name和password都符合则验证登录成功
		{
			if (select == 1)
			{
				cout << "学生验证登录成功!" << endl;
				ifs.close(); //关闭文件
				system("pause");
				system("cls");

				//父类的指针指向子类在堆区开辟的空间,并调用有参构造
				/*由于 Student 类是 Person 类的派生类，因此可以将 Student 类的对象指针赋值给 Person 类的指针，
				这也是 C++ 多态的体现。这样做的好处是可以通过指向基类的指针调用派生类的成员函数，
				从而实现代码的灵活性和扩展性。*/
				p = new Student(id, name, password);

				//将指针传入子类的函数
				studentMenu(p);
				//退出学生登陆界面后,直接返回主菜单,不执行下面代码
				return;
			}
			else if (select == 2)
			{
				cout << "老师验证登录成功!" << endl;
				ifs.close(); //关闭文件
				system("pause");
				system("cls");

				//父类的指针指向子类在堆区开辟的空间,并调用有参构造
				p = new Teacher(id, name, password);

				//将指针传入子类的函数
				teacherMenu(p);
				//退出老师登陆界面后,直接返回主菜单,不执行下面代码
				return;
			}
			else
			{
				cout << "管理员验证登录成功!" << endl;
				ifs.close(); //关闭文件
				system("pause");
				system("cls");

				//父类的指针指向子类在堆区开辟的空间,并调用有参构造
				p = new Manager(id, name, password);

				//将指针传入子类的函数
				managerMenu(p);

				//退出管理员登陆界面后,直接返回主菜单,不执行下面代码
				return;
			}
		}
	}

	//验证登录失败
	cout << error_Tip << endl;
	ifs.close(); //关闭文件
	system("pause");
	system("cls");
	return;
}

//管理员登录界面
void managerMenu(Person*& p)
{
	//调用管理员菜单界面
	//p->operMenu();

	//将person类型的指针p强转为manager,并将p重命名为man
	/*Person* p=NULL;
	p=new Student(id,name);
	Student* s=(Student*)p;
	这段代码中，首先定义了一个指向 Person 类对象的指针 p，并将其初始化为 NULL。
	然后，通过 new 运算符在堆上创建一个 Student 类的对象，并将其指针赋值给 p。
	由于 Student 类是 Person 类的子类，因此可以将 Student 对象指针隐式地转换为 Person 对象指针，
	即将 Student 类对象的地址赋值给指向 Person 类对象的指针。

	接下来，定义了一个指向 Student 类对象的指针 s，并将 p 指针所指向的对象强制类型转换为 Student 对象指针类型，并将其赋值给 s。
	这个强制类型转换可以将一个指向基类对象的指针转换成指向派生类对象的指针，
	但是需要注意的是，只有在基类指针实际指向的对象是派生类对象时，才能安全地将其转换为派生类指针，
	否则会引起 undefined behavior。因此，在进行强制类型转换时，应该先判断指针所指向的对象的类型，以确保转换的安全性。*/
	Manager* man = (Manager*)p;

	int select;
	
	while (true)
	{
		//调用管理员菜单界面
		man->operMenu();

		cin >> select;

		switch (select)
		{
		case 1: //添加账号
			man->addPerson();
			break;

		case 2: //查看账号
			man->showPerson();
			break;

		case 3: //查看机房 
			man->showComputer();
			break;

		case 4: //清空预约
			man->cleanFile();
			break;

		case 0: //注销登录
			man->exitManager(man->name);
			//删除创建的管理员对象
			delete(man);
			return; //返回上一级菜单

		default: //其他
			cout << "输入有误,请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//学生登录界面
void studentMenu(Person*& p)
{
	//调用学生菜单界面
	//p->operMenu();

	//将person类型的指针p强转为Student,并将p重命名为man
	/*Person* p=NULL;
	p=new Student(id,name);
	Student* s=(Student*)p;
	这段代码中，首先定义了一个指向 Person 类对象的指针 p，并将其初始化为 NULL。
	然后，通过 new 运算符在堆上创建一个 Student 类的对象，并将其指针赋值给 p。
	由于 Student 类是 Person 类的子类，因此可以将 Student 对象指针隐式地转换为 Person 对象指针，
	即将 Student 类对象的地址赋值给指向 Person 类对象的指针。

	接下来，定义了一个指向 Student 类对象的指针 s，并将 p 指针所指向的对象强制类型转换为 Student 对象指针类型，并将其赋值给 s。
	这个强制类型转换可以将一个指向基类对象的指针转换成指向派生类对象的指针，
	但是需要注意的是，只有在基类指针实际指向的对象是派生类对象时，才能安全地将其转换为派生类指针，
	否则会引起 undefined behavior。因此，在进行强制类型转换时，应该先判断指针所指向的对象的类型，以确保转换的安全性。*/
	Student* stu = (Student*)p;

	int select;

	while (true)
	{
		//调用管理员菜单界面
		stu->operMenu();

		cin >> select;

		switch (select)
		{
		case 1: //申请预约
			stu->applyOrder();
			break;

		case 2: //查看我的预约
			stu->showMyOrder();
			break;

		case 3: //查看所有预约 
			stu->showAllOrder();
			break;

		case 4: //取消预约
			stu->cancelOrder();
			break;

		case 0: //注销登录
			stu->exitStudent(stu->name);
			//删除创建的学生对象
			delete(stu);
			return; //返回上一级菜单

		default: //其他
			cout << "输入有误,请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//老师登录界面
void teacherMenu(Person*& p)
{
	//调用老师菜单界面
	//p->operMenu();

	//将person类型的指针p强转为Student,并将p重命名为man
	/*Person* p=NULL;
	p=new Student(id,name);
	Student* s=(Student*)p;
	这段代码中，首先定义了一个指向 Person 类对象的指针 p，并将其初始化为 NULL。
	然后，通过 new 运算符在堆上创建一个 Student 类的对象，并将其指针赋值给 p。
	由于 Student 类是 Person 类的子类，因此可以将 Student 对象指针隐式地转换为 Person 对象指针，
	即将 Student 类对象的地址赋值给指向 Person 类对象的指针。

	接下来，定义了一个指向 Student 类对象的指针 s，并将 p 指针所指向的对象强制类型转换为 Student 对象指针类型，并将其赋值给 s。
	这个强制类型转换可以将一个指向基类对象的指针转换成指向派生类对象的指针，
	但是需要注意的是，只有在基类指针实际指向的对象是派生类对象时，才能安全地将其转换为派生类指针，
	否则会引起 undefined behavior。因此，在进行强制类型转换时，应该先判断指针所指向的对象的类型，以确保转换的安全性。*/
	Teacher* tea = (Teacher*)p;

	int select;

	while (true)
	{
		//调用管理员菜单界面
		tea->operMenu();

		cin >> select;

		switch (select)
		{
		case 1: //查看所有预约
			tea->showAllOrder();
			break;

		case 2: //审核预约
			tea->validOrder();
			break;

		case 0: //注销登录
			tea->exitTeacher(tea->name);
			//删除创建的老师对象
			delete(tea);
			return; //返回上一级菜单

		default: //其他
			cout << "输入有误,请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}