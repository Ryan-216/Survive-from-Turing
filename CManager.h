#include<graphics.h>
#include"CResource.h"
#include"CFunction.h"
#include"CButton.h"
#include"CHero.h"
#include"CMonster.h"
#include"CWeapon.h"
#include<iostream>
#include<fstream>
#include <vector>
#pragma once
using namespace std;

class CManager
{
public:
	CManager()
	{
		resM.Init();
	}
	vector<class CMoster*>monster;
	vector<class CBullet*>bullet;
	CResource resM;
	void InitLarge();		//初始化大窗口
	void InitSmall();		//初始化小窗口
	bool Menu();		//主菜单，返回是否进入大厅
	bool Lobby();		//大厅，返回大厅选择结果
	bool Game();		//游戏，返回游戏结果

	//Menu
	void DrawMenu();	//绘制主菜单界面
	bool LogIn();		//登录
	bool Guest();
	bool Register();	//注册
	bool Developer();	//开发人员
	bool GetPassword();	//忘记密码
	bool issame(const char* s1, const char* s2);

	//Lobby
	void DrawLobby();	//绘制大厅界面
	void OptionView();	//进入设置界面
	void ChargeView();	//进入充值界面

	//Game
	vector<class CMonster*>moster;
	void DrawGame();
	void CreateMonster(int level);//怪物生成
	bool Pause();		//暂停界面
	bool Settlement(bool r);	//结算界面
};

