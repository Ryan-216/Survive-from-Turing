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
	void InitLarge();		//��ʼ���󴰿�
	void InitSmall();		//��ʼ��С����
	bool Menu();		//���˵��������Ƿ�������
	bool Lobby();		//���������ش���ѡ����
	bool Game();		//��Ϸ��������Ϸ���

	//Menu
	void DrawMenu();	//�������˵�����
	bool LogIn();		//��¼
	bool Guest();
	bool Register();	//ע��
	bool Developer();	//������Ա
	bool GetPassword();	//��������
	bool issame(const char* s1, const char* s2);

	//Lobby
	void DrawLobby();	//���ƴ�������
	void OptionView();	//�������ý���
	void ChargeView();	//�����ֵ����

	//Game
	vector<class CMonster*>moster;
	void DrawGame();
	void CreateMonster(int level);//��������
	bool Pause();		//��ͣ����
	bool Settlement(bool r);	//�������
};

