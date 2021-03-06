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
bool check(char *str)
{
	bool flag = true;
	LIFO st;
	st.top = 0;

	int i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			push(&st, str[i]);

		else if (str[i] == ')')
		{
			if (st.top != 0) pop(&st);
			else flag = false;
		}
		i++;
	}
	
	if (st.top != 0) flag = false;

	return flag;
}

int main()
{
	char str[30];
	cin >> str;
	if (check(str)) cout<<"Is right";
	else cout << "Is wrong";
	//cout << boolalpha << check(str); выводит true false вместо 0 1

	cout << endl;
	system("pause");
	return 0;
}
