#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
const int size = 20;

long fileSize(FILE *in)
{
	fseek(in, 0, SEEK_END);
	return ftell(in);
}
bool checkFileOpen(FILE *in, const char *filename)
{
	if (!in){
		printf("%s is not  open\n", filename);
		return false;
	}
	return true;
}
void writeTXT(FILE *ftxt)
{
	for (int i = 0; i < size; i++)
		fprintf(ftxt, "%d%	",rand());

}
void writeBIN(FILE *fbin)
{
	int number;
	for (int i = 0; i < size; i++){
		number = rand();
		fwrite(&number, sizeof(number), 1, fbin);
	}
}
void write(FILE *ftxt, FILE*fbin)
{
	int number;
	for (int i = 0; i < size; i++){
		number = rand();
		fprintf(ftxt, "%d%	", number);
		fwrite(&number, sizeof(number), 1, fbin);
	}
}
void printTXT(FILE *ftxt)
{
	printf("Numbers from txt: ");
	int number;
	while (!feof(ftxt))
	{
		fscanf(ftxt, "%d",&number);
		printf("%d ", number);
	}
}
void printBIN(FILE *fbin)
{
	printf("Numbers from dat: ");
	int number;
	while (!feof(fbin))
	{
		fread(&number,sizeof(number),1,fbin);
		printf("%d ", number);
	}
}

int main()
{
	FILE *binf, *textf;
	binf = fopen("binfile.dat", "wb");
	textf = fopen("textfile.txt", "w");

	checkFileOpen(textf,"textfile.txt");
	checkFileOpen(binf, "binfile.dat");

	write(textf, binf);
	fclose(textf);
	fclose(binf);

	binf = fopen("binfile.dat", "rb");
	textf = fopen("textfile.txt", "r");

	printf("Size of txt: %d\n", fileSize(textf));
	printf("Size of bin: %d\n", fileSize(binf));

	fseek(textf, 0, SEEK_SET);
	fseek(binf, 0, SEEK_SET);

	printTXT(textf);
	printf("\n");
	printBIN(binf);
	
	return 0;
}

