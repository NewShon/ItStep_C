//Строка состоит из целых чисел бинарных арифметических операций и пробелов.
//Определить является ли строка арифметическим выражением.
//Например: 34 + 56 * 4 арифметическое выражение.
//Например: 34 + * 56 не является арифметическим выражением.
//Например: 56 56 + не является арифметическим выражением.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	char str[100];
	cout << "Input str: "; cin.getline(str, 100);
	
	char delim[2] = " ";
	char *s = strtok(str, delim);
	bool b = 0;
	char arr[50][8];
	int i = 0;
	while (s != NULL)
	{
		strcpy(arr[i], s);
		i++;
		s = strtok(0, delim);
	}

	for (int j = 0; j < i; j++)
	{
		int counterN = 0, counterZ = 0;
		for (int k = 0; k < strlen(arr[j]); k++)
		{
			if (isalnum(arr[j][k])) counterN++;
			else counterZ++;
		}

		if (counterN != 0 && counterZ != 0) b = 1;
	}

	if (b) cout << "Not an arithmetic expression";
	else
	{
		for (int j = 1; j < i; j++)
		{
			if (isalnum(arr[j - 1][0]) && isalnum(arr[j][0]) || !isalnum(arr[j - 1][0]) && !isalnum(arr[j][0])) b = 1;
		}

		if (b) cout << "Not an arithmetic expression";
		else cout << "Arithmetic expression";
	}

	cout << endl;
	system("pause");
	return 0;
}
