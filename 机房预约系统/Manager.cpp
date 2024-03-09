#include"Manager.h"
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

//���������ͷ�ļ������еĺ���ʵ��
//���캯������������
Manager::Manager()
{
	//�ղι��캯����ʵ��
}
Manager::Manager(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	//����init,ʹÿ�δ�������Ա����ʱ,���ܴ��ļ��л�ȡ��ʦѧ����Ϣ��������
	this->initVector();

	////��¼ʱ��ʾ����
	//cout << "��ǰѧ������:" << v_Stu.size() << endl;
	//cout << "��ǰ��ʦ����:" << v_Tea.size() << endl;

	////��������
	//for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
	//{
	//	cout << it->id << " " << it->name << " " << it->password << endl;
	//}

	////��ʦ��������
	//for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
	//{
	//	cout << it->id << " " << it->name << " " << it->password << endl;
	//}
}
Manager::~Manager()
{
	//��û���ڶ���new�����Ķ���,��������дdelet
}

//��д���������,չʾ�˵�����
void Manager::operMenu() //������дvirtual,��������ʱ�Ѿ�д��
{
	//ÿ���õ��˽���ʱ����ʾ����
	cout << "��ǰѧ������:" << v_Stu.size() << endl;
	cout << "��ǰ��ʦ����:" << v_Tea.size() << endl;
	cout << "��ǰ��������:" << v_Com.size() << endl;

	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ���:";
}

/*����Ա���幦�ܵ�ʵ��*/
//*����˺�-- - ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
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
		cout << "������Ҫ��ӵ��˺�(1.ѧ�� 2.��ʦ):";
		cin >> select;

		if (select == 1)
		{
			//���ѧ���˺�
			fileName = STUDENT_FILE;
			id_Tip = "������ѧ��:";
			id_Error_Tip = "��������,����������ѧ��:";
			ok_Tip = "ѧ����ӳɹ�!";
			error_Tip = "ѧ�����ʧ��!";
			break;
		}
		else if (select == 2)
		{
			//�����ʦ�˺�
			fileName = TEACHER_FILE;
			id_Tip = "������ְ����:";
			id_Error_Tip = "��������,����������ְ����:";
			ok_Tip = "��ʦ��ӳɹ�!";
			error_Tip = "��ʦ���ʧ��!";
			break;
		}
		else
		{
			cout << "��������,����������!" << endl;
		}
	}
		
	//������Ӧ���ļ���,���ļ�,���������Ϣд���ļ���,���ж��ļ��Ƿ�򿪳ɹ�
	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app); //��׷�ӵķ�ʽд���ļ�.ע����|
	if (!ofs.is_open())
	{
		cout << fileName << "�ļ���ʧ��!" << endl;
		system("puase");
		system("cls");
		return;
	}
	
	flag:
	//�����û�������Ϣ,��¼���ļ���(ע��:���ز������ⶨ�庯����,�����Ȳ�������)
	//����id
	int id;
	cout << id_Tip;
	cin >> id;
	while (cin.fail())
	{
		/*ʹ��cin.fail()�������ж��û��Ƿ�������һ��������
	����û������˷�����ֵ����cin.fail()��������true����ʱ�������������������ʾ�û���������id��*/
	// ����û�����Ĳ�������
		cin.clear();  // �����������״̬��־
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������뻺����
		cout << id_Error_Tip;
		cin >> id;
	}
	//��������
	string name;
	cout << "����������:";
	cin >> name;
	//��������
	string password;
	cout << "����������:";
	cin >> password;

	//����idȥ��
	//����bug,�������ʱ,�޷�ȥ��(����δ�ܼ�ʹ����) �Ѿ����
	if (repeat(fileName, select, id)==1)
	{
		//�����ظ�id
		int select_1;
		while (true)
		{
			cout << "���ڴ�id,�Ƿ�Ҫ�������(1.�� 2.��):";
			cin >> select_1;
			while (cin.fail())
			{
				/*ʹ��cin.fail()�������ж��û��Ƿ�������һ��������
			����û������˷�����ֵ����cin.fail()��������true����ʱ�������������������ʾ�û���������id��*/
			// ����û�����Ĳ�������
				cin.clear();  // �����������״̬��־
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������뻺����
				cout << "��������,�Ƿ�Ҫ�������(1.�� 2.��):" << endl;
				cin >> select_1;
			}

			if (select_1 == 1)
			{
				goto flag;
			}
			else if (select_1 == 2)
			{
				cout << "ȡ������˺ųɹ�!" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "��������,����������!" << endl;
			}
		}
	}
	else if (repeat(fileName, select, id) == 0)
	{
		//�ļ���ʧ��
		cout << fileName << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		//�����������˳�,�Ժ������
		return;
	}

	//���������Ϣ¼���ļ�
	ofs << id << " " << name << " " << password << endl;

	//�ر��ļ�
	ofs.close();
	
	//ÿ����ӳɹ�(����Ҫ��ӵ���Ϣд���ļ�)��ʱ��������(���ļ��ж�ȡ��Ϣ��������)
	this->initVector();

	//��ʾ��ӳɹ�
	cout << ok_Tip << endl;
	system("pause");
	system("cls");
	return;
}

//* �鿴�˺�-- - ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
void Manager::showPerson()
{
	/*��Ҫ�Ĳ������Ƕ��������б���*/
	int index = 1;

	int select;
	cout << "������Ҫ�鿴������(1.ѧ�� 2.��ʦ 3.����):";
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
			cout << "��������,����������Ҫ�鿴������(1.ѧ�� 2.��ʦ 3.����):";
			cin >> select;
		}

		if (select == 1)
		{
			if (v_Stu.size() == 0)
			{
				cout << "��ǰû��ѧ��!" << endl;
				system("pause");
				system("cls");
				return;
			}

			cout << "ѧ����Ϣ����:" << endl;
			//�鿴ѧ��
			for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
			{
				cout << setw(5) << index++ << "��" << "ѧ��:" << setw(3) << it->id << setw(10) << "����:" << setw(10) << it->name << setw(10) << "����:" << setw(5) << it->password << endl;
			}

			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)
		{

			if (v_Tea.size() == 0)
			{
				cout << "��ǰû����ʦ1!" << endl;
				system("pause");
				system("cls");
				return;
			}

			//�鿴��ʦ
			cout << "��ʦ��Ϣ����:" << endl;
			//�鿴��ʦ
			for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
			{
				cout << setw(5) << index++ << "��" << "ְ����:" << setw(3) << it->id << setw(10) << "����:" << setw(10) << it->name << setw(10) << "����:" << setw(5) << it->password << endl;
			}

			system("pause");
			system("cls");
			return;
		}
		else if (select == 3)
		{
			//ѧ����ʦ����

			if (v_Stu.size() == 0)
			{
				cout << "��ǰû��ѧ��!" << endl;
			}
			else
			{
				//�鿴ѧ��
				cout << "ѧ����Ϣ����:" << endl;
				for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
				{
					cout << setw(5) << index++ << "��" << "ѧ��:" << setw(3) << it->id << setw(10) << "����:" << setw(10) << it->name << setw(10) << "����:" << setw(5) << it->password << endl;
				}
			}
			
			//���³�ʼ�����Ϊ1
			index = 1;

			if (v_Tea.size() == 0)
			{
				cout << "��ǰû����ʦ!" << endl;
				return;
			}
			else
			{
				//�鿴��ʦ
				cout << "��ʦ��Ϣ����:" << endl;
				for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
				{
					cout << setw(5) << index++ << "��" << "ְ����:" << setw(3) << it->id << setw(10) << "����:" << setw(10) << it->name << setw(10) << "����:" << setw(5) << it->password << endl;
				}

				system("pause");
				system("cls");
				return;
			}
		}
		else
		{
			cout << "��������,���������Ҫ�鿴������(1.ѧ�� 2.��ʦ 3.����):";
		}
	}
}

//* �鿴����-- - �鿴���л�������Ϣ
void Manager::showComputer()
{
	int index = 1;

	//�Ի����������б���
	if (v_Com.size() == 0)
	{
		cout << "��ǰû�л���!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "������Ϣ����:" << endl;
		for (vector<Computer>::iterator it = v_Com.begin(); it != v_Com.end(); it++)
		{
			cout << setw(5) << index++ << "��" << "�������:" << setw(5) << it->number << setw(20) << "��������:" << setw(5) << it->count << endl;

		}
		system("pause");
		system("cls");
		return;
	}
}

//* ���ԤԼ-- - �������ԤԼ��¼
void Manager::cleanFile()
{
	//��ǰ��û��ԤԼ,�Ȳ�д.��д��ѧ���ĺ���ʵ�ֺ���������

	OrderFile of;
	if (of.m_Order.size() == 0)
	{
		cout << "��ǰû��ԤԼ,�޷����!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string select;
	cout << "�Ƿ�ȷ���������ԤԼ(�� ��):";
	
	while (true)
	{
		cin >> select;

		if (select == "��")
		{
			//of.m_Order.clear();

			of.clearOrder();

			cout << "���ԤԼ�ɹ�!" << endl;
			system("pause");
			system("cls");
			return;

		}
		else if (select == "��")
		{
			cout << "��ȡ�����ԤԼ!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "��������,������ȷ���Ƿ��������ԤԼ(�� ��):";
		}
	}
}

//* ע����¼-- - �˳���¼
void Manager::exitManager(string name)
{
	cout << "��ӭ" << "����Ա" << name << "�´�ʹ��, �ټ�!" << endl;
	system("pause");
	system("cls");
}

//* ��ʼ��ѧ������ʦ�ͻ���������(���ļ��ж�ȡ��Ϣ��������)
/*����������ѧ������ʦ�ļ��ж�ȡ��Ϣ,
������Ϣ����������,
�������ȥ�ز������ж�,
����ȥ����ֻ��Ҫ����������ȡ��Ϣ����
*/
void Manager::initVector()
{
	//���϶��������,������в���,�ǳ���Ҫ
	v_Stu.clear();
	v_Tea.clear();
	v_Com.clear();
	
	ifstream ifs;
	
	//��ѧ������
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) //������bug,�Ժ����о�
	{
		cout <<STUDENT_FILE<< "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	/*��ѧ���ļ��е�����һ��һ�д���vector�еķ���:
	1.����һ��ѧ������s
	2.��ȡ�ļ�,���ļ�����д��s�ĳ�Ա������
	3.��s����vector��
	*/
	//����ѧ������
	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password) //���ļ��е���Ϣ���𸳸�id name pwd,����������ʱֹͣ
	{
		//��s����������
		v_Stu.push_back(s);
	}
	//�ر��ļ�,�ǳ���Ҫ(���ر��ļ����׳���,ȥ�ز�������)
	/*ÿ���ļ�Ӧ����ʹ����Ϻ�ʱ�رա�
	����㲻�رյ�һ���ļ�����ô�ڴ򿪵ڶ����ļ�ʱ���ܻ�������⣬�����ȡ����������ݻ����޷����ļ���
	���ס���ڲ����ļ�ʱ��һ��Ҫע�⼰ʱ�ر��ļ������Է�ֹ����Ǳ�ڵĴ���
	*/
	ifs.close();

	//����ʦ����
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << TEACHER_FILE << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	/*��ѧ���ļ���һ���е����ݴ���һ���д���vector�еķ���:
	1.����һ��ѧ������s
	2.��ȡ�ļ�,���ļ�����д��s�ĳ�Ա������
	3.��s����vector��
	*/
	//������ʦ����
	Teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.password) //���ļ��е���Ϣ���𸳸�id name pwd,����������ʱֹͣ
	{
		//��s����������
		v_Tea.push_back(t);
	}
	//�ر��ļ�,�ǳ���Ҫ(���ر��ļ����׳���,ȥ�ز�������)
	ifs.close();

	//�Ի�������
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//������������
	Computer c;
	while (ifs >> c.number && ifs >> c.count) //���ļ��е���Ϣ�ֱ𸳸�cout number,����������ʱֹͣ
	{
		//��c��������
		v_Com.push_back(c);
	}
	//�ر��ļ�,�ǳ���Ҫ(���ر��ļ����׳���,ȥ�ز�������)
	ifs.close();
}

//* ���һ��int���͵ĺ���,�����ж��ļ����Ƿ��Ѿ���Ҫ��ӵ�id
int Manager::repeat(string fileName, int select, int id)
{
	//��Ȼ�����ȥ�ز���,����һ��ʼ�ļ������ڵĻ�,���������ǻ���ܴ�����,�����Ȳ��о�(����ֵ��Ϊint,Ӧ���ܽ����)
	if (select == 1)
	{
		//��ѧ��ȥ��
		ifstream ifs;
		ifs.open(fileName, ios::in);
		if (!ifs.is_open())
		{
			return 0;//����bug?
		}
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
		{
			//�ļ����Ѿ����ڴ�id
			if (it->id == id)
			{
				ifs.close();
				return 1;
			}
		}
		ifs.close();
		//�ļ���δ���ڴ�id
		return 2;
	}
	else
	{
		//����ʦȥ��
		ifstream ifs;
		ifs.open(fileName, ios::in);
		if (!ifs.is_open())
		{
			return 0; //����bug?
		}
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			//�ļ����Ѿ����ڴ�id
			if (it->id == id)
			{
				ifs.close();
				return 1;
			}
		}
		ifs.close();
		//�ļ���δ���ڴ�id
		return 2;
	}
}