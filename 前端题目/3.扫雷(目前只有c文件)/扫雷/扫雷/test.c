#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("**************************************\n");
	printf("***********    1.play      ***********\n");
	printf("***********    0.exit      ***********\n");
	printf("**************************************\n");
}
void game()
{
	//1.布置雷
	//2.排雷
	//雷の信息存储:
    //1.布置好的雷
	//2.排出的雷
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//扫雷
	FindMine(mine,show,ROW,COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:printf("退出游戏\n");
			break;
		default:
			printf("选择错误,重新选择!\n");
			break;
		}
	} while (input);
}
int main()
{
	printf("扫雷\n");
	test();
	return 0;
}