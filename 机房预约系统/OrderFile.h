#pragma once
#include<iostream>
#include<map>

//### 8.3 ��ʾԤԼ
//
//#### 8.3.1 ����ԤԼ��
//
//������������ʾԤԼ��¼ʱ����Ҫ���ļ��л�ȡ�����м�¼��������ʾ������ԤԼ�����������¼�Լ�����
//
//��ͷ�ļ��Լ�Դ�ļ��·ֱ𴴽� * *orderFile.h * *�� * *orderFile.cpp * *�ļ�
//
//orderFile.h��������´��룺


class OrderFile
{
public:
	//�ղι���
	/*ֻд��һ���ղι���,�ڿղι����ж�ԤԼ�ļ����д���,�Ѵ���Ľ������map��*/
	OrderFile();

	//���� ���������е���Ϣ���µ�ԤԼ�ļ���
	void updateOrder();

	//���ԤԼ��¼
	void clearOrder();

	//����һ��map����,�����Ǵ�Ŵ�����ԤԼ��Ϣ
	//key ��ż�¼�����±� value��ż�¼������
	std::map<int,std::map<std::string, std::string>> m_Order;

	//��¼����
	int orderCount;
};