#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(){
	
	FILE *in;
	int a, b;

	if (!(in = fopen("input.txt", "r"))){//для чтения данных, файл уже должен быть создан
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}
	
	fscanf(in, "%d%d", &a, &b);
	fclose(in);

	int sum = a + b;
	printf("sum = %d\n", sum);



	FILE *out;
	if (!(out = fopen("output.txt", "w"))){//при записи, файл создается сам
		printf("Чёто пошло не так.\n");
		return 1;
	}

	fprintf(out, "sum = %d\n", sum);
	fclose(out);


		return 0;
}
