#include<iostream>
#include<cstring>
using namespace std;

struct bit
{
	bool a0 : 1;
	bool a1 : 1;
	bool a2 : 1;
	bool a3 : 1;
	bool a4 : 1;
	bool a5 : 1;
	bool a6 : 1;
	bool a7 : 1;
};

union Int{
	int data;
	unsigned char byte[sizeof(int)];
	bit b[sizeof(int)];
};

union Float{
	double data;
	unsigned char byte[sizeof(double)];
	bit b[sizeof(double)];
};

int main()
{
	Int a;
	Float b;
	a.data = 200;
	b.data = 20.41;
	for (int i = 3; i >= 0; i--)
	{
		cout << hex << (int)a.byte[i] << " ";
	}
	cout << endl;

	for (int i = 7; i >= 0; i--)
	{
		cout << hex << (int)b.byte[i] << " ";
	}
	cout << endl;

	for (int i = 3; i >= 0; i--)
	{
		cout << a.b[i].a7 << a.b[i].a6 << a.b[i].a5 << a.b[i].a4 << a.b[i].a3 << a.b[i].a2 << a.b[i].a1 << a.b[i].a0 << " ";
	}
	cout << endl;

	for (int i = 7; i >= 0; i--)
	{
		cout << b.b[i].a7 << b.b[i].a6 << b.b[i].a5 << b.b[i].a4 << b.b[i].a3 << b.b[i].a2 << b.b[i].a1 << b.b[i].a0 << " ";
	}
	cout << endl;

	int choise;
	cin >> choise;
	choise = 3 - choise;
	cout << a.b[choise].a7 << a.b[choise].a6 << a.b[choise].a5 << a.b[choise].a4 << a.b[choise].a3 << a.b[choise].a2 << a.b[choise].a1 << a.b[choise].a0 << " ";


	//int choise;
	/*cout << "1.Enter int" << endl;
	cout << "2.Enter int" << endl;
	cout << "3.Enter int" << endl;
	cout << "4.Enter int" << endl;
	cout << "Enter choise: ";
	cin >> choise;

	switch (choise)
	{
	case 1:
	{

	}
	}*/



	return 0;
}
