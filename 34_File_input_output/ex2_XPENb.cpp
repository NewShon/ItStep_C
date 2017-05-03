/*Дан текстовый файл. Необходимо создать новый файл и записать в него следующую статистику по исходному файлу:
•	Количество символов
•	Количество строк
•	Количество гласных букв
•	Количество согласных букв
•	Количество цифр.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

void qs(FILE *in, FILE *out)
{
	fseek(in, 0, SEEK_SET);
	char str[255];
	int counter = 0;

	while (!feof(in))
	{
		fgets(str, 255, in);
		counter += strlen(str);
	}

	fprintf(out,"Symbols:\t%d\n",counter);
}
void qr(FILE *in, FILE *out)
{
	fseek(in, 0, SEEK_SET);
	char str[255];
	int counter = -1;

	while (!feof(in++))
		counter++;

	fprintf(out, "Rows:\t\t%d\n", counter);
}
void gb(FILE *in, FILE *out)
{
	fseek(in, 0, SEEK_SET);
	char str[255];
	char glasn[] = "йуеыаоэяию";
	int counter = 0;

	while (!feof(in))
	{
		fgets(str, 255, in);
		char *ptr = strtok(str, glasn);
		
		while (ptr != NULL)
		{
			counter++;
			ptr = strtok(NULL, glasn);
		}
	}
	fprintf(out, "Vowels:\t\t%d\n", counter);
}
void sb(FILE *in, FILE *out)
{
	fseek(in, 0, SEEK_SET);
	char str[255];
	char sogl[] = "цкнгшщзхфвпрлджчмтб";
	int counter = 0;
	while (!feof(in))
	{
		fgets(str, 255, in);
		char *ptr = strtok(str, sogl);
		while (ptr != NULL)
		{
			counter++;
			ptr = strtok(NULL, sogl);
		}
	}
	fprintf(out, "Consonants:\t%d\n", counter);
}
void qn(FILE *in, FILE *out)
{
	fseek(in, 0, SEEK_SET);
	char str[255];
	char numbers[] = "1234567890";
	int counter = 0;
	while (!feof(in))
	{
		fgets(str, 255, in);
		char *ptr = strtok(str, numbers);
		while (ptr != NULL)
		{
			ptr++;
			if (atoi(ptr) == 1 || atoi(ptr) == 6 ||
				atoi(ptr) == 2 || atoi(ptr) == 7 ||
				atoi(ptr) == 3 || atoi(ptr) == 8 ||
				atoi(ptr) == 4 || atoi(ptr) == 9 ||
				atoi(ptr) == 5) counter++;
		}
	}
	fprintf(out, "Numbers:\t%d\n", counter);
}



int main()
{
	FILE *in, *out;

	if (!(in = fopen("34.txt", "r"))){
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}

	if (!(out = fopen("out.txt", "a"))){
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}

	qs(in, out);
	qr(in, out);
	gb(in, out);
	sb(in, out);
	qn(in, out);

	system("pause");
	return 0;
}
