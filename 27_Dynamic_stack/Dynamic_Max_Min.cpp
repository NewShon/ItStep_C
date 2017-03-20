#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

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


char solve(char *str)
{
	LIFO *st = NULL;
	char num1, num2, oper;
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'i' || isdigit(str[i]))
			st = push(st, str[i]);
		if (str[i] == ')')
		{
			num1 = pop(&st);
			num2 = pop(&st);
			oper = pop(&st);

			if (oper == 'a') st = push(st, maxx(num1, num2));
			else if (oper == 'i') st = push(st, minn(num1, num2));
		}
		i++;
	}
	return pop(&st);
}


int main()
{
	char str[100];
	cout << "Input expression: "; cin >> str;
	cout << "Solution: " << solve(str);
	
	cout << endl;
	system("pause");
	return 0;
}
