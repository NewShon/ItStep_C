#include<iostream>
#include <cstring>
using namespace std;

int func(int col, int first, ...)
{
	int sum = 0;
	int *ptr = &first;
	while (col--)
	{
		sum += *ptr;
		ptr++;
	}
	return sum;
}

int main(){

	cout << func(8, 3, 2, 1, 5, 9, 8, 5, 3);

	cout << endl;
	return 0;
}
