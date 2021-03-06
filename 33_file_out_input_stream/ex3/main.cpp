/*3.	Задан текстовый файл, содержащий информацию о студентах в следующем виде :
ФИО пробел ГРУППА пробел НОМЕР ЗАЧЕТКИ пробел Оценка   пробел Оценка   пробел Оценка 
 Например  
Иванов 4  456345   5 3 4.   
Петров  4  456348   4 3 4.
Иванова  5 456340   5 3 5
Петрова  5 456349   4 5 4
Составить программу получения:
•	среднего балла каждого студента
•	общего среднего балла
•	общего списка, состоящего из фамилии, номера группы, номера зачетки, среднего балла.
•	списка отличников, состоящего из фамилии, номера группы, номера зачетки 
•	списка имеющих неудовлетворительные  оценки, состоящего из фамилии, номера группы, номера зачетки
•	Для проверки результатов информацию созданных списков вывести на экран.
Все  полученные списки записать  в текстовые файлы OutAll.txt, OutО.txt  и OutN.txt, упорядочив списки по группам, каждую группу по фамилиям  в алфавитном порядке (используя  свою  и стандартную процедуры сортировки)  и вывести на экран. 
Общий средний балл записать первой строкой в файл OutAll.txt.
*/



#include "Student.h"


int main()
{
	Student student[size];
	FILE *in, *out;

	if (!(in = fopen("input.txt", "r"))){
		printf("Not found");
		return 1;
	}

	if (!(out = fopen("output.txt", "w"))){
		printf("Not found");
		return 2;
	}


	for (int i = 0; i < size; i++)
		student[i] = read(in);

	for (int i = 0; i < size; i++)
	{
		output(student[i],out);
		fprintf(out, "Средний балл: %0.2f\n\n", avg(student[i]));
	}

	fprintf(out, "Whole avg: %0.2f", whole_avg(student, size));

	fprintf(out, "\n\nGood Boys:\n");
	for (int i = 0, j = 1; i < size; i++)
		if (otlichniki(student[i])){
			fprintf(out, "%d. %s\n", j, student[i].FIO);
			j++;
		}
	
	return 0;
}

