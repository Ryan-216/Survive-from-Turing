#include<easyx.h>
#include<iostream>
#pragma once
using namespace std;

class CResource
{
public:
	//Ӣ���������� ��9��Ӣ���������
	IMAGE imageH[3][9][2];
	IMAGE imageHA[3][9][2];

	IMAGE imageM[7][2];
	IMAGE imageMA[7][2];

	//ͼƬ������Դ����ͼƬ��֯��Ӧ
	//ͼƬ����
	IMAGE imageBg[10];
	IMAGE imageWB[10];
	IMAGE imageWM[10];
	IMAGE image0B[3];
	IMAGE image0M[3];
	IMAGE imageD[10];

	//��������
	const double bgx = 0, bgy = 0;//����ͼ����
	const int windowWidth = 900, windowHeight = 600;//���ڳ���
	const int windowWidths = 600, windowHeights = 400;//���ڳ���
	const double centery = windowHeight / 2.0;
	const double centerx = windowWidth / 2.0;
	const int bgWidth = 900, bgHeight = 600;//��������
	const int bgWidthw = 1200, bgHeightw = 800;//��ͼ����

	void Init();//��ʼ����������Դ
};

