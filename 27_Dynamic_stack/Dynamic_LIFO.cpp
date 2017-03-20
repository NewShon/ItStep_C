struct LIFO
{
	char data;
	LIFO *prev;
};
LIFO *push(LIFO *top, char ch)//первый вариант написания функции
{
	LIFO *cur = (LIFO*)malloc(sizeof(LIFO));
	cur->data = ch;
	cur->prev = top;
	top = cur;
	return top;
}
char pop(LIFO **top)//второй вариант написания функции
{
	char temp;
	LIFO *cur = *top;
	if (*top == NULL) return 0;
	temp = (*top)->data;
	*top = cur->prev;
	free(cur);
	return temp;
}
