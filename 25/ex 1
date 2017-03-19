//Дана строка символов. Определить количество букв,
//количество цифр и количество остальных символов, присутствующих в строке.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	char str[100];

	/*isalpha - true if letter
	isdigit - true if number
	isalnum - true if letter or nmber*/

	cin.getline(str, 100);
	int qn = 0, ql = 0, qs = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (isalpha(str[i])) ql++;
		if (isdigit(str[i])) qn++;
	}

	cout << "Letters: " << ql << "\nNumbers: " << qn << "\nSymbols: " << strlen(str) - ql - qn;


	cout << endl;
	system("pause");
	return 0;
}
