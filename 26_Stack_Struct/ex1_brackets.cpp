//Напишите программу, которая определит, правильно ли расставлены скобки в выражении,
//если оно состоит из скобок типа: ( ) [ ] { }. (использовать структуру данных стек)

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

bool brackets(char *str)
{
	LIFO lf;
	lf.top = 0;
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			push(&lf, str[i]);
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (str[i] == ')' && lf.stack[lf.top-1] == '(') pop(&lf);
			else if (str[i] == '}' && lf.stack[lf.top-1] == '{') pop(&lf);
			else if (str[i] == ']' && lf.stack[lf.top-1] == '[') pop(&lf);
			else return 0;
		}
		i++;
	}
	if (lf.top != 0) return 0;
	else return 1;
}

int main()
{
	char str[100];
	cout << "Input brackets: "; gets(str);
	cout << boolalpha << brackets(str);
	
	cout << endl;
	system("pause");
	return 0;
}
