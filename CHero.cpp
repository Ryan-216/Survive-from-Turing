#include "CHero.h"
#include<cmath>
using namespace std;
#define PI 3.1415926
#define MyBlue RGB(78,129,197)
CFunction funH;

/*英雄移动-核心
	负责人:
	功能: 
	1.接收按键消息
	2.判断按键内容
	while(true)
	{
		if (按下)
		{			
			switch (m.vkcode)
			{
			//判断按键内容
			//反馈
			}
		}
		坐标变化
	}
	
	参数: void
	返回值: void
*/

static double Mousex ;
static double Mousey ;
double* CHero::Move(ExMessage &m,double* pBgv)
{
	if (peekmessage(&m, EX_MOUSE)) {}
	Mousex = m.x;
	Mousey = m.y;
	double x1 = resH->centerx + 100, y1 = resH->centery;
	double L2x = pow((Mousex - resH->centerx), 2)+ pow((Mousey - resH->centery), 2);
	double L2m = pow((x1 - resH->centerx), 2) + pow((y1 - resH->centery), 2);
	double L2c = pow((x1 - Mousex), 2) + pow((y1 - Mousey), 2);
	double cosc;
	if (L2x * L2m != 0)
	{
		cosc = (L2x + L2m - L2c) / (2 * sqrt(L2x * L2m));
	}
	else
	{
		cosc = 0;
	}
	double angle = acos(cosc);//计算夹角，0-180
	if (Mousey <= resH->centery) angle = 2 * PI - angle;
	if (angle >= PI / 4 && angle < (3 * PI) / 4) direction = 3;//下
	else if (angle >= (3 * PI) / 4 && angle < (5 * PI) / 4) direction = 2;//左
	else if (angle >= (5 * PI) / 4 && angle < (7 * PI) / 4) direction = 1;//上
	else direction = 4;//右


	
	if (bgx >= resH->centerx)
	{
		bgx = resH->centerx; 
		pBgv[0] = 0, pBgv[1] = -SD * sin(angle);
		if (bgx ==resH->centerx && direction == 4)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else if (bgx <= resH->centerx - resH->bgWidthw)
	{
		bgx = resH->centerx - resH->bgWidthw;
		pBgv[0] = 0, pBgv[1] = -SD * sin(angle);
		if (bgx == resH->centerx-resH->bgWidthw && direction == 2)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else if (bgy >= resH->centery)
	{
		bgy = resH->centery;
		pBgv[0] = -SD * cos(angle),pBgv[1] = 0;
		if (bgy == resH->centery && direction == 3)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else if (bgy <= resH->centery - resH->bgHeightw + r) 
	{
		bgy = resH->centery - resH->bgHeightw + r;
		pBgv[0] = -SD * cos(angle),pBgv[1] = 0;
		if (bgy == resH->centery - resH->bgHeightw + r && direction == 1)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else 
	{
		bgx -= SD * cos(angle);
		bgy -= SD * sin(angle);
		pBgv[0] = -SD * cos(angle);
		pBgv[1] = -SD * sin(angle);
		pBgv[2] = bgx;
		pBgv[3] = bgy;
		
	}
	return pBgv;
}

/*英雄攻击-核心
	负责人:
	功能: 
	while(true)
	{
		画出攻击范围
		if (攻击范围与怪物碰撞)
		{
			cm.Hert();
		}
		坐标变化
	}
	参数: 攻击目标（怪物）的类
	返回值: void
*/
//void CHero::Attack()

	//确定攻击范围
	//判断是否在范围内
	//怪物周期性掉血



/*画英雄-核心
	负责人:
	功能: 
	1.调用窗口参数，计算中心坐标
	2.画圆
	参数: void
	返回值: void
*/
void CHero::Draw()
{
	int speed = 50;
	//圆
	if (alive)
	{
		//setfillcolor(MyBlue);//画模型
		//solidcircle(resH->centerx, resH->centery, r);
		//setlinecolor(RED);//画攻击范围
		//circle(resH->centerx, resH->centery, AR);
		double HPx = 50 + 100 * (HPb / HP);
		
		setfillcolor(MyBlue);
		fillrectangle(0, 10, 200, 160);
		setfillcolor(WHITE);
		solidroundrect(50, 20, 150, 30, 10, 10);//画血条
		setfillcolor(RED);
		solidroundrect(50, 20, HPx, 30, 10, 10);//画血条
		char s1[50];
		sprintf(s1, "攻 击 力：%d", ATK);
		char s2[50];
		sprintf(s2, "攻击范围：%.lf",AR);
		char s3[50];
		sprintf(s3, "攻击速度：%.lf", ASD);
		char s4[50];
		sprintf(s4, "移动速度：%.1f", SD);
		char s5[50];
		sprintf(s5, "经 验 值：%d", EXP);
		char s6[50];
		sprintf(s6, "%d", HP);
		char s7[50];
		const char* s8 = weaponname.data();
		sprintf(s7, "学习进度：%s", s8);
		outtextxy(10, 15, "血量：");
		outtextxy(160, 15, s6);
		outtextxy(50, 30, s1);
		outtextxy(50, 50, s2);
		outtextxy(50, 70, s3);
		outtextxy(50, 90, s4);
		outtextxy(50, 110, s5);
		outtextxy(30, 130, s7);

		if (!attack)
		{	
			//英雄移动
			putimage(resH->centerx - imager, resH->centery - imager, 2 * imager, 2 * imager, &resH->imageH[type][level][1], imgx + gapx * index, imgy + (direction - 1) * gapy, NOTSRCERASE);
			putimage(resH->centerx - imager, resH->centery - imager, 2 * imager, 2 * imager, &resH->imageH[type][level][0], imgx + gapx * index, imgy + (direction - 1) * gapy, SRCINVERT);
		}
		else
		{
			//英雄攻击
			putimage(resH->centerx - imagerA, resH->centery - imagerA, 2 * imagerA, 2 * imagerA, &resH->imageHA[type][level][1], imgxA + gapxA * indexA, imgyA + (direction - 1) * gapyA, NOTSRCERASE);
			putimage(resH->centerx - imagerA, resH->centery - imagerA, 2 * imagerA, 2 * imagerA, &resH->imageHA[type][level][0], imgxA + gapxA * indexA, imgyA + (direction - 1) * gapyA, SRCINVERT);
		}
		index = (clock() / speed) % frames;
		indexA = (clock() / speed) % framesA;
	}
	
}

/*受伤判断-核心
	负责人:
	功能: 
	if(HP>0)
	{
		HP减少
	}
	else
	{
		角色死亡，调用结算函数
	}
	参数: void
	返回值: void
*/
bool CHero::Hurt(double*pMonsterxyr ,double* attack, bool* isattack)
{
	//血量判断，>0则减少，<=0则死亡
	//调用结算
	if (funH.IsCrash(pMonsterxyr[0], pMonsterxyr[1], attack[1], resH->centerx, resH->centery, r))
	{
		*isattack = true;
		int gameTime = clock()/10;//第gameTime10毫秒
		int attackTime = 100 / attack[2];//多少个10毫秒攻击一次
		if (gameTime % attackTime == 0 && (HPb > 0) && attack[3] >= 3)
		{
			HPb -= attack[0];
			return true;
		}
		else if (HPb <= 0)
		{
			alive = false;
			return false;
		}
	}
}

/*拾取装备-核心
	负责人:
	功能: 
	if(装备和英雄 体积碰撞)
	{
		属性修改
		装备消失
	}
	参数: void
	返回值: void
*/
bool CHero::Pick(CWeapon w,double x,double y)
{
	//判断体积是否碰撞
	//碰撞则属性叠加，装备消失
	if (funH.IsCrash(resH->centerx, resH->centery, r, x, y, 20)&& level<8)
	{
		EXP +=pow(2,w.level+2);
		if ((EXP > pow(2, level + 3))||w.level>level) level++;
		return true;
	}
	return false;
}

void CHero::LevelUp(int choice1)
{
	if (level < 8)
	{
		HP = 200 + 110 * level;
		HPb = HP;
		ATK = 20 + 15 * level;
		AR = 10;
		ASD = 2 + 0.3 * level;
		SD = 0.6 + 0.1 * level;
		string nameall[3][9] =
		{
			{"核心语法", "面向对象", "常用API", "集合框架", "I/O", "多线程","异常","开发实用", "JDK8新特性"},
			{"编程基础","基础语法","函数","数组","指针","内存管理","文件操作","标准库函数","实际应用" },
			{"基础语法", "类和对象", "内存管理", "模板", "IO流", "继承多态", "异常", "智能指针", "STL"}
		};
		weaponname = nameall[choice1][level];
	}
	

}