#include<easyx.h>
#include"CFunction.h"
#include"CResource.h"
#include"cmath"
#include<iostream>
#include<time.h>
#include"CWeapon.h"
#include<vector>
#pragma once
using namespace std;

class CMonster
{
public:
	CMonster(double x1, double y1, int level1,CResource* res)
	{
		x = x1;
		y = y1;
		r = 30;
		//��ֵ����
		if (level < 5)
		{
			HP = 50 + 50 * level1;
			HPb = HP;
			ATK = 10 + 10 * level1;
			ASD = 2 + 0.15 * level1;
			SD = 0.4 + 0.1 * level1;
		}
		else if (level == 5)
		{
			HP = 2000;
			HPb = HP;
			ATK = 20;
			ASD = 1;
			SD = 1;
		}
		alive = true;

		resMo = res;

		level = level1;

		if (level < 3)
		{
			imgxA = 35, imgyA = 48;
			framesA = 5;
			gapxA = 193;
			gapyA = 195;
			imagerA = 60;
			AR = 30;
		}
		else
		{
			imgxA = 0, imgyA = 13;
			framesA = 7;
			gapxA = 193;
			gapyA = 195;
			imagerA = 95;
			AR = 30;
		}
	}
public:
	//char path[50] = "Resource/Picture/Monster/1/walk0.png";//ͼ��·��
	//char pathMask[50] = "Resource/Picture/Monster/1/walk1.png";//ͼ������ͼ·��
	//��һ�����Ͻǣ�65��70������95
	//8��
	//x:65-1475,y:70-720
	//r:30,
	//gap;192.8571

	//�ƶ�ͼ������,ͨ��
	double imgx = 30, imgy = 40;
	int frames = 8;//ͼ������
	double gapx = 192;//ͼ���x�ļ�϶
	double gapy = 194;//ͼ���y�ļ�϶
	int index;
	double imager = 60;//��ͼ�İ뾶

	double imgxA, imgyA;
	int framesA;//ͼ������
	double gapxA;//ͼ���x�ļ�϶
	double gapyA;//ͼ���y�ļ�϶
	int indexA;
	double imagerA;//��ͼ�İ뾶

	double bgx = 0, bgy = 0;//�ƶ�ʱ����������
	int direction;//�ƶ�����

	double x, y;//ͼ��ʼ����
	int r;//�뾶

	int HP;//Ѫ��
	double HPb;//ս�������е�HP
	bool alive=true;//�Ƿ���
	int ATK;//������
	double AR;//������Χ
	double ASD;//�����ٶ�
	double SD;//�ƶ��ٶ�
	bool attack = false;//�Ƿ�Ϊ����״̬
	int level;
	CResource *resMo;

	double* Move(double *pv, double* pMonsterxy, vector<CMonster*>& moster);
	void Attack(int x, int y, int r);//�Զ�����
	void Draw();
	bool Hurt(double* attack, bool* isattack);//���˼���HP�������������װ��,
	bool isOverlap(const CMonster& other) const;
	void Super();
	string name[7] = { "��","ֱ��","����","����" ,"��Ŀ���" ,"�ֹ�����" ,"�ֹ�����-debug" };
};

