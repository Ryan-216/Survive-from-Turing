#include<easyx.h>
#include"CFunction.h"
#pragma once
using namespace std;

class CButton
{
public:
	CButton(int x1, int y1, int w1, int h1, const char* text1, int color1)
	{
		x = x1;
		y = y1;
		w = w1;
		h = h1;
		text = text1;
		color = color1;
	}

	int x, y;//按钮左上角坐标
	int w, h;//按钮宽、高 
	const char* text;
	int color;//按钮文本、颜色

	void DrawButton();//根据基础信息绘制均为圆角矩形，有填充
	bool ClickButton(ExMessage m);//判断按钮是否被点击	
};

