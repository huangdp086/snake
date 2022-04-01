#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
/*
	̰����
	֪ʶ�㣺�ṹ�壬ѭ����������easyx������
	easyx��ͼ�ν����
*/

//������1������һ�����ڣ�ͼ�δ���
#define SNAKE_NUM 500 //�ߵ�������
//��ʾ�ߵķ���
enum DIR {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
//�ߵĽṹ
struct Snake
{
	int size;//�ߵĽ���
	int dir;//�ߵķ���
	int speed;//�ƶ��ٶ�
	POINT coor[SNAKE_NUM];//���� POINT:����õĽṹ�壬��x��y
}snake;
//ʳ��ṹ
struct Food{
	int x;
	int y;
	int r;	//ʳ���С
	bool flag;	//ʳ���Ƿ񱻳�
	DWORD color; // ʳ����ɫ
}food;


//���ݵĳ�ʼ��
void GameInit(){
	//init��ʼ��grapgͼ�δ���,SHOWCONSOLE����ʾ����̨
	initgraph(640, 640);
	//�������������
	srand(GetTickCount());//GetTickCount()��ȡϵͳ�����������������ĺ�����
	//��ʼ����,һ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;//�ߵķ���
	for (int i = 0; i < snake.size; i++) {
		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10; 
	}

	//��ʼ��ʳ��,rand()�������һ�����������û��������������ӣ�ÿ�β����Ķ��ǹ̶�����
	//����������Ҫͷ�ļ� stdlib.h,һ���ʱ����Ϊ���ӣ���Ϊ�仯
	
	food.x = rand()%640;
	food.y = rand()%480;
	food.color = RGB(rand()%256, rand()%256, rand()%256);
	food.r = rand()%10 + 5;
	food.flag = true;
	printf("%d %d,", food.x, food.y);
}

void GameDraw() {
	//˫�����ͼ
	BeginBatchDraw();
	//���ñ�����ɫ
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//������
	setfillcolor(GREEN); //�ߵ���ɫ
	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//����ʳ��
	if (food.flag) {
		solidcircle(food.x, food.y, food.color);
	}
	EndBatchDraw();
	
}

//�ƶ���
void snakeMove() {
	//���������ͷ�ƶ�
	for (int i = snake.size-1; i > 0; i--) {
		
		snake.coor[i] = snake.coor[i - 1];
	}
	//�ƶ���x y�����ı�
	switch (snake.dir) {
		case UP:
			snake.coor[0].y -= snake.speed;
			if (snake.coor[0].y + 10 <= 0) {	//����������ı߽�
				snake.coor[0].y = 640;
			}
			break;
		case DOWN:
			snake.coor[0].y += snake.speed;
			if (snake.coor[0].y - 10 >= 640) {	//����������ı߽�
				snake.coor[0].y = 0;
			}
			break;
		case LEFT:
			snake.coor[0].x -= snake.speed;
			if (snake.coor[0].x + 10 <= 0) {	//����������ı߽�
				snake.coor[0].x = 640;
			}
			break;
		case RIGHT:
			snake.coor[0].x += snake.speed;
			if (snake.coor[0].x - 10 >= 640) {	//����������ı߽�
				snake.coor[0].x = 0;
			}
			break;
	}	
}
//ͨ�������ı��ߵķ���
void keyControl() {
	//�ж���û�а���
	//����Ƿ��а���
	if (_kbhit()) {
		//72 80 75 77 �������Ҽ�ֵ
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			//�ı䷽��
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