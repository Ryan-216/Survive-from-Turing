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
	//考虑贴图
	//CHero(IMAGE path[4],int x1,int y1,int allImgWidth1, int imgwidth1, int imgHeight1,int frames1,int gap1, 
	//	int HP1,int ATK1,int ASD1, int SD1)
	//暂不考虑贴图



	CHero(int choice1,int level1,CResource* res)
	{
		r = 30;
		//数值调整
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
			{"核心语法", "面向对象", "常用API", "集合框架", "I/O", "多线程","异常","开发实用", "JDK8新特性"},
			{"编程基础","基础语法","函数","数组","指针","内存管理","文件操作","标准库函数","实际应用" },
			{"基础语法", "类和对象", "内存管理", "模板", "IO流", "继承多态", "异常", "智能指针", "STL"}
		};
		weaponname = nameall[choice1][level1];

	}
	int type;

	CResource* resH;


	
	//移动图像属性,通用
	double imgx = 30, imgy = 40;
	int frames=8;//图像数量
	double gapx=192;//图像间x的间隙
	double gapy = 194;//图像间y的间隙
	int index;
	double imager=60;//贴图的半径
	//攻击图像属性
	//长枪,中心点(95,108)
	//double imgxA = 0, imgyA = 13;
	//int framesA = 7;//图像数量
	//double gapxA = 193;//图像间x的间隙
	//double gapyA = 195;//图像间y的间隙
	//int indexA;
	//double imagerA =95;//贴图的半径
	//刀剑
	//double imgxA = 35, imgyA = 48;
	//int framesA = 5;//图像数量
	//double gapxA = 193;//图像间x的间隙
	//double gapyA = 195;//图像间y的间隙
	//int indexA;
	//double imagerA =60;//贴图的半径
	double imgxA, imgyA;
	int framesA;//图像数量
	double gapxA;//图像间x的间隙
	double gapyA;//图像间y的间隙
	int indexA;
	double imagerA;//贴图的半径


	double bgx=0, bgy=0;//移动时背景的坐标
	int direction;//移动方向
	
	double r;//体积半径
	int HP;//血量
	double HPb;//战斗时血量
	bool alive;//是否存活
	int ATK;//攻击力
	double AR;//攻击范围
	double ASD;//攻击速度
	double SD;//移动速度
	int EXP;
	int level=0;
	string weaponname;

	bool attack=false;//是否为攻击状态

	double* Move(ExMessage& m, double* pBgv);
	//void Attack();//自动攻击，传入怪物类
	void Draw();
	bool Hurt(double* pMonsterxyr, double* attack, bool* isattack);
	bool Pick(CWeapon w,double x, double y);
	void LevelUp(int choice1);

};

