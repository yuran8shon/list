#include "stdafx.h"
/**
* Количество элемнтов в списке.
*/
extern int n;
/** 
* \class list
* \brief Структура, реализующая элемент списка. 
* 
* Имеет поля: value - значение элемента, flag - значение true - элемент был введен, 
* false - элемент не был введен.
*/
struct list{
	int value;
	bool flag; 
};
/** 
* \fn void read (list *first)
* \brief Функция, служащая для считывания списка. 
* 
* Считывание происходит в формате "номер в списке"-"значение". Если на данном месте уже естоит какое-то значение, будет 
* произведена проверка на наличее свободных мест (сначала с прва от вводимого номера, затем слева). Если такое место будет найдено,
* все элементы в списке сдвинутся в соответсвующую сторону. Если такое место найдено не будет(в данной реализации невозможно, 
* новый элемент запишется поверх существующего. При неправильном вводе номера элемнта, будет выдана ошибка "error number".
* \param first - указатель на массив(на 1 элемент).
*/
void read (list *first){	
	for (int i=0; i < n; i++){

		bool flag_right=false, flag_left=false;
		int j;
		cout << "j: ";
		cin >> j;

		if ((j>0) && (j<n+1)){

			if (first[j-1].flag) {
				for (int k = n-1; k>j-1; k--){

					if (!first[k].flag){
						first[k].value=first[k-1].value; 
						first[k].flag=true;
						first[k-1].value=0;
						first[k-1].flag=false;
						flag_right = true;
					}
				}
				if (!flag_right) {
					for (int k = 0; k<j-1; k++){
						if (!first[k].flag){
							first[k].value=first[k+1].value; 
							first[k].flag=first[k+1].flag;
							first[k+1].value=0;
							first[k+1].flag=false;					
							flag_left = true;
						}

					}
				}
			}
			cout << "list[" << j << "]: "; 
			cin >> first[j-1].value;
			first[j-1].flag = true;
		}
		else cout << "error number" << endl;
	}
	return;
}
/** 
* \fn  void print (list *first)
* \brief Функция, служащая для вывода списка. 
* 
* Вывод i-ый элемент. Если i-ый элемент не был заполнен - выводится "Not set."
* \param first - указатель на массив(на 1 элемент).
*/
void print (list *first){
	if (n==0) cout << "NULL";
	for (int i=0; i < n; i++){
		if (first[i].flag) cout << first[i].value << endl;
		else cout << "Not set." << endl;
	}
	return;
}
/** 
* \fn void initialisation(list *first)
* \brief Функция, служащая для начальной инициализации. 
* 
* По умолчанию все элементы равны "0", все флаги равны "false".
* \param first - указатель на массив(на 1 элемент).
*/
void initialisation(list *first){
	for (int i = 0; i<n; i++){
		first[i].flag=false;
		first[i].value=0;
	}
	return;
}
/** 
* \fn void remove(list *first, int d)
* \brief Функция, служащая для удаления i-го элемента из списка.
* \param first - указатель на массив(на 1 элемент).
* \param d - номер элемента, который необходимо удалить.
*/
void remove(list *first, int d){
	if ((d>0) && (d<n+1)){
		first[d-1].flag=false;
		first[d-1].value=0;
	} else cout << "error number" << endl;
}