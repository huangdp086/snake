#include<stdio.h>
#include<graphics.h>
/*
	̰����
	֪ʶ�㣺�ṹ�壬ѭ����������easyx������
	easyx��ͼ�ν����
*/

//������1������һ�����ڣ�ͼ�δ���
#define SNAKE_NUM 500 //�ߵ�������
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
	initgraph(640, 480, SHOWCONSOLE);
	//��ʼ����,һ��ʼ����
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
	//���ñ�����ɫ
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//������
	solidcircle(snake.coor[0].x, snake.coor[0].y, 5);
}


int main(){
	GameInit();
	GameDraw();

	while (1) {

	}

	return 0;
}