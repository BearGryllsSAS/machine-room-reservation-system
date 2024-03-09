#pragma once
#include"Person.h" //包含自己写的头文件时,要用""而不用<>
#include"Teacher.h"
#include"Student.h"
#include"Computer.h"
#include<vector>
//using namespace std; //这行在.h头文件不要写,可能会出错

//通常情况下，#pragma once应该放在头文件的最开始，#include指令应该放在#pragma once之后。
/*在子类的头文件中不需要再次包含iostream，因为它已经被包含在父类的头文件中了。
当子类继承父类时，子类会自动继承父类的所有成员和头文件包含关系。
如果子类的头文件中再次包含iostream，会导致重复包含，可能会出现编译错误。*/

//头文件创建管理员类,继承Person,在源文件,写具体实现
class Manager :public Person
{
public:
	//构造函数与析构函数
	Manager();
	Manager(int id, std::string name, std::string password);
	~Manager();

	//重写父类抽象函数,展示菜单界面
	virtual void operMenu(); //virtual可写可不写

	/*管理员具体功能的函数定义*/

	//添加账号-- - 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
	void addPerson();

	//查看账号-- - 可以选择查看学生或教师的全部信息
	void showPerson();

	//查看机房-- - 查看所有机房的信息
	void showComputer();

	//清空预约-- - 清空所有预约记录
	void cleanFile();

	//注销登录-- - 退出登录
	void exitManager(std::string name);

	/* 去重操作*/
  
	/*去重操作
	功能描述：添加新账号时，如果是重复的学生编号，或是重复的教师职工编号，提示有误
	读取信息
	要去除重复的账号，首先要先将学生和教师的账号信息获取到程序中，方可检测*/
	//*在manager.h中，添加两个容器，用于存放学生和教师的信息
	//应该将这两个定义在私有权限下的,这里先不管
	std::vector<Teacher> v_Tea; //不加std:: 编译器将会报错
	std::vector<Student> v_Stu;

	//*添加一个新的成员函数  `void initVector()` 初始化容器
	void initVector();

	//添加一个int类型的函数,用来判断文件中是否已经有要添加的id
	//存在返回true 不存在返回false
	int repeat(std::string fileName, int select, int id);

	//添加一个容器,用于存放机房信息
	std::vector<Computer> v_Com;
};