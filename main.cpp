#include<easyx.h>
#include"CManager.h"
#include"CResource.h"
#include"CFunction.h"
#include<time.h>
#include<iostream>

using namespace std;
//����ͼ��д����

//������������
//������ C��ͷ ����ĸ��д 
//�������� ���շ巨 InArea
//�������� С�շ巨 pathMask[50]


int main()
{
	CManager man1;
	while (true)
	{
		bool choice1 = man1.Menu();//���˵�
		if (choice1)
		{
			//Sleep(500);
			while (true)
			{
				bool choice2 = man1.Lobby();
				if (choice2)
				{
					
					bool choice3 = man1.Game();
					bool choice4 = man1.Settlement(choice3);
					choice3 = false;
				}
				else break;
			}
			
		}
	}
		
	return 0;
}
