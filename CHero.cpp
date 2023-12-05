#include "CHero.h"
#include<cmath>
using namespace std;
#define PI 3.1415926
#define MyBlue RGB(78,129,197)
CFunction funH;

/*Ӣ���ƶ�-����
	������:
	����: 
	1.���հ�����Ϣ
	2.�жϰ�������
	while(true)
	{
		if (����)
		{			
			switch (m.vkcode)
			{
			//�жϰ�������
			//����
			}
		}
		����仯
	}
	
	����: void
	����ֵ: void
*/

static double Mousex ;
static double Mousey ;
double* CHero::Move(ExMessage &m,double* pBgv)
{
	if (peekmessage(&m, EX_MOUSE)) {}
	Mousex = m.x;
	Mousey = m.y;
	double x1 = resH->centerx + 100, y1 = resH->centery;
	double L2x = pow((Mousex - resH->centerx), 2)+ pow((Mousey - resH->centery), 2);
	double L2m = pow((x1 - resH->centerx), 2) + pow((y1 - resH->centery), 2);
	double L2c = pow((x1 - Mousex), 2) + pow((y1 - Mousey), 2);
	double cosc;
	if (L2x * L2m != 0)
	{
		cosc = (L2x + L2m - L2c) / (2 * sqrt(L2x * L2m));
	}
	else
	{
		cosc = 0;
	}
	double angle = acos(cosc);//����нǣ�0-180
	if (Mousey <= resH->centery) angle = 2 * PI - angle;
	if (angle >= PI / 4 && angle < (3 * PI) / 4) direction = 3;//��
	else if (angle >= (3 * PI) / 4 && angle < (5 * PI) / 4) direction = 2;//��
	else if (angle >= (5 * PI) / 4 && angle < (7 * PI) / 4) direction = 1;//��
	else direction = 4;//��


	
	if (bgx >= resH->centerx)
	{
		bgx = resH->centerx; 
		pBgv[0] = 0, pBgv[1] = -SD * sin(angle);
		if (bgx ==resH->centerx && direction == 4)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else if (bgx <= resH->centerx - resH->bgWidthw)
	{
		bgx = resH->centerx - resH->bgWidthw;
		pBgv[0] = 0, pBgv[1] = -SD * sin(angle);
		if (bgx == resH->centerx-resH->bgWidthw && direction == 2)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else if (bgy >= resH->centery)
	{
		bgy = resH->centery;
		pBgv[0] = -SD * cos(angle),pBgv[1] = 0;
		if (bgy == resH->centery && direction == 3)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else if (bgy <= resH->centery - resH->bgHeightw + r) 
	{
		bgy = resH->centery - resH->bgHeightw + r;
		pBgv[0] = -SD * cos(angle),pBgv[1] = 0;
		if (bgy == resH->centery - resH->bgHeightw + r && direction == 1)
		{
			bgx -= SD * cos(angle);
			bgy -= SD * sin(angle);
			pBgv[0] = -SD * cos(angle);
			pBgv[1] = -SD * sin(angle);
			pBgv[2] = bgx;
			pBgv[3] = bgy;
		}
	}
	else 
	{
		bgx -= SD * cos(angle);
		bgy -= SD * sin(angle);
		pBgv[0] = -SD * cos(angle);
		pBgv[1] = -SD * sin(angle);
		pBgv[2] = bgx;
		pBgv[3] = bgy;
		
	}
	return pBgv;
}

/*Ӣ�۹���-����
	������:
	����: 
	while(true)
	{
		����������Χ
		if (������Χ�������ײ)
		{
			cm.Hert();
		}
		����仯
	}
	����: ����Ŀ�꣨�������
	����ֵ: void
*/
//void CHero::Attack()

	//ȷ��������Χ
	//�ж��Ƿ��ڷ�Χ��
	//���������Ե�Ѫ



/*��Ӣ��-����
	������:
	����: 
	1.���ô��ڲ�����������������
	2.��Բ
	����: void
	����ֵ: void
*/
void CHero::Draw()
{
	int speed = 50;
	//Բ
	if (alive)
	{
		//setfillcolor(MyBlue);//��ģ��
		//solidcircle(resH->centerx, resH->centery, r);
		//setlinecolor(RED);//��������Χ
		//circle(resH->centerx, resH->centery, AR);
		double HPx = 50 + 100 * (HPb / HP);
		
		setfillcolor(MyBlue);
		fillrectangle(0, 10, 200, 160);
		setfillcolor(WHITE);
		solidroundrect(50, 20, 150, 30, 10, 10);//��Ѫ��
		setfillcolor(RED);
		solidroundrect(50, 20, HPx, 30, 10, 10);//��Ѫ��
		char s1[50];
		sprintf(s1, "�� �� ����%d", ATK);
		char s2[50];
		sprintf(s2, "������Χ��%.lf",AR);
		char s3[50];
		sprintf(s3, "�����ٶȣ�%.lf", ASD);
		char s4[50];
		sprintf(s4, "�ƶ��ٶȣ�%.1f", SD);
		char s5[50];
		sprintf(s5, "�� �� ֵ��%d", EXP);
		char s6[50];
		sprintf(s6, "%d", HP);
		char s7[50];
		const char* s8 = weaponname.data();
		sprintf(s7, "ѧϰ���ȣ�%s", s8);
		outtextxy(10, 15, "Ѫ����");
		outtextxy(160, 15, s6);
		outtextxy(50, 30, s1);
		outtextxy(50, 50, s2);
		outtextxy(50, 70, s3);
		outtextxy(50, 90, s4);
		outtextxy(50, 110, s5);
		outtextxy(30, 130, s7);

		if (!attack)
		{	
			//Ӣ���ƶ�
			putimage(resH->centerx - imager, resH->centery - imager, 2 * imager, 2 * imager, &resH->imageH[type][level][1], imgx + gapx * index, imgy + (direction - 1) * gapy, NOTSRCERASE);
			putimage(resH->centerx - imager, resH->centery - imager, 2 * imager, 2 * imager, &resH->imageH[type][level][0], imgx + gapx * index, imgy + (direction - 1) * gapy, SRCINVERT);
		}
		else
		{
			//Ӣ�۹���
			putimage(resH->centerx - imagerA, resH->centery - imagerA, 2 * imagerA, 2 * imagerA, &resH->imageHA[type][level][1], imgxA + gapxA * indexA, imgyA + (direction - 1) * gapyA, NOTSRCERASE);
			putimage(resH->centerx - imagerA, resH->centery - imagerA, 2 * imagerA, 2 * imagerA, &resH->imageHA[type][level][0], imgxA + gapxA * indexA, imgyA + (direction - 1) * gapyA, SRCINVERT);
		}
		index = (clock() / speed) % frames;
		indexA = (clock() / speed) % framesA;
	}
	
}

/*�����ж�-����
	������:
	����: 
	if(HP>0)
	{
		HP����
	}
	else
	{
		��ɫ���������ý��㺯��
	}
	����: void
	����ֵ: void
*/
bool CHero::Hurt(double*pMonsterxyr ,double* attack, bool* isattack)
{
	//Ѫ���жϣ�>0����٣�<=0������
	//���ý���
	if (funH.IsCrash(pMonsterxyr[0], pMonsterxyr[1], attack[1], resH->centerx, resH->centery, r))
	{
		*isattack = true;
		int gameTime = clock()/10;//��gameTime10����
		int attackTime = 100 / attack[2];//���ٸ�10���빥��һ��
		if (gameTime % attackTime == 0 && (HPb > 0) && attack[3] >= 3)
		{
			HPb -= attack[0];
			return true;
		}
		else if (HPb <= 0)
		{
			alive = false;
			return false;
		}
	}
}

/*ʰȡװ��-����
	������:
	����: 
	if(װ����Ӣ�� �����ײ)
	{
		�����޸�
		װ����ʧ
	}
	����: void
	����ֵ: void
*/
bool CHero::Pick(CWeapon w,double x,double y)
{
	//�ж�����Ƿ���ײ
	//��ײ�����Ե��ӣ�װ����ʧ
	if (funH.IsCrash(resH->centerx, resH->centery, r, x, y, 20)&& level<8)
	{
		EXP +=pow(2,w.level+2);
		if ((EXP > pow(2, level + 3))||w.level>level) level++;
		return true;
	}
	return false;
}

void CHero::LevelUp(int choice1)
{
	if (level < 8)
	{
		HP = 200 + 110 * level;
		HPb = HP;
		ATK = 20 + 15 * level;
		AR = 10;
		ASD = 2 + 0.3 * level;
		SD = 0.6 + 0.1 * level;
		string nameall[3][9] =
		{
			{"�����﷨", "�������", "����API", "���Ͽ��", "I/O", "���߳�","�쳣","����ʵ��", "JDK8������"},
			{"��̻���","�����﷨","����","����","ָ��","�ڴ����","�ļ�����","��׼�⺯��","ʵ��Ӧ��" },
			{"�����﷨", "��Ͷ���", "�ڴ����", "ģ��", "IO��", "�̳ж�̬", "�쳣", "����ָ��", "STL"}
		};
		weaponname = nameall[choice1][level];
	}
	

}