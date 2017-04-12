#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(){
	
	//Запись из файла в файл
	FILE *in, *out;
	char str[256];

	if (!(in = fopen("Source.cpp", "r"))){//для чтения данных, файл уже должен быть создан
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}
	if (!(out = fopen("output.txt", "w"))){//при записи, файл создается сам
		printf("Чёто пошло не так.\n");
		return 1;
	}
	
	while (!feof(in))
	{
		fgets(str, 255, in);
		fputs(str, out);
	}


	fclose(in);
	fclose(out);
	return 0;
}
