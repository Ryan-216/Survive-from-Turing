#include "CMonster.h"
#define PI 3.1415926
using namespace std;

CFunction funMo;
CResource ResMo;
/*怪物移动-核心
	负责人:
	功能: 以英雄为目标进行移动
	参数: void
	返回值: void
*/
static double monsterx = 100;
static double monstery = 100;

double* CMonster::Move(double* pv, double* pMonsterxy, vector<CMonster*>& moster)
{

	int distance1 = sqrt(pow(x- ResMo.centerx , 2) + pow(y - ResMo.centery, 2));
	int minDistance1 = r ;

	double x1 = x + 100, y1 = y;
	double L2x = pow((x - resMo->centerx), 2) + pow((y - resMo->centery), 2);
	double L2m = pow((x1 - resMo->centerx), 2) + pow((y1 - resMo->centery), 2);
	double L2c = pow((x1 - x), 2) + pow((y1 - y), 2);
	double cosm = (L2x + L2c - L2m) / (2 * sqrt(L2x * L2c));
	double angle = acos(cosm);//计算夹角，0-180
	if (y > resMo->centery) angle = 2 * PI - angle;
	if (angle >= PI / 4 && angle < (3 * PI) / 4) direction = 3;//下
	else if (angle >= (3 * PI) / 4 && angle < (5 * PI) / 4) direction = 2;//左
	else if (angle >= (5 * PI) / 4 && angle < (7 * PI) / 4) direction = 1;//上
	else direction = 4;//右
	//cout << cos(angle)<<"         "<<sin(angle) << "         "<<endl;
	//cout << pv[0] << "         " <<pv[1] << endl;
	//BeginBatchDraw();
	//Draw(monsterx,monstery);
	//EndBatchDraw();
	if (x >= pv[2] + resMo->bgWidthw) x = pv[2] + resMo->bgWidthw - 1;
	else if (x <= pv[2]) x = pv[2] + 1;
	else if (y >= pv[3] + resMo->bgHeightw) y = pv[3] + resMo->bgHeightw - 1;
	else if (y <= pv[3]) y = pv[3] + 1 + r;
	else if (distance1 > minDistance1)
	{
		x += SD * cos(angle) + pv[0];
		y += SD * sin(angle) + pv[1];
	}
	else if (distance1 <= minDistance1)
	{
		x += pv[0];
		y += pv[1];
	}
	pMonsterxy[0] = x;
	pMonsterxy[1] = y;
	pMonsterxy[2] = r;

	for (auto& m : moster)
	{
		if (m != this && isOverlap(*m))
		{
			// 如果重叠，根据重叠的情况调整位置
			int distance = sqrt(pow(x - m->x, 2) + pow(y - m->y, 2));
			int minDistance = r + m->r;

			if (distance < minDistance)
			{
				// 计算需要移动的距离
				int moveDistance = minDistance - distance;
				int directionX = 0;
				int directionY = 0;
				// 计算需要移动的方向
				if (distance > 0)
				{
					directionX = (m->x - x) / distance;
					directionY = (m->y - y) / distance;
				}

				// 移动当前圆和其他圆
				x -= moveDistance * directionX;
				y -= moveDistance * directionY;
				m->x += moveDistance * directionX;
				m->y += moveDistance * directionY;
			}
		}
	}


	return pMonsterxy;
}


/*怪物攻击-核心
	负责人:
	功能: 碰撞攻击
	参数: 攻击目标（英雄）的坐标和半径
	返回值: void
*/
void CMonster::Attack(int x, int y, int r)//自动攻击
{

}

/*画怪物-核心
	负责人:
	功能: 画出怪物，暂不贴图，圆形
	参数: void
	返回值: void
*/

void CMonster::Draw()
{
	if (alive)
	{
		int speed = 50;
		setfillcolor(RED);
		//solidcircle(x, y, r);
		double HPx = x - r + 2 * r * (HPb / HP);
		solidroundrect(x - r, y - r - 14, HPx, y - r - 8, 5, 5);
		if (!attack)
		{
			//移动
			putimage(x - imager, y - imager, 2 * imager, 2 * imager, &resMo->imageM[level][1], imgx + gapx * index, imgy + (direction - 1) * gapy, NOTSRCERASE);
			putimage(x - imager, y - imager, 2 * imager, 2 * imager, &resMo->imageM[level][0], imgx + gapx * index, imgy + (direction - 1) * gapy, SRCINVERT);
		}
		else
		{
			//攻击
			putimage(x - imagerA, y - imagerA, 2 * imagerA, 2 * imagerA, &resMo->imageMA[level][1], imgxA + gapxA * indexA, imgyA + (direction - 1) * gapyA, NOTSRCERASE);
			putimage(x - imagerA, y - imagerA, 2 * imagerA, 2 * imagerA, &resMo->imageMA[level][0], imgxA + gapxA * indexA, imgyA + (direction - 1) * gapyA, SRCINVERT);
		}
		index = (clock() / speed) % frames;
		indexA = (clock() / speed) % framesA;
	}
	char s[50];
	const char* s1 = name[level].data();
	sprintf(s, "%s", s1);
	funMo.MyOutText(x, y + 30, s);
}

/*怪物受伤-核心
	负责人:
	功能: 判断怪物是否受伤，受伤HP减少
	HP是否为0，死亡则模型消失随机掉落装备
	参数: void
	返回值: void
*/

bool CMonster::Hurt(double* attack, bool* isattack)
{
	//判断是否在攻击范围
	//血量判断，>0则减少，<=0则死亡
	//死亡则随机掉落装备
	//掉落则在死处生成装备DrawWeapon()
	if (funMo.IsCrash(x, y, r, resMo->centerx, resMo->centery, attack[1]))
	{
		*isattack = true;
		//cout << *isattack << endl;
		int gameTime = clock() / 10;
		int attackTime = 100 / (attack[2]);//多少毫秒攻击一次
		if (gameTime % attackTime == 0 && (HPb > 0) && attack[3] >= 3)
		{
			cout << HPb << endl;
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

bool CMonster::isOverlap(const CMonster& other) const {
	// 判断当前圆与另一个圆是否重叠
	int distance = sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	return distance < r + other.r;
}

void CMonster::Super()
{
	if (level == 5 && HPb <= HP / 2)
	{
		level++;
		HP = 2000;
		HPb = HP;
		ATK = 20;
		ASD = 1;
		SD = 1;
	}
}