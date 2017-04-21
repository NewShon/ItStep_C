/*
Создайте объединение, состоящее из целого числа и массива символов и из вещественного числа и массива символов. 
Напишите следующие функции:
	Ввести целое число
	Просмотреть все байты числа
	Просмотреть выбранный байт числа
	Вывод байтов числа в двоичном и шестнадцатеричном виде

*/

#include<iostream>
#include<cstring>
using namespace std;

struct bit
{
	bool a0 : 1;
	bool a1 : 1;
	bool a2 : 1;
	bool a3 : 1;
	bool a4 : 1;
	bool a5 : 1;
	bool a6 : 1;
	bool a7 : 1;
};

union Int{
	int data;
	unsigned char byte[sizeof(int)];
	bit b[sizeof(int)];
};

union Float{
	double data;
	unsigned char byte[sizeof(double)];
	bit b[sizeof(double)];
};

int main()
{
	Int a;
	Float b;
	a.data = 123;
	b.data = 123.123;


	for (int i = 3; i >= 0; i--)//Вывод байтов числа в шестнадцатеричном виде
		cout << hex << (int)a.byte[i] << " ";
	cout << endl;


	for (int i = 7; i >= 0; i--)//Вывод байтов числа в шестнадцатеричном виде
		cout << hex << (int)b.byte[i] << " ";
	cout << endl;


	for (int i = 3; i >= 0; i--)//Вывод байтов числа в двоичном виде
		cout << a.b[i].a7 << a.b[i].a6 << a.b[i].a5 << a.b[i].a4 << a.b[i].a3 << a.b[i].a2 << a.b[i].a1 << a.b[i].a0 << " ";
	cout << endl;


	for (int i = 7; i >= 0; i--)//Вывод байтов числа в двоичном виде
		cout << b.b[i].a7 << b.b[i].a6 << b.b[i].a5 << b.b[i].a4 << b.b[i].a3 << b.b[i].a2 << b.b[i].a1 << b.b[i].a0 << " ";
	cout << endl;


	return 0;
}
