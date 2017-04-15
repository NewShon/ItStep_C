//Выяснить является ли число степенью двойки, используя битовые операции.

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	setlocale(0, "");
	int a; cout << "Enter a number: "; cin >> a;
	bool flag = true;
	for (; a > 1;){
		if (a == 2)
		{
			cout << "Число является степенем двойки\n";
			flag = false;
			break;
		}
		a >>= 1;
	}
	if (flag) cout << "Число не является степенем двойки\n";

	cout << endl;
	return 0;
}
