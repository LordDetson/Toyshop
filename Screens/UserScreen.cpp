/*
 * UserScreen.cpp
 *
 *  Created on: 13 нояб. 2017 г.
 *      Author: Дмитрий
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
		cout<<"1.\tСортировка по возрастанию/А-Я\n"
				<<"2.\tСортировка по убыванию/Я-А\n"
				<<"3.\tПоиск\n"
				<<"4.\tВывести названия игрушек, которые подходят детям от x до y лет\n"
				<<"0.\tВыйти"
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
	cout << "1.\tПо названию\n" << "2.\tПо цене\n"
			<< "3.\tПо количеству\n"
			<< "4.\tПо возростному ограничению от x года\n"
			<< "5.\tПо возростному ограничению до y года\n"
			<< "0.\tВернуться" << endl;
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
	cout << "1.\tПо названию\n" << "2.\tПо цене\n"
				<< "3.\tПо количеству\n"
				<< "4.\tПо возростному ограничению от x года\n"
				<< "5.\tПо возростному ограничению до y года\n"
				<< "0.\tВернуться" << endl;
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
		cout << "1.\tПо названию\n" << "2.\tПо цене\n"
				<< "3.\tПо количеству\n"
				<< "4.\tПо возростному ограничению от x года\n"
				<< "5.\tПо возростному ограничению до y года\n"
				<< "0.\tВернуться" << endl;
		variation = inputUnsignedInt(cin);
		list<Toy> findListToys;
		list<Toy>::iterator begin = ListToys->begin();
		list<Toy>::iterator end = ListToys->end();
		string str;
		switch (variation) {
		case 1:
			system("cls");
			cout << "Введите название (начало/конец/часть названия) для поиска нужной записи" << endl;
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
					<< "Введите цену для поиска нужной записи"
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
					<< "Введите количество для поиска нужной записи"
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
					<< "Введите возростному ограничению от x года для поиска нужной записи"
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
					<< "Введите возростному ограничению до y года для поиска нужной записи"
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
