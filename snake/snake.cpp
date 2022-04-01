#include<stdio.h>
#include<graphics.h>
/*
	贪吃蛇
	知识点：结构体，循环，函数，easyx，数组
	easyx：图形界面库
*/

//做界面1：创建一个窗口，图形窗口
#define SNAKE_NUM 500 //蛇的最大节数
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
	initgraph(640, 480, SHOWCONSOLE);
	//初始化蛇,一开始三节
	snake.size = 0;
	snake.speed = 10;
	snake.dir;
	for ( int i = snake.size-1; i >= 0; i--) {
		snake.coor[i].x = 10*i;
		snake.coor[i].y = 10; 
		printf("^? d% d%", snake.coor[i].x, snake.coor[i].y);
	}
	
}

void GameDraw() {
	//设置背景颜色
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//绘制蛇
	solidcircle(snake.coor[0].x, snake.coor[0].y, 5);
}


int main(){
	GameInit();
	GameDraw();

	while (1) {

	}

	return 0;
}