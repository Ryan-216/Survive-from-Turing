#include "CBullet.h"
using namespace std;

CBullet::CBullet(int x_, int y_, int vx_, int vy_) :x(x_), y(y_), vx(vx_), vy(vy_)
{
	val = bulletval;
}

void CBullet::move()
{
	x += vx;
	y += vy;
}

void CBullet::Drawbullet()
{
	fillcircle(x, y, bulletr);
}