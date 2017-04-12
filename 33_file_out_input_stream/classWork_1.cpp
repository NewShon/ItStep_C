#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(){
	
	FILE *in;
	int a, b;

	if (!(in = fopen("input.txt", "r"))){
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}
	
	fscanf(in, "%d%d", &a, &b);
	fclose(in);

	int sum = a + b;
	printf("sum = %d\n",sum);


		return 0;
}
