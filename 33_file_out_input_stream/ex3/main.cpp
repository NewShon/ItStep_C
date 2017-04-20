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

	//cout << "Good boys: ";
	//for (int i = 0; i < size; i++)
	//{
	//	if (otlichniki(student[i]))
	//		cout << student[i].FIO << " ";
	//}

	//cout << "Input student for changing marks: ";
	//char st[20]; cin >> st;
	//for (int i = 0; i < size; i++)
	//	change_marks(&student[i], st);

	//for (int i = 0; i < size; i++)
	//	output(student[i]);

	return 0;
}

