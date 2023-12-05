#include<easyx.h>
#include<iostream>
#pragma once
using namespace std;

class CResource
{
public:
	//英雄武器变量 有9种英雄武器组合
	IMAGE imageH[3][9][2];
	IMAGE imageHA[3][9][2];

	IMAGE imageM[7][2];
	IMAGE imageMA[7][2];

	//图片音乐资源，与图片组织对应
	//图片变量
	IMAGE imageBg[10];
	IMAGE imageWB[10];
	IMAGE imageWM[10];
	IMAGE image0B[3];
	IMAGE image0M[3];
	IMAGE imageD[10];

	//基本参数
	const double bgx = 0, bgy = 0;//背景图坐标
	const int windowWidth = 900, windowHeight = 600;//窗口长宽
	const int windowWidths = 600, windowHeights = 400;//窗口长宽
	const double centery = windowHeight / 2.0;
	const double centerx = windowWidth / 2.0;
	const int bgWidth = 900, bgHeight = 600;//背景长宽
	const int bgWidthw = 1200, bgHeightw = 800;//地图长宽

	void Init();//初始化，加载资源
};

