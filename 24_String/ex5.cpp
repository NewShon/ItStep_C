//Создать копию строки и «перевернуть» в строке все слова
//(например: «Жили были дед и баба» - «илиЖ илыб дед и абаб»).

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(0, "");
	char str[100];
	cin.getline(str, 100);
	
	char str2[100];
	for (int i = strlen(str)-1, j = 0; i >= 0; i--, j++)
		str2[j] = str[i];

	str2[strlen(str)] = '\0';
	cout << str2 << endl;


	system("pause");
	return 0;
}
