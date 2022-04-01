#include<stdio.h>
#include<graphics.h>
#include<conio.h>
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
	RIGHT,
};
//�ߵĽṹ
struct Snake
{
	int size;//�ߵĽ���
	int dir;//�ߵķ���
	int speed;//�ƶ��ٶ�
	POINT coor[SNAKE_NUM];//���� POINT:����õĽṹ�壬��x��y
}snake;

//���ݵĳ�ʼ��
void GameInit(){
	//init��ʼ��grapgͼ�δ���,SHOWCONSOLE����ʾ����̨
	initgraph(640, 480);
	//��ʼ����,һ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;//�ߵķ���
	for (int i = 0; i < snake.size; i++) {
		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10; 
	}
}

void GameDraw() {
	//˫�����ͼ
	BeginBatchDraw();
	//���ñ�����ɫ
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//������
	setfillcolor(rad10); //�ߵ���ɫ
	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	EndBatchDraw();
}

//�ƶ���
void snakeMove() {
	//�ƶ���x y�����ı�
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