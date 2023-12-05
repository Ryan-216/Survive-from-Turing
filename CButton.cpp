#include "CButton.h"
using namespace std;

CFunction fun;
/*画按钮-核心
	负责人:
	功能: 
	1.设置颜色、字体、坐标、宽高、文字、颜色
	2.画出按钮框
	3.在按钮框中心画文本
	参数: void
	返回值: void
*/
void CButton::DrawButton()
{
	setfillcolor(color);
	settextstyle(24, 0, "微软雅黑");
	solidroundrect(x, y, x + w, y + h, 20, 20);
	int lSpace = (w - textwidth(text)) / 2;
	int wSpace = (h - textheight(text)) / 2;
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	outtextxy(x + lSpace, y + wSpace, text);

}//根据基础信息绘制均为圆角矩形，有填充

/*点击按钮-核心
	负责人:
	功能: 
	1.判断鼠标是否在按钮内
	2.判断鼠标是否点击左键
	3.返回结果
	参数: 消息标识
	返回值: bool
*/
bool CButton::ClickButton(ExMessage m)
{
	if (m.message == WM_LBUTTONDOWN && fun.InArea(m.x, m.y, x, y, w, h))
	{
		return true;
	}
	return false;
}//判断按钮是否被点击
