//  определяет точку входа для консольного приложения.
//
/**
* \mainpage Приложение, реализующее список. 
* \brief 
* 
* Список хранится в виде массива длины n. Все функции для работы со списком хранятся в файле functions.h
*/
#include "stdafx.h"
#include "head.h"

int n;
struct list;
void read (list *first);

void print (list *first);

void initialisation(list *first);

void remove(list *first, int d);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter n: ";
	cin >> n; 
	list *first;
	first = new list[n];
	initialisation(first);
	read (first);
	int d;
	cout << "num del: ";
	cin >> d;
	remove (first, d);
	print(first);
	return 0;
}


