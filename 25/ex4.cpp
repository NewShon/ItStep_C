//������ ������������ ����� �������������� ������������ ���������, ��������� �� ��������� � �������������� �������� ��������(+, -,*, /).
//�	������� ��������.
//�	������� ��������.
//�	��������� �������� ���������.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100]; // ������ ������
	char *s; // ���������
	char oper[20]; // ������ ��������
	const char operation[5] = "*/+-"; // ������ �������� ��������� ��� ������������� ������ ������� strpbrk
	int arr[20]; // ������ ���������(�����)
	int	n_arr = 0; // ���������� ����� � ������
	int size_operation = 0; // ���������� �������� � ������

	cout << "������� �������������� ���������:	";
	cin.getline(str, 100);

	while (s = strpbrk(str, operation)) // ���������� ������� ���������� �� ������
	{
		oper[size_operation++] = *s;
		*s = ' ';
	}

	s = strtok(str, " ");
	while (s) // ���������� ������ ��������� �� ������
	{
		arr[n_arr++] = atoi(s);
		s = strtok(0, " ");
	}

	cout << "\n���� ����� �������� ���� = ";
	for (int i = 0; i < n_arr; i++) // ������� ��������(�����)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "���� �������������� �������� �������� ���� = ";
	for (int i = 0; i < size_operation; i++) // ������� ��������(*/+-)
	{
		cout << oper[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size_operation; i++) // �������� * � / ����� ����� ������� ��������� ��� + � -, ������ ���� �� �������� ���������, ��������� �������� � ������� ������ ������� �� -2
	{
		if (oper[i] == '*')
		{
			arr[i] *= arr[i + 1];
			memcpy(&arr[i + 1], &arr[i + 2], sizeof(int)*n_arr - (i + 1) - 1);
			n_arr--;
			memcpy(&oper[i], &oper[i + 1], size_operation - (i + 1));
			size_operation--;
			i--;
		}
		else if (oper[i] == '/')
		{
			arr[i] /= arr[i + 1];
			memcpy(&arr[i + 1], &arr[i + 2], sizeof(int)*n_arr - (i + 2));
			n_arr--;
			memcpy(&oper[i], &oper[i + 1], size_operation - (i + 1));
			size_operation--;
			i--;
		}
	}

	for (int i = 0; i < size_operation; i++) // ��������� ������� ������� �������� ���������� �������� + � -
	{
		if (oper[i] == '+')
		{
			arr[i + 1] += arr[i];
		}
		else if (oper[i] == '-')
		{
			arr[i + 1] = arr[i] - arr[i + 1];
		}
	}
	cout << "\n����� = " << arr[size_operation] << endl << endl;
	return 0;
}