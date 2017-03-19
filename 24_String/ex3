//Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void ex3(char*str)
{
	int counter = 0;
	char *sim = strchr(str, '!');

	for (; sim != 0; sim = strchr(sim + 1, '!'))
		counter++;

	cout << counter << endl;
}

int main()
{
	char ptr[100];
	cin.getline(ptr, 100);

	ex3(ptr);

	system("pause");
	return 0;
}
