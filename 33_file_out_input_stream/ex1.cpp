//Дан код программы на С++.  Вывести  все операции и частоту их использования в программе.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
int main()
{

	FILE *in, *out;//объявляем 2 потока
	char str[256];
	if (!(out = fopen("output.txt", "w")))
	{
		printf("Error\n");
		return 1;
	}
	if (!(in = fopen("28.txt", "r"))) //проверка на создание файла
	{
		printf("Error\n");
		return 1;
	}
	char operations[10][5] = { "+", "=", "++", "*", "||", "==", "!", "%", "<< ", "->" }; //искомые операторы
	int counters[10] = { 0 };//счетчик
	while (!feof(in))//принимает поток и ищет конец файла
	{
		fgets(str, 255, in);//считывает строку , в конце файла  вернет str
		for (int i = 0; i < 10; i++)
		{
			char*s = str;
			while (s)
				if (s = strstr(s, operations[i]))
				{
					counters[i]++;
					s += strlen(operations[i]);
				}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		fprintf(out, "%s - %d\n", operations[i], counters[i]);
	}

	fclose(in);
	fclose(out);



	return 0;

}
