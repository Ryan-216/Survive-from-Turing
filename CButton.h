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

	int x, y;//��ť���Ͻ�����
	int w, h;//��ť���� 
	const char* text;
	int color;//��ť�ı�����ɫ

	void DrawButton();//���ݻ�����Ϣ���ƾ�ΪԲ�Ǿ��Σ������
	bool ClickButton(ExMessage m);//�жϰ�ť�Ƿ񱻵��	
};

