#include "CResource.h"
using namespace std;

/*资源初始化-核心
	负责人:
	功能: 将资源文件存如变量中，图片、音乐
	参数: void
	返回值: void
*/
void CResource:: Init()
{
	//模型
	char path[50];
	char pathA[50];	
	//加载英雄
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				sprintf(path, "Resource/Picture/Hero/%d/%d/walk%d.png", i, j, k);
				sprintf(pathA, "Resource/Picture/Hero/%d/%d/attack%d.png", i, j, k);
				loadimage(&imageH[i][j][k], path);
				loadimage(&imageHA[i][j][k], pathA);
			}						
		}
	}
	//加载怪物
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sprintf(path, "Resource/Picture/Monster/%d/walk%d.png", i, j);
			sprintf(pathA, "Resource/Picture/Monster/%d/attack%d.png", i, j);
			loadimage(&imageM[i][j], path);
			loadimage(&imageMA[i][j], pathA);
		}
	}
	//加载背景
	loadimage(&imageBg[0], "Resource/Picture/game.png", bgWidthw, bgHeightw);
	loadimage(&imageBg[1], "Resource/Picture/menu.png", bgWidth, bgHeight);
	loadimage(&imageBg[2], "Resource/Picture/developer.png", bgWidth, bgHeight);
	loadimage(&imageBg[3], "Resource/Picture/lobby.png", bgWidth, bgHeight);
	loadimage(&imageBg[4], "Resource/Picture/small.png", bgWidth, bgHeight);
	loadimage(&imageBg[5], "Resource/Picture/sea.png", bgWidth, bgHeight);
	loadimage(&imageBg[6], "Resource/Picture/ending.png", bgWidth, bgHeight);
	//加载武器
	for (int i = 0; i < 9; i++)
	{
		sprintf(path, "Resource/Picture/Weapon/b%d.png", i);
		sprintf(pathA, "Resource/Picture/Weapon/m%d.png", i);
		loadimage(&imageWB[i], path, 60, 60);
		loadimage(&imageWM[i], pathA, 60, 60);
	}

	for (int i = 0; i < 3; i++)
	{
		sprintf(path, "Resource/Picture/Hero/%d/o0.png", i);
		sprintf(pathA, "Resource/Picture/Hero/%d/o1.png", i);
		loadimage(&image0B[i], path);
		loadimage(&image0M[i], pathA);
	}

	for (int i = 0; i < 10; i++)
	{
		sprintf(path, "Resource/Picture/Developer/%d.jpg", i);
		loadimage(&imageD[i], path, 120, 120);
	}
}

/*资源加载-核心
	负责人:
	功能: 加载所需要的资源文件，图片、音乐
	参数: void
	返回值: void
*/
