/*Добавить в односвязный список добавление элемента в конец списка, 
удаление из конца списка, написать функцию добавления в отсортированный список с сохранением порядка.*/

#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*next;
};
Node *pop(Node *cl)
{
	if (cl == NULL) return cl;
	Node *cur = cl;
	if (cur->next == NULL){
		free(cur);
		return NULL;
	}
	for (; cur->next->next != NULL; cur = cur->next);
	free(cur->next->next);
	cur->next = NULL;
	
	return cl;
}
Node *addTail(Node *client, int value)
{
	Node *cur = (Node*)malloc(sizeof(Node));
	cur->next = NULL;
	cur->data = value;

	if (!client) return cur;

	Node *next_client = client;
	for (; next_client->next != NULL; next_client = next_client->next);

	next_client->next = cur;
	return client;
}
Node* Sort(Node *cl)
{
	if (cl->next == NULL) return cl;
	Node *cur, *temp, *temp2, *prev, *end = NULL;
	bool flag = true;

	while (flag)
	{
		flag = false;
		cur = cl;
		prev = NULL;
		if (cur->data > cur->next->data)
		{
			temp = cur; temp2 = cur->next->next;
			cl = temp->next;
			cl->next = temp;
			cl->next->next = temp2;
			flag = true;
		}
		else cur = cur->next;
		prev = cl;
		while (cur->next != NULL)
		{
			if (cur->data > cur->next->data)
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = cur;
				flag = true;
			}
			else cur = cur->next;
			prev = prev->next;
		}
	}
	return cl;
}
Node *insertHead(Node *head, int value, int pos)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = value;
	cur->next = NULL;
	if (pos == 0)//добавление элемента в начало списка
	{

		cur->next = head;//указатель нового элемента направляем на голову списка
		head = cur;//смещение головы
		return head;
	}
	Node *element = head;//создали вспомогательный элемент для продвижения по списку
	for (int i = 0; i < pos&&element;
		i++, element = element->next);//поиск позиции для вставки
		if (element)//проверка на допустимость позиции
		{
			cur->next = element->next;//присвоение новому элементу указателя на элемент после него в списке
			element->next = cur;//присвоение предыдущему элементу указателя на новый элемент
		}
		else cout << " Error!!!";
		return head;
}
void print(Node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
void remove(Node **head, int value)
{
	Node *cur = *head, *prev = NULL;
	while (cur->data != value&&cur)//поиск элемента по значению||конца списка
	{
		prev = cur;//сохраняем текущий элемент
		cur = cur->next;//переход к следующему элементу
	}
	if (cur)//если нашли 
	{
		if (prev) //если перед ним  есть предыдущий
			prev->next = cur->next;//переставляем указатель из предыдущего элемента на следующий за удаляемым
		else //если удаляем первый
			*head = cur->next; //изменяем голову списка на следующий за удаляемым
		free(cur);
		return;
	}
	if (*head) cout << "Element not found" << endl;
	else cout << "List is empty" << endl;

}
Node *addPos(Node*node, int element, int pos)
{
	Node * cur = node;
	Node *temp;
	Node *el = (Node*)malloc(sizeof(Node));
	el->data = element;
	el->next = NULL;

	for (int i = 0; i < pos-1; i++)
		cur = cur->next;//ищем позицию


	temp = cur->next;
	cur->next = el;
	el->next = temp;


	return node;
}

int main()
{
	setlocale(0, "");
	Node *list = NULL;

	list = insertHead(list,1,0);
	list = insertHead(list, 2, 0);
	list = insertHead(list, 3, 0);
	list = addTail(list, 1);
	list = addTail(list, 2);
	list = addTail(list, 3);
	print(list);

	cout << endl;

	list = pop(list);
	list = pop(list);

	print(list);

	cout << endl;

	list = Sort(list);
	print(list);

	cout << endl;

	list = addPos(list, 8, 3);
	list = addPos(list, 5, 3);
	print(list);

	cout << endl;
	return 0;
}
