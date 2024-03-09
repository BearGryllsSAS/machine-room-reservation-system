#pragma once
#include<iostream>
#include<map>

//### 8.3 显示预约
//
//#### 8.3.1 创建预约类
//
//功能描述：显示预约记录时，需要从文件中获取到所有记录，用来显示，创建预约的类来管理记录以及更新
//
//在头文件以及源文件下分别创建 * *orderFile.h * *和 * *orderFile.cpp * *文件
//
//orderFile.h中添加如下代码：


class OrderFile
{
public:
	//空参构造
	/*只写这一个空参构造,在空参构造中对预约文件进行处理,把处理的结果放入map中*/
	OrderFile();

	//更新 即将容器中的信息更新到预约文件中
	void updateOrder();

	//清空预约记录
	void clearOrder();

	//定义一个map容器,作用是存放处理后的预约信息
	//key 存放记录条数下标 value存放记录的内容
	std::map<int,std::map<std::string, std::string>> m_Order;

	//记录条数
	int orderCount;
};