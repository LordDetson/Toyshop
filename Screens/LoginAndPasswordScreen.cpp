/*
 * LoginAndPasswordScreen.cpp
 *
 *  Created on: 13 ����. 2017 �.
 *      Author: �������
 */

#include "LoginAndPasswordScreen.h"

bool LoginAndPasswordScreen::created=false;

LoginAndPasswordScreen::LoginAndPasswordScreen(list<UserAccount> &ListUserAccounts){
	this->ListUserAccounts=&ListUserAccounts;
}

LoginAndPasswordScreen::~LoginAndPasswordScreen(){
	delete ListUserAccounts;
}

LoginAndPasswordScreen& LoginAndPasswordScreen::instance(list<UserAccount> &ListUserAccounts){
	static LoginAndPasswordScreen *inst;
	if (!created)
		inst = new LoginAndPasswordScreen(ListUserAccounts);
	return *inst;
}

list<UserAccount>::iterator LoginAndPasswordScreen::showLoginAndPasswordScreen() {
	list<UserAccount>::iterator activeAccount;
	while(true){
		activeAccount = inputAndCheckLoginAndPassword();
		if (activeAccount != ListUserAccounts->end()){
			system("cls");
			cout<<"�� ����� ��� ������� �������"<<endl;
			cout << (*activeAccount) << endl;
			fflush(stdin);
			cin.get();
			break;
		}
	}
	return activeAccount;
}

list<UserAccount>::iterator LoginAndPasswordScreen::inputAndCheckLoginAndPassword(){
	system("cls");
	cout << "������� ����� � ������ ��� ����� � �������" << endl;
	cout << "�����" << endl;
	unsigned int login = inputUnsignedInt(cin);
	cout << "������" << endl;
	string password = inputString(cin);
	list<UserAccount>::iterator it = ServiceUserAccounts::findUserAccountByUserId(ListUserAccounts->begin(),
			ListUserAccounts->end(), login);
	if (it == ListUserAccounts->end()){
		showNotFindData();
		return ListUserAccounts->end();
	}
	if ((*it).getPassword().compare(
			HashPasswordWithSal()(password, (*it).getSurname())) != 0){
		showExceptionScreen();
		return ListUserAccounts->end();
	}
	return it;
}
