#include "CResource.h"
using namespace std;

/*��Դ��ʼ��-����
	������:
	����: ����Դ�ļ���������У�ͼƬ������
	����: void
	����ֵ: void
*/
void CResource:: Init()
{
	//ģ��
	char path[50];
	char pathA[50];	
	//����Ӣ��
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
	//���ع���
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
	//���ر���
	loadimage(&imageBg[0], "Resource/Picture/game.png", bgWidthw, bgHeightw);
	loadimage(&imageBg[1], "Resource/Picture/menu.png", bgWidth, bgHeight);
	loadimage(&imageBg[2], "Resource/Picture/developer.png", bgWidth, bgHeight);
	loadimage(&imageBg[3], "Resource/Picture/lobby.png", bgWidth, bgHeight);
	loadimage(&imageBg[4], "Resource/Picture/small.png", bgWidth, bgHeight);
	loadimage(&imageBg[5], "Resource/Picture/sea.png", bgWidth, bgHeight);
	loadimage(&imageBg[6], "Resource/Picture/ending.png", bgWidth, bgHeight);
	//��������
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

/*��Դ����-����
	������:
	����: ��������Ҫ����Դ�ļ���ͼƬ������
	����: void
	����ֵ: void
*/
