#include<iostream>
#include<cstring>
using namespace std;
const int size = 20;
struct FIFO
{
	int queue[size];
	int head, tail;
};
void push_back(FIFO*st, int data)
{
	if (st->tail + 1 == st->head || st->tail + 1 == size &&st->head == 0)
	{
		cout << " queue is full";
		return;
	}
	st->tail++;
	if (st->tail == size) st->tail = 0;//организация кругового цикла для очереди
	st->queue[st->tail] = data;
}
int pop_front(FIFO *st)
{
	if (st->head == st->tail)
	{
		cout << "queue is empty\n";
		return 0;
	}
	st->head++;
	if (st->head == size) st->head = 0;
	return st->queue[st->head];
}

		
int main()
{
	setlocale(0, "");
	FIFO Q1,Q2,Q3; 
	int size_Q1, size_Q2;
	Q1.head = 0;
	Q1.tail = 0;
	Q2.head = 0;
	Q2.tail = 0;
	Q3.head = 0;
	Q3.tail = 0;
	cout << "Введите кол-во элементов первой очереди: ";
	cin >> size_Q1;
	cout << "Введите элементы первой очереди: " << endl;
	for (int i = 0; i < size_Q1; i++)
	{
		push_back(&Q1,rand()%10+1);
	}
	cout << "Введите кол-во элементов второй очереди: ";
	cin >> size_Q2;
	cout << "Введите элементы второй очереди: " << endl;
	for (int i = 0; i < size_Q2; i++)
	{
		push_back(&Q2, rand() % 10+1);
	}
	int  z,x, y;
	while ((x=pop_front(&Q1)) && (y=pop_front(&Q2)))
	{
		
		push_back(&Q3,x+y);
	}
	while (z = pop_front(&Q3))
	{

		cout << z << " ";
	}


	return 0;
}
