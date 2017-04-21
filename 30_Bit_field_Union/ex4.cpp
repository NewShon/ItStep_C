/*Реализовать структуру «Утюг» 
(фирма, модель, цвет, минимальная температура, максимальная температура, подача пара да/нет, мощность).
Создайте динамический массив структур  «Утюг»:
Редактировать элемент
Вывести модели только с подачей пара
Вывести модели больше заданной мощности
Вывести все модели одного производителя*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
using namespace std;

struct Iron
{
	char firm[10];
	char model[10];
	char color[10];
	int tempMin;
	int tempMax;
	bool steam;
	int power;
};
Iron *change(Iron *iron, int n)
{
	int el;
	printf("1 - firm\n2 - model\n3 - color\n4 - tempMin\n5 - tempMax\n6 - steam\n");
	scanf("Enter el which u want to change: %d", &el);
	switch (el)
	{
	case 1: scanf("Enter: "); iron->firm; break;
	case 2: scanf("Enter: "); iron->model; break;
	case 3: scanf("Enter: "); iron->color; break;
	case 4: scanf("Enter: "); iron->tempMin; break;
	case 5: scanf("Enter: "); iron->tempMax; break;
	case 6: scanf("Enter: "); iron->steam; break;
	}
	return iron;
}
Iron *add(Iron *iron,int n)
{
	printf("1 - firm\n2 - model\n3 - color\n4 - tempMin\n5 - tempMax\n6 - steam\n");
	for (int i = 0; i < n; i++)
	{
		scanf("Enter: "); scanf("&s",iron->firm);
		scanf("Enter: ");  scanf("&s", iron->model);
		scanf("Enter: ");  scanf("&s", iron->color);
		scanf("Enter: ");  scanf("&d", iron->tempMin);
		scanf("Enter: ");  scanf("&d", iron->tempMax);
		scanf("Enter: ");  scanf("&d", iron->steam);
	}

	return iron;
}
void printSteam(Iron *iron, int n)
{
	for (int i = 0; i < n; i++)
		if (iron[i].steam == 1){
			printf("firm: ", iron[i].firm);
			printf("model: ", iron[i].model);
			printf("color: ", iron[i].color);
			printf("tempMin: ", iron[i].tempMin);
			printf("tempMax: ", iron[i].tempMax);
			printf("steam: ", iron[i].steam);
		}
}
void printFirm(Iron *iron, int n, char *str)
{
	for (int i = 0; i < n; i++)
		if (iron[i].firm == str){
			printf("firm: ", iron[i].firm);
			printf("model: ", iron[i].model);
			printf("color: ", iron[i].color);
			printf("tempMin: ", iron[i].tempMin);
			printf("tempMax: ", iron[i].tempMax);
			printf("steam: ", iron[i].steam);
		}
}
void printPower(Iron *iron, int n, int power)
{
	for (int i = 0; i < n; i++)
		if (iron[i].power > power){
			printf("firm: ", iron[i].firm);
			printf("model: ", iron[i].model);
			printf("color: ", iron[i].color);
			printf("tempMin: ", iron[i].tempMin);
			printf("tempMax: ", iron[i].tempMax);
			printf("steam: ", iron[i].steam);
		}
}
int main()
{
	int n;
	printf("Input number of irons: ");
	scanf("%d", &n);
	Iron *iron = (Iron*)malloc(n*sizeof(Iron));

	iron = add(iron, n);
	iron = change(iron, 1);

	printSteam(iron,n);
	printPower(iron, n, 50);
	printFirm(iron, n, "Bulbash");

	return 0;
}
