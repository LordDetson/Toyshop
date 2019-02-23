/*
 * ServiceUserAccounts.cpp
 *
 *  Created on: 21 ����. 2017 �.
 *      Author: �������
 */

#include "ServiceUserAccounts.h"

const string ServiceUserAccounts::PATH_FREE_USERID =
		"./Resources/FreeUserId.txt";

ServiceUserAccounts::ServiceUserAccounts() {
}

ServiceUserAccounts::~ServiceUserAccounts() {
}

bool ServiceUserAccounts::compUserAccountByUserId(UserAccount& first,
		UserAccount& second) {
	return first.getUserId() < second.getUserId();
}
bool ServiceUserAccounts::compUserAccountByName(UserAccount& first,
		UserAccount& second) {
	return (first.getName().compare(second.getName()) == -1 ? true : false);
}
bool ServiceUserAccounts::compUserAccountByMidname(UserAccount& first,
		UserAccount& second) {
	return (first.getMidname().compare(second.getMidname()) == -1 ? true : false);
}
bool ServiceUserAccounts::compUserAccountByDepartment(UserAccount& first,
		UserAccount& second) {
	return (first.getDepartment().compare(second.getDepartment()) == -1 ?
			true : false);
}
bool ServiceUserAccounts::recompUserAccountByUserId(UserAccount& first,
		UserAccount& second) {
	return first.getUserId() > second.getUserId();
}
bool ServiceUserAccounts::recompUserAccountBySurname(UserAccount& first,
		UserAccount& second) {
	return (first.getSurname().compare(second.getSurname()) == 1 ? true : false);
}
bool ServiceUserAccounts::recompUserAccountByName(UserAccount& first,
		UserAccount& second) {
	return (first.getName().compare(second.getName()) == 1 ? true : false);
}
bool ServiceUserAccounts::recompUserAccountByMidname(UserAccount& first,
		UserAccount& second) {
	return (first.getMidname().compare(second.getMidname()) == 1 ? true : false);
}
bool ServiceUserAccounts::recompUserAccountByDepartment(UserAccount& first,
		UserAccount& second) {
	return (first.getDepartment().compare(second.getDepartment()) == 1 ?
			true : false);
}

list<UserAccount>::iterator ServiceUserAccounts::findUserAccountByUserId(
		list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
		unsigned int userId) {
	for (; begin != end; begin++)
		if (to_string((*begin).getUserId()).find(to_string(userId))!=string::npos)
			return begin;
	return end;
}

list<UserAccount>::iterator ServiceUserAccounts::findUserAccountByPassword(
		list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
		string password) {
	for (; begin != end; begin++)
		if ((*begin).getPassword().find(password) != string::npos)
			return begin;
	return end;
}

list<UserAccount>::iterator ServiceUserAccounts::findUserAccountBySurname(
		list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
		string surname) {
	for (; begin != end; begin++)
		if ((*begin).getSurname().find(surname) != string::npos)
			return begin;
	return end;
}

list<UserAccount>::iterator ServiceUserAccounts::findUserAccountByName(
		list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
		string name) {
	for (; begin != end; begin++)
		if ((*begin).getName().find(name) != string::npos)
			return begin;
	return end;
}

list<UserAccount>::iterator ServiceUserAccounts::findUserAccountByMidname(
		list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
		string midname) {
	for (; begin != end; begin++)
		if ((*begin).getMidname().find(midname) != string::npos)
			return begin;
	return end;
}

list<UserAccount>::iterator ServiceUserAccounts::findUserAccountByDepartment(
		list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
		string department) {
	for (; begin != end; begin++)
		if ((*begin).getDepartment().find(department) != string::npos)
			return begin;
	return end;
}

void ServiceUserAccounts::addUserAccount(list<UserAccount> &ListUserAccounts, list<unsigned int> &ListFreeUserId) {
	system("cls");
	unsigned int maxUserIdInListNow = (*ListUserAccounts.begin()).getUserId();
	if (ListFreeUserId.size() == 0) {
		for (UserAccount ua : ListUserAccounts) {
			if (maxUserIdInListNow < ua.getUserId())
				maxUserIdInListNow = ua.getUserId();
		}
		maxUserIdInListNow++;
	} else {
		maxUserIdInListNow = *ListFreeUserId.begin();
		ListFreeUserId.pop_front();
	}
	UserAccount newUser;
	newUser.setUserId(maxUserIdInListNow);
	cout << "������� ������ � ����� ������������ c ��������������� "
			<< newUser.getUserId() << "\n" << endl;
	cin >> newUser;
	cout << "����������� �������� ����� ������� ������ ������������ (��/���)"
			<< endl;
	cout << newUser << endl;
	string confirmation(inputString(cin));
	if (confirmation == "��")
		ListUserAccounts.push_back(newUser);
	if (confirmation != "��" && confirmation != "���")
		showExceptionScreen();
}

void ServiceUserAccounts::editingSNMUserAccount(list<UserAccount>::iterator& it,
		string passwordAccount) {
	cout << "�������" << endl;
	(*it).setSurname(inputString(cin));
	(*it).setPasdword(
			HashPasswordWithSal()(passwordAccount, (*it).getSurname()));
	cout << "���" << endl;
	(*it).setName(inputString(cin));
	cout << "��������" << endl;
	(*it).setMidname(inputString(cin));
}

void ServiceUserAccounts::editingDepartmentUserAccount(
		list<UserAccount>::iterator& it) {
	cout << "�����" << endl;
	(*it).setDepartment(inputString(cin));
}

void ServiceUserAccounts::editingPasswordUserAccount(
		list<UserAccount>::iterator& it, string passwordAccount) {
	cout << "����� ������" << endl;
	passwordAccount = inputString(cin);
	(*it).setPasdword(
			HashPasswordWithSal()(passwordAccount, (*it).getSurname()));
}

void ServiceUserAccounts::editingAllDataUserAccount(
		list<UserAccount>::iterator& it) {
	cin >> (*it);
}

void ServiceUserAccounts::deleteUserAccount(
		list<UserAccount> &ListUserAccounts, list<unsigned int> &ListFreeUserId) {
	system("cls");
	cout
			<< "������� �������������� ������������, ������ �������� ���������� �������"
			<< endl;
	unsigned int inputUserId = inputUnsignedInt(cin);
	ListUserAccounts.sort(ServiceUserAccounts::compUserAccountByUserId);
	if (inputUserId != 0) {
		list<UserAccount>::iterator findUserAccount = ServiceUserAccounts::findUserAccountByUserId(
				ListUserAccounts.begin(), ListUserAccounts.end(), inputUserId);
		if (findUserAccount != ListUserAccounts.end()) {
			cout
					<< "����������� �������� ������� ������ ������������ � ���� ��� ������� (��/���)"
					<< endl;
			cout << (*findUserAccount) << endl;
			string confirmation(inputString(cin));
			if (confirmation == "��")
				deleteUserAccountByIterator(ListUserAccounts, findUserAccount, ListFreeUserId);
			if (confirmation != "��" && confirmation != "���")
				showExceptionScreen();
		} else
			showNotFindData();
	} else
		cout << "�������������� ������� ������" << endl;
}

void ServiceUserAccounts::deleteUserAccountByIterator(list<UserAccount> &ListUserAccounts, list<UserAccount>::iterator &findUserAccount, list<unsigned int> &ListFreeUserId){
	ListFreeUserId.push_back((*findUserAccount).getUserId());
	ListUserAccounts.remove((*findUserAccount));
}

void ServiceUserAccounts::deleteAllUserAccounts(
		list<UserAccount> &ListUserAccounts, list<unsigned int> &ListFreeUserId) {
	cout
			<< "����������� �������� ���� ������� ������� ������������� � ���� ������� (��/���)"
			<< endl;
	string confirmation(inputString(cin));
	if (confirmation == "��") {
		while(true){
			list<UserAccount>::iterator begin = ++ListUserAccounts.begin();
			list<UserAccount>::iterator end = ListUserAccounts.end();
			if(begin == end)
				break;
			ServiceUserAccounts::deleteUserAccountByIterator(ListUserAccounts, begin, ListFreeUserId);
		}
	}
	if (confirmation != "��" && confirmation != "���")
		showExceptionScreen();

}
