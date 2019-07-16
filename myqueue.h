#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_


typedef struct _Queue
{
	char* _space;
	int _len;
	int _rear;
	int _front;
}Queue;
void initQueue(Queue* q, int size);
int isQueueFull(Queue* q);
int isQueueEmpty(Queue* q);
void enQueue(Queue* q, char h);
char deQueue(Queue* q);
void resetQueue(Queue* q);
void clearQueue(Queue* q);





#endif