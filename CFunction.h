#include<easyx.h>
#include<cmath>
#include<time.h>
#pragma once
using namespace std;

class CFunction
{
public:
	bool InArea(double mx, double my, double x, double y, double w, double h);//�ж�����Ƿ���ĳ���� ������

	bool IsCrash(double x1, double y1, double r1, double x2, double y2, double r2);//��ײ���

	double GetAngle(double x1, double y1, double x2, double y2, double centerx, double centery);//��centerΪ���㣬���������߶εļнǣ�0-360�� //��չ

	void DrawBg(IMAGE image, int bgx, int bgy);

	int Timer(int duration, int id);

	void MyOutText(double x, double y, char* text);
	
};



