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
CButton butLogIn(310-10, 420 + 10, 100, 40, "��¼", MyBlue);
CButton butRegister(490+10, 420 + 10, 100, 40, "ע��", MyBlue);
CButton butGuest(310-10, 500 + 20, 100, 40, "�ο͵�¼", MyBlue);
CButton butGetpassword(490+10, 500 + 20, 100, 40, "��������", MyBlue);
CButton butDeveloper(750, 50, 100, 30, "������Ա", RGB(184, 194, 202));
CButton butStart(390, 460, 80, 40, "��ʼ��Ϸ", MyBlue);
static int volume = 300;//0-1000

void PlayBgm(const char* music)//�������֣���������·��
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
bool CManager::Menu()//����
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

/*������Ա-��չ
	������:
	����:
	1.����������Ա����
	2.չʾ������Ա��Ϣ
	����: void
	����ֵ: void
*/
bool CManager::Developer()
{
	CButton back(870, 10, 20, 20, "��", MyBlue);
	CButton pagea(700 - 30, 500 - 20, 60, 40, "��һҳ", MyBlue);
	CButton paged(200 - 30, 500 - 20, 60, 40, "��һҳ", MyBlue);
	int page = 0;
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}

		BeginBatchDraw();
		cleardevice();
		funM.DrawBg(resM.imageBg[2], resM.bgx, resM.bgy);//���ߡ�·�������Ͻ�x�����Ͻ�y
		back.DrawButton();
		pagea.DrawButton();
		paged.DrawButton();
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		if (pagea.ClickButton(msg)) page = 1;
		if (paged.ClickButton(msg)) page = 0;
		if (page == 0)
		{
			//������ɫ����Ҫ��Ϊ��ɫ�����������Ϊ��ɫ
			putimage(50, 75 + 25, &resM.imageD[5]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(50, 20 + 25, "Ƚ����");
			outtextxy(50, 45 + 25, "VS2022 ����");

			putimage(330, 75 + 25, &resM.imageD[8]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(330, 20 + 25, "���ϳ�");
			outtextxy(330, 45 + 25, "ԭ������");

			putimage(610, 75 + 25, &resM.imageD[6]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(610, 20 + 25, "̷�ܷ�");
			//            ������δ��
			outtextxy(610, 45 + 25, "���ɱ���Цһʱ�����ɱ���Цһ��");

			putimage(50, 265 + 50, &resM.imageD[1]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(50, 210 + 50, "lemon");
			outtextxy(50, 235 + 50, "����д��Խ���������ܵ�Խ��");

			putimage(330, 265 + 50, &resM.imageD[2]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(330, 210 + 50, "����");
			outtextxy(330, 235 + 50, "���������У�Ψbug������");

			putimage(610, 260 + 50, &resM.imageD[3]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(610, 210 + 50, "������");
			//            ������δ��
			outtextxy(610, 235 + 50, "�ڼ������ͷû���κκ�ħ��������");
			outtextxy(610, 235 + 70, "�Ķ���ֻ�����������ڲ�֪������");
		}
		if (page == 1)
		{
			putimage(50, 75 + 25, &resM.imageD[9]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(50, 20 + 25, "֣����");
			outtextxy(50, 45 + 25, "��ǿ����ǿ������ɽ��");

			putimage(330, 75 + 25, &resM.imageD[7]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(330, 20 + 25, "��ʢ��");
			outtextxy(330, 45 + 25, "�������δ�볡");

			putimage(610, 75 + 25, &resM.imageD[4]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(610, 20 + 25, "�ȷ���");
			outtextxy(610, 45+25, "���꣺�㲻����ϲ������緭�̾���");

			putimage(50, 265 + 50, &resM.imageD[0]);
			settextstyle(24, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			outtextxy(50, 210 + 50, "����Сѧ��");
			//outtextxy(50, 235 + 50, "����д��Խ���������ܵ�Խ��");
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

/*�˵�-����
	������:
	����:
	1.�����˵�����putimage()
	2.������ť��
	����: void
	����ֵ: void
*/
void CManager::DrawMenu()//������ο�
{
	BeginBatchDraw();
	cleardevice();
	funM.DrawBg(resM.imageBg[1], resM.bgx, resM.bgy);//���ߡ�·�������Ͻ�x�����Ͻ�y
	butLogIn.DrawButton();
	butRegister.DrawButton();
	butGuest.DrawButton();
	butGetpassword.DrawButton();
	butDeveloper.DrawButton();
	EndBatchDraw();
	//������
	//����ť DrawButton()
}












/*��¼-����(�ο͵�¼-��չ)
	������:
	����:
	1.��������
	if(�˺Ų�����)
	{
		��ʾ
	}
	else if(�˺Ŵ��ڵ����벻��)
	{
		��ʾ
	}
	else
		return true;
	����: void
	����ֵ: bool
*/
bool CManager::LogIn()
{
	InitSmall();
	CButton butl(300 - 30, 150 - 20, 60, 40, "��¼", MyBlue);
	CButton butb(300 - 30, 250 - 20, 60, 40, "����", MyBlue);
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
			HWND hnd = GetHWnd();//��ȡ���ھ��  hnd����ı���
			if (InputBox(id, 100, "�������˺�", NULL, NULL, 0, 0, false))
			{
				if (id[0] != NULL)
				{
					bool exist = false;//�ж��˺Ŵ治����

					char id1[100];//��id����
					char psd[100];
					char que[100];
					char asw[100];
					char score[100] = "NULL";

					ifs.seekg(0L, ios::beg);

					while (ifs.peek() != EOF) {//���һ�ֶ���ȫ��
						ifs >> id1;
						ifs >> psd;
						ifs >> que;
						ifs >> asw;
						ifs >> score;

						if (issame(id, id1)) {//����ҵ��˶�Ӧ�˺�
							exist = true;

							break;
						}
					}
					ifs.close();
					if (exist) {//�˺Ŵ���
						char psd1[100];
						if (InputBox(psd1, 100, "����������", NULL, NULL, 0, 0, false)) {
							if (issame(psd, psd1)) {
								MessageBox(hnd, "��¼�ɹ���", "��ʾ", MB_OKCANCEL);
								ID = atoi(id);
								return true;
							}
							else {
								MessageBox(hnd, "�������", "��ʾ", MB_OKCANCEL);
							}
						}
						else {
							MessageBox(hnd, "���벻��Ϊ�գ�", "����", MB_OKCANCEL);
						}
					}
					else {//�˺Ų�����
						MessageBox(hnd, "�˺Ų����ڣ�", "��ʾ", MB_OKCANCEL);
					}
				}
				else MessageBox(hnd, "�˺Ų���Ϊ�գ�", "����", MB_OKCANCEL);
			}
		}
		if (butb.ClickButton(msg))
		{
			closegraph();
			return false;
		}
	}
}


/*ע��-��չ
	������:
	����:
	1.����ע�����
	2.��������
	if(�˺Ų�����Ҫ��)
	{
		��ʾ������ע��
	}
	else if(�˺ŷ���Ҫ���Ѿ�����)
	{
		��ʾ������ע��
	}
	else
		��ʾע��ɹ������ز˵�

	����: void
	����ֵ: void
*/
bool CManager::Register()
{
	InitSmall();
	CButton butr(300 - 30, 150 - 20, 60, 40, "ע��", MyBlue);
	CButton butb(300 - 30, 250 - 20, 60, 40, "����", MyBlue);
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
			HWND hnd = GetHWnd();//��ȡ���ھ��  hnd����ı���
			if (InputBox(id, 100, "�������˺�", NULL, NULL, 0, 0, false))
			{
				if (id[0] != NULL)
				{
					if (InputBox(psd, 100, "����������", NULL, NULL, 0, 0, false) &&
						InputBox(que, 100, "�������ܱ�����", NULL, NULL, 0, 0, false))
					{
						if (que[0] != NULL)
						{
							/*que1 = (LPCWSTR) que2;
							char* asciiq = (char*) que1;*/

							if (InputBox(asw, 100, "�������ܱ���", NULL, NULL, 0, 0, false))
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
						else MessageBox(hnd, "�ܱ����ⲻ��Ϊ�գ�", "����", MB_OKCANCEL);
					}


				}
				else MessageBox(hnd, "�˺Ų���Ϊ�գ�", "����", MB_OKCANCEL);
			}
		}
		if (butb.ClickButton(msg))
		{
			closegraph();
			return false;
		}
	}

}


/*��������-��չ
	������:
	����:
	1.���������������
	2.���������˺��ṩ����
	3.���ݴ��Ƿ���ȷ��������
	����: void
	����ֵ: void
*/
bool CManager::GetPassword()//��bug
{
	InitSmall();
	CButton butl(300 - 40, 150 - 20, 80, 40, "��ȡ����", MyBlue);
	CButton butb(300 - 30, 250 - 20, 60, 40, "����", MyBlue);
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

			HWND hnd = GetHWnd();//��ȡ���ھ��  hnd����ı���
			if (InputBox(id, 100, "�������˺�", NULL, NULL, 0, 0, false))
			{
				if (id[0] != NULL)
				{
					int myArray[99][5];

					ifstream inputfile("account.txt");//���ļ�

					if (!inputfile.is_open()) cout << "Error opening file";
					bool exist = false;



					inputfile.seekg(0L, ios::beg);

					//===========================��
					char id1[100];//��id����
					char psd[100];
					char que[100];
					char asw[100];
					char score[100] = "NULL";



					while (inputfile.peek() != EOF) {//���һ�ֶ���ȫ��
						inputfile >> id1;
						inputfile >> psd;
						inputfile >> que;
						inputfile >> asw;
						inputfile >> score;

						if (issame(id, id1)) {//����ҵ��˶�Ӧ�˺�

							exist = true;
							break;
						}
					}

					inputfile.close();
					if (exist) {//�˺Ŵ���
						char s[100];
						if (InputBox(s, 100, que, NULL, NULL, 0, 0, false)) {
							if (issame(s, asw)) {//�ش���ȷ
								MessageBox(hnd, psd, "��������", MB_OKCANCEL);
							}
							else {
								MessageBox(hnd, "�𰸴���", "��ʾ", MB_OKCANCEL);
							}
						}
						else {
							MessageBox(hnd, "�𰸲���Ϊ��", "����", MB_OKCANCEL);
						}
					}
					else {//�˺Ų�����
						MessageBox(hnd, "�˺Ų����ڣ�", "��ʾ", MB_OKCANCEL);
					}
				}
				else MessageBox(hnd, "�˺Ų���Ϊ�գ�", "����", MB_OKCANCEL);
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
bool CManager::Lobby()//�ϳ�
{


	//���˼����ط�
	//��DrawLobby()ɾ�� ֱ�ӷ�����Lobby()��  ��ΪDrawLobby()���û�ȡ��ť������
	// ��easyx.h�ĳ���graphics.h ������ǰ�ߵĸĽ���
	// CButton�Ĺ��캯�� �в���char* text1��Ϊ��const char* text1 ��Ȼ�ᱨ��
	//��û����ӻ�����ͼ�Ĺ��� 
	InitLarge();
	CButton role1(100, 150, 100, 40, "Java", MyBlue);
	CButton role2(400, 150, 100, 40, "C", MyBlue);
	CButton role3(700, 150, 100, 40, "C++", MyBlue);
	CButton weapon1(100, 200, 100, 100, "", WHITE);
	CButton weapon2(400, 200, 100, 100, "", WHITE);
	CButton weapon3(700, 200, 100, 100, "", WHITE);
	/*CButton prelevel(150, 400, 100, 50, "��һ��", MyBlue);
	CButton nextlevel(650, 400, 100, 50, "��һ��", MyBlue);*/
	CButton entergame(400, 425, 100, 50, "������Ϸ", MyBlue);
	CButton quitgame(870, 10, 20, 20, "��", MyBlue);
	//330 128 r=32 (352,160)
	//150,250

	int rolechoose = 1;
	int weaponchoose = 1;
	int levelchoose = 1;
	int r = 15;//�뾶
	choice[0] = 0;
	while (true) {

		BeginBatchDraw();
		cleardevice();
		funM.DrawBg(resM.imageBg[3], resM.bgx, resM.bgy);

		//�������а�ť
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
		char text[50] = "��ѡ���������";
		settextcolor(MyBlue);
		outtextxy(450 - textwidth(text) / 2.0, 50 - textheight(text) / 2.0, text);
		/*prelevel.DrawButton();
		nextlevel.DrawButton();*/
		entergame.DrawButton();
		quitgame.DrawButton();


		//���Ʊ���ѡ���ԲȦ
		/*circle(150, 325, r);
		circle(450, 325, r);
		circle(750, 325, r);*/
		circle(150, 325, r);
		circle(450, 325, r);
		circle(750, 325, r);

		//���ݵ�ǰѡ�����ԲȦ
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
		//���������Ϣ

		msg = getmessage(EX_MOUSE);
		//����ɫ�л�

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
		//��������л�
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
		//����Ƿ��˳���Ϸ
		if (quitgame.ClickButton(msg)) {
			return false;
		}
	}
	return false;
}

/*������-����
	������:
	����:
	1.���ƴ������а�ť ����  DrawButton()
	2.���ƴ���������ͼ
	����: void
	����ֵ: void
*/
//void CManager::DrawLobby() {
//	//����
//	//���ƴ������а�ť ����  DrawButton()
//	//���ƴ���������ͼ
//	BeginBatchDraw();
//	cleardevice();
//	funM.LoadBg(resM.bgWidth, resM.windowHeight, "Resource/Picture/menu.png", resM.bgx, resM.bgy);
//	butStart.DrawButton();
//	EndBatchDraw();
//
//}

/*����-��չ
	������:
	����:
	1.�������ý��棨��ť ��ͼ��
	2.����Ƿ��и���������ʽ
	3.����Ƿ��и�������
	4.����Ƿ������ش�����ť
	����: void
	����ֵ: void
*/
void CManager::OptionView() {
	//while(1){
	//�������ý��棨��ť ��ͼ�� 
	//����Ƿ��и���������ʽ  
	//����Ƿ��и�������  
	//����Ƿ������ش�����ť   
	//}
}

/*��ֵ-��չ
	������:
	����:
	1.���Ƴ�ֵ���棨��ť ��ͼ��
	2.����Ƿ��и���������Ʒ
	3.����Ƿ���֧��
	4.����Ƿ������ش�����ť
	����: void
	����ֵ: void
*/
void CManager::ChargeView() {
	//while(1){
	//���Ƴ�ֵ���棨��ť ��ͼ�� 
	//����Ƿ��и���������Ʒ  
	//����Ƿ���֧��  
	//����Ƿ������ش�����ť  
	//}


}

/**************************Game******************************/
vector<double*>death_coo;	//�洢������������
CWeapon weapon[10];

char sweapon[9];
static int startTime;
static int surviveTime;

bool CManager::Game()//����
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
	CButton butp(850 - 20, 40 - 20, 40, 30, "��ͣ", MyBlue);
	//DrawGame();
	int weaponLevel[99] = { 0 };
	int bulletcnt = 1;//�ӵ���������� 
	int bulletshot = 20;//һ���������ֵ ����һö�ӵ� Ȼ��������ػ�1 
	while (true)
	{
		if (butp.ClickButton(msg))
		{
			if (!Pause()) 
			{
				moster.clear();
				return false;
			}//ѡ�񷵻ش���	
			else InitLarge();
		}
		BeginBatchDraw();
		cleardevice();
		double* attackH = new double[4];//���Ӣ�۵Ĺ�������
		attackH[0] = pHero->ATK;//����������ͬ
		attackH[1] = pHero->AR;//�����뾶����ͬ
		attackH[2] = pHero->ASD;//���٣���ͬ
		attackH[3] = pHero->indexA;//����֡����ͬ

		bool* isattackH = &pHero->attack;

		double* pBgv = new double[4];//��ű����ƶ����ݡ�����	
		pBgv[0] = 0;
		pBgv[1] = 0;
		pBgv[2] = 0;
		pBgv[3] = 0;
		pBgv = pHero->Move(msg, pBgv);//ͨ��Move�������±������ƶ�����
		//cout << pHero->bgx << endl;

		if (funM.Timer(2000, 5) && numMonster > 0) {
			CreateMonster(1);
			numMonster--;
			if (numMonster == 0)
			{
				CreateMonster(-1);
			}
		}
		double* attackM = new double[4];//��Ź���Ĺ�������

		const int framedelay = 1000 / 120;//֡��
		int framestart = 0;
		int frametime = 0;
		
		
		funM.DrawBg(resM.imageBg[5], 0, 0);
		settextstyle(60, 20, "΢���ź�");
		outtextxy(100, 100, "ѧ��");
		outtextxy(233, 478, "ѧ��");
		outtextxy(612, 55, "ѧ��");
		outtextxy(769, 285, "ѧ��");
		outtextxy(685, 455, "ѧ��");
		funM.DrawBg(resM.imageBg[0], pHero->bgx, pHero->bgy);
		butp.DrawButton();
		settextcolor(RED);
		settextstyle(20, 0, "΢���ź�");
		/*outtextxy(250, 30, "BUG1�����������Ϣ���ӳ�");
		outtextxy(250, 60, "BUG2������ż����Ա�����ֹ��һ��Ϊ��ɫˮƽ��ֱ�ƶ�ʱ,����ǽ�ڣ�");
		outtextxy(250, 90, "BUG3����������������");*/
		char s[50];
		sprintf(s, "�����ɹ��%d", numMonster);
		outtextxy(750, 50, s);
		char t[50];
		surviveTime = clock() / 1000 - startTime;
		sprintf(t, "���ʱ�䣺%d", surviveTime);
		outtextxy(750, 80, t);
		//cout << numMonster << endl;

		pHero->Draw();

		if (pHero->level >= 7)
		{
			//���ӵ�
			setfillcolor(BLUE);
			bullet.reserve(1000);
			for (int i = 0; i < bullet.size(); i++) {
				if (bullet[i]) {
					bullet[i]->move();
					bullet[i]->Drawbullet();

					for (auto m : moster) {
						int distance = sqrt((m->x - bullet[i]->x) * (m->x - bullet[i]->x) + (m->y - bullet[i]->y) * (m->y - bullet[i]->y));
						if (distance < 15) {//���10���ٽ���� С���ٽ�����ж�Ϊ�ӵ�����
							m->HPb -= bullet[i]->val;//��Ѫ
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

			for (auto it1 = moster.begin(); it1 != moster.end(); it1++)		//�������й���
			{
				(*it1)->Super();
				(*it1)->Draw();

				if (bulletcnt == bulletshot) {
					//��������ĵ��� �����ӵ�   (����ʱ������)
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
		
		for (auto it1 = moster.begin(); it1 != moster.end(); it1++)		//�������й���
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
				//outtextxy(250, 30, "ʰȡ�ɹ�");
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
			double* attackM = new double[4];//��Ź���Ĺ�������
			attackM[0] = moster[i]->ATK;
			attackM[1] = moster[i]->AR;
			attackM[2] = moster[i]->ASD;
			attackM[3] = moster[i]->indexA;

			bool* isattackM = &moster[i]->attack;

			double* pMonsterxyr = new double[3];//��Ź�������Ͱ뾶

			pMonsterxyr = moster[i]->Move(pBgv, pMonsterxyr, moster);
			int distance = sqrt(pow(moster[i]->x - h1.r, 2) + pow(moster[i]->y - h1.r, 2));
			int minDistance = moster[i]->r + h1.r;

			if (distance < minDistance)
			{
				// �����Ŀ��Բ�ص��������ص����������λ��
				// ������Ҫ�ƶ��ľ���
				int moveDistance = minDistance - distance;
				// ������Ҫ�ƶ��ķ���
				int directionX = (resM.centerx - moster[i]->x) / distance;
				int directionY = (resM.centery - moster[i]->y) / distance;

				// �ƶ���ǰԲ��Ŀ��Բ
				moster[i]->x -= moveDistance * directionX;
				moster[i]->y -= moveDistance * directionY;
				//resM.centerx += moveDistance * directionX;
				//resM.centery += moveDistance * directionY;
			}
			if (pHero->Hurt(pMonsterxyr, attackM, isattackM)) moster[i]->attack = true;//���ݹ��������Ͱ뾶�����������ж�Ӣ���Ƿ�����
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

			if (!moster[i]->alive)						//�������Ѫ��<=0,���Ƴ�����			
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
		for (auto it1 = moster.begin(); it1 != moster.end(); it1++)		//�������й���
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
	//����
	//���ƴ������а�ť ����  DrawButton()
	//���ƴ���������ͼ
	BeginBatchDraw();
	cleardevice();
	funM.DrawBg(resM.imageBg[4], resM.bgx, resM.bgy);
	EndBatchDraw();
}

/*���ɹ���-����
	������:
	����: ������ɹ�����ݲ�ͬ�ȼ�������������ͬ�������ٶȲ�ͬ���Զ���
	����: �Ѷȵȼ�
	����ֵ: void
*/
//vector<class CMonster*>monster
void CManager::CreateMonster(int levelx)
{

	double _x = rand() % resM.bgWidth;
	double _y = rand() % resM.bgHeight;
	switch (levelx)
	{
	case 1:
		if (funM.Timer(2000, 0))		//0.5������һ������
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
		//	if (funM.Timer(250, 1))		//0.25������һ������
		//	{
		//		CMonster* m = new CMonster(_x, _y, 10 * 2, 20 * 2, 1 * 2, 2 * 2, 1 * 2, &resM);
		//		moster.push_back(m);
		//		break;
		//	}
		//case 3:
		//	if (funM.Timer(100, 2))		//0.1������һ������
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
//װ�����䡢ʰȡ//װ���� 
//�ж������Ƿ����ˣ�������ˣ�����Hert();										
//�жϹ����Ƿ����ˣ��������, ����Hert();											
//���������������������ȥ����																													
//��������ͣ��Ŧ��������ͣ���棻									
//��������������ý������

/*��ͣ-��չ
	������:
	����:
	1.������ͣ����
	2.��ָ��λ�û��ư�ť��������Ϸ�����ã����ش�����
	3.�ж������λ��
	4.���������Ϸ��	������Ϸ����
	5.������ã�		�������ý���
	6.������ش�����	���ô�������
	����: void
	����ֵ: void
*/
bool CManager::Pause()		//��ͣ����
{
	InitSmall();
	CButton butb(400 - 50, 350 - 30, 100, 40, "���ش���", MyBlue);
	CButton butc(200 - 50, 350 - 30, 100, 40, "������Ϸ", MyBlue);

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
		settextstyle(20, 0, "΢���ź�");
		char s[] = "����";
		funM.MyOutText(170, 150, s);

		settextstyle(20, 0, "΢���ź�");
		char s2[10];
		sprintf(s2, "%d", volume);
		funM.MyOutText(430, 150, s2);

		settextstyle(60, 0, "΢���ź�");
		char s1[] = "ͼ��Ժ�Ҵ���";
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

/*����-����
	������:
	����:
	1.���ƽ��㱳��
	2.���ư�ť�����ش�����
	3.��������ť�����ô�������
	����: void
	����ֵ: void
*/
bool CManager::Settlement(bool r)		//�������
{
	//���ƽ��㱳��
	//���ư�ť�����ش�����
	//��������ť��	���ô�����
	PlayBgm("Resource/Audio/menu.mp3");
	InitLarge();
	while (true)
	{
		BeginBatchDraw();
		setbkcolor(WHITE);
		cleardevice();
		funM.DrawBg(resM.imageBg[6], 0, 0);
		CButton backLobby(400, 400, 100, 50, "���ش���", MyBlue);
		backLobby.DrawButton();
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char text1[50] = "��ϲ�������뿪ͼ��Ժ�� ";
		char text2[50];
		char text3[50];
		char text4[50];
		sprintf(text2, "���ź���ֻ��ͼ��Ժ����ˣ�%d��", surviveTime);
		sprintf(text3, "ͨ��ʱ�䣺%d��", surviveTime);
		int wage = 100 - (surviveTime - 80) / 2;
		if (wage < 10) wage = 10;
		sprintf(text4, "�����н��%d��", wage);
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

