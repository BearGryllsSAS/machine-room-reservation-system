#pragma once
#include "Person.h" //�����Լ�д��ͷ�ļ�ʱ,Ҫ��""������<>
//using namespace std; //������.hͷ�ļ���Ҫд,���ܻ����

//ͨ������£�#pragma onceӦ�÷���ͷ�ļ����ʼ��#includeָ��Ӧ�÷���#pragma once֮��
/*�������ͷ�ļ��в���Ҫ�ٴΰ���iostream����Ϊ���Ѿ��������ڸ����ͷ�ļ����ˡ�
������̳и���ʱ��������Զ��̳и�������г�Ա��ͷ�ļ�������ϵ��
��������ͷ�ļ����ٴΰ���iostream���ᵼ���ظ����������ܻ���ֱ������*/


//ͷ�ļ�������ʦ��,�̳�Person.��Դ�ļ�,д����ʵ��
class Teacher :public Person
{
public:
	//���캯������������
	Teacher();
	Teacher(int id, std::string name, std::string password);
	~Teacher();

	//��д���������,չʾ�˵�����
	virtual void operMenu(); 

	/*��ʦ���幦��*/
	//�鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void showAllOrder();
	
	//���ԤԼ-- - ��ѧ����ԤԼ�������
	void validOrder();
	
	//ע����¼-- - �˳���¼
	void exitTeacher(std::string name);
};

