/*В постфиксной записи (или обратной польской записи) операция записывается после двух операндов.
Например, сумма двух чисел A и B записывается как A B +.
Запись B C + D * обозначает, привычное нам  (B + C) * D, а запись A B C + D * + означает A + (B + C) * D.
Достоинство постфиксной записи в том,
что она не требует скобок и дополнительных соглашений о приоритете операторов для своего чтения.
Вычислить значение выражения записанного в постфиксной записи используя динамическую структуру данных стек.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
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

float strange_record(char exp[][5], int size)
{
	LIFO *lf = nullptr;
	float n1, n2, oper;
	int i = 0;
	while (i != size)
	{
		if (isdigit(*exp[i]))
			lf = push(lf, atoi(exp[i]));
		else
		{
			n2 = pop(&lf);
			n1 = pop(&lf);

			if (*exp[i] == '*') lf = push(lf, n1*n2);
			else if (*exp[i] == '/') lf = push(lf, n1 / n2);
			else if (*exp[i] == '+') lf = push(lf, n1 + n2);
			else if (*exp[i] == '-') lf = push(lf, n1 - n2);
		}
		i++;
	}
	return pop(&lf);
}

int main()
{
	char expression[100];
	cout << "Enter expression using separaters(Space):";
	cin.getline(expression, 100);

	char new_exp[30][5];

	char delim[] = " ";
	char *ptr = strtok(expression, delim);
	int i = 0;
	while (ptr != NULL)
	{
		strcpy(new_exp[i], ptr);
		i++;
		ptr = strtok(0, delim);
	}
	cout << "Expression = " << strange_record(&new_exp[0], i);

	cout << endl;
	system("pause");
	return 0;
}
