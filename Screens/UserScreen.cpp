/*
 * UserScreen.cpp
 *
 *  Created on: 13 ����. 2017 �.
 *      Author: �������
 */

#include "UserScreen.h"

bool UserScreen::created = false;

UserScreen::UserScreen(list<Toy> &ListToys) {
	this->ListToys = &ListToys;
	this->created = true;
}

UserScreen::~UserScreen() {
}

UserScreen& UserScreen::instance(list<Toy> &ListToys) {
	static UserScreen *inst;
	if (!created)
		inst = new UserScreen(ListToys);
	return *inst;
}

void UserScreen::showUserScreen() {
	unsigned int variation;
	while (true) {
		system("cls");
		showList(*ListToys);
		cout<<"1.\t���������� �� �����������/�-�\n"
				<<"2.\t���������� �� ��������/�-�\n"
				<<"3.\t�����\n"
				<<"4.\t������� �������� �������, ������� �������� ����� �� x �� y ���\n"
				<<"0.\t�����"
				<<endl;
		variation = inputUnsignedInt(cin);
		switch(variation){
		case 1:
			sortInAscendingOrderToysMenu();
			break;
		case 2:
			sortInDecreasingOrderToysMenu();
			break;
		case 3:
			findToyMenu();
			break;
		case 4:
			ServiceToys::showListToyByFromYearBeforeYear(*ListToys);
			break;
		case 0:
		default:
			showExceptionScreen();
		}
		if (variation == 0)
			break;
	}
}

void UserScreen::sortInAscendingOrderToysMenu(){
	unsigned int variation;
	system("cls");
	cout << "1.\t�� ��������\n" << "2.\t�� ����\n"
			<< "3.\t�� ����������\n"
			<< "4.\t�� ����������� ����������� �� x ����\n"
			<< "5.\t�� ����������� ����������� �� y ����\n"
			<< "0.\t���������" << endl;
	variation = inputUnsignedInt(cin);
	switch (variation) {
	case 1:
		ListToys->sort();
		break;
	case 2:
		ListToys->sort(ServiceToys::compToyByPrice);
		break;
	case 3:
		ListToys->sort(ServiceToys::compToyByCount);
		break;
	case 4:
		ListToys->sort(ServiceToys::compToyByFromYear);
		break;
	case 5:
		ListToys->sort(ServiceToys::compToyByBeforeYear);
		break;
	case 0:
		break;
	default:
		showExceptionScreen();
	}
}

void UserScreen::sortInDecreasingOrderToysMenu(){
	unsigned int variation;
	system("cls");
	cout << "1.\t�� ��������\n" << "2.\t�� ����\n"
				<< "3.\t�� ����������\n"
				<< "4.\t�� ����������� ����������� �� x ����\n"
				<< "5.\t�� ����������� ����������� �� y ����\n"
				<< "0.\t���������" << endl;
	variation = inputUnsignedInt(cin);
	switch (variation) {
	case 1:
		ListToys->sort(ServiceToys::recompToyByTitle);
		break;
	case 2:
		ListToys->sort(ServiceToys::recompToyByPrice);
		break;
	case 3:
		ListToys->sort(ServiceToys::recompToyByCount);
		break;
	case 4:
		ListToys->sort(ServiceToys::recompToyByFromYear);
		break;
	case 5:
		ListToys->sort(ServiceToys::recompToyByBeforeYear);
		break;
	case 0:
		break;
	default:
		showExceptionScreen();
	}
}

void UserScreen::findToyMenu(){
	unsigned int variation;
	while (true) {
		system("cls");
		cout << "1.\t�� ��������\n" << "2.\t�� ����\n"
				<< "3.\t�� ����������\n"
				<< "4.\t�� ����������� ����������� �� x ����\n"
				<< "5.\t�� ����������� ����������� �� y ����\n"
				<< "0.\t���������" << endl;
		variation = inputUnsignedInt(cin);
		list<Toy> findListToys;
		list<Toy>::iterator begin = ListToys->begin();
		list<Toy>::iterator end = ListToys->end();
		string str;
		switch (variation) {
		case 1:
			system("cls");
			cout << "������� �������� (������/�����/����� ��������) ��� ������ ������ ������" << endl;
			str = inputLine(cin);
			while (true) {
				begin = ServiceToys::findToyByTitle(begin, end, str);
				if (begin == end)
					break;
				findListToys.push_back(*begin);
				begin++;
			}
			if (findListToys.size() != 0) {
				showList(findListToys);
				cin.get();
			} else
				showNotFindData();
			break;
		case 2:
			system("cls");
			float price;
			cout
					<< "������� ���� ��� ������ ������ ������"
					<< endl;
			price = inputFloat(cin);
			while (true) {
				begin = ServiceToys::findToyByPrice(begin, end, price);
				if (begin == end)
					break;
				findListToys.push_back(*begin);
				begin++;
			}
			if (findListToys.size() != 0) {
				showList(findListToys);
				cin.get();
			} else
				showNotFindData();
			break;
		case 3:
			system("cls");
			unsigned int count;
			cout
					<< "������� ���������� ��� ������ ������ ������"
					<< endl;
			count = inputUnsignedInt(cin);
			while (true) {
				begin = ServiceToys::findToyByCount(begin, end, count);
				if (begin == end)
					break;
				findListToys.push_back(*begin);
				begin++;
			}
			if (findListToys.size() != 0) {
				showList(findListToys);
				cin.get();
			} else
				showNotFindData();
			break;
		case 4:
			system("cls");
			unsigned int FromYear;
			cout
					<< "������� ����������� ����������� �� x ���� ��� ������ ������ ������"
					<< endl;
			FromYear = inputUnsignedInt(cin);
			while (true) {
				begin = ServiceToys::findToyByFromYear(begin, end, FromYear);
				if (begin == end)
					break;
				findListToys.push_back(*begin);
				begin++;
			}
			if (findListToys.size() != 0) {
				showList(findListToys);
				cin.get();
			} else
				showNotFindData();
			break;
		case 5:
			system("cls");
			unsigned int BeforeYear;
			cout
					<< "������� ����������� ����������� �� y ���� ��� ������ ������ ������"
					<< endl;
			BeforeYear = inputUnsignedInt(cin);
			while (true) {
				begin = ServiceToys::findToyByBeforeYear(begin, end, BeforeYear);
				if (begin == end)
					break;
				findListToys.push_back(*begin);
				begin++;
			}
			if (findListToys.size() != 0) {
				showList(findListToys);
				cin.get();
			} else
				showNotFindData();
			break;
		case 0:
			break;
		default:
			showExceptionScreen();
		}
		if (variation == 0)
			break;
		cin.get();
	}
}
