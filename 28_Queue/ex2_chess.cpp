/*Дана шахматная доска. 
Найти минимальное количество ходов,
за которое конь переместится из одной клетки в другую.
Использовать структуру данных очередь.*/

#include<iostream>
#include<cstring>
using namespace std;
const int size = 130;
struct FIFO
{
	int queue[size];
	int head, tail;
};
void push(FIFO*st, int data)
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
int pop(FIFO *st)
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
	FIFO q;
	q.head = 0;
	q.tail = 0;

	int board[9][9];
	for (int i = 1; i < 9; i++)
	for (int j = 1; j < 9; j++)
		board[i][j] = -1;


	int x = 0, y = 0;
	cout << "Enter the position of your knight: ";
	cin >> x >> y;


	int x1 = 0, y1 = 0;
	cout << "Enter the position what you need: ";
	cin >> x1 >> y1;


	push(&q, y);
	push(&q, x);
	board[x][y] = 0;

	int turns = 0, size = 0;
	while (x != x1 || y != y1)
	{
		turns++;
		size = (q.tail - q.head) / 2;
		for (int s = 0; s < size; s++)
		{
			x = pop(&q);
			y = pop(&q);
			if (x == x1 && y == y1) break;


			if (x + 2 > 0 && x + 2 <= 8)
			if (y + 1 > 0 && y + 1 <= 8)
			if (board[x + 2][y + 1] == -1){
				board[x + 2][y + 1] = turns;
				push(&q, x + 2);
				push(&q, y + 1);
			}

			if (x - 2 > 0 && x - 2 <= 8)
			if (y + 1 > 0 && y + 1 <= 8)
			if (board[x - 2][y + 1] == -1){
				board[x - 2][y + 1] = turns;
				push(&q, x - 2);
				push(&q, y + 1);
			}

			if (x + 2 > 0 && x + 2 <= 8)
			if (y - 1 > 0 && y - 1 <= 8)
			if (board[x + 2][y - 1] == -1){
				board[x + 2][y - 1] = turns;
				push(&q, x + 2);
				push(&q, y - 1);
			}

			if (x - 2 > 0 && x - 2 <= 8)
			if (y - 1 > 0 && y - 1 <= 8)
			if (board[x - 2][y - 1] == -1){
				board[x - 2][y - 1] = turns;
				push(&q, x - 2);
				push(&q, y - 1);
			}


			//////////////////////////////////////////


			if (y + 2 > 0 && y + 2 <= 8)
			if (x + 1 > 0 && x + 1 <= 8)
			if (board[x + 1][y + 2] == -1){
				board[x + 1][y + 2] = turns;
				push(&q, x + 1);
				push(&q, y + 2);
			}

			if (y - 2 > 0 && y - 2 <= 8)
			if (x + 1 > 0 && x + 1 <= 8)
			if (board[x + 1][y - 2] == -1){
				board[x + 1][y - 2] = turns;
				push(&q, x + 1);
				push(&q, y - 2);
			}

			if (y + 2 > 0 && y + 2 <= 8)
			if (x - 1 > 0 && x - 1 <= 8)
			if (board[x - 1][y + 2] == -1){
				board[x - 1][y + 2] = turns;
				push(&q, x - 1);
				push(&q, y + 2);
			}

			if (y - 2 > 0 && y - 2 <= 8)
			if (x - 1 > 0 && x - 1 <= 8)
			if (board[x - 1][y - 2] == -1){
				board[x - 1][y - 2] = turns;
				push(&q, x - 1);
				push(&q, y - 2);
			}
		}
	}

	cout << "Knight needs " << board[x][y] << " turns" << endl;


	board[x][y] = 777;
	for (int i = 1; i < 9; i++){
		for (int j = 1; j < 9; j++)
			cout << board[j][i] << "\t";
		cout << endl << endl;
	}


	cout << endl;
	system("pause");
	return 0;
}
