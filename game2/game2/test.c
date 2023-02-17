#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void menu()
{
	printf("###########################\n");
	printf("######## 【1】PLAY ########\n");
	printf("######## 【0】EXIT ########\n");
	printf("###########################\n");
}

void game()
{
	char mine[ROWS][COLS];//存放布置好雷的信息
	char show[ROWS][COLS];//存放排查好雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');//初始化为‘0’
	InitBoard(show, ROWS, COLS,'*');//初始化为‘*’
	//为了解决一个函数实现两种内容，所以之间传过去字符

	//打印一下棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
	DisplayBoard(mine, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择: \n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("欢迎进入扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择：\n");
			break;

		}
	} while (input);
	//括号里是input是1时候，玩第一次游戏回到主菜单
	//是0时候，do while语句停止
	//非0时候，又上来主菜单选择
	return 0;
}

//可以优化
//1、如果坐标不是雷，可以打开周围一圈
