//Написать функцию, которая вычисляет длину строки, проиллюстрировать примером ее работу.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int ex1(char* str)
{
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

int main()
{
	char ptr[100];
	cin.getline(ptr, 100);

	cout << ex1(ptr) << endl;

	system("pause");
	return 0;
}
