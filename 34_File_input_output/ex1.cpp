#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<cstring>

bool correct(FILE *in)
{
	if (!(in)){
		printf("Error!!!\n");
		return 0;
	}
	return 1;
}
void compare(FILE *in1, FILE *in2, FILE *out)
{
	fseek(in1, 0, SEEK_SET);
	char str1[256], str2[256];
	while (!feof(in1))
	{
		fgets(str1, 255, in1);
		bool flag = 1;
		fseek(in2, 0, SEEK_SET);
		while (!feof(in2))
		{
			fgets(str2, 255, in2);
			if (strcmp(str2, str1) == 0){
				flag = false;
				break;
			}
		}
		if (flag == true) fputs(str1, out);

	}
}
int main()
{
	FILE *in1, *in2, *out;

	in1 = fopen("in1.txt","r");
	in2 = fopen("in2.txt", "r");
	out = fopen("out.txt", "a");

	if (!correct(in1) && !correct(out) && !correct(in2)) return 1;

	compare(in1, in2, out);
	fprintf(out, "\n");
	compare(in2, in1, out);

	fclose(in1);
	fclose(in2);
	fclose(out);
	return 0;
}
