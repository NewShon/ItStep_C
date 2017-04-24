/*Имеется N черных и белых карточек, сложенных в стопку. 
Карточки раскладываются на столе в одну линию следующим образом: 
первая кладется на стол, вторая — вниз стопки, третья — на стол, 
четвертая — вниз стопки и т. д., пока все карточки не будут выложены на стол. 
Напишите программу, которая определит, каким должно быть исходное расположение карточек в стопке,
чтобы разложенные на столе карточки чередовались по цвету: белая, черная, белая, черная и т. д.*/


#include<iostream>
#include<cstring>
using namespace std;

struct Node//Создание звена(узла) цепи
{
	int data;//данные в узле
	int color;
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

FIFO push(FIFO q, int value, int col)
{
	Node *cur = (Node *)malloc(sizeof(Node));//Создает узел
	cur->data = value;//Сохраняем данные в новый узел
	cur->color = col;
	cur->next = NULL;//Задаем указатель

	if (q.tail)//проверка, есть ли элементы  вочереди
		q.tail->next = cur;//переместили указатель с NULL на новый элемент cur

	q.tail = cur;//присвоили хвосту добавленный элемент

	if (q.head == NULL)//если в очереди ничего нет(срабатывает только в самом начале, когда очередь пуста)
		q.head = q.tail;//то изменяем голову в очереди

	return q;
}

int *pop(FIFO *q)
{
	if (q->head == NULL)//если очередь пуста, выходим из функции
		return 0;

	Node *cur = q->head;//создаем копию головы

	Node *temp = q->head;//копируем данные из головы в темп     q->head обращение к структуре Node   а потом обращаемся к элементу структуры data
	q->head = cur->next;//перемеещние головы на следующий элемент
	int arr[2];
	arr[0] = temp->data;
	arr[1] = temp->color;
	free(cur);//удаляем узел
	return arr;
}


int main()
{
	FIFO q, q2;
	int *c, *c2;
	init(&q);
	init(&q2);

	cout << "Enter quantity of cards: ";
	int quantity; cin >> quantity;


	for (int i = 0; i < quantity; i++)
		q = push(q, i, 0);


	for (int i = 0; i < quantity; i++)
	{
		c = pop(&q);
		c[1] = i % 2;
		int a = c[1];
		int b = c[0];
		cout << "color: " << a << "   ID: " << b << endl;
		
		q2 = push(q2, b, a);

		if (quantity - 1 == i) break;
		c = pop(&q);
		q = push(q, c[0], c[1]);
	}

	cout << endl << endl;

	for (int i = 0; q2.head != NULL;)
	{
		c2 = pop(&q2);
		if (c2[0] == i){ 
			cout << "color: " << c2[1] << "   ID: " << c2[0] << endl; 
			i++;
		}
		else q2 = push(q2, c2[0], c2[1]);
	}
	


	system("pause");
	return 0;
}
