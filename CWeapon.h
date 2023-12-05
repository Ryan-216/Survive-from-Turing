#pragma once
#include<graphics.h>
#include"CResource.h"
using namespace std;

class CWeapon
{
public:
	CWeapon()
	{

	}

	CWeapon(int AR1, int ATK1, int ASD1, double SD1,int choice,int level1, CResource* res)
	{
		AR = AR1;
		ATK = ATK1;
		ASD = ASD1;
		SD = SD1;
		level = level1;
		resW = res;
		string nameall[3][9] =
		{
			{"�����﷨", "�������", "����API", "���Ͽ��", "I/O", "���߳�","�쳣","����ʵ��", "JDK8������"},
			{"��̻���","�����﷨","����","����","ָ��","�ڴ����","�ļ�����","��׼�⺯��","ʵ��Ӧ��" },
			{"�����﷨", "��Ͷ���", "�ڴ����", "ģ��", "IO��", "�̳ж�̬", "�쳣", "����ָ��", "STL"}
		};
		name = nameall[choice][level1];
	}
	int ATK;//������
	int AR;//Ѫ��
	int ASD;//�����ٶ�
	double SD;//�ƶ��ٶ�
	int level;
	string name;
	CResource* resW;
	void DrawWeapon(int x, int y);
};

