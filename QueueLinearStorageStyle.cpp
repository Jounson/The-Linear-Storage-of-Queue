#include "pch.h"
#include <iostream>
#include<stdio.h>
#include"myqueue.h"

using namespace std;

int main()
{
	Queue q;
	initQueue(&q, 26);
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		if (!isQueueFull(&q))
		{
			enQueue(&q, ch);
		}
	}
	system("cls");
	while (!isQueueEmpty(&q))
		printf("%3c", deQueue(&q));

	cout << endl;
	return 0;
}


