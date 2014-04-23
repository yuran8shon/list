#include "stdafx.h"
/**
* ���������� �������� � ������.
*/
extern int n;
/** 
* \class list
* \brief ���������, ����������� ������� ������. 
* 
* ����� ����: value - �������� ��������, flag - �������� true - ������� ��� ������, 
* false - ������� �� ��� ������.
*/
struct list{
	int value;
	bool flag; 
};
/** 
* \fn void read (list *first)
* \brief �������, �������� ��� ���������� ������. 
* 
* ���������� ���������� � ������� "����� � ������"-"��������". ���� �� ������ ����� ��� ������ �����-�� ��������, ����� 
* ����������� �������� �� ������� ��������� ���� (������� � ���� �� ��������� ������, ����� �����). ���� ����� ����� ����� �������,
* ��� �������� � ������ ��������� � �������������� �������. ���� ����� ����� ������� �� �����(� ������ ���������� ����������, 
* ����� ������� ��������� ������ �������������. ��� ������������ ����� ������ �������, ����� ������ ������ "error number".
* \param first - ��������� �� ������(�� 1 �������).
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
* \brief �������, �������� ��� ������ ������. 
* 
* ����� i-�� �������. ���� i-�� ������� �� ��� �������� - ��������� "Not set."
* \param first - ��������� �� ������(�� 1 �������).
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
* \brief �������, �������� ��� ��������� �������������. 
* 
* �� ��������� ��� �������� ����� "0", ��� ����� ����� "false".
* \param first - ��������� �� ������(�� 1 �������).
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
* \brief �������, �������� ��� �������� i-�� �������� �� ������.
* \param first - ��������� �� ������(�� 1 �������).
* \param d - ����� ��������, ������� ���������� �������.
*/
void remove(list *first, int d){
	if ((d>0) && (d<n+1)){
		first[d-1].flag=false;
		first[d-1].value=0;
	} else cout << "error number" << endl;
}