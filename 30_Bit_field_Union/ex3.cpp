/*
Создайте объединение, состоящее из целого числа и массива логических переменных. Напишите следующие функции:
	Ввести целое число
	Посчитать сколько нулевых байтов у числа
	Вывод информации о байтах числа (нулевой, не нулевой)

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
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

union variable
{
	int data;
	bit b[sizeof(int)];
};

int main()
{
	variable a;

	printf("Enter a number: ");
	scanf("%d",&a.data);

	printf("Bin number: ");
	for (int i = 3; i >= 0; i--)//Вывод байтов числа в двоичном виде
		cout << a.b[i].a7 << a.b[i].a6 << a.b[i].a5 << a.b[i].a4 << a.b[i].a3 << a.b[i].a2 << a.b[i].a1 << a.b[i].a0 << " ";
	cout << endl;

	printf("Integer number: %d\n",a.data);

	int counter = 0, byte = 0;
	for (int i = 31; i >= 0; i--)
	{
		if (((a.data >> i) & 1) == 0)counter++;	
		if (counter == 8) byte++;
		if (i % 24 == 0 || i % 16 == 0 || i % 8 == 0) counter = 0;
	}

	printf("Zero bytes: %d\n", byte);

	return 0;
}
