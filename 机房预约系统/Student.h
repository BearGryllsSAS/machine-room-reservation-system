#pragma once
#include"Person.h" //�����Լ�д��ͷ�ļ�ʱ,Ҫ��""������<>
#include"Computer.h"
#include<vector>
//using namespace std; //������.hͷ�ļ���Ҫд,���ܻ����

//ͨ������£�#pragma onceӦ�÷���ͷ�ļ����ʼ��#includeָ��Ӧ�÷���#pragma once֮��
/*�������ͷ�ļ��в���Ҫ�ٴΰ���iostream����Ϊ���Ѿ��������ڸ����ͷ�ļ����ˡ�
������̳и���ʱ��������Զ��̳и�������г�Ա��ͷ�ļ�������ϵ��
��������ͷ�ļ����ٴΰ���iostream���ᵼ���ظ����������ܻ���ֱ������*/

//ͷ�ļ�����ѧ����,�̳�Person��Դ�ļ�,д����ʵ��
class Student :public Person
{
public:
	//���캯������������
	Student();
	Student(int id, std::string name, std::string password);
	~Student();
	
	//��д���������,չʾ�˵�����
	virtual void operMenu(); //��д���������,չʾ�˵�����
	
	/*ѧ�����幦��*/
	//����ԤԼ-- - ԤԼ����
	void applyOrder();
	
	//�鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬
	void showMyOrder();
	
	//�鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void showAllOrder();
	
	//ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
	void cancelOrder();
	
	//ע����¼-- - �˳���¼
	void exitStudent(std::string name);

	//����һ������,���ڴ�Ż�����Ϣ
	std::vector<Computer> v_Com;
	//��ʼ�����������ĺ���
	void initVector();
};