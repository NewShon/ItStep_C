const int size = 20;
struct LIFO
{
	char stack[size];
	int top;
};
void push(LIFO *st, char ch)
{
	if (st->top == size){//если указатель, то обращаемся через ->  если обычная переменная то через точку.
		cout << "Stack is overflow";
		return;
	}

	st->stack[st->top++] = ch;
}
char pop(LIFO *st)
{
	if (st->top == 0){
		cout << "Stack is empty";
		return 0;
	}

	return st->stack[--st->top];
}
