#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
/*
	贪吃蛇
	知识点：结构体，循环，函数，easyx，数组
	easyx：图形界面库
*/

//做界面1：创建一个窗口，图形窗口
#define SNAKE_NUM 500 //蛇的最大节数
//表示蛇的方向
enum DIR {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
//蛇的结构
struct Snake
{
	int size;//蛇的节数
	int dir;//蛇的方向
	int speed;//移动速度
	POINT coor[SNAKE_NUM];//坐标 POINT:定义好的结构体，含x、y
}snake;
//食物结构
struct Food{
	int x;
	int y;
	int r;	//食物大小
	bool flag;	//食物是否被吃
	DWORD color; // 食物颜色
}food;


//数据的初始化
void GameInit(){
	//init初始化grapg图形窗口,SHOWCONSOLE：显示控制台
	initgraph(640, 640);
	//设置随机数种子
	srand(GetTickCount());//GetTickCount()获取系统开机到现在所经过的毫秒数
	//初始化蛇,一开始三节
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;//蛇的方向
	for (int i = 0; i < snake.size; i++) {
		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10; 
	}

	//初始化食物,rand()随机产生一个整数，如果没有设置随机数种子，每次产生的都是固定整数
	//设置种子需要头文件 stdlib.h,一般把时间作为种子，因为变化
	
	food.x = rand()%640;
	food.y = rand()%480;
	food.color = RGB(rand()%256, rand()%256, rand()%256);
	food.r = rand()%10 + 5;
	food.flag = true;
	printf("%d %d,", food.x, food.y);
}

void GameDraw() {
	//双缓冲绘图
	BeginBatchDraw();
	//设置背景颜色
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//绘制蛇
	setfillcolor(GREEN); //蛇的颜色
	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制食物
	if (food.flag) {
		solidcircle(food.x, food.y, food.color);
	}
	EndBatchDraw();
	
}

//移动蛇
void snakeMove() {
	//让身体跟着头移动
	for (int i = snake.size-1; i > 0; i--) {
		
		snake.coor[i] = snake.coor[i - 1];
	}
	//移动是x y发生改变
	switch (snake.dir) {
		case UP:
			snake.coor[0].y -= snake.speed;
			if (snake.coor[0].y + 10 <= 0) {	//超出了上面的边界
				snake.coor[0].y = 640;
			}
			break;
		case DOWN:
			snake.coor[0].y += snake.speed;
			if (snake.coor[0].y - 10 >= 640) {	//超出了下面的边界
				snake.coor[0].y = 0;
			}
			break;
		case LEFT:
			snake.coor[0].x -= snake.speed;
			if (snake.coor[0].x + 10 <= 0) {	//超出了左面的边界
				snake.coor[0].x = 640;
			}
			break;
		case RIGHT:
			snake.coor[0].x += snake.speed;
			if (snake.coor[0].x - 10 >= 640) {	//超出了右面的边界
				snake.coor[0].x = 0;
			}
			break;
	}	
}
//通过按键改变蛇的方向
void keyControl() {
	//判断有没有按键
	//检测是否有按键
	if (_kbhit()) {
		//72 80 75 77 上下左右键值
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			//改变方向
			if (snake.dir != DOWN) {
				snake.dir = UP;
			}
			break;
		case 's':
		case 'S':
		case 80:
			if (snake.dir != UP) {
				snake.dir = DOWN;
			}
			break;
		case 'a':
		case 'A':
		case 75:
			if (snake.dir != RIGHT) {
				snake.dir = LEFT;
			}
			break;
		case 'd':
		case 'D':
		case 77:
			if (snake.dir != LEFT) {
				snake.dir = RIGHT;
			}
			break;
		}
	}
}
void EatFodd() {
	if (snake.coor[0].x == food.x && snake.coor[0].y == food.y) {
		food.flag = false;
		snake.size++;
	}
}

int main(){
	GameInit();
	GameDraw();
	
	while (1) {
		snakeMove();
		GameDraw();
		keyControl();
		EatFodd();
		Sleep(50);
	}

	return 0;
}