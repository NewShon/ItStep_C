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

