#include"Teacher.h"
#include"OrderFile.h"
#include <iomanip>
#include<vector>
#include<iostream>
using namespace std;
/*��Դ�ļ���д����һ������������������ͷ�ļ�*/
/*ͨ������£���Ӧ����"b.cpp"��Դ�ļ��а���"a.h"ͷ�ļ�����Ϊֻ����ʵ���ļ�����Ҫʹ��"a.h"ͷ�ļ������ݡ�
�������"b.h"�а���"a.h"����������һ��Դ�ļ��а�����"b.h"����ô�������Ὣ"a.h"ͷ�ļ��������Σ�����ܻᵼ�±������
���⣬����ͷ�ļ������λ����ʵ���ļ��Ķ�������Ϊ��������ȷ�������ڱ���ʱֻ����һ�Ρ�*/

/*������һ��"a.h"��ͷ�ļ�,��"a.cpp"Դ�ļ���ʵ����,Դ�ļ�Ҫд"a.h"��?��д������֪����*/
/*��"a.cpp"Դ�ļ�����Ҫд��#include "a.h"�Ա��ñ�����֪����Դ�ļ�������"a.h"ͷ�ļ���
������������޷�������ͷ�ļ��еĶ��壬���±������
��Ȼ��Щ���������ܻ��Զ�����ͷ�ļ���������û���Ҫд��ͷ�ļ������ã��Ա�֤����Ŀ���ֲ�Ժ������ԡ�*/

/*����ͷ�ļ���˳��*/
/*����ͷ�ļ���˳���Ǻ���Ҫ�ġ�
ͨ������Ӧ�����Ȱ�����ǰʵ���ļ���Ҫ��ͷ�ļ���Ȼ����������ϵͳ���ͷ�ļ���
��������ȷ�����ǰ���ȷ��˳��������Ӷ�����һЩǱ�ڵı������*/

/*��.hͷ�ļ���д��"#include<iostream>",��.cppԴ�ļ��л�Ҫд��*/
/*��.cppԴ�ļ���Ҳ��Ҫд#include<iostream>��
��Ϊͷ�ļ�(.h�ļ�)��Դ�ļ�(.cpp�ļ�)��������ͬ���ļ�����Ҫ�ֱ���������ͷ�ļ���
��ͷ�ļ��а���ͷ�ļ���Ҫ��Ϊ����ʹ�ø�ͷ�ļ����ļ����Է��ʸ�ͷ�ļ������������ݡ�
��Դ�ļ��а���ͷ�ļ���Ҫ��Ϊ����Դ�ļ����Է��ʸ�ͷ�ļ������������ݡ�
��ˣ���Ҫ��ÿ����Ҫʹ�ø�ͷ�ļ����ļ��ж����а�����*/

/*������һ��"a.h"��ͷ�ļ�,��"a.cpp"Դ�ļ���ʵ����,Դ�ļ�Ҫд"a.h"��?��д������֪����*/
/*��"a.cpp"Դ�ļ�����Ҫд��#include "a.h"�Ա��ñ�����֪����Դ�ļ�������"a.h"ͷ�ļ���
������������޷�������ͷ�ļ��еĶ��壬���±������
��Ȼ��Щ���������ܻ��Զ�����ͷ�ļ���������û���Ҫд��ͷ�ļ������ã��Ա�֤����Ŀ���ֲ�Ժ������ԡ�*/


//���캯������������
Teacher::Teacher()
{
	//�ղι��캯����ʵ��
}
Teacher::Teacher(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;
}
Teacher::~Teacher()
{
	//��û���ڶ���new�����Ķ���,��������дdelet
}

//��д���������,չʾ�˵�����
void Teacher::operMenu() //������дvirtual,��������ʱ�Ѿ�д��
{
	cout << "��ӭ��ʦ��" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ���:";
}

/*��ʦ���幦�ܵ�ʵ��*/
//�鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Teacher::showAllOrder()
{
	//����OrderFile����
	OrderFile of;
	if (of.orderCount == 0)
	{
		cout << "��ǰû��ԤԼ!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	int i;

	cout << "����ԤԼ����:" << endl;
	for (i = 0; i < of.orderCount; i++) //����f�е�map����
	{
		cout << setw(5) << index++ << "��" << setw(5)
			<< "ѧ��:" << setw(5) << of.m_Order[i]["ѧ��"] << setw(9)
			<< "����:" << setw(8) << of.m_Order[i]["����"] << setw(9)
			<< "ʱ��:" << setw(8) << of.m_Order[i]["ʱ��"] << setw(9)
			<< "ʱ���:" << setw(8) << of.m_Order[i]["ʱ���"] << setw(9)
			<< "����:" << setw(8) << of.m_Order[i]["����"] << setw(9)
			<< "״̬:" << setw(8) << of.m_Order[i]["״̬"] << endl;
	}

	system("pause");
	system("cls");
	return;
}

//���ԤԼ-- - ��ѧ����ԤԼ�������
void Teacher::validOrder()
{
	//����е�ԤԼ�������

	OrderFile of;
	if (of.orderCount == 0)
	{
		cout << "��ǰû��ԤԼ!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	int i;
	//����һ��������ſ���˵�ԤԼ��λ��
	vector<int> v_Index;

	for (i = 0; i < of.m_Order.size(); i++)
	{
		if (of.m_Order[i]["״̬"] == "�����")
		{
			index++;
			v_Index.push_back(i);
		}
	}
	
	if (index == 1)
	{
		cout << "��ǰû�п���˵�ԤԼ!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else //�п���˵�ԤԼ
	{
		index = 1;

		cout << "����˵�ԤԼ����:" << endl;
		for (i = 0; i < v_Index.size(); i++)
		{
			cout << setw(5) << index++ << "��" << setw(5)
				<< "ѧ��:" << setw(5) << of.m_Order[v_Index[i]]["ѧ��"] << setw(9)
				<< "����:" << setw(8) << of.m_Order[v_Index[i]]["����"] << setw(9)
				<< "ʱ��:" << setw(8) << of.m_Order[v_Index[i]]["ʱ��"] << setw(9)
				<< "ʱ���:" << setw(8) << of.m_Order[v_Index[i]]["ʱ���"] << setw(9)
				<< "����:" << setw(8) << of.m_Order[v_Index[i]]["����"] << setw(9)
				<< "״̬:" << setw(8) << of.m_Order[v_Index[i]]["״̬"] << endl;
		}

		int select;
		cout << "Ҫ��˵�ԤԼ(0 ȡ�����):";
		while (true)
		{
			cin >> select;
			while (cin.fail())
			{
				/*ʹ��cin.fail()�������ж��û��Ƿ�������һ��������
			����û������˷�����ֵ����cin.fail()��������true����ʱ�������������������ʾ�û���������id��*/
			// ����û�����Ĳ�������
				cin.clear();  // �����������״̬��־
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������뻺����
				cout << "��������,����������Ҫ��˵�ԤԼ(0 ȡ�����):";
				cin >> select;
			}

			if (0 <= select && select <= v_Index.size())
			{
				if (select == 0)
				{
					cout << "�Ѿ������ԤԼ!" << endl;
					system("pause");
					system("cls");
					return;
				}
				break;
			}
			else
			{
				cout << "��������,����������Ҫ��˵�ԤԼ(0 ��ȡ��):";
			}
		}

		string result;
		cout << "������˽��(ͨ�� ��ͨ��):";
		while (true)
		{
			cin >> result;

			if (result == "ͨ��" || result == "��ͨ��")
			{
				break;
			}
			else
			{
				cout << "��������,������������˽��(ͨ�� ��ͨ��):";
			}
		}

		//����û�ж�select result�ж�,�Ժ���˵(������ܶ඼��) �Ѿ����

		of.m_Order[v_Index[select - 1]]["״̬"] = result;

		//���� ��������Ϣд���ļ�
		of.updateOrder();

		cout << "��˳ɹ�!" << endl;
		system("pause");
		system("cls");
		return;

	}
}

//ע����¼-- - �˳���¼
void Teacher::exitTeacher(string name)
{
	cout << "��ӭ" << "��ʦ" << name << "�´�ʹ��, �ټ�!" << endl;
	system("pause");
	system("cls");
}