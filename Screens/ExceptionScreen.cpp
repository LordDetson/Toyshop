/*
 * ExceptionScreen.cpp
 *
 *  Created on: 13 ����. 2017 �.
 *      Author: �������
 */

#include "ExceptionScreen.h"

void showExceptionScreen(){
	system("cls");
	cout<<"������ ����� ������! ���������� ��� ���!"<<endl;
	fflush(stdin);
	cin.get();
}

void showNotFindData(){
	system("cls");
	cout<<"�� ������ ������� ������ �� ����������! ���������� ��� ���!"<<endl;
	fflush(stdin);
	cin.get();
}

void showNotData(){
	system("cls");
	cout<<"������ ��� � ���� ������! ��� ����������� �����������!"<<endl;
	fflush(stdin);
	cin.get();
}

void showNotFindUserId(unsigned int UserId){
	system("cls");
	cout<<"������������ � ����� ID = " << UserId << " ��� � ���� ������!"<<endl;
	fflush(stdin);
	cin.get();
}
