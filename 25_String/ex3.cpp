//Строка состоит из целых чисел, возможно отрицательных,
//разделенных пробелами или запятыми, найти сумму этих чисел.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	char str[100];
	cout << "Input str: "; cin.getline(str, 100);
	
	char delim[3] = " ,";
	char *s = strtok(str, delim);
	
	int sum = 0;

	while (s!=NULL)
	{
		sum += atoi(s);
		s = strtok(0, delim);
	}

	cout << "Sum = " << sum;

	cout << endl;
	system("pause");
	return 0;
}
