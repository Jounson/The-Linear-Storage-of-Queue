#include"pch.h"
#include"myqueue.h"
#include<stdlib.h>


/* 队列初始化函数 */
void initQueue(Queue* q, int size)
{
	/* 队列的长度 */
	q->_len = size;
	/* 申请队列的所占内存空间 */
	q->_space = (char*)malloc(sizeof(char)*q->_len);
	/*  */
	q->_rear = q->_front = 0;
}
/* 队列的判满函数 */
int isQueueFull(Queue* q)
{
	/* (rear+1)%length==front, 满了 */
	return (q->_rear + 1) % q->_len == q->_front;
}
/* 队列的判空函数 */
int isQueueEmpty(Queue* q)
{
	return q->_front == q->_rear;
}
/* 队列元素入队函数 */
void enQueue(Queue* q, char ch)
{
	/* 对于栈和队列来说，rear永远都是指向待压入元素的位置 */
	q->_space[q->_rear] = ch;
	/* 元素入队之后，rear向后移动一个位置 */
	q->_rear = ++q->_rear%q->_len;
}
/* 队列元素出队函数 */
char deQueue(Queue* q)
{
	/* 将出队的数据暂存起来 */
	char ch = q->_space[q->_front];
	/* 队列的空间有限，防止越界，出队一个元素后，front向后移动一个位置，对队列长度取余 */
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



