#include "CWeapon.h"
#include"CFunction.h"
using namespace std;
CFunction funW;
/*������-����
	������:
	����:
	��������
	����: ������������
	����ֵ: void
*/
void CWeapon::DrawWeapon(int x,int y)
{
	//putimage(x, y, &resW.imageWM[level - 1]);
	char s[50];
	const char* s1 = name.data();
	sprintf(s, "%s", s1);
	funW.MyOutText(x + 30, y + 70, s);
	putimage(x, y, 60, 60, &resW->imageWM[level], 0, 0, NOTSRCERASE);
	putimage(x, y, 60, 60, &resW->imageWB[level], 0, 0, SRCINVERT);
	//setfillcolor(RED);
	//solidcircle(x, y, 10);
}