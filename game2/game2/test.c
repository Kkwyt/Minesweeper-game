#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void menu()
{
	printf("###########################\n");
	printf("######## ��1��PLAY ########\n");
	printf("######## ��0��EXIT ########\n");
	printf("###########################\n");
}

void game()
{
	char mine[ROWS][COLS];//��Ų��ú��׵���Ϣ
	char show[ROWS][COLS];//����Ų���׵���Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');//��ʼ��Ϊ��0��
	InitBoard(show, ROWS, COLS,'*');//��ʼ��Ϊ��*��
	//Ϊ�˽��һ������ʵ���������ݣ�����֮�䴫��ȥ�ַ�

	//��ӡһ������
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//�Ų���
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
		printf("��ѡ��: \n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ӭ����ɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;

		}
	} while (input);
	//��������input��1ʱ�����һ����Ϸ�ص����˵�
	//��0ʱ��do while���ֹͣ
	//��0ʱ�����������˵�ѡ��
	return 0;
}

//�����Ż�
//1��������겻���ף����Դ���ΧһȦ
