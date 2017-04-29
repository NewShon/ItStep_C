/*Задана некоторая плоскость NxM. Каждой клетке поля соответствует некоторое число. 
Фишка, начиная движение из угла поля с координатами (0, 0), может перемещаться влево, 
вправо, вверх и вниз. Напишите программу, которая определит, 
какую максимальную сумму может набрать фишка за К ходов, при условии, 
что закончить свое движение она должна в любой клетке N-ой строки поля.*/


#include <iostream>
#include <ctime>
using namespace std;

struct Node//Создание звена(узла) цепи
{
	int x;//данные в узле
	int y;
	int sum;
	int step;
	Node *next;//указатель на следующий узел
};
struct FIFO//Объявление очереди
{
	Node *head; //указатель на первый элемент
	Node *tail;//указатель на последний элемент
};

void init(FIFO*q)//Иницилизация очереди(создание пустой очереди)
{
	q->head = NULL;
	q->tail = NULL;
}

FIFO push(FIFO q, int x, int y, int sum, int step)
{
	Node *cur = (Node *)malloc(sizeof(Node));//Создает узел
	cur->x = x;//Сохраняем данные в новый узел
	cur->y = y;
	cur->sum = sum;
	cur->step = step;
	cur->next = NULL;//Задаем указатель

	if (q.tail)//проверка, есть ли элементы  вочереди
		q.tail->next = cur;//переместили указатель с NULL на новый элемент cur

	q.tail = cur;//присвоили хвосту добавленный элемент

	if (q.head == NULL)//если в очереди ничего нет(срабатывает только в самом начале, когда очередь пуста)
		q.head = q.tail;//то изменяем голову в очереди

	return q;
}

int pop(FIFO *q)
{
	if (q->head == NULL)//если очередь пуста, выходим из функции
		return 0;

	Node *cur = q->head;//создаем копию головы

	int temp = q->head->sum;//копируем данные из головы в темп     q->head обращение к структуре Node   а потом обращаемся к элементу структуры data
	q->head = cur->next;//перемеещние головы на следующий элемент

	free(cur);//удаляем узел
	return temp;
}

int main(){
	srand((unsigned)time(0));
	FIFO q;
	init(&q);
	int n, m;
	cout << "Enter MxN: "; cin >> n >> m;

	int **board = (int**)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		board[i] = (int*)malloc(sizeof(int)*m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = rand() % 8 + 1;

	board[0][0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}

	int k; cout << "Enter k: "; cin >> k;
	int sum = 0;
	sum += board[0][0];
	q = push(q, 0,0,sum,-1);

	int temp = 0;
	while (q.head->step <= k)
	{
		int x = q.head->x;
		int y = q.head->y;
		int step = q.head->step + 1;
		sum = pop(&q);
		

		if (x + 1 < n) q = push(q, x + 1, y, sum + board[x + 1][y],step);
		if (x - 1 >= 0) q = push(q, x - 1, y, sum + board[x - 1][y], step);

		if (y - 1 >= 0) q = push(q, x, y - 1, sum + board[x][y - 1], step);
		if (y + 1 < m) q = push(q, x, y + 1, sum + board[x][y + 1], step);

		if (x == n-1 && step == k && sum > temp) temp = sum;

	}


	cout << "Sum: " << temp << endl;


	system("pause");
	return 0;
}
