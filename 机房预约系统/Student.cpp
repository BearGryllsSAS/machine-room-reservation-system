#include"Student.h"
#include"GlobalFile.h"
#include"OrderFile.h"
#include <iomanip>
#include<fstream>
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
Student::Student()
{
	//�ղι��캯����ʵ��
}
Student::Student(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	//��������ʱ��ʼ����������
	this->initVector();
}
Student::~Student()
{
	//��û���ڶ���new�����Ķ���,��������дdelet
}

//��д���������,չʾ�˵�����
void Student::operMenu() //������дvirtual,��������ʱ�Ѿ�д��
{
	//ÿ��ʹ�õ��������ʱ����ʾ��������
	cout << "��ǰ��������:" << v_Com.size() << endl;
	
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ���:";
}

/*ѧ�����幦�ܵ�ʵ��*/
//����ԤԼ-- - ԤԼ����
void Student::applyOrder()
{
	//Ŀǰֻ�ṩ�򵥵�ԤԼ����,���ܳ�ͻ(�Ѿ�����)
	//ʵ���ϻ��Ƕ��ļ����в���,��ʾ�û�������Ϣ,Ȼ����Ϣд���ļ�

	//�ж��Ƿ��л���,��û��,����ʾ��ֱ�ӷ���
	if (v_Com.size() == 0)
	{
		cout << "��ǰû�л���,�޷�ԤԼ!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//��ԤԼ�ļ����ж��ļ��Ƿ����
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::app); //׷�ӵķ�ʽ
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "��ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	flag:
	//����û�ж����������ȷ���ж�,�Ժ���˵(�Ѿ�����)
	//ʱ��
	string date;
	cout << "ҪԤԼ��ʱ��(��һ �ܶ� ���� ���� ����):";
	while (true)
	{
		cin >> date;
		if (date == "��һ" || date == "�ܶ�" || date == "����" || date == "����" || date == "����")
		{
			break;
		}
		else
		{
			cout << "��������,����������ҪԤԼ��ʱ��(��һ �ܶ� ���� ���� ����):";
		}
	}
	
	//ʱ���
	string time;
	cout << "ҪԤԼ��ʱ���(���� ����):";
	while (true)
	{
		cin >> time;
		if (time == "����" || time == "����")
		{
			break;
		}
		else
		{
			cout << "��������,����������ҪԤԼ��ʱ���(���� ����):";
		}
	}

	//����
	int computerRoom;
	int index = 1;
	cout << "������Ϣ����:" << endl;
	for (vector<Computer>::iterator it = v_Com.begin(); it != v_Com.end(); it++)
	{
		cout << index++ << "��" << "���:" << it->number << " " << "����:" << it->number << endl;
	}
	cout << "ҪԤԼ�Ļ�����:";
	while (true)
	{
		cin >> computerRoom;
		while (cin.fail())
		{
			/*ʹ��cin.fail()�������ж��û��Ƿ�������һ��������
		����û������˷�����ֵ����cin.fail()��������true����ʱ�������������������ʾ�û���������id��*/
		// ����û�����Ĳ�������
			cin.clear();  // �����������״̬��־
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������뻺����
			cout << "��������,����������ҪԤԼ�Ļ�����:";
			cin >> computerRoom;
		}
		if (computerRoom > 0 && computerRoom < index)
		{
			break;
		}
		else
		{
			cout << "��������,����������ҪԤԼ�Ļ�����:";
		}
	}

	//ԤԼ״̬
	string status = "�����";

	//��������ȫ��ͬ��ԤԼ����ʾ,�޷��ظ�ԤԼ
	OrderFile of; //����OrderFile����
	if (of.orderCount != 0) //��ԤԼ�������м�¼
	{
		int i;
		for (i = 0; i < of.orderCount; i++) //ѭ������ԤԼ����
		{
			if (atoi(of.m_Order[i]["ѧ��"].c_str()) == this->id) //�������Լ�id��ͬ��ԤԼ��¼
			{
				if (of.m_Order[i]["ʱ��"] == date && of.m_Order[i]["ʱ���"] == time && of.m_Order[i]["״̬"] == status)
				{
					//���Ѿ�������ͬʱ��,��ͬ״̬��ԤԼ��¼
					cout << "�Ѿ�������ͬ��ԤԼ��¼,��ѡ��(1.����ԤԼ 2.ȡ��ԤԼ);";
					
					int select;
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
							cout << "��������,��������ѡ��(1.����ԤԼ 2.ȡ��ԤԼ);";
							cin >> select;
						}

						if (select == 1)
						{
							goto flag;
						}
						else if(select==2)
						{
							cout << "ȡ��ԤԼ�ɹ�!" << endl;
							system("pause");
							system("cls");
							return;
						}
						else
						{
							cout << "��������,��������ѡ��(1.����ԤԼ 2.ȡ��ԤԼ);";
						}
					}
				}
			}
		}
	}

	//����Ϣ¼���ļ���
	ofs << "ѧ��:" << this->id << " ";
	ofs << "����:" << this->name << " ";
	ofs << "ʱ��:" << date << " ";
	ofs << "ʱ���:" << time << " ";
	ofs << "����:" << computerRoom << " ";
	ofs << "״̬:" << status << endl;
	
	//�ر��ļ�
	ofs.close();

	/*����ԤԼ��Ϣ
	�����ò���,��ԤԼ��¼д���ļ��ͺ�,û�и���ԤԼ�����е���Ϣ
	���Ե����ԤԼ����ȡ��ԤԼ,Ҫ�ı�ԤԼ�����е���Ϣʱ�ŵ��ú��������ļ�
	*/
	
	//��ʾԤԼ�ɹ�
	cout << "ԤԼ�ɹ�,��ȴ���ʦ���" << endl;
	system("pause");
	system("cls");
}

//�鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬
void Student::showMyOrder()
{
	//��ʵ���Ǵ���OrderFile����,������������ԤԼ�������б����Ĺ���
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
	
	for (i = 0; i < of.orderCount; i++) //����f�е�map����
	{
		//����bug,����������ԤԼ��Ϣ(�Ѿ����,ԭ����:�ٿղι�������δ��ʱ���OrderFile��m����)
		//���Ǳ��˵�ѧ��
		/*������˵��of.m_order[i]��һ��map����ʾ��i��ԤԼ��¼��
		of.m_order[i]["ѧ��"]��ʾ��i��ԤԼ��¼��ѧ��ѧ���������Ӧ��ֵ����ԤԼ��ѧ����ѧ�š�
		atoi(of.m_orderData[i]["stuId"].c_str())��ʾ����ֵ���ַ�������ת�������ͣ�Ȼ���뵱ǰѧ����ID�Ƚϡ�
		�������ID��ȣ���˵������ԤԼ��¼�ǵ�ǰѧ��ԤԼ�ģ�Ӧ�������*/
		if (atoi(of.m_Order[i]["ѧ��"].c_str()) == this->id)
		{
			if (index == 1)
			{
				cout << "����ԤԼԤԼ����:" << endl;
			}

			cout << setw(5) << index++ << "��" << setw(5)
				<< "ʱ��:" << setw(5) << of.m_Order[i]["ʱ��"] << setw(20)
				<< "ʱ���:" << setw(5) << of.m_Order[i]["ʱ���"] << setw(20)
				<< "����:" << setw(5) << of.m_Order[i]["����"] << setw(20)
				<< "״̬:" << setw(5) << of.m_Order[i]["״̬"] << endl;
		}
	}

	if (index == 1)
	{
		cout << "��ǰû��ԤԼ!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		system("pause");
		system("cls");
		return;
	}
}

//������ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Student::showAllOrder()
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

//ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
void Student::cancelOrder()
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
	//����һ��������ŵ�ǰѧ��ԤԼ��¼����λ��
	vector<int> v_Index;

	for (i = 0; i < of.orderCount; i++) //����f�е�map����
	{
		//����bug,����������ԤԼ��Ϣ(�Ѿ����,ԭ����:�ղι���ʱδ��ʱ���OrderFile��m����)
		//���Ǳ��˵�ѧ��
		/*������˵��of.m_order[i]��һ��map����ʾ��i��ԤԼ��¼��
		of.m_order[i]["ѧ��"]��ʾ��i��ԤԼ��¼��ѧ��ѧ���������Ӧ��ֵ����ԤԼ��ѧ����ѧ�š�
		atoi(of.m_orderData[i]["stuId"].c_str())��ʾ����ֵ���ַ�������ת�������ͣ�Ȼ���뵱ǰѧ����ID�Ƚϡ�
		�������ID��ȣ���˵������ԤԼ��¼�ǵ�ǰѧ��ԤԼ�ģ�Ӧ�������*/
		if (atoi(of.m_Order[i]["ѧ��"].c_str()) == this->id) //�ҵ��Լ���ԤԼ��¼
		{
			if (of.m_Order[i]["״̬"] == "�����" || of.m_Order[i]["״̬"] == "ͨ��") //ԤԼʧ�ܵĺ��Ѿ�ȡ����¼����ȡ��
			{
				v_Index.push_back(i); //��ŵ�ǰѧ����ȡ����ԤԼ��¼����λ��
				index++;
			}
		}
	}

	////����
	//for (int x = 0; x < v_Index.size(); x++)
	//{
	//	cout << "------------------------" << endl;
	//	cout << v_Index[x] << endl;
	//	cout << v_Index[0] << endl;
	//	cout << "---------------------" << endl;
	//}

	if (index == 1)
	{
		cout << "��ǰû�п���ȡ����ԤԼ!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else //���ڿ�ȡ����ԤԼ
	{
		//��ʼ��index
		index = 1;

		cout << "��ȡ����ԤԼ����:" << endl;
		for (i = 0; i < v_Index.size(); i++)
		{
			cout << setw(5) << index++ << "��" << setw(5)
				<< "ʱ��:" << setw(5) << of.m_Order[v_Index[i]]["ʱ��"] << setw(20)
				<< "ʱ���:" << setw(5) << of.m_Order[v_Index[i]]["ʱ���"] << setw(20)
				<< "����:" << setw(5) << of.m_Order[v_Index[i]]["����"] << setw(20)
				<< "״̬:" << setw(5) << of.m_Order[v_Index[i]]["״̬"] << endl;
		}

		int select;
		cout << "Ҫȡ����ԤԼ(0 ��ȡ��):";
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
				cout << "��������,����������Ҫȡ����ԤԼ(0 ��ȡ��):";
				cin >> select;
			}

			if (0 <= select && select <= v_Index.size())
			{
				if (select == 0)
				{
					cout << "�Ѿ���ȡ��ԤԼ!" << endl;
					system("pause");
					system("cls");
					return;
				}
				break;
			}
			else
			{
				cout << "��������,����������Ҫȡ����ԤԼ(0 ��ȡ��):";
			}
		}

		//��ԤԼ��Ϣ�޸�
		//of.m_Order[v_Index[select - 1]]["ԤԼ"] = "��ȡ��"; md�������ִ���!!!!!!!!!!!�ö����
		of.m_Order[v_Index[select - 1]]["״̬"] = "��ȡ��";

		//����
		/*for (int j = 0; j < of.m_Order.size(); j++)
		{
			cout << of.m_Order[j]["ԤԼ"] << " " << endl;
		}*/
		//����ȷʵ�Ѿ��޸�,�����ļ�δ�ܸ���

		//��������Ϣ���µ��ļ���
		of.updateOrder();
	
		//��ʾ�û�
		cout << "ԤԼ�Ѿ��ɹ�ȡ��!" << endl;

		system("pause");
		system("cls");
		return;
	}
}

//ע����¼-- - �˳���¼
void Student::exitStudent(string name)
{
	cout << "��ӭ" << "ѧ��" << name << "�´�ʹ��, �ټ�!" << endl;
	system("pause");
	system("cls");
}

//��ʼ�����������ĺ���
void Student::initVector()
{
	//ÿ�ε���ʱ���������
	v_Com.clear();

	//�򿪻����ļ�
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "��ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//������������
	Computer c;

	while (ifs >> c.number && ifs >> c.count) //�����ļ��ж�ȡ����Ϣ¼��number count��
	{
		v_Com.push_back(c);
	}
	
	//�ر��ļ�
	ifs.close();

	return;
}
