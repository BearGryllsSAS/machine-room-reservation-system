#include"GlobalFile.h"
#include"Person.h"
#include"Student.h"
#include"Manager.h"
#include"Teacher.h"
#include<iostream>
#include<fstream>
using namespace std;

//�����֤
void authenticate(string fileName, int select);
//�����֤��,�õ�����֤��¼�ĺ���
void verification(string fileName, int select, string error_Tip, int id, string name, string password);
//����Ա��¼����
void managerMenu(Person*& p);
//ѧ����¼����
void studentMenu(Person*& p);
//��ʦ��¼����
void teacherMenu(Person*& p);

int main()
{
	int select;

	while (true)
	{
		// cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|								 |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��:";

		cin >> select;

		switch (select)
		{
		case 1: //ѧ������
			authenticate(STUDENT_FILE, 1);
			break;
		
		case 2: //��ʦ
			authenticate(TEACHER_FILE,2);
			break;
		
		case 3: //�� �� Ա
			authenticate(MANAGER_FILE,3);
			break;

		case 4: //������
			system("pause");
			break;

		case 0: //�˳�
			cout << "��ӭ�´�ʹ��,�ټ�!" << endl;
			system("pause");
			exit(0);
			break;
		
		default: //����
			cout << "��������,����������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	
	}

	return 0;
}

//�����֤
/*
�����е�ͷ�ļ���Դ�ļ������ɺ�, ����һ����֤��¼�ĺ���,
main������case 1 2 3������ô˺���,���������֤,�������id������
����ȷ��,���ܽ�����Ӧ����Ĳ˵�����(��ʱ������һ����Ӧ�ĺ���)

����main�д�������ֵ, ���������֤��¼
�����������ֵһ�����ļ���,һ����select
1.select����ȷ��������Ҫ��֤�ĸ����
2.�ļ���������������֤(����ݲ����ڻ���֤ʧ��)
*/
void authenticate(string fileName, int select)
{
	//�����ļ���,�Ӵ�����ļ����ж�ȡ�ļ�
	/*ִ�� ifstream ifs(fileName, ios::in); ����ʱ����� fileName ָ�����ļ������ҽ��ļ��� ifs ������й�����
	��ˣ�ifs �����Ѿ�����ָ�����ļ���
	��Ҫע����ǣ�������ļ�ʧ�ܣ�ifs �����״̬�ᱻ����Ϊ����״̬��
	��Ҫʹ�� fail() �� bad() ��Ա����������ļ��Ƿ�ɹ��򿪡�
	���⣬��Ҫע����ǣ���Ȼ ifs �����Ѿ������ļ������������������ļ��ж�ȡ���ݡ�
	ֻ������Ҫ���ļ��ж�ȡ����ʱ���Ż���ж�ȡ������*/
	/*ifstream ifs(fileName, ios::in); �� ifstream ifs; ifs.open(fileName, ios::in);
	���ַ�ʽ�������������ļ�������һ�������ļ�������
	��֮ͬ�����ڣ�ifstream ifs(fileName, ios::in); ���ڶ��󴴽���ͬʱ�ʹ��ļ���
	�� ifstream ifs; ifs.open(fileName, ios::in); ���ȴ���������ͨ������ open ��Ա�������ļ���
	����ļ��򿪳ɹ������ַ�ʽ������ʹ�� ifs ������ļ��ж�ȡ���ݡ�
	������ļ���ʧ�ܣ������ַ�ʽ����Ҫʹ�� fail() �� bad()��ifs.is_open() ��Ա����������ļ�״̬��
	��Ҫע����ǣ���ʹ�� open ��Ա�������ļ�֮ǰ�������ȴ��� ifstream ����
	��ˣ����ʹ�� ifstream ifs; �������ʱ����Ҫ���� open ���������ļ���*/
	/*�ж��ļ��Ƿ�ɹ���ȡ��д�룬����ʹ�� eof() �� good() ��Ա������
	eof() �� ios ��ĳ�Ա���������ڼ���������Ƿ��Ѿ������ļ�ĩβ��
	����������Ѿ������ļ�ĩβ���򷵻� true�����򷵻� false��

	good() �� ios ��ĳ�Ա���������ڼ���������Ƿ��ڿɶ���д״̬��
	���������û�з����κδ����򷵻� true�����򷵻� false��
	һ������£�����ȡ�ļ�ʱ������ʹ�� while (!ifs.eof()) ѭ����ȡ�ļ���ÿһ�����ݣ�
	����ÿ�ζ�ȡ���ݺ�ʹ�� if (ifs.good()) ������ȡ�����Ƿ�ɹ��������ȡ����ʧ�ܣ�
	����Ϳ��Ը��ݾ������������Ӧ�Ĵ�����

	��д���ļ�ʱ������ʹ�� if (ofs.good()) �����д������Ƿ�ɹ���
	���д�����ʧ�ܣ�����Ϳ��Ը��ݾ������������Ӧ�Ĵ�����*/
	ifstream ifs;
	ifs.open(fileName, ios::in); //ios::in��ʹ��дҲû��,Ĭ�Ͼ���
	//�ж��ļ��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << fileName << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.close();

	//����һЩ��ʾ,��������ʹ��
	string id_Tip;
	string id_Error_Tip;
	string error_Tip;
	if (select == 1)
	{
		id_Tip = "������ѧ��:";
		id_Error_Tip = "������Ч������������ѧ��:";
		error_Tip = "ѧ����֤��¼ʧ��!";
	}
	else if (select == 2)
	{
		id_Tip = "������ְ����:";
		id_Error_Tip = "������Ч������������ְ����:";
		error_Tip = "��ʦ��֤��¼ʧ��!";
	}
	else
	{
		id_Tip = "���������Ա��:";
		id_Error_Tip = "������Ч���������������Ա��:";
		error_Tip = "����Ա��֤��¼ʧ��!";
	}

	//��ʾ�û�����
	//id
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
	//name
	string name;
	cout << "����������:";
	cin >> name;
	//password
	string password;
	cout << "����������:";
	cin >> password;

	//���庯��,�����û��������Ϣ,����������ֱ������֤
	verification(fileName, select, error_Tip, id, name, password);
}

//�����֤��,�õ�����֤��¼�ĺ���
void verification(string fileName, int select, string error_Tip, int id, string name, string password)
{
	//����Person���͵�pָ��,�����֤�ɹ���,������������һ������
	Person* p = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << fileName << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//������������,��Ŵ��ļ��ж�ȡ������,Ȼ�����û���������ݱȽ�
	int f_Id;
	string f_Name;
	string f_Password;

	//��ʼ���ļ�
	/*һ��һ�ж�,������ĩβ�������з�ʱ,����һ��whileѭ�����ɹ�
	���Ĺ�����,�����ָ���(�ո��)ʱ,ǰһ�������Ͷ�ȡ�ɹ�,Ȼ����һ��������ȡ
	*/
	while (ifs >> f_Id && ifs >> f_Name && ifs >> f_Password)
	{
		if (f_Id == id && f_Name == name && f_Password == password) //��id��name��password����������֤��¼�ɹ�
		{
			if (select == 1)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				ifs.close(); //�ر��ļ�
				system("pause");
				system("cls");

				//�����ָ��ָ�������ڶ������ٵĿռ�,�������вι���
				/*���� Student ���� Person ��������࣬��˿��Խ� Student ��Ķ���ָ�븳ֵ�� Person ���ָ�룬
				��Ҳ�� C++ ��̬�����֡��������ĺô��ǿ���ͨ��ָ������ָ�����������ĳ�Ա������
				�Ӷ�ʵ�ִ��������Ժ���չ�ԡ�*/
				p = new Student(id, name, password);

				//��ָ�봫������ĺ���
				studentMenu(p);
				//�˳�ѧ����½�����,ֱ�ӷ������˵�,��ִ���������
				return;
			}
			else if (select == 2)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				ifs.close(); //�ر��ļ�
				system("pause");
				system("cls");

				//�����ָ��ָ�������ڶ������ٵĿռ�,�������вι���
				p = new Teacher(id, name, password);

				//��ָ�봫������ĺ���
				teacherMenu(p);
				//�˳���ʦ��½�����,ֱ�ӷ������˵�,��ִ���������
				return;
			}
			else
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				ifs.close(); //�ر��ļ�
				system("pause");
				system("cls");

				//�����ָ��ָ�������ڶ������ٵĿռ�,�������вι���
				p = new Manager(id, name, password);

				//��ָ�봫������ĺ���
				managerMenu(p);

				//�˳�����Ա��½�����,ֱ�ӷ������˵�,��ִ���������
				return;
			}
		}
	}

	//��֤��¼ʧ��
	cout << error_Tip << endl;
	ifs.close(); //�ر��ļ�
	system("pause");
	system("cls");
	return;
}

//����Ա��¼����
void managerMenu(Person*& p)
{
	//���ù���Ա�˵�����
	//p->operMenu();

	//��person���͵�ָ��pǿתΪmanager,����p������Ϊman
	/*Person* p=NULL;
	p=new Student(id,name);
	Student* s=(Student*)p;
	��δ����У����ȶ�����һ��ָ�� Person ������ָ�� p���������ʼ��Ϊ NULL��
	Ȼ��ͨ�� new ������ڶ��ϴ���һ�� Student ��Ķ��󣬲�����ָ�븳ֵ�� p��
	���� Student ���� Person ������࣬��˿��Խ� Student ����ָ����ʽ��ת��Ϊ Person ����ָ�룬
	���� Student �����ĵ�ַ��ֵ��ָ�� Person ������ָ�롣

	��������������һ��ָ�� Student ������ָ�� s������ p ָ����ָ��Ķ���ǿ������ת��Ϊ Student ����ָ�����ͣ������丳ֵ�� s��
	���ǿ������ת�����Խ�һ��ָ���������ָ��ת����ָ������������ָ�룬
	������Ҫע����ǣ�ֻ���ڻ���ָ��ʵ��ָ��Ķ��������������ʱ�����ܰ�ȫ�ؽ���ת��Ϊ������ָ�룬
	��������� undefined behavior����ˣ��ڽ���ǿ������ת��ʱ��Ӧ�����ж�ָ����ָ��Ķ�������ͣ���ȷ��ת���İ�ȫ�ԡ�*/
	Manager* man = (Manager*)p;

	int select;
	
	while (true)
	{
		//���ù���Ա�˵�����
		man->operMenu();

		cin >> select;

		switch (select)
		{
		case 1: //����˺�
			man->addPerson();
			break;

		case 2: //�鿴�˺�
			man->showPerson();
			break;

		case 3: //�鿴���� 
			man->showComputer();
			break;

		case 4: //���ԤԼ
			man->cleanFile();
			break;

		case 0: //ע����¼
			man->exitManager(man->name);
			//ɾ�������Ĺ���Ա����
			delete(man);
			return; //������һ���˵�

		default: //����
			cout << "��������,����������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//ѧ����¼����
void studentMenu(Person*& p)
{
	//����ѧ���˵�����
	//p->operMenu();

	//��person���͵�ָ��pǿתΪStudent,����p������Ϊman
	/*Person* p=NULL;
	p=new Student(id,name);
	Student* s=(Student*)p;
	��δ����У����ȶ�����һ��ָ�� Person ������ָ�� p���������ʼ��Ϊ NULL��
	Ȼ��ͨ�� new ������ڶ��ϴ���һ�� Student ��Ķ��󣬲�����ָ�븳ֵ�� p��
	���� Student ���� Person ������࣬��˿��Խ� Student ����ָ����ʽ��ת��Ϊ Person ����ָ�룬
	���� Student �����ĵ�ַ��ֵ��ָ�� Person ������ָ�롣

	��������������һ��ָ�� Student ������ָ�� s������ p ָ����ָ��Ķ���ǿ������ת��Ϊ Student ����ָ�����ͣ������丳ֵ�� s��
	���ǿ������ת�����Խ�һ��ָ���������ָ��ת����ָ������������ָ�룬
	������Ҫע����ǣ�ֻ���ڻ���ָ��ʵ��ָ��Ķ��������������ʱ�����ܰ�ȫ�ؽ���ת��Ϊ������ָ�룬
	��������� undefined behavior����ˣ��ڽ���ǿ������ת��ʱ��Ӧ�����ж�ָ����ָ��Ķ�������ͣ���ȷ��ת���İ�ȫ�ԡ�*/
	Student* stu = (Student*)p;

	int select;

	while (true)
	{
		//���ù���Ա�˵�����
		stu->operMenu();

		cin >> select;

		switch (select)
		{
		case 1: //����ԤԼ
			stu->applyOrder();
			break;

		case 2: //�鿴�ҵ�ԤԼ
			stu->showMyOrder();
			break;

		case 3: //�鿴����ԤԼ 
			stu->showAllOrder();
			break;

		case 4: //ȡ��ԤԼ
			stu->cancelOrder();
			break;

		case 0: //ע����¼
			stu->exitStudent(stu->name);
			//ɾ��������ѧ������
			delete(stu);
			return; //������һ���˵�

		default: //����
			cout << "��������,����������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//��ʦ��¼����
void teacherMenu(Person*& p)
{
	//������ʦ�˵�����
	//p->operMenu();

	//��person���͵�ָ��pǿתΪStudent,����p������Ϊman
	/*Person* p=NULL;
	p=new Student(id,name);
	Student* s=(Student*)p;
	��δ����У����ȶ�����һ��ָ�� Person ������ָ�� p���������ʼ��Ϊ NULL��
	Ȼ��ͨ�� new ������ڶ��ϴ���һ�� Student ��Ķ��󣬲�����ָ�븳ֵ�� p��
	���� Student ���� Person ������࣬��˿��Խ� Student ����ָ����ʽ��ת��Ϊ Person ����ָ�룬
	���� Student �����ĵ�ַ��ֵ��ָ�� Person ������ָ�롣

	��������������һ��ָ�� Student ������ָ�� s������ p ָ����ָ��Ķ���ǿ������ת��Ϊ Student ����ָ�����ͣ������丳ֵ�� s��
	���ǿ������ת�����Խ�һ��ָ���������ָ��ת����ָ������������ָ�룬
	������Ҫע����ǣ�ֻ���ڻ���ָ��ʵ��ָ��Ķ��������������ʱ�����ܰ�ȫ�ؽ���ת��Ϊ������ָ�룬
	��������� undefined behavior����ˣ��ڽ���ǿ������ת��ʱ��Ӧ�����ж�ָ����ָ��Ķ�������ͣ���ȷ��ת���İ�ȫ�ԡ�*/
	Teacher* tea = (Teacher*)p;

	int select;

	while (true)
	{
		//���ù���Ա�˵�����
		tea->operMenu();

		cin >> select;

		switch (select)
		{
		case 1: //�鿴����ԤԼ
			tea->showAllOrder();
			break;

		case 2: //���ԤԼ
			tea->validOrder();
			break;

		case 0: //ע����¼
			tea->exitTeacher(tea->name);
			//ɾ����������ʦ����
			delete(tea);
			return; //������һ���˵�

		default: //����
			cout << "��������,����������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}