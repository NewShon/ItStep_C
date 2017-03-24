#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

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


char maxx(char a, char b)
{
	if (a > b) return a;
	else return b;
}
char minn(char a, char b)
{
	if (a < b) return a;
	else return b;
}


char ex2(char *str)
{
	LIFO st;
	st.top = 0;
	
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			push(&st, str[i]);

		else if (str[i] == 'i')
			push(&st, str[i]);

		else if (isdigit(str[i]))
			push(&st, str[i]);

		else if (str[i] == ')')
		{
			char a = pop(&st);
			char b = pop(&st);
			char c = pop(&st);
			
			if (c == 'a') push(&st, maxx(a,b));
			else if (c == 'i') push(&st, minn(a,b));
		}
		i++;
	}
	return st.stack[st.top-1];
}

int main()
{
	char str[100];
	cin >> str;
	cout << ex2(str);

	cout << endl;
	system("pause");
	return 0;
}
