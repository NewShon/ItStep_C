//Написать программу, которая заменяет все символы точки «.» в строке,
//введенной пользователем, на символы восклицательного знака «!».

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void ex2(char*str)
{
	char *sim = strchr(str, '.');
	for (; sim != 0; sim = strchr(sim + 1, '.'))
		*sim = '!';

	cout << str << endl;
}

int main()
{
	char ptr[100];
	cin.getline(ptr, 100);

	ex2(ptr);

	system("pause");
	return 0;
}
