#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------扫雷游戏-----------\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY_COUNT;
	
	while (count)
	{
		//生产随机下标
		int x = rand() % row + 1;//因为此时模9得到的余数是0到8；
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
		
	}
}

//static三个作用
//修饰局部变量
//修饰全局变量
//修饰函数

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1、输入排查坐标
	//2、检查坐标是不是雷
		//(1)如果是雷==》炸弹==》游戏结束
		//(2)如果不是雷==》统计周围有几个雷--存储排查雷的信息到show数组，游戏继续

	int x = 0;
	int y = 0;
	int win = 0;

	while (win<row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标：\n");
		scanf_s("%d %d", &x, &y);
		//x=[1,9];y=[1,9]

		//判断左边的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，You were killed\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//统计坐标周围有多少雷
				int count = get_mine_count(mine, x, y);
				//字符0的ASCII码值是48
				//count+'0'  --》 可以得到相对的ASCII码值
				show[x][y] = count + '0';
				//显示排查后的信息
				DisplayBoard(show, row, col);

			}
		}
		else
		{
			printf("坐标不合法\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}