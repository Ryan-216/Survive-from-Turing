#pragma once
#include<graphics.h>
using namespace std;

const int bulletv = 20;
const int bulletval = 5;
const int bulletr = 5;

class CBullet
{
public:
	int x, y;
	int vx, vy;
	int val;//������ɵ��˺�ֵ
public:
	CBullet(int x_, int y_, int vx_, int vy_);
	void move();
	void Drawbullet();
};