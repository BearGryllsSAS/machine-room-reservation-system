#pragma once
#include"Person.h" //�����Լ�д��ͷ�ļ�ʱ,Ҫ��""������<>
#include"Teacher.h"
#include"Student.h"
#include"Computer.h"
#include<vector>
//using namespace std; //������.hͷ�ļ���Ҫд,���ܻ����

//ͨ������£�#pragma onceӦ�÷���ͷ�ļ����ʼ��#includeָ��Ӧ�÷���#pragma once֮��
/*�������ͷ�ļ��в���Ҫ�ٴΰ���iostream����Ϊ���Ѿ��������ڸ����ͷ�ļ����ˡ�
������̳и���ʱ��������Զ��̳и�������г�Ա��ͷ�ļ�������ϵ��
��������ͷ�ļ����ٴΰ���iostream���ᵼ���ظ����������ܻ���ֱ������*/

//ͷ�ļ���������Ա��,�̳�Person,��Դ�ļ�,д����ʵ��
class Manager :public Person
{
public:
	//���캯������������
	Manager();
	Manager(int id, std::string name, std::string password);
	~Manager();

	//��д���������,չʾ�˵�����
	virtual void operMenu(); //virtual��д�ɲ�д

	/*����Ա���幦�ܵĺ�������*/

	//����˺�-- - ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
	void addPerson();

	//�鿴�˺�-- - ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
	void showPerson();

	//�鿴����-- - �鿴���л�������Ϣ
	void showComputer();

	//���ԤԼ-- - �������ԤԼ��¼
	void cleanFile();

	//ע����¼-- - �˳���¼
	void exitManager(std::string name);

	/* ȥ�ز���*/
  
	/*ȥ�ز���
	����������������˺�ʱ��������ظ���ѧ����ţ������ظ��Ľ�ʦְ����ţ���ʾ����
	��ȡ��Ϣ
	Ҫȥ���ظ����˺ţ�����Ҫ�Ƚ�ѧ���ͽ�ʦ���˺���Ϣ��ȡ�������У����ɼ��*/
	//*��manager.h�У�����������������ڴ��ѧ���ͽ�ʦ����Ϣ
	//Ӧ�ý�������������˽��Ȩ���µ�,�����Ȳ���
	std::vector<Teacher> v_Tea; //����std:: ���������ᱨ��
	std::vector<Student> v_Stu;

	//*���һ���µĳ�Ա����  `void initVector()` ��ʼ������
	void initVector();

	//���һ��int���͵ĺ���,�����ж��ļ����Ƿ��Ѿ���Ҫ��ӵ�id
	//���ڷ���true �����ڷ���false
	int repeat(std::string fileName, int select, int id);

	//���һ������,���ڴ�Ż�����Ϣ
	std::vector<Computer> v_Com;
};