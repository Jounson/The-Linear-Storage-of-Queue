#include"pch.h"
#include"myqueue.h"
#include<stdlib.h>


/* ���г�ʼ������ */
void initQueue(Queue* q, int size)
{
	/* ���еĳ��� */
	q->_len = size;
	/* ������е���ռ�ڴ�ռ� */
	q->_space = (char*)malloc(sizeof(char)*q->_len);
	/*  */
	q->_rear = q->_front = 0;
}
/* ���е��������� */
int isQueueFull(Queue* q)
{
	/* (rear+1)%length==front, ���� */
	return (q->_rear + 1) % q->_len == q->_front;
}
/* ���е��пպ��� */
int isQueueEmpty(Queue* q)
{
	return q->_front == q->_rear;
}
/* ����Ԫ����Ӻ��� */
void enQueue(Queue* q, char ch)
{
	/* ����ջ�Ͷ�����˵��rear��Զ����ָ���ѹ��Ԫ�ص�λ�� */
	q->_space[q->_rear] = ch;
	/* Ԫ�����֮��rear����ƶ�һ��λ�� */
	q->_rear = ++q->_rear%q->_len;
}
/* ����Ԫ�س��Ӻ��� */
char deQueue(Queue* q)
{
	/* �����ӵ������ݴ����� */
	char ch = q->_space[q->_front];
	/* ���еĿռ����ޣ���ֹԽ�磬����һ��Ԫ�غ�front����ƶ�һ��λ�ã��Զ��г���ȡ�� */
	q->_front = ++q->_front%q->_len;
	return ch;
}

void resetQueue(Queue* q)
{
	q->_front = q->_rear;
}
void clearQueue(Queue* q)
{
	free(q->_space);
}



