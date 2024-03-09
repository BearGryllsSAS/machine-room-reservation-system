#include"OrderFile.h"
#include"GlobalFile.h"
#include<fstream>
using namespace std;


OrderFile::OrderFile()
{
	/*�ղι����������ÿ�δ���OerderFile����ʱ,���ö����е�map��ʼ��,
	�����ļ��ж�ȡ��Ϣ,���µ�map��.ͬʱ����Ϣ�����޸�,
	��Ϊһ��ʼ��������ʱ"ѧ��:1"��������ʽ,����Ҫ�����ֿ�Ϊ"ѧ��" "1"(ȥ��ʡ�Ժ�)
	key�з�"ѧ��" value�з�"1" �����Ϳ���ͨ��key�ҵ�value
	*/

	//��������� ??�ݶ�,Ҳ����(��)
	this->m_Order.clear();

	//��Ҫ��ȡ��ԤԼ�ļ�
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << ORDER_FILE << "��ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string id; //ѧ��
	string name; //����
	string date; //ʱ��
	string time; //ʱ���
	string computerRoom; //����
	string status; //״̬

	//��ʼ��ԤԼ����Ϊ0
	this->orderCount = 0;

	//����һ��map����,��Ŵ��ļ��ж�ȡ�����ļ�ֵ��
	map<string, string> m;
	//����ȡ��������Ϣ�ָ�,�ֱ�ŵ�key value��,�ٷ���m��,�����ͬorderCount�����map��
	string key;
	string value;
	int pos = -1;
	
	while (ifs >> id && ifs >> name && ifs >> date && ifs >> time && ifs >> computerRoom && ifs >> status)
	{
		//�����Ƿ��ܽ���Ϣ�ó���
		//cout << id << " " << name << " " << date << " " << time << " " << computerRoom << " " << status << endl;

		//ÿһ�ֶ��������m����,��ֹ��һ�ֲ������´�map��������
		m.clear();

		//id ѧ��:1
		//�ҵ�":"��λ��
		pos = id.find(":"); //�ַ�����λ��������0��ʼ
		if (pos == -1)
		{
			cout << "id����!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//���нض�
		key = id.substr(0, pos); //���±�Ϊ0��ʼ,��ȡ����Ϊpos+1���ַ���
		value = id.substr(pos + 1); //����Ϊpos+1��ʼ,��ȡ��ĩβ
		//��id����Ϣ����m��
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); ��һ�ֲ��뷽��
		//m.insert(key) ֻ�������ֵ

		//�����ȸ���ճ��,�Ժ���Զ��庯��


		//name ����:zhangsan
		//�ҵ�":"��λ��
		pos = name.find(":"); //�ַ�����λ��������0��ʼ
		if (pos == -1)
		{
			cout << "name����!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//���нض�
		key = name.substr(0, pos); //���±�Ϊ0��ʼ,��ȡ����Ϊpos+1���ַ���
		value = name.substr(pos + 1); //����Ϊpos+1��ʼ,��ȡ��ĩβ
		//��id����Ϣ����m��
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); ��һ�ֲ��뷽��
		//m.insert(key) ֻ�������ֵ


		//date ʱ��:��һ
		//�ҵ�":"��λ��
		pos = date.find(":"); //�ַ�����λ��������0��ʼ
		if (pos == -1)
		{
			cout << "date����!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//���нض�
		key = date.substr(0, pos); //���±�Ϊ0��ʼ,��ȡ����Ϊpos+1���ַ���
		value = date.substr(pos + 1); //����Ϊpos+1��ʼ,��ȡ��ĩβ
		//��id����Ϣ����m��
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); ��һ�ֲ��뷽��
		//m.insert(key) ֻ�������ֵ


		//time ʱ���:����
		//�ҵ�":"��λ��
		pos = time.find(":"); //�ַ�����λ��������0��ʼ
		if (pos == -1)
		{
			cout << "time����!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//���нض�
		key = time.substr(0, pos); //���±�Ϊ0��ʼ,��ȡ����Ϊpos+1���ַ���
		value = time.substr(pos + 1); //����Ϊpos+1��ʼ,��ȡ��ĩβ
		//��id����Ϣ����m��
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); ��һ�ֲ��뷽��
		//m.insert(key) ֻ�������ֵ


		//computerRoom ����:1
		//�ҵ�":"��λ��
		pos = computerRoom.find(":"); //�ַ�����λ��������0��ʼ
		if (pos == -1)
		{
			cout << "computerRoom����!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//���нض�
		key = computerRoom.substr(0, pos); //���±�Ϊ0��ʼ,��ȡ����Ϊpos+1���ַ���
		value = computerRoom.substr(pos + 1); //����Ϊpos+1��ʼ,��ȡ��ĩβ
		//��id����Ϣ����m��
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); ��һ�ֲ��뷽��
		//m.insert(key) ֻ�������ֵ


		//status ״̬:�����
		//�ҵ�":"��λ��
		pos = status.find(":"); //�ַ�����λ��������0��ʼ
		if (pos == -1)
		{
			cout << "status����!" << endl;
			system("pause");
			system("cls");
			return;
		}
		//���нض�
		key = status.substr(0, pos); //���±�Ϊ0��ʼ,��ȡ����Ϊpos+1���ַ���
		value = status.substr(pos + 1); //����Ϊpos+1��ʼ,��ȡ��ĩβ
		//��id����Ϣ����m��
		m.insert(make_pair(key, value));
		//m.insert({ key,value }); ��һ�ֲ��뷽��
		//m.insert(key) ֻ�������ֵ


		//��count��m�����map��
		this->m_Order.insert(make_pair(this->orderCount, m));

		//ԤԼ����++
		this->orderCount++;

	}

	//�ر��ļ�,�ǳ���Ҫ
	ifs.close();

	return;
	//����map�Ƿ��ж���
	/*for (map<int, map<string, string>>::iterator it = m_Order.begin(); it != m_Order.end(); it++)
	{
		cout << "value:" << it->first << endl;

		for (map<string, string>::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
		{
			cout << itt->first << ":" << itt->second << " ";

		}
		
		cout << endl;
		cout << endl;
	}*/

}

//��map�е���Ϣд���ļ���
void OrderFile::updateOrder()
{
	/*�Ժ����ԤԼ�ʹ���OrderFile����,���ö����map,ֱ���޸�statusֵ,�����˵�ͬʱҪ�����ļ�*/


	//������û�м�¼
	if (this->orderCount == 0)
	{
		cout << "��ǰ������û��ԤԼ,�޷�д���ļ�!" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //trunc ���ļ�������Ϣ,��ɾ��
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "��ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�������е���Ϣд���ļ���
	for (int i = 0; i < this->orderCount; i++)
	{
		//ͨ��key�ҵ�value
		ofs << "ѧ��:" << this->m_Order[i]["ѧ��"] << " ";
		ofs << "����:" << this->m_Order[i]["����"] << " ";
		ofs << "ʱ��:" << this->m_Order[i]["ʱ��"] << " ";
		ofs << "ʱ���:" << this->m_Order[i]["ʱ���"] << " ";
		ofs << "����:" << this->m_Order[i]["����"] << " ";
		ofs << "״̬:" << this->m_Order[i]["״̬"] << endl;
	}
		
	//�ر��ļ�
	ofs.close();

	return;
}

//���ԤԼ��¼
void OrderFile::clearOrder()
{
	//����Ա����,�����������ԤԼ

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //trunc ���ļ�������Ϣ,��ɾ��
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "��ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�ر��ļ�
	ofs.close();

	return;
}