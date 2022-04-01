#include<stdio.h>
#include<graphics.h>
#include<conio.h>
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
	RIGHT,
};
//蛇的结构
struct Snake
{
	int size;//蛇的节数
	int dir;//蛇的方向
	int speed;//移动速度
	POINT coor[SNAKE_NUM];//坐标 POINT:定义好的结构体，含x、y
}snake;

//数据的初始化
void GameInit(){
	//init初始化grapg图形窗口,SHOWCONSOLE：显示控制台
	initgraph(640, 480);
	//初始化蛇,一开始三节
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;//蛇的方向
	for (int i = 0; i < snake.size; i++) {
		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10; 
	}
}

void GameDraw() {
	//双缓冲绘图
	BeginBatchDraw();
	//设置背景颜色
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//绘制蛇
	setfillcolor(rad10); //蛇的颜色
	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	EndBatchDraw();
}

//移动蛇
void snakeMove() {
	//移动是x y发生改变
	for (int i = 0; i < snake.size; i++) {
			switch (snake.dir){
			case UP:
				snake.coor[i].y--;
				break;
			case DOWN:
				snake.coor[i].y++;
				break;
			case LEFT:
				snake.coor[i].x--;
				break;
			case RIGHT:
				snake.coor[i].x++;
				break;
		}	
		snake.coor[i].x++;
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
			snake.dir = UP;
			break;
		case 's':
		case 'S':
		case 80:
			snake.dir = DOWN;
			break;
		case 'a':
		case 'A':
		case 75:
			snake.dir = LEFT;
			break;
		case 'd':
		case 'D':
		case 77:
			snake.dir = RIGHT;
			break;
		}
	}
	
}

int main(){
	GameInit();
	GameDraw();
	
	while (1) {
		GameDraw();
		snakeMove();
		keyControl();
		Sleep(20);
	}

	return 0;
}