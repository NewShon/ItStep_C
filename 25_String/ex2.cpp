//Удалить из строки заданное слово.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	char str[100];// = "long cruel and long dirty world long";
	cout << "Input str: "; cin.getline(str, 100);

	char str2[15];// = "long";
	cout << "Input word: "; cin >> str2;
	
	char delim[2] = " ";
	char *s = strtok(str, delim);
	char str3[100] = "";

	while (s!=NULL)
	{
		if (strcmp(s, str2)){
			strcat(str3, s);
			strcat(str3, " ");
		}
		s = strtok(0, delim);
	}

	cout << str3;

	cout << endl;
	system("pause");
	return 0;
}
