#include "CManager.h"
#include<Windows.h>
#include<mmsystem.h>
#include"CBullet.h"
#pragma comment(lib,"winmm.lib")
#define MyBlue RGB(78,129,197)
using namespace std;

static int ID;
ExMessage msg;
CFunction funM;
CButton butLogIn(310-10, 420 + 10, 100, 40, "登录", MyBlue);
CButton butRegister(490+10, 420 + 10, 100, 40, "注册", MyBlue);
CButton butGuest(310-10, 500 + 20, 100, 40, "游客登录", MyBlue);
CButton butGetpassword(490+10, 500 + 20, 100, 40, "忘记密码", MyBlue);
CButton butDeveloper(750, 50, 100, 30, "开发人员", RGB(184, 194, 202));
CButton butStart(390, 460, 80, 40, "开始游戏", MyBlue);
static int volume = 300;//0-1000

void PlayBgm(const char* music)//播放音乐，传入音乐路径
{
	char cmd[100] = { 0 };

	sprintf(cmd, "open %s alias bgm", music);
	mciSendString("close  bgm ", NULL, 0, NULL);
	mciSendString(cmd, NULL, 0, NULL);

	char cmd1[100] = { 0 };
	sprintf(cmd1, "play bgm repeat");
	mciSendString(cmd1, NULL, 0, NULL);

}
void Volume()
{
	char cmd2[100] = { 0 };
	sprintf(cmd2, "setaudio bgm volume to %d", volume);
	MCIERROR ret = mciSendString(cmd2, NULL, 0, NULL);

	char err[100] = { 0 };
	mciGetErrorString(ret, err, sizeof(err));
	//puts(err);
}

void CManager::InitLarge()
{
	initgraph(resM.windowWidth, resM.windowHeight, EX_SHOWCONSOLE);
	/*int screenW = GetSystemMetrics(SM_CXSCREEN);
	int screenH = GetSystemMetrics(SM_CYSCREEN);
	int x = (screenW - resM.windowWidth) / 2;
	int y = (screenH - resM.windowHeight) / 2;
	HWND hwnd = initwindow(resM.windowWidth, resM.windowHeight,"",x,y);*/

}
void CManager::InitSmall()
{
	initgraph(resM.windowWidths, resM.windowHeights, EX_SHOWCONSOLE);
}
/**************************Menu******************************/
bool CManager::Menu()//红云
{
	PlayBgm("Resource/Audio/menu.mp3");
	Volume();
	InitLarge();
	DrawMenu();
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		if (butLogIn.ClickButton(msg))
		{
			if (LogIn()) return true;
			else
			{
				InitLarge();
				DrawMenu();
			}
		}
		if (butRegister.ClickButton(msg))
		{
			if (!Register())
			{
				InitLarge();
				DrawMenu();
			}
		}
		if (butGuest.ClickButton(msg))
		{
			return true;
		}
		if (butGetpassword.ClickButton(msg))
		{
			if (!GetPassword())
			{
				InitLarge();
				DrawMenu();
			}
		}
		if (butDeveloper.ClickButton(msg))
		{
			if (!Developer())
			{
				InitLarge();
				DrawMenu();
			}
		}
	}

}

/*开发人员-拓展
	负责人:
	功能:
	1.画出开发人员界面
	2.展示开发人员信息
	参数: void
	返回值: void
*/
bool CManager::Developer()
{
	CButton back(870, 10, 20, 20, "×", MyBlue);
	CButton pagea(700 - 30, 500 - 20, 60, 40, "下一页", MyBlue);
	CButton paged(200 - 30, 500 - 20, 60, 40, "上一页", MyBlue);
	int page = 0;
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}

		BeginBatchDraw();
		cleardevice();
		funM.DrawBg(resM.imageBg[2], resM.bgx, resM.bgy);//宽、高、路径、左上角x、左上角y
		back.DrawButton();
		pagea.DrawButton();
		paged.DrawButton();
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		if (pagea.ClickButton(msg)) page = 1;
		if (paged.ClickButton(msg)) page = 0;
		if (page == 0)
		{
			//背景颜色，需要改为白色，或者字体改为白色
			putimage(50, 75 + 25, &resM.imageD[5]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(50, 20 + 25, "冉红云");
			outtextxy(50, 45 + 25, "VS2022 启动");

			putimage(330, 75 + 25, &resM.imageD[8]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(330, 20 + 25, "赵严晨");
			outtextxy(330, 45 + 25, "原神启动");

			putimage(610, 75 + 25, &resM.imageD[6]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(610, 20 + 25, "谭榆凡");
			//            座右铭未改
			outtextxy(610, 45 + 25, "宁可被人笑一时，不可被人笑一世");

			putimage(50, 265 + 50, &resM.imageD[1]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(50, 210 + 50, "lemon");
			outtextxy(50, 235 + 50, "代码写的越急，程序跑的越慢");

			putimage(330, 265 + 50, &resM.imageD[2]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(330, 210 + 50, "纯氧");
			outtextxy(330, 235 + 50, "天下万般兵刃，唯bug最伤人");

			putimage(610, 260 + 50, &resM.imageD[3]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(610, 210 + 50, "房康乐");
			//            座右铭未改
			outtextxy(610, 235 + 50, "在计算机里头没有任何黑魔法！所有");
			outtextxy(610, 235 + 70, "的东西只不过是我现在不知道而已");
		}
		if (page == 1)
		{
			putimage(50, 75 + 25, &resM.imageD[9]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(50, 20 + 25, "郑宝怡");
			outtextxy(50, 45 + 25, "他强任他强，清风拂山岗");

			putimage(330, 75 + 25, &resM.imageD[7]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(330, 20 + 25, "杨盛淋");
			outtextxy(330, 45 + 25, "我梦想从未离场");

			putimage(610, 75 + 25, &resM.imageD[4]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(610, 20 + 25, "谷方舟");
			outtextxy(610, 45+25, "少年：你不是最喜欢打逆风翻盘局吗！");

			putimage(50, 265 + 50, &resM.imageD[0]);
			settextstyle(24, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			outtextxy(50, 210 + 50, "望仔小学长");
			//outtextxy(50, 235 + 50, "代码写的越急，程序跑的越慢");
		}
		////////////////////////
		EndBatchDraw();
		if (back.ClickButton(msg))
		{
			closegraph();
			return false;
		}
	}
}
bool CManager::issame(const char* s1, const char* s2)
{
	char c1 = 0;
	char c2 = 0;

	while (s1[c1] != '\0' && s2[c2] != '\0') {
		if (s1[c1] != s2[c2]) {
			return false;
		}
		c1++;
		c2++;
	}
	if (s1[c1] == '\0' && s2[c2] == '\0') {
		return true;
	}
	else {
		return false;
	}
}

/*菜单-核心
	负责人:
	功能:
	1.画出菜单背景putimage()
	2.创建按钮类
	参数: void
	返回值: void
*/
void CManager::DrawMenu()//画界面参考
{
	BeginBatchDraw();
	cleardevice();
	funM.DrawBg(resM.imageBg[1], resM.bgx, resM.bgy);//宽、高、路径、左上角x、左上角y
	butLogIn.DrawButton();
	butRegister.DrawButton();
	butGuest.DrawButton();
	butGetpassword.DrawButton();
	butDeveloper.DrawButton();
	EndBatchDraw();
	//画背景
	//画按钮 DrawButton()
}












/*登录-核心(游客登录-拓展)
	负责人:
	功能:
	1.接收输入
	if(账号不存在)
	{
		提示
	}
	else if(账号存在但密码不对)
	{
		提示
	}
	else
		return true;
	参数: void
	返回值: bool
*/
bool CManager::LogIn()
{
	InitSmall();
	CButton butl(300 - 30, 150 - 20, 60, 40, "登录", MyBlue);
	CButton butb(300 - 30, 250 - 20, 60, 40, "返回", MyBlue);
	ifstream ifs("account.txt");

	BeginBatchDraw();
	funM.DrawBg(resM.imageBg[4], 0, 0);
	butl.DrawButton();
	butb.DrawButton();
	EndBatchDraw();
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		if (butl.ClickButton(msg))
		{
			char id[100];
			char psd[100];
			HWND hnd = GetHWnd();//获取窗口句柄  hnd定义的变量
			if (InputBox(id, 100, "请输入账号", NULL, NULL, 0, 0, false))
			{
				if (id[0] != NULL)
				{
					bool exist = false;//判断账号存不存在

					char id1[100];//和id区分
					char psd[100];
					char que[100];
					char asw[100];
					char score[100] = "NULL";

					ifs.seekg(0L, ios::beg);

					while (ifs.peek() != EOF) {//最后一轮读到全空
						ifs >> id1;
						ifs >> psd;
						ifs >> que;
						ifs >> asw;
						ifs >> score;

						if (issame(id, id1)) {//如果找到了对应账号
							exist = true;

							break;
						}
					}
					ifs.close();
					if (exist) {//账号存在
						char psd1[100];
						if (InputBox(psd1, 100, "请输入密码", NULL, NULL, 0, 0, false)) {
							if (issame(psd, psd1)) {
								MessageBox(hnd, "登录成功！", "提示", MB_OKCANCEL);
								ID = atoi(id);
								return true;
							}
							else {
								MessageBox(hnd, "密码错误！", "提示", MB_OKCANCEL);
							}
						}
						else {
							MessageBox(hnd, "密码不能为空！", "警告", MB_OKCANCEL);
						}
					}
					else {//账号不存在
						MessageBox(hnd, "账号不存在！", "提示", MB_OKCANCEL);
					}
				}
				else MessageBox(hnd, "账号不能为空！", "警告", MB_OKCANCEL);
			}
		}
		if (butb.ClickButton(msg))
		{
			closegraph();
			return false;
		}
	}
}


/*注册-拓展
	负责人:
	功能:
	1.画出注册界面
	2.接收输入
	if(账号不符合要求)
	{
		提示，重新注册
	}
	else if(账号符合要求但已经存在)
	{
		提示，重新注册
	}
	else
		提示注册成功，返回菜单

	参数: void
	返回值: void
*/
bool CManager::Register()
{
	InitSmall();
	CButton butr(300 - 30, 150 - 20, 60, 40, "注册", MyBlue);
	CButton butb(300 - 30, 250 - 20, 60, 40, "返回", MyBlue);
	ofstream ofs;
	BeginBatchDraw();
	funM.DrawBg(resM.imageBg[4], 0, 0);
	butr.DrawButton();
	butb.DrawButton();
	EndBatchDraw();
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		if (butr.ClickButton(msg))
		{
			char id[100];
			char psd[100];
			char que[100];
			char asw[100];
			char score[100] = "NULL";
			/*LPCWSTR que1;
			LPCWSTR asw1;
			LPTSTR que2=0;
			LPTSTR asw2=0;*/
			HWND hnd = GetHWnd();//获取窗口句柄  hnd定义的变量
			if (InputBox(id, 100, "请输入账号", NULL, NULL, 0, 0, false))
			{
				if (id[0] != NULL)
				{
					if (InputBox(psd, 100, "请输入密码", NULL, NULL, 0, 0, false) &&
						InputBox(que, 100, "请输入密保问题", NULL, NULL, 0, 0, false))
					{
						if (que[0] != NULL)
						{
							/*que1 = (LPCWSTR) que2;
							char* asciiq = (char*) que1;*/

							if (InputBox(asw, 100, "请输入密保答案", NULL, NULL, 0, 0, false))
							{
								/*asw1 = (LPCWSTR)asw2;
								char* asciia = (char*)asw1;*/

								ofs.open("account.txt", ios::app);
								ofs << id << "\t";
								ofs << psd << "\t";
								ofs << que << "\t";
								ofs << asw << "\t";
								ofs << score << endl;
								ofs.close();
							}
						}
						else MessageBox(hnd, "密保问题不能为空！", "警告", MB_OKCANCEL);
					}


				}
				else MessageBox(hnd, "账号不能为空！", "警告", MB_OKCANCEL);
			}
		}
		if (butb.ClickButton(msg))
		{
			closegraph();
			return false;
		}
	}

}


/*忘记密码-拓展
	负责人:
	功能:
	1.画出忘记密码界面
	2.根据输入账号提供问题
	3.根据答案是否正确返回密码
	参数: void
	返回值: void
*/
bool CManager::GetPassword()//有bug
{
	InitSmall();
	CButton butl(300 - 40, 150 - 20, 80, 40, "获取密码", MyBlue);
	CButton butb(300 - 30, 250 - 20, 60, 40, "返回", MyBlue);
	ifstream ifs;

	BeginBatchDraw();
	funM.DrawBg(resM.imageBg[4], 0, 0);
	butl.DrawButton();
	butb.DrawButton();
	EndBatchDraw();
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		if (butl.ClickButton(msg))
		{

			char id[100];

			HWND hnd = GetHWnd();//获取窗口句柄  hnd定义的变量
			if (InputBox(id, 100, "请输入账号", NULL, NULL, 0, 0, false))
			{
				if (id[0] != NULL)
				{
					int myArray[99][5];

					ifstream inputfile("account.txt");//打开文件

					if (!inputfile.is_open()) cout << "Error opening file";
					bool exist = false;



					inputfile.seekg(0L, ios::beg);

					//===========================新
					char id1[100];//和id区分
					char psd[100];
					char que[100];
					char asw[100];
					char score[100] = "NULL";



					while (inputfile.peek() != EOF) {//最后一轮读到全空
						inputfile >> id1;
						inputfile >> psd;
						inputfile >> que;
						inputfile >> asw;
						inputfile >> score;

						if (issame(id, id1)) {//如果找到了对应账号

							exist = true;
							break;
						}
					}

					inputfile.close();
					if (exist) {//账号存在
						char s[100];
						if (InputBox(s, 100, que, NULL, NULL, 0, 0, false)) {
							if (issame(s, asw)) {//回答正确
								MessageBox(hnd, psd, "您的密码", MB_OKCANCEL);
							}
							else {
								MessageBox(hnd, "答案错误！", "提示", MB_OKCANCEL);
							}
						}
						else {
							MessageBox(hnd, "答案不能为空", "警告", MB_OKCANCEL);
						}
					}
					else {//账号不存在
						MessageBox(hnd, "账号不存在！", "提示", MB_OKCANCEL);
					}
				}
				else MessageBox(hnd, "账号不能为空！", "警告", MB_OKCANCEL);
			}

		}

		if (butb.ClickButton(msg))
		{
			closegraph();
			return false;
		}
	}
}
int* choice = new int(3);


/**************************Lobby******************************/
bool CManager::Lobby()//严晨
{


	//改了几个地方
	//把DrawLobby()删了 直接放在了Lobby()里  因为DrawLobby()不好获取按钮的数据
	// 把easyx.h改成了graphics.h 后者是前者的改进版
	// CButton的构造函数 中参数char* text1改为了const char* text1 不然会报错
	//还没有添加绘制贴图的功能 
	InitLarge();
	CButton role1(100, 150, 100, 40, "Java", MyBlue);
	CButton role2(400, 150, 100, 40, "C", MyBlue);
	CButton role3(700, 150, 100, 40, "C++", MyBlue);
	CButton weapon1(100, 200, 100, 100, "", WHITE);
	CButton weapon2(400, 200, 100, 100, "", WHITE);
	CButton weapon3(700, 200, 100, 100, "", WHITE);
	/*CButton prelevel(150, 400, 100, 50, "上一关", MyBlue);
	CButton nextlevel(650, 400, 100, 50, "下一关", MyBlue);*/
	CButton entergame(400, 425, 100, 50, "进入游戏", MyBlue);
	CButton quitgame(870, 10, 20, 20, "×", MyBlue);
	//330 128 r=32 (352,160)
	//150,250

	int rolechoose = 1;
	int weaponchoose = 1;
	int levelchoose = 1;
	int r = 15;//半径
	choice[0] = 0;
	while (true) {

		BeginBatchDraw();
		cleardevice();
		funM.DrawBg(resM.imageBg[3], resM.bgx, resM.bgy);

		//绘制所有按钮
		role1.DrawButton();
		role2.DrawButton();
		role3.DrawButton();
		weapon1.DrawButton();
		weapon2.DrawButton();
		weapon3.DrawButton();
		for (int i = 0; i < 3; i++)
		{
			putimage(150 + 300 * i - 32 + 10, 250 - 32, 2 * 32, 2 * 32, &resM.image0M[i], 330, 128, NOTSRCERASE);
			putimage(150 + 300 * i - 32 + 10, 250 - 32, 2 * 32, 2 * 32, &resM.image0B[i], 330, 128, SRCINVERT);
		}
		char text[50] = "请选择你的语言";
		settextcolor(MyBlue);
		outtextxy(450 - textwidth(text) / 2.0, 50 - textheight(text) / 2.0, text);
		/*prelevel.DrawButton();
		nextlevel.DrawButton();*/
		entergame.DrawButton();
		quitgame.DrawButton();


		//绘制表明选项的圆圈
		/*circle(150, 325, r);
		circle(450, 325, r);
		circle(750, 325, r);*/
		circle(150, 325, r);
		circle(450, 325, r);
		circle(750, 325, r);

		//根据当前选择填充圆圈
		/*switch (rolechoose) {
		case 1:fillcircle(150, 325, r); break;
		case 2:fillcircle(450, 325, r); break;
		case 3:fillcircle(750, 325, r); break;
		}*/
		switch (weaponchoose) {
		case 1:fillcircle(150, 325, r); break;
		case 2:fillcircle(450, 325, r); break;
		case 3:fillcircle(750, 325, r); break;
		}
		EndBatchDraw();
		//接收鼠标信息

		msg = getmessage(EX_MOUSE);
		//检测角色切换

		/*if (role1.ClickButton(msg)) {
			rolechoose = 1;
			choice[0] = 0;
		}
		if (role2.ClickButton(msg)) {
			rolechoose = 2;
			choice[0] = 1;
		}
		if (role3.ClickButton(msg)) {
			rolechoose = 3;
			choice[0] = 2;
		}*/
		//检测武器切换
		if (weapon1.ClickButton(msg)) {
			weaponchoose = 1;
			choice[0] = 0;
		}
		if (weapon2.ClickButton(msg)) {
			weaponchoose = 2;
			choice[0] = 1;
		}
		if (weapon3.ClickButton(msg)) {
			weaponchoose = 3;
			choice[0] = 2;
		}

		if (entergame.ClickButton(msg)) {
			return true;
		}
		//检测是否退出游戏
		if (quitgame.ClickButton(msg)) {
			return false;
		}
	}
	return false;
}

/*画大厅-核心
	负责人:
	功能:
	1.绘制大厅所有按钮 调用  DrawButton()
	2.绘制大厅所有贴图
	参数: void
	返回值: void
*/
//void CManager::DrawLobby() {
//	//功能
//	//绘制大厅所有按钮 调用  DrawButton()
//	//绘制大厅所有贴图
//	BeginBatchDraw();
//	cleardevice();
//	funM.LoadBg(resM.bgWidth, resM.windowHeight, "Resource/Picture/menu.png", resM.bgx, resM.bgy);
//	butStart.DrawButton();
//	EndBatchDraw();
//
//}

/*设置-拓展
	负责人:
	功能:
	1.绘制设置界面（按钮 贴图）
	2.检测是否有更换操作方式
	3.检测是否有更改音量
	4.检测是否点击返回大厅按钮
	参数: void
	返回值: void
*/
void CManager::OptionView() {
	//while(1){
	//绘制设置界面（按钮 贴图） 
	//检测是否有更换操作方式  
	//检测是否有更改音量  
	//检测是否点击返回大厅按钮   
	//}
}

/*充值-拓展
	负责人:
	功能:
	1.绘制充值界面（按钮 贴图）
	2.检测是否有更换购买物品
	3.检测是否点击支付
	4.检测是否点击返回大厅按钮
	参数: void
	返回值: void
*/
void CManager::ChargeView() {
	//while(1){
	//绘制充值界面（按钮 贴图） 
	//检测是否有更换购买物品  
	//检测是否点击支付  
	//检测是否点击返回大厅按钮  
	//}


}

/**************************Game******************************/
vector<double*>death_coo;	//存储怪物死亡坐标
CWeapon weapon[10];

char sweapon[9];
static int startTime;
static int surviveTime;

bool CManager::Game()//康乐
{
	int numMonster = 40;
	CWeapon weapon0(100, 0, 2, 0.5, choice[0], 0, &resM);
	CWeapon weapon1(100, 0, 2, 1, choice[0], 1, &resM);
	CWeapon weapon2(100, 0, 2, 1, choice[0], 2, &resM);
	CWeapon weapon3(100, 0, 2, 1, choice[0], 3, &resM);
	CWeapon weapon4(100, 0, 2, 1, choice[0], 4, &resM);
	CWeapon weapon5(100, 0, 2, 1, choice[0], 5, &resM);
	CWeapon weapon6(100, 0, 2, 1, choice[0], 6, &resM);
	CWeapon weapon7(100, 0, 2, 1, choice[0], 7, &resM);
	CWeapon weapon8(100, 0, 2, 1, choice[0], 8, &resM);

	startTime = clock() / 1000;
	PlayBgm("Resource/Audio/battle2.mp3");
	weapon[0] = weapon0;
	weapon[1] = weapon1;
	weapon[2] = weapon2;
	weapon[3] = weapon3;
	weapon[4] = weapon4;
	weapon[5] = weapon5;
	weapon[6] = weapon6;
	weapon[7] = weapon7;
	weapon[8] = weapon8;
	CHero h1(choice[0], 0, &resM);
	CHero* pHero = &h1;
	CButton butp(850 - 20, 40 - 20, 40, 30, "暂停", MyBlue);
	//DrawGame();
	int weaponLevel[99] = { 0 };
	int bulletcnt = 1;//子弹发射计数器 
	int bulletshot = 20;//一旦到达这个值 发射一枚子弹 然后计数器重回1 
	while (true)
	{
		if (butp.ClickButton(msg))
		{
			if (!Pause()) 
			{
				moster.clear();
				return false;
			}//选择返回大厅	
			else InitLarge();
		}
		BeginBatchDraw();
		cleardevice();
		double* attackH = new double[4];//存放英雄的攻击数据
		attackH[0] = pHero->ATK;//攻击力，下同
		attackH[1] = pHero->AR;//攻击半径，下同
		attackH[2] = pHero->ASD;//攻速，下同
		attackH[3] = pHero->indexA;//攻击帧，下同

		bool* isattackH = &pHero->attack;

		double* pBgv = new double[4];//存放背景移动数据、坐标	
		pBgv[0] = 0;
		pBgv[1] = 0;
		pBgv[2] = 0;
		pBgv[3] = 0;
		pBgv = pHero->Move(msg, pBgv);//通过Move函数更新背景的移动数据
		//cout << pHero->bgx << endl;

		if (funM.Timer(2000, 5) && numMonster > 0) {
			CreateMonster(1);
			numMonster--;
			if (numMonster == 0)
			{
				CreateMonster(-1);
			}
		}
		double* attackM = new double[4];//存放怪物的攻击数据

		const int framedelay = 1000 / 120;//帧率
		int framestart = 0;
		int frametime = 0;
		
		
		funM.DrawBg(resM.imageBg[5], 0, 0);
		settextstyle(60, 20, "微软雅黑");
		outtextxy(100, 100, "学海");
		outtextxy(233, 478, "学海");
		outtextxy(612, 55, "学海");
		outtextxy(769, 285, "学海");
		outtextxy(685, 455, "学海");
		funM.DrawBg(resM.imageBg[0], pHero->bgx, pHero->bgy);
		butp.DrawButton();
		settextcolor(RED);
		settextstyle(20, 0, "微软雅黑");
		/*outtextxy(250, 30, "BUG1：接收鼠标信息有延迟");
		outtextxy(250, 60, "BUG2：怪物偶尔相对背景静止（一般为角色水平或垂直移动时,贴着墙壁）");
		outtextxy(250, 90, "BUG3：攻击动画会闪）");*/
		char s[50];
		sprintf(s, "待生成怪物：%d", numMonster);
		outtextxy(750, 50, s);
		char t[50];
		surviveTime = clock() / 1000 - startTime;
		sprintf(t, "存活时间：%d", surviveTime);
		outtextxy(750, 80, t);
		//cout << numMonster << endl;

		pHero->Draw();

		if (pHero->level >= 7)
		{
			//画子弹
			setfillcolor(BLUE);
			bullet.reserve(1000);
			for (int i = 0; i < bullet.size(); i++) {
				if (bullet[i]) {
					bullet[i]->move();
					bullet[i]->Drawbullet();

					for (auto m : moster) {
						int distance = sqrt((m->x - bullet[i]->x) * (m->x - bullet[i]->x) + (m->y - bullet[i]->y) * (m->y - bullet[i]->y));
						if (distance < 15) {//这个10是临界距离 小于临界距离判定为子弹击中
							m->HPb -= bullet[i]->val;//扣血
							if (m->HPb <= 0)
							{
								m->alive = false;
							}
							bullet.erase(bullet.begin() + i);
							break;
						}
					}

				}
			}

			for (auto it1 = moster.begin(); it1 != moster.end(); it1++)		//遍历所有怪物
			{
				(*it1)->Super();
				(*it1)->Draw();

				if (bulletcnt == bulletshot) {
					//计算最近的敌人 发射子弹   (发射时间间隔？)
					int min = INT_MAX;
					int X = 0;
					int Y = 0;
					int distance = sqrt(((*it1)->x - 450) * ((*it1)->x - 450) + ((*it1)->y - 300) * ((*it1)->y - 300));
					if (distance < min) {
						min = distance;
						X = (*it1)->x;
						Y = (*it1)->y;
					}
					int vx_;
					int vy_;
					if (min > 0)
					{
						vx_ = (X - 450) * bulletv / min;
						vy_ = (Y - 300) * bulletv / min;
					}
					else
					{
						vx_ = 0;
						vy_ = 0;
					}
					CBullet* B = new CBullet(450, 300, vx_, vy_);
					bullet.push_back(B);

					bulletcnt = 1;

				}
				else {
					bulletcnt++;
				}
			}
		}
		
		for (auto it1 = moster.begin(); it1 != moster.end(); it1++)		//遍历所有怪物
		{
			(*it1)->Draw();
		}

		for (int i = 0; i < death_coo.size(); i++)
		{
			death_coo[i][0] = death_coo[i][0] + pBgv[0];
			death_coo[i][1] = death_coo[i][1] + pBgv[1];
			if (pHero->level < 8)
			{
				weapon[int(death_coo[i][2])].DrawWeapon(death_coo[i][0], death_coo[i][1]);
			}
			
			if (pHero->Pick(weapon[(int)(death_coo[i][2])], death_coo[i][0], death_coo[i][1]))
			{
				//outtextxy(250, 30, "拾取成功");
				death_coo.erase(death_coo.begin() + i);
			}
			pHero->LevelUp(choice[0]);
		}

		
		frametime = clock() - framestart;
		if (framedelay > frametime)
		{
			Sleep(framedelay - frametime);
		}

		pHero->attack = false;

		for (int i = 0; i < moster.size(); i++)
		{
			moster[i]->attack = false;
			double* attackM = new double[4];//存放怪物的攻击数据
			attackM[0] = moster[i]->ATK;
			attackM[1] = moster[i]->AR;
			attackM[2] = moster[i]->ASD;
			attackM[3] = moster[i]->indexA;

			bool* isattackM = &moster[i]->attack;

			double* pMonsterxyr = new double[3];//存放怪物坐标和半径

			pMonsterxyr = moster[i]->Move(pBgv, pMonsterxyr, moster);
			int distance = sqrt(pow(moster[i]->x - h1.r, 2) + pow(moster[i]->y - h1.r, 2));
			int minDistance = moster[i]->r + h1.r;

			if (distance < minDistance)
			{
				// 如果与目标圆重叠，根据重叠的情况调整位置
				// 计算需要移动的距离
				int moveDistance = minDistance - distance;
				// 计算需要移动的方向
				int directionX = (resM.centerx - moster[i]->x) / distance;
				int directionY = (resM.centery - moster[i]->y) / distance;

				// 移动当前圆和目标圆
				moster[i]->x -= moveDistance * directionX;
				moster[i]->y -= moveDistance * directionY;
				//resM.centerx += moveDistance * directionX;
				//resM.centery += moveDistance * directionY;
			}
			if (pHero->Hurt(pMonsterxyr, attackM, isattackM)) moster[i]->attack = true;//根据怪物的坐标和半径、攻击数据判断英雄是否受伤
			if (!h1.alive)
			{
				moster.clear();
				delete[]attackH;
				return false;
			}
			if (moster[i]->Hurt(attackH, isattackH))
			{
				//pHero->attack = true;
			}
			//cout << moster.size();
			//cout << pHero->attack<<endl;

			if (!moster[i]->alive)						//如果怪物血量<=0,则移除容器			
			{
				if (surviveTime <= 20)
				{
					weaponLevel[i] = rand() % 3;//0 1 2
				}
				else if (surviveTime > 30 && surviveTime <= 40)
				{
					weaponLevel[i] = rand() % 3 + 3;//3 4 5 
				}
				else
				{
					weaponLevel[i] = rand() % 3 + 6;//6 7 8 
				}
				double* arr = new double [3] { moster[i]->x, moster[i]->y, double(weaponLevel[i])};
				//arr[0] = moster[i]->x;
				//arr[1] = moster[i]->y;
				double isGenWeapon;
				if (pHero->level < 8)
				{
					isGenWeapon = rand() % 3;
				}
				else
				{
					isGenWeapon = 0;
				}
				//cout << "ISG = " << isGenWeapon << endl;
				if (isGenWeapon >= 1)
				{
					death_coo.push_back(arr);
				}
				moster.erase(moster.begin() + i);
				delete[]pMonsterxyr;
				delete[]attackM;
			}
		}

		bool alldead = true;
		for (auto it1 = moster.begin(); it1 != moster.end(); it1++)		//遍历所有怪物
		{
			if ((*it1)->alive) alldead = false;
		}
		if (pHero->alive && alldead && numMonster == 0)
		{
			moster.clear();
			return true;
		}
		EndBatchDraw();
	}

}

void CManager::DrawGame()
{
	//功能
	//绘制大厅所有按钮 调用  DrawButton()
	//绘制大厅所有贴图
	BeginBatchDraw();
	cleardevice();
	funM.DrawBg(resM.imageBg[4], resM.bgx, resM.bgy);
	EndBatchDraw();
}

/*生成怪物-核心
	负责人:
	功能: 随机生成怪物，根据不同等级，生成总数不同，生成速度不同（自定）
	参数: 难度等级
	返回值: void
*/
//vector<class CMonster*>monster
void CManager::CreateMonster(int levelx)
{

	double _x = rand() % resM.bgWidth;
	double _y = rand() % resM.bgHeight;
	switch (levelx)
	{
	case 1:
		if (funM.Timer(2000, 0))		//0.5秒生成一个怪物
		{
			int levelM = 0;
			if (surviveTime <= 40)
			{
				levelM = rand() % 2;//0 1
			}
			else if (surviveTime > 40 && surviveTime <= 60)
			{
				levelM = rand() % 3 + 1;//1 2 3
			}
			else if (surviveTime > 60)
			{
				levelM = rand() % 3 + 2;//2 3 4
			}
			CMonster* m = new CMonster(_x, _y, levelM, &resM);
			moster.push_back(m);
			break;
		}
		//case 2:
		//	if (funM.Timer(250, 1))		//0.25秒生成一个怪物
		//	{
		//		CMonster* m = new CMonster(_x, _y, 10 * 2, 20 * 2, 1 * 2, 2 * 2, 1 * 2, &resM);
		//		moster.push_back(m);
		//		break;
		//	}
		//case 3:
		//	if (funM.Timer(100, 2))		//0.1秒生成一个怪物
		//	{
		//		CMonster* m = new CMonster(_x, _y, 10 * 3, 20 * 3, 1 * 3, 2 * 3, 1 * 3, &resM);
		//		moster.push_back(m);
		//		break;
		//	}
	case -1:
	{
		CMonster* m = new CMonster(_x, _y, 5, &resM);
		moster.push_back(m);
		break;
	}
	default:
		break;
	}
}
//装备掉落、拾取//装备类 
//判断人物是否受伤，如果受伤，调用Hert();										
//判断怪物是否受伤，如果受伤, 调用Hert();											
//如果怪物死亡，从容器中去除；																													
//如果点击暂停按纽，调用暂停界面；									
//如果人物死亡调用结算界面

/*暂停-拓展
	负责人:
	功能:
	1.绘制暂停背景
	2.在指定位置绘制按钮（继续游戏，设置，返回大厅）
	3.判断鼠标点击位置
	4.点击继续游戏，	返回游戏界面
	5.点击设置，		调用设置界面
	6.点击返回大厅，	调用大厅界面
	参数: void
	返回值: void
*/
bool CManager::Pause()		//暂停界面
{
	InitSmall();
	CButton butb(400 - 50, 350 - 30, 100, 40, "返回大厅", MyBlue);
	CButton butc(200 - 50, 350 - 30, 100, 40, "继续游戏", MyBlue);

	double volumex = 300;
	bool isdown = false;
	while (true)
	{
		Volume();
		BeginBatchDraw();
		cleardevice();
		funM.DrawBg(resM.imageBg[4], 0, 0);

		setlinecolor(WHITE);
		setlinestyle(PS_SOLID, 3);
		line(200, 150, 400, 150);

		setlinecolor(RED);
		setlinestyle(PS_SOLID, 3);
		line(200, 150, volumex, 150);
		CButton butv(volumex - 5, 150 - 5, 10, 10, "", RED);
		settextcolor(RED);
		setbkmode(TRANSPARENT);
		settextstyle(20, 0, "微软雅黑");
		char s[] = "音量";
		funM.MyOutText(170, 150, s);

		settextstyle(20, 0, "微软雅黑");
		char s2[10];
		sprintf(s2, "%d", volume);
		funM.MyOutText(430, 150, s2);

		settextstyle(60, 0, "微软雅黑");
		char s1[] = "图灵院幸存者";
		funM.MyOutText(300, 40, s1);
		butb.DrawButton();
		butc.DrawButton();
		butv.DrawButton();
		EndBatchDraw();
		if (peekmessage(&msg, EX_MOUSE)) {}
		//cout << funM.InArea(msg.x, msg.y, butv.x, butv.y, butv.w, butv.h)<<"         " << volumex << endl;
		if (msg.message == WM_LBUTTONDOWN && funM.InArea(msg.x, msg.y, butv.x, butv.y, butv.w, butv.h) && volumex >= 200 && volumex <= 400)
		{
			isdown = true;
		}
		if (isdown && volumex >= 200 && volumex <= 400) volumex = msg.x;
		if (volumex < 200) volumex = 200;
		if (volumex > 400) volumex = 400;
		volume = (volumex - 200) * 5;
		if (msg.message == WM_LBUTTONUP)
		{
			isdown = false;
		}
		if (butb.ClickButton(msg))
		{
			closegraph();
			return false;
		}
		if (butc.ClickButton(msg))
		{
			closegraph();
			return true;
		}
	}
}

/*结算-核心
	负责人:
	功能:
	1.绘制结算背景
	2.绘制按钮（返回大厅）
	3.如果点击按钮，调用大厅界面
	参数: void
	返回值: void
*/
bool CManager::Settlement(bool r)		//结算界面
{
	//绘制结算背景
	//绘制按钮（返回大厅）
	//如果点击按钮，	调用大厅界
	PlayBgm("Resource/Audio/menu.mp3");
	InitLarge();
	while (true)
	{
		BeginBatchDraw();
		setbkcolor(WHITE);
		cleardevice();
		funM.DrawBg(resM.imageBg[6], 0, 0);
		CButton backLobby(400, 400, 100, 50, "返回大厅", MyBlue);
		backLobby.DrawButton();
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char text1[50] = "恭喜您活着离开图灵院！ ";
		char text2[50];
		char text3[50];
		char text4[50];
		sprintf(text2, "很遗憾您只在图灵院存活了：%d天", surviveTime);
		sprintf(text3, "通关时间：%d天", surviveTime);
		int wage = 100 - (surviveTime - 80) / 2;
		if (wage < 10) wage = 10;
		sprintf(text4, "获得年薪：%d万", wage);
		if (r)
		{
			outtextxy(450 - textwidth(text1) / 2, 100 - textheight(text1) / 2, text1);
			outtextxy(450 - textwidth(text3) / 2, 200 - textheight(text3) / 2, text3);
			outtextxy(450 - textwidth(text4) / 2, 300 - textheight(text4) / 2, text4);
		}

		else outtextxy(450 - textwidth(text2) / 2, 200 - textheight(text2) / 2, text2);

		if (peekmessage(&msg, EX_MOUSE)) {};
		if (backLobby.ClickButton(msg))
		{
			return true;
		}
		EndBatchDraw();
	}
}

