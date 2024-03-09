#pragma once
#include<iostream>
//using namespace std; //这行在.h头文件不要写,可能会出错

//通常情况下，#pragma once应该放在头文件的最开始，#include指令应该放在#pragma once之后。

/*由于现阶段项目没有对机房做太多操作,所以这个类暂时不写.cpp的源文件实现,
目前只定义机房类,别的类中会用到
*/


//创建一个机房类
class Computer
{
public:

	//机房编号与电脑数量
	int number;
	int count;
};