#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows,int cols,char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//排查雷
void SetMine(char mine[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//统计坐标周围有多少雷
//int get_mine__count(char mine[ROWS][COLS], int x, int y);此处头文件不用写，因为该函数是为了支持排查