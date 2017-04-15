//Дано число, вывести  его двоичное представление, используя только битовые операции.

#include<iostream>
#include<cstring>
using namespace std;


int main()
{
	int a, b; cout << "Input a,b: "; cin >> a >> b;
	char symb; cout << "*/+-: "; cin >> symb;
	
	int result;
	switch (symb){
	case '*': result = a*b; break;
	case '/': result = a / b; break;
	case '+': result = a + b; break;
	case '-': result = a - b; break;
	}
	cout << "Result = " << result;

	for (int i = 31; i >= 0; --i)
	{
		cout << ((result >> i) & 1);//побитовый сдвиг на единицу и битовое & с единицей для получения каждого отдельного бита
		if (i % 8 == 0) cout << " ";
	}

	cout << endl;
	return 0;
}
