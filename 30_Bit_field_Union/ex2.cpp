/*Реализовать 4-х байтовую целую переменную, 
к которой можно обращаться и как к знаковому целому, 
и как беззнаковому целому, без явного преобразования типов. 
Для этого используйте объединение.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

union variable
{
	int data;
	unsigned int data2;
};

int main()
{
	variable a;
	a.data2 = 50;
	printf("%d\n", a.data2);

	return 0;
}
