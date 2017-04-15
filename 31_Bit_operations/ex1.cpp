//Даны 2 числа и операция. Вывести на консоль выбранный  байт ответа. 
//Например: 21*37=777, 777= 00000011 00001001, последний байт это 00001001=9.

#include<iostream>
#include<cstring>
using namespace std;



int main()
{

	int a, b;
	cout << "Input a,b: "; cin >> a >> b;
	cout << "*/+-: ";
	char symb;
	cin >> symb;
	int result;
	switch (symb){
	case '*': result = a*b; break;
	case '/': result = a/b; break;
	case '+': result = a+b; break;
	case '-': result = a-b; break;
	}
	
	cout << "Result = " << result << endl;
	
	int number; cout << "\nInput number of byte (0-3): "; cin >> number;
	int new_result = ((255 << (3 - number) * 8)&result) >> ((3 - number) * 8);
	//(3 - number) * 8) - выбор на сколько сдвинуть 255 (0-8-16-24)
	//((255 << (3 - number) * 8) - сдвиг 255 для получения нужного байта
	//((255 << (3 - number) * 8)&result) - к полученому байту применяем битовое & для получения заданного байта
	//>> ((3 - number) * 8) - сдвиг обратно на (0-8-16-24)битиков)

	cout << endl;
	for (int i = 7; i >= 0; --i)
	{
		cout << ((new_result >> i) & 1);
	}
	
	cout << endl;
	return 0;
}

