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
		//数值调整
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
	//char path[50] = "Resource/Picture/Monster/1/walk0.png";//图像路径
	//char pathMask[50] = "Resource/Picture/Monster/1/walk1.png";//图像掩码图路径
	//第一行左上角，65，70，中轴95
	//8张
	//x:65-1475,y:70-720
	//r:30,
	//gap;192.8571

	//移动图像属性,通用
	double imgx = 30, imgy = 40;
	int frames = 8;//图像数量
	double gapx = 192;//图像间x的间隙
	double gapy = 194;//图像间y的间隙
	int index;
	double imager = 60;//贴图的半径

	double imgxA, imgyA;
	int framesA;//图像数量
	double gapxA;//图像间x的间隙
	double gapyA;//图像间y的间隙
	int indexA;
	double imagerA;//贴图的半径

	double bgx = 0, bgy = 0;//移动时背景的坐标
	int direction;//移动方向

	double x, y;//图像开始坐标
	int r;//半径

	int HP;//血量
	double HPb;//战斗过程中的HP
	bool alive=true;//是否存活
	int ATK;//攻击力
	double AR;//攻击范围
	double ASD;//攻击速度
	double SD;//移动速度
	bool attack = false;//是否为攻击状态
	int level;
	CResource *resMo;

	double* Move(double *pv, double* pMonsterxy, vector<CMonster*>& moster);
	void Attack(int x, int y, int r);//自动攻击
	void Draw();
	bool Hurt(double* attack, bool* isattack);//受伤减少HP，死亡随机掉落装备,
	bool isOverlap(const CMonster& other) const;
	void Super();
	string name[7] = { "打卡","直播","开会","立项" ,"项目设计" ,"分工开发" ,"分工开发-debug" };
};

