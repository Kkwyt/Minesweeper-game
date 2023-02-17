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
	printf("--------------ɨ����Ϸ-----------\n");
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EASY_COUNT;
	
	while (count)
	{
		//��������±�
		int x = rand() % row + 1;//��Ϊ��ʱģ9�õ���������0��8��
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
		
	}
}

//static��������
//���ξֲ�����
//����ȫ�ֱ���
//���κ���

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
	//1�������Ų�����
	//2����������ǲ�����
		//(1)�������==��ը��==����Ϸ����
		//(2)���������==��ͳ����Χ�м�����--�洢�Ų��׵���Ϣ��show���飬��Ϸ����

	int x = 0;
	int y = 0;
	int win = 0;

	while (win<row*col-EASY_COUNT)
	{
		printf("������Ҫ�Ų�����꣺\n");
		scanf_s("%d %d", &x, &y);
		//x=[1,9];y=[1,9]

		//�ж���ߵĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź���You were killed\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//ͳ��������Χ�ж�����
				int count = get_mine_count(mine, x, y);
				//�ַ�0��ASCII��ֵ��48
				//count+'0'  --�� ���Եõ���Ե�ASCII��ֵ
				show[x][y] = count + '0';
				//��ʾ�Ų�����Ϣ
				DisplayBoard(show, row, col);

			}
		}
		else
		{
			printf("���겻�Ϸ�\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
		DisplayBoard(mine, row, col);
	}
}