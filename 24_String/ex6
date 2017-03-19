//В строке все вхождения подстроки str1 заменить подстрокой str2. Str2 вводится с клавиатуры.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(0, "");
	char str[100];
	strcpy(str, "This is wonderful and dread str2 , ohh str2...");
	cout << str << endl;

	char str2[100];
	cout << "Input str2: ";
	cin.get(str2, 100);

	char str3[100];
	strcpy(str3, "This ");

	char delim[3] = " .";
	char *ptr = strtok(str+4, delim);

	while (ptr != NULL)
	{
		if (strcmp(ptr, "str2") == 0)
		{
			strcat(str3, str2);
			strcat(str3, " ");
		}
		else 
		{
			strcat(str3, ptr);
			strcat(str3, " ");
		}
		ptr = strtok(NULL, delim);
	}
	strcat(str3, "\b...");
	cout << str3 << endl;
	
	

	system("pause");
	return 0;
}
