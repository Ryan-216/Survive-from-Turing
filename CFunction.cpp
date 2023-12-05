#include "CFunction.h"
using namespace std;
#define PI 3.1415926



void CFunction::MyOutText(double x,double y,char* text)
{
	outtextxy(x - textwidth(text) / 2, y - textheight(text) / 2, text);
}
/*����Ƿ���ĳ����-����
	������:
	����: 
	1.�ж���������Ƿ��ڰ�ť������
	2.���ؽ��
	����: ������꣬��ť�����Ͻ����꣬����
	����ֵ: bool
*/
bool CFunction::InArea(double mx, double my, double x, double y, double w, double h)//�ж�����Ƿ���ĳ����
{
	if (mx >= x && mx <= x + w && my >= y && my <= y + h)
	{
		return true;
	}
	return false;
}
/*��Բ�Ƿ���ײ-����
	������:
	����: 
	1.������Բ�ľ���
	2.�����뾶�ͽ��бȽ�
	����: ��ԲԲ�ģ��뾶
	����ֵ: bool
*/
bool CFunction::IsCrash(double x1, double y1, double r1, double x2, double y2, double r2)//��ײ���
{
	double distance2 = pow((x1-x2), 2) + pow((y1-y2), 2);
	double distance = pow(distance2, 0.5);

	if (distance <= r1 + r2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*���������߼н�-��չ
	������:
	����:
	1.����н�ĳ�����Ǻ���ֵ
	2.�����Ǻ�����üн�
	����: ������
	����ֵ: double �н�
*/
double CFunction::GetAngle(double x1, double y1, double x2, double y2, double centerx, double centery)//x2 y2 Ϊ������꣬x2 y2 ,x1 y1��x��ƽ��
{
	//double L1 = pow((x2 - centerx), 2) + pow((y2 - centery), 2);
	//double L2 = pow((x1 - centerx), 2) + pow((y1 - centery), 2);
	//double Lc = pow((x1 - x2), 2) + pow((y1 - y2), 2);
	//double cosc = (L1 + L2 - Lc) / (2 * sqrt(L1 * L2));
	//double angle = acos(cosc);//����нǣ�0-PI
	//if (y2<= centery) angle = 2 * PI - angle;//���������� ���Ƕȷ�Χת��Ϊ 0-2PI
	//return angle;
	return 0;
}

void CFunction::DrawBg(IMAGE image,int bgx, int bgy)//���������������load�Ƴ���
{
	putimage(bgx, bgy, &image);
}


int CFunction::Timer(int duration, int id)
{
	static int startTime[10];
	int endTime = clock();
	if (endTime - startTime[id] > duration)
	{
		startTime[id] = endTime;
		return 1;
	}
	return 0;
}
