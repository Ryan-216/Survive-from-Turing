#include "CButton.h"
using namespace std;

CFunction fun;
/*����ť-����
	������:
	����: 
	1.������ɫ�����塢���ꡢ��ߡ����֡���ɫ
	2.������ť��
	3.�ڰ�ť�����Ļ��ı�
	����: void
	����ֵ: void
*/
void CButton::DrawButton()
{
	setfillcolor(color);
	settextstyle(24, 0, "΢���ź�");
	solidroundrect(x, y, x + w, y + h, 20, 20);
	int lSpace = (w - textwidth(text)) / 2;
	int wSpace = (h - textheight(text)) / 2;
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	outtextxy(x + lSpace, y + wSpace, text);

}//���ݻ�����Ϣ���ƾ�ΪԲ�Ǿ��Σ������

/*�����ť-����
	������:
	����: 
	1.�ж�����Ƿ��ڰ�ť��
	2.�ж�����Ƿ������
	3.���ؽ��
	����: ��Ϣ��ʶ
	����ֵ: bool
*/
bool CButton::ClickButton(ExMessage m)
{
	if (m.message == WM_LBUTTONDOWN && fun.InArea(m.x, m.y, x, y, w, h))
	{
		return true;
	}
	return false;
}//�жϰ�ť�Ƿ񱻵��
