#pragma once
#include"Person.h" //包含自己写的头文件时,要用""而不用<>
#include"Computer.h"
#include<vector>
//using namespace std; //这行在.h头文件不要写,可能会出错

//通常情况下，#pragma once应该放在头文件的最开始，#include指令应该放在#pragma once之后。
/*在子类的头文件中不需要再次包含iostream，因为它已经被包含在父类的头文件中了。
当子类继承父类时，子类会自动继承父类的所有成员和头文件包含关系。
如果子类的头文件中再次包含iostream，会导致重复包含，可能会出现编译错误。*/

//头文件创建学生类,继承Person在源文件,写具体实现
class Student :public Person
{
public:
	//构造函数与析构函数
	Student();
	Student(int id, std::string name, std::string password);
	~Student();
	
	//重写父类抽象函数,展示菜单界面
	virtual void operMenu(); //重写父类抽象函数,展示菜单界面
	
	/*学生具体功能*/
	//申请预约-- - 预约机房
	void applyOrder();
	
	//查看自身的预约-- - 查看自己的预约状态
	void showMyOrder();
	
	//查看所有预约-- - 查看全部预约信息以及预约状态
	void showAllOrder();
	
	//取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
	void cancelOrder();
	
	//注销登录-- - 退出登录
	void exitStudent(std::string name);

	//定义一个容器,用于存放机房信息
	std::vector<Computer> v_Com;
	//初始化机房容器的函数
	void initVector();
};