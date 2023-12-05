#include "CFunction.h"
using namespace std;
#define PI 3.1415926



void CFunction::MyOutText(double x,double y,char* text)
{
	outtextxy(x - textwidth(text) / 2, y - textheight(text) / 2, text);
}
/*鼠标是否在某区域-核心
	负责人:
	功能: 
	1.判断鼠标坐标是否在按钮区域内
	2.返回结果
	参数: 鼠标坐标，按钮的左上角坐标，宽、高
	返回值: bool
*/
bool CFunction::InArea(double mx, double my, double x, double y, double w, double h)//判断鼠标是否在某区域
{
	if (mx >= x && mx <= x + w && my >= y && my <= y + h)
	{
		return true;
	}
	return false;
}
/*两圆是否碰撞-核心
	负责人:
	功能: 
	1.计算两圆心距离
	2.与两半径和进行比较
	参数: 两圆圆心，半径
	返回值: bool
*/
bool CFunction::IsCrash(double x1, double y1, double r1, double x2, double y2, double r2)//碰撞检测
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

/*计算两条边夹角-拓展
	负责人:
	功能:
	1.计算夹角某个三角函数值
	2.反三角函数求得夹角
	参数: 三个点
	返回值: double 夹角
*/
double CFunction::GetAngle(double x1, double y1, double x2, double y2, double centerx, double centery)//x2 y2 为鼠标坐标，x2 y2 ,x1 y1与x轴平行
{
	//double L1 = pow((x2 - centerx), 2) + pow((y2 - centery), 2);
	//double L2 = pow((x1 - centerx), 2) + pow((y1 - centery), 2);
	//double Lc = pow((x1 - x2), 2) + pow((y1 - y2), 2);
	//double cosc = (L1 + L2 - Lc) / (2 * sqrt(L1 * L2));
	//double angle = acos(cosc);//计算夹角，0-PI
	//if (y2<= centery) angle = 2 * PI - angle;//根据鼠标情况 将角度范围转换为 0-2PI
	//return angle;
	return 0;
}

void CFunction::DrawBg(IMAGE image,int bgx, int bgy)//画背景，后续会把load移出来
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
