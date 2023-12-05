#include<easyx.h>
#include"CManager.h"
#include"CResource.h"
#include"CFunction.h"
#include<time.h>
#include<iostream>

using namespace std;
//不贴图，写核心

//函数命名规则
//类命名 C开头 首字母大写 
//函数命名 大驼峰法 InArea
//变量命名 小驼峰法 pathMask[50]


int main()
{
	CManager man1;
	while (true)
	{
		bool choice1 = man1.Menu();//主菜单
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
