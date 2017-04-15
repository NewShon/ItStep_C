/*Счет в банке представляет собой структуру с полями:
•	номер счета, 
•	код счета, 
•	фамилия владельца, 
•	сумма на счете, 
•	дата открытия счета, 
•	годовой процент начисления.
 Реализовать поиск в массиве структур по номеру счета, по коду счета и по владельцу.
Реализовать сортировку по фамилии владельца и по номеру счета.
Реализовать удаление в массиве структур по коду счета и по владельцу.*/


#include<iostream>
#include<cstring>
using namespace std;

const int size = 20;
struct Client
{
	int account;
	int id;
	char fio[40];
	int money;
	char dateOpen[12];
	float procent;
	Client *next;
};

Client *ClientAddClient(Client *client)
{
	Client *cur = (Client*)malloc(sizeof(Client));

	cur->next = NULL;
	cout << "Enter account: "; cin >> cur->account;
	cout << "Enter id: "; cin >> cur->id;
	cout << "Enter fio: "; cin >> cur->fio;
	cout << "Enter money: "; cin >> cur->money;
	cout << "Enter dataOpen: "; cin >> cur->dateOpen;
	cout << "Enter procent: "; cin >> cur->procent;
	cout << endl;

	if (!client) return cur;
	
	Client *next_client = client;
	for (; next_client->next != NULL; next_client = next_client->next);

	next_client->next = cur;
	return client;
}
void ClientPrintClients(Client cl)
{
	Client *client = &cl;
	for (; client != NULL; client = client->next)
	{
		cout << "\naccount: " << client->account;
		cout << "\nid: " << client->id;
		cout << "\nfio: " << client->fio;
		cout << "\nmoney: " << client->money;
		cout << "\ndataOpen: " << client->dateOpen;
		cout << "\nprocent: " << client->procent;
		cout << endl;
	}
}
void ClientFindAcc(Client *cl, int acc)
{
	Client *client = cl;
	for (; client != NULL; client = client->next){
		if (client->account == acc){
			cout << "\naccount: " << client->account;
			cout << "\nid: " << client->id;
			cout << "\nfio: " << client->fio;
			cout << "\nmoney: " << client->money;
			cout << "\ndataOpen: " << client->dateOpen;
			cout << "\nprocent: " << client->procent;
			cout << endl;
			return;
		}
	}
	cout << "Not found\n";
}
void ClientFindNum(Client *cl, int num)
{
	Client *client = cl;
	for (; client != NULL; client = client->next){
		if (client->id == num){
			cout << "\naccount: " << client->account;
			cout << "\nid: " << client->id;
			cout << "\nfio: " << client->fio;
			cout << "\nmoney: " << client->money;
			cout << "\ndataOpen: " << client->dateOpen;
			cout << "\nprocent: " << client->procent;
			cout << endl;
			return;
		}
	}
	cout << "Not found\n";
}
void ClientFindFIO(Client *cl, char *name)
{
	Client *client = cl;
	for (; client != NULL; client = client->next){
		if (client->fio != name){
			cout << "\naccount: " << client->account;
			cout << "\nid: " << client->id;
			cout << "\nfio: " << client->fio;
			cout << "\nmoney: " << client->money;
			cout << "\ndataOpen: " << client->dateOpen;
			cout << "\nprocent: " << client->procent;
			cout << endl;
			return;
		}
	}
	cout << "Not found\n";
}
Client* ClientSortID(Client *cl)
{
	if (cl->next == NULL) return cl;
	Client *cur, *temp, *temp2, *prev, *end = NULL;
	bool flag = true;

	while (flag)
	{
		flag = false;
		cur = cl;
		prev = NULL;
		if (cur->id > cur->next->id)
		{
			temp = cur; temp2 = cur->next->next;
			cl = temp->next;
			cl->next = temp;
			cl->next->next = temp2;
			flag = true;
		}
		else cur = cur->next;
		prev = cl;
		while (cur->next != NULL)
		{
			if (cur->id > cur->next->id)
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = cur;
				flag = true;
			}
			else cur = cur->next;
			prev = prev->next;
		}
	}
	return cl;
}
Client* ClientSortFIO(Client *cl)
{
	if (cl->next == NULL) return cl;
	Client *cur, *temp, *temp2, *prev, *end = NULL;
	bool flag = true;

	while (flag)
	{
		flag = false;
		cur = cl;
		prev = NULL;
		if (strcmp(cur->fio, cur->next->fio)>0)
		{
			temp = cur; temp2 = cur->next->next;
			cl = temp->next;
			cl->next = temp;
			cl->next->next = temp2;
			flag = true;
		}
		else cur = cur->next;
		prev = cl;
		while (cur->next != NULL)
		{
			if (strcmp(cur->fio, cur->next->fio)>0)
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = cur;
				flag = true;
			}
			else cur = cur->next;
			prev = prev->next;
		}
	}
	return cl;
}
Client *ClientDeliteFIO(Client *cl)
{
	char name[30];
	cin >> name;
	Client *cur = cl;

	if (strcmp(name, cur->fio) == 0)
	{
		Client *temp = cur->next;
		free(cur);
		return temp;
	}

	while (cur)
	{
		if (strcmp(name, cur->next->fio) == 0)
		{
			Client *temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
		}
		cur = cur->next;
	}
	return cl;
}
Client *ClientDeliteID(Client *cl)
{
	char name[30];
	cin >> name;
	Client *cur = cl;

	if (name, cur->id == 0)
	{
		Client *temp = cur->next;
		free(cur);
		return temp;
	}

	while (cur)
	{
		if (name, cur->next->id == 0)
		{
			Client *temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
		}
		cur = cur->next;
	}
	return cl;
}




int main(){
	setlocale(0, "");
	Client *client = NULL;

	bool flag = true;
	while (flag)
	{
		cout << "1 - поиск по номеру счета\n"
			<< "2 - поиск по коду счета\n"
			<< "3 - поиск по владельцу\n"
			<< "4 - сортировка по фамилии владельца\n"
			<< "5 - сортировка по номеру счета\n"
			<< "6 - удаление по коду счета\n"
			<< "7 - удаление по владельцу\n"
			<< "8 - добавление клиента\n"
			<< "9 - вывод всех клиентов\n"
			<< "0 - Выход\n";
		int choice; cout << "Ваш выбор: "; cin >> choice;
		system("cls");

		switch (choice){
		case 1:int acc; cout << "Введите номер счета: "; cin >> acc; ClientFindAcc(client, acc); break;
		case 2:int id; cout << "Введите код счета: "; cin >> id; ClientFindNum(client, id); break;
		case 3:char fio[40]; cout << "Введите имя владельца: "; cin >> fio; ClientFindFIO(client, fio); break;
		case 4: client = ClientSortFIO(client); break;
		case 5: client = ClientSortID(client); break;
		case 6: cout << "Введите id владельца которого желаете удалить: "; client = ClientDeliteID(client); break;
		case 7: {cout << "Введите имя владельца которого желаете удалить: "; client = ClientDeliteFIO(client); break; }
		case 8: client = ClientAddClient(client); break;
		case 9: ClientPrintClients(*client); break;
		case 0: flag = false;
		}
	}
	
	system("pause");
	return 0;
}
