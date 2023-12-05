#include"CWeapon.h"
#include"CResource.h"
#include"CFunction.h"
#include<easyx.h>
#include<cmath>
#include<time.h>
#pragma once
using namespace std;

class CHero
{
public:
	//������ͼ
	//CHero(IMAGE path[4],int x1,int y1,int allImgWidth1, int imgwidth1, int imgHeight1,int frames1,int gap1, 
	//	int HP1,int ATK1,int ASD1, int SD1)
	//�ݲ�������ͼ



	CHero(int choice1,int level1,CResource* res)
	{
		r = 30;
		//��ֵ����
		HP = 200 + 110 * level1;
		HPb = HP;
		ATK= 20 + 15 * level1;
		AR = 10;
		ASD= 2 + 0.3 * level1;
		SD = 0.6 + 0.1 * level1;
		alive = true;

		resH = res;
		type = choice1;	
		level = level1;
		EXP = 0;

		if (level < 4)
		{
			imgxA = 35, imgyA = 48;
			framesA = 5;
			gapxA = 193;
			gapyA = 195;
			imagerA = 60;
			AR = 40;
		}
		else
		{
			imgxA = 0, imgyA = 13;
			framesA = 7;
			gapxA = 193;
			gapyA = 195;
			imagerA = 95;
			AR = 60;
		}
		string nameall[3][9] =
		{
			{"�����﷨", "�������", "����API", "���Ͽ��", "I/O", "���߳�","�쳣","����ʵ��", "JDK8������"},
			{"��̻���","�����﷨","����","����","ָ��","�ڴ����","�ļ�����","��׼�⺯��","ʵ��Ӧ��" },
			{"�����﷨", "��Ͷ���", "�ڴ����", "ģ��", "IO��", "�̳ж�̬", "�쳣", "����ָ��", "STL"}
		};
		weaponname = nameall[choice1][level1];

	}
	int type;

	CResource* resH;


	
	//�ƶ�ͼ������,ͨ��
	double imgx = 30, imgy = 40;
	int frames=8;//ͼ������
	double gapx=192;//ͼ���x�ļ�϶
	double gapy = 194;//ͼ���y�ļ�϶
	int index;
	double imager=60;//��ͼ�İ뾶
	//����ͼ������
	//��ǹ,���ĵ�(95,108)
	//double imgxA = 0, imgyA = 13;
	//int framesA = 7;//ͼ������
	//double gapxA = 193;//ͼ���x�ļ�϶
	//double gapyA = 195;//ͼ���y�ļ�϶
	//int indexA;
	//double imagerA =95;//��ͼ�İ뾶
	//����
	//double imgxA = 35, imgyA = 48;
	//int framesA = 5;//ͼ������
	//double gapxA = 193;//ͼ���x�ļ�϶
	//double gapyA = 195;//ͼ���y�ļ�϶
	//int indexA;
	//double imagerA =60;//��ͼ�İ뾶
	double imgxA, imgyA;
	int framesA;//ͼ������
	double gapxA;//ͼ���x�ļ�϶
	double gapyA;//ͼ���y�ļ�϶
	int indexA;
	double imagerA;//��ͼ�İ뾶


	double bgx=0, bgy=0;//�ƶ�ʱ����������
	int direction;//�ƶ�����
	
	double r;//����뾶
	int HP;//Ѫ��
	double HPb;//ս��ʱѪ��
	bool alive;//�Ƿ���
	int ATK;//������
	double AR;//������Χ
	double ASD;//�����ٶ�
	double SD;//�ƶ��ٶ�
	int EXP;
	int level=0;
	string weaponname;

	bool attack=false;//�Ƿ�Ϊ����״̬

	double* Move(ExMessage& m, double* pBgv);
	//void Attack();//�Զ����������������
	void Draw();
	bool Hurt(double* pMonsterxyr, double* attack, bool* isattack);
	bool Pick(CWeapon w,double x, double y);
	void LevelUp(int choice1);

};

