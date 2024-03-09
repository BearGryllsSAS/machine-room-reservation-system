#pragma once
#include<iostream>
//using namespace std; //这行在.h头文件不要写,可能会出错

//通常情况下，#pragma once应该放在头文件的最开始，#include指令应该放在#pragma once之后。


//在"全局文件"这个头文件中,可以把我们后续需要的文件名定义成宏,方便各个文件中使用
/*在此之前, 我们项目文件的路径中已经有了以下文件:
1.Manager.txt
2.Studetn.txt
3.Teacher.txt
4.Compuater.txt
5.Order.txt
之后写的代码都要进行文件操作
*/

#define MANAGER_FILE "Manager.txt"
#define TEACHER_FILE "Teacher.txt"
#define STUDENT_FILE "Student.txt"
#define COMPUTER_FILE "Computer.txt"
#define ORDER_FILE "Order.txt"