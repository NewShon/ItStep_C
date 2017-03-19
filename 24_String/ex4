//В строке найти частоты всех двухбуквенных сочетаний и вывести.
//Например: Ехали ли вы, да, да, да. Результат: ли-1 вы-1 да-3.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[100];
	cout << "Input str: ";
	cin.getline(str, 100);

	char delim[3] = " ."; char words[10][3];
	char *s = str;
	s = strtok(s, delim);

	int i = 0;
	while (s != NULL)
	{
		if (strlen(s) == 2)
		{
			strcpy(words[i], s);
			i++;
		}
		s = strtok(0, delim);
	}

	for (int j = 0; j < i; j++)
		for (int k = 1; k < i; k++)
			if (strcmp(words[k - 1], words[k]) < 0)
				swap(words[k - 1], words[k]);

	int counter = 1;
	for (int j = 0; j < i; j++)
	{
		if (strcmp(words[j], words[j + 1]) == 0) counter++;

		else{
			cout << words[j] << " - " << counter << endl;
			counter = 1;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
