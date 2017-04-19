#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
#include<stdlib.h>

const short size = 20;

bool correct(FILE *in)//проверка на корректность открытия файла
{
	if (!in)
	{
		printf("Error\n");
		return 0;
	}
	return 1;
}
void fill(FILE*in)/*//заполнение бинарного файла случайными числами (-size;size)*/
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		temp = rand() % 41 - size;
		fwrite(&temp, sizeof(int), 1, in);
	}
}
void show(FILE*in)//вывод содержимого бинарного файла
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		fread(&temp, sizeof(int), 1, in);
		printf("%d ", temp);
	}
	printf("\n");
}
void sum(FILE*in,FILE*out)//увеличение каждого числа на последнее
{
	int lastnum, temp;
	fseek(in, 19 * sizeof(int), SEEK_SET);//смещение указателя на последнее число
	fread(&lastnum, sizeof(int), 1, in);//чтение последнего числа из бин.файла
	fseek(in, 0, SEEK_SET);//смещение указателя на начало
	for (int i = 0; i < size; i++)
	{
		fread(&temp, sizeof(int), 1, in);//чтение числа на позиции i из бин.файла
		temp += lastnum;//сложение числа i с последним
		fprintf(out, "%d ", temp);//вывод числа в текстовый файл
	}
	fprintf(out, "\n");//переход на новую строку
}
void mult(FILE*in,FILE*out)
{
	int first, last, temp;
	fseek(in, 0, SEEK_SET);
	for (int i = 0; i < size; i++)
	{
		fread(&temp, sizeof(int), 1, in);
		if (temp < 0)
		{
			first = temp;
			break;
		}
	}
	for (int i = size - 1; i >= 0; i--)
	{
		fseek(in, i*sizeof(int), SEEK_SET);
		fread(&temp, sizeof(int), 1, in);
		if (temp < 0)
		{
			last = temp;
			break;
		}
	}
	fseek(in, 0, SEEK_SET);
	for (int i = 0; i < size; i++)
	{
		fread(&temp, sizeof(int), 1, in);//
		temp *= first*last;//
		fprintf(out, "%d ", temp);//
	}
	fprintf(out, "\n");//переход на новую строку
}
void replace_zero(FILE*in,FILE*out)
{
	int temp, avg = 0;
	fseek(in, 0, SEEK_SET);
	for (int i = 0; i < size; i++)
	{
		fread(&temp, sizeof(int), 1, in);
		avg += temp;
	}
	avg /= 20;
	avg = 99;
	fseek(in, 0, SEEK_SET);
	for (int i = 0; i < size; i++)
	{
		fread(&temp, sizeof(int), 1, in);
		if (temp == 0)fprintf(out, "%d ", avg);
		else fprintf(out, "%d ", temp);
	}
	fprintf(out, "\n");
}
int main()
{
	FILE *in, *out;
	in = fopen("Numbers.dat", "wb");
	out = fopen("Text1.txt", "w");
	if (!(correct(in)))
	{
		return 1;
	}
	if (!(correct(out)))
	{
		return 1;
	}

	fill(in);
	fclose(in);

	in = fopen("Numbers.dat", "rb");
	show(in);
	sum(in, out);
	mult(in, out);
	replace_zero(in, out);

	fclose(in);
	fclose(out);
	return 0;
}
