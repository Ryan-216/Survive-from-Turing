#include<easyx.h>
#include<cmath>
#include<time.h>
#pragma once
using namespace std;

class CFunction
{
public:
	bool InArea(double mx, double my, double x, double y, double w, double h);//判断鼠标是否在某区域 长方形

	bool IsCrash(double x1, double y1, double r1, double x2, double y2, double r2);//碰撞检测

	double GetAngle(double x1, double y1, double x2, double y2, double centerx, double centery);//以center为交点，计算两条线段的夹角（0-360） //拓展

	void DrawBg(IMAGE image, int bgx, int bgy);

	int Timer(int duration, int id);

	void MyOutText(double x, double y, char* text);
	
};



