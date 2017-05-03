/*Описать структуру, с именем TRAIN, содержащий следующие поля: 
•	название пункта назначения; 
•	номер поезда; 
•	экспресс или нет.
Создать массив структур, данные прочитать из файла Input.txt
Реализовать  функции:
•	вывод в файл Output.txt. информации о поездах, направляющихся в пункт, название которого введено с клавиатуры; 
вывод  в файл  Output.txt. всех поездов экспресс, направляющихся в заданный пункт назначения
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;


struct TRAIN
{
	char destination[20];
	int id;
	int exp;
};


int main()
{
	FILE *in, *out;

	TRAIN trains[4];

	if (!(in = fopen("34.txt", "r"))){
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}
	if (!(out = fopen("out.txt", "a"))){
		printf("Чёто пошло не так, возможно файл не найден.\n");
		return 1;
	}

	int i = 0;
	while (i!=4)
	{
		fscanf(in, "%s %d %d", &trains[i].destination, &trains[i].id, &trains[i].exp);
		//fprintf(out, "%s %d %d\n", &trains[i].destination, trains[i].id, trains[i].exp);
		i++;
	}

	char name[20];
	cout << "name"; cin >> name;

	for (int i = 0; i != 4; i++)
	{
		if (strcmp(name, trains[i].destination) == 0)
			fprintf(out, "%s %d %d\n", &trains[i].destination, trains[i].id, trains[i].exp);
	}
	for (int i = 0; i != 4; i++)
	{
		if (strcmp(name, trains[i].destination) == 0 && trains[i].exp == 1)
			fprintf(out, "%s %d %d\n", &trains[i].destination, trains[i].id, trains[i].exp);
	}


	system("pause");
	return 0;
}
