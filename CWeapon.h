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
			{"核心语法", "面向对象", "常用API", "集合框架", "I/O", "多线程","异常","开发实用", "JDK8新特性"},
			{"编程基础","基础语法","函数","数组","指针","内存管理","文件操作","标准库函数","实际应用" },
			{"基础语法", "类和对象", "内存管理", "模板", "IO流", "继承多态", "异常", "智能指针", "STL"}
		};
		name = nameall[choice][level1];
	}
	int ATK;//攻击力
	int AR;//血量
	int ASD;//攻击速度
	double SD;//移动速度
	int level;
	string name;
	CResource* resW;
	void DrawWeapon(int x, int y);
};

