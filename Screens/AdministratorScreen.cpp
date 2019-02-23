/*
 * AdministratorScreen.cpp
 *
 *  Created on: 13 ����. 2017 �.
 *      Author: �������
 */

#include "AdministratorScreen.h"

bool AdministratorScreen::created = false;

AdministratorScreen::AdministratorScreen(list<UserAccount> &ListUserAccounts,
		list<Toy> &ListToys) {
	this->ListUserAccounts = &ListUserAccounts;
	this->ListToys = &ListToys;
	this->created = true;
	this->ListFreeUserId = readFile(ServiceUserAccounts::PATH_FREE_USERID,
			ListFreeUserId);
}

AdministratorScreen::~AdministratorScreen() {
}

AdministratorScreen& AdministratorScreen::instance(
		list<UserAccount> &ListUserAccounts, list<Toy> &ListToys) {
	static AdministratorScreen *inst;
	if (!created)
		inst = new AdministratorScreen(ListUserAccounts, ListToys);
	return *inst;
}

void AdministratorScreen::showAdministratorScreen() {
	unsigned int variation;
	while (true) {
		system("cls");
		cout << "1.\t������� ������ �������������\n"
				<< "2.\t������\n" << "3.\t���������� ���������\n"
				<< "0.\t�����" << endl;
		variation = inputUnsignedInt(cin);
		switch (variation) {
		case 1:
			accountManagementMenu();
			break;
		case 2:
			toyManagementMenu();
			break;
		case 3:
			ListUserAccounts->sort(
					ServiceUserAccounts::compUserAccountByUserId);
			ListToys->sort();
			writeFile(UserAccount::PATH_USER_ACCOUNTS, *ListUserAccounts);
			writeFile(Toy::PATH_TOYS, *ListToys);
			writeFile(ServiceUserAccounts::PATH_FREE_USERID, ListFreeUserId);
			*ListUserAccounts = readFile(UserAccount::PATH_USER_ACCOUNTS,
					*ListUserAccounts);
			*ListToys = readFile(Toy::PATH_TOYS, *ListToys);
			ListFreeUserId = readFile(ServiceUserAccounts::PATH_FREE_USERID,
					ListFreeUserId);
			cout << "��������� ���������" << endl;
			fflush(stdin);
			cin.get();
			break;
		case 0:
			break;
		default:
			showExceptionScreen();
		}
		if (variation == 0)
			break;
	}
}

void AdministratorScreen::accountManagementMenu() {
	unsigned int variation;
	while (true) {
		system("cls");
		showList(*ListUserAccounts);
		cout << "1.\t�������� ������� ������ ������������\n"
				<< "2.\t������������� ������� ������ ������������\n"
				<< "3.\t�������� ������� ������ ������������\n"
				<< "4.\t�������� ���� ������� ������� �������������\n"
				<< "5.\t���������� �� �����������/�-�\n"
				<< "6.\t���������� �� ��������/�-�\n" << "7.\t�����\n"
				<< "0.\t���������" << endl;
		variation = inputUnsignedInt(cin);
		switch (variation) {
		case 1:
			ServiceUserAccounts::addUserAccount(*ListUserAccounts, ListFreeUserId);
			break;
		case 2:
			editingUserAccountMenu();
			break;
		case 3:
			ServiceUserAccounts::deleteUserAccount(*ListUserAccounts, ListFreeUserId);
			break;
		case 4:
			ServiceUserAccounts::deleteAllUserAccounts(
					*ListUserAccounts, ListFreeUserId);
			break;
		case 5:
			sortInAscendingOrderUserAccountsMenu();
			break;
		case 6:
			sortInDecreasingOrderUserAccountsMenu();
			break;
		case 7:
			findUserAccountMenu();
			break;
		case 0:
			break;
		default:
			showExceptionScreen();
		}
		if (variation == 0)
			break;
	}
}

void AdministratorScreen::toyManagementMenu() {
	unsigned int variation;
	while (true) {
		system("cls");
		showList(*ListToys);
		cout << "1.\t�������� �������\n" << "2.\t������������� �������\n"
				<< "3.\t�������� �������\n" << "4.\t�������� ���� �������\n"
				<< "5.\t���������� �� �����������/�-�\n"
				<< "6.\t���������� �� ��������/�-�\n" << "7.\t�����\n"
				<< "8.\t������� �������� �������, ������� �������� ����� �� x �� y ���\n"
				<< "0.\t���������" << endl;
		variation = inputUnsignedInt(cin);
		switch (variation) {
		case 1:
			ServiceToys::addToy(*ListToys);
			break;
		case 2:
			editingToyMenu();
			break;
		case 3:
			ServiceToys::deleteToy(*ListToys);
			break;
		case 4:
			ServiceToys::deleteAllToy(*ListToys);
			break;
		case 5:
			sortInAscendingOrderToysMenu();
			break;
		case 6:
			sortInDecreasingOrderToysMenu();
			break;
		case 7:
			findToyMenu();
			break;
		case 8:
			ServiceToys::showListToyByFromYearBeforeYear(*ListToys);
			break;
		case 0:
			break;
		default:
			showExceptionScreen();
		}
		if (variation == 0)
			break;
	}
}

void AdministratorScreen::editingUserAccountMenu() {
	system("cls");
	cout
			<< "������� �������������� ������������, ������ �������� ���������� ��������"
			<< endl;
	unsigned int inputUserId = inputUnsignedInt(cin);
	ListUserAccounts->sort(ServiceUserAccounts::compUserAccountByUserId);
	list<UserAccount>::iterator findUserAccount =
			ServiceUserAccounts::findUserAccountByUserId(
					ListUserAccounts->begin(), ListUserAccounts->end(),
					inputUserId);
	if (findUserAccount != ListUserAccounts->end()) {
		cout
				<< "����������� �������������� ���� ������� ������ ������������ (������)\n"
				<< (*findUserAccount) << endl;
		string passwordAccount(inputString(cin));
		if (HashPasswordWithSal()(passwordAccount,
				(*findUserAccount).getSurname())
				== (*findUserAccount).getPassword()) {
			unsigned int variation;
			while (true) {
				system("cls");
				cout << (*findUserAccount) << endl;
				cout << "1.\t������� ��� �������� ������� ������ ������������\n"
						<< "2.\t����� ������� ������ ������������\n"
						<< "3.\t������ ������� ������ ������������\n"
						<< "4.\t��� ������ �� ������� ������ ������������\n"
						<< "0.\t���������" << endl;
				variation = inputUnsignedInt(cin);
				switch (variation) {
				case 1:
					ServiceUserAccounts::editingSNMUserAccount(findUserAccount,
							passwordAccount);
					ListUserAccounts->sort();
					break;
				case 2:
					ServiceUserAccounts::editingDepartmentUserAccount(
							findUserAccount);

					break;
				case 3:
					ServiceUserAccounts::editingPasswordUserAccount(
							findUserAccount, passwordAccount);
					break;
				case 4:
					ServiceUserAccounts::editingAllDataUserAccount(
							findUserAccount);
					ListUserAccounts->sort();
					break;
				case 0:
					break;
				default:
					showExceptionScreen();
				}
				if (variation == 0)
					break;
			}
		} else
			showExceptionScreen();
	} else
		showNotFindData();
}

void AdministratorScreen::editingToyMenu() {
	system("cls");
	cout << "������� �������� �������, ������ �������� ���������� ��������"
			<< endl;
	string inputToyTitle = inputLine(cin);
	ListToys->sort();
	list<Toy>::iterator findToy = ServiceToys::findToyByTitle(
			ListToys->begin(), ListToys->end(), inputToyTitle);
	list<UserAccount>::iterator activeAccount = (*ListUserAccounts).begin();
	if (findToy != ListToys->end()) {
		cout << "����������� �������������� ���� ������� (��/���)\n"
				<< (*findToy) << endl;
		string confirmation(inputString(cin));
		if (confirmation == "��") {
			unsigned int variation;
			while (true) {
				system("cls");
				cout << (*findToy) << endl;
				cout << "1.\t��������\n"
						<< "2.\t����\n"
						<< "3.\t����������\n"
						<< "4.\t���������� �����������\n"
						<< "0.\t���������"
						<< endl;
				variation = inputUnsignedInt(cin);
				switch (variation) {
				case 1:
					ServiceToys::editingTitleToy(findToy);
					break;
				case 2:
					ServiceToys::editingPriceToy(findToy);
					break;
				case 3:
					ServiceToys::editingCountToy(findToy);
					break;
				case 4:
					ServiceToys::editingFromYearAndBeforeYearToy(findToy);
					break;
				case 0:
					break;
				default:
					showExceptionScreen();
				}
				if (variation == 0)
					break;
			}
		}
		if (confirmation != "��" && confirmation != "���")
			showExceptionScreen();
	} else
		showNotFindData();
}

void AdministratorScreen::sortInAscendingOrderUserAccountsMenu() {
	unsigned int variation;
	system("cls");
	cout << "1.\t�� ��������������\n" << "2.\t�� �������\n" << "3.\t�� �����\n"
			<< "4.\t�� ��������\n" << "5.\t�� �������\n" << "0.\t���������"
			<< endl;
	variation = inputUnsignedInt(cin);
	switch (variation) {
	case 1:
		ListUserAccounts->sort(ServiceUserAccounts::compUserAccountByUserId);
		break;
	case 2:
		ListUserAccounts->sort();
		break;
	case 3:
		ListUserAccounts->sort(ServiceUserAccounts::compUserAccountByName);
		break;
	case 4:
		ListUserAccounts->sort(ServiceUserAccounts::compUserAccountByMidname);
		break;
	case 5:
		ListUserAccounts->sort(
				ServiceUserAccounts::compUserAccountByDepartment);
		break;
	case 0:
		break;
	default:
		showExceptionScreen();
	}
}

void AdministratorScreen::sortInAscendingOrderToysMenu() {
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

void AdministratorScreen::sortInDecreasingOrderUserAccountsMenu() {
	unsigned int variation;
	system("cls");
	cout << "1.\t�� ��������������\n" << "2.\t�� �������\n"
			<< "3.\t�� �����\n" << "4.\t�� ��������\n" << "5.\t�� �������\n"
			<< "0.\t���������" << endl;
	variation = inputUnsignedInt(cin);
	switch (variation) {
	case 1:
		ListUserAccounts->sort(
				ServiceUserAccounts::recompUserAccountByUserId);
		break;
	case 2:
		ListUserAccounts->sort(
				ServiceUserAccounts::recompUserAccountBySurname);
		break;
	case 3:
		ListUserAccounts->sort(
				ServiceUserAccounts::recompUserAccountByName);
		break;
	case 4:
		ListUserAccounts->sort(
				ServiceUserAccounts::recompUserAccountByMidname);
		break;
	case 5:
		ListUserAccounts->sort(
				ServiceUserAccounts::recompUserAccountByDepartment);
		break;
	case 0:
		break;
	default:
		showExceptionScreen();
	}
}

void AdministratorScreen::sortInDecreasingOrderToysMenu(){
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

void AdministratorScreen::findUserAccountMenu() {
	unsigned int variation;
	while (true) {
		system("cls");
		cout << "1.\t�� ��������������\n" << "2.\t�� �������\n"
				<< "3.\t�� �����\n" << "4.\t�� ��������\n" << "5.\t�� �������\n"
				<< "0.\t���������" << endl;
		variation = inputUnsignedInt(cin);
		list<UserAccount> findListUserAccounts;
		list<UserAccount>::iterator begin = ListUserAccounts->begin();
		list<UserAccount>::iterator end = ListUserAccounts->end();
		string str;
		switch (variation) {
		case 1:
			system("cls");
			unsigned int userId;
			cout << "������� ������������� ��� ������ ������ ������" << endl;
			userId = inputUnsignedInt(cin);
			while (true) {
				begin = ServiceUserAccounts::findUserAccountByUserId(begin, end,
						userId);
				if (begin == end)
					break;
				findListUserAccounts.push_back(*begin);
				begin++;
			}
			if (findListUserAccounts.size() != 0) {
				showList(findListUserAccounts);
				cin.get();
			} else
				showNotFindData();
			break;
		case 2:
			system("cls");
			cout
					<< "������� ������� (������/�����/����� �������) ��� ������ ������ ������"
					<< endl;
			str = inputString(cin);
			while (true) {
				begin = ServiceUserAccounts::findUserAccountBySurname(begin,
						end, str);
				if (begin == end)
					break;
				findListUserAccounts.push_back(*begin);
				begin++;
			}
			if (findListUserAccounts.size() != 0) {
				showList(findListUserAccounts);
				cin.get();
			} else
				showNotFindData();
			break;
		case 3:
			system("cls");
			cout
					<< "������� ��� (������/�����/����� �����) ��� ������ ������ ������"
					<< endl;
			str = inputString(cin);
			while (true) {
				begin = ServiceUserAccounts::findUserAccountByName(begin, end,
						str);
				if (begin == end)
					break;
				findListUserAccounts.push_back(*begin);
				begin++;
			}
			if (findListUserAccounts.size() != 0) {
				showList(findListUserAccounts);
				cin.get();
			} else
				showNotFindData();
			break;
		case 4:
			system("cls");
			cout
					<< "������� �������� (������/�����/����� ��������) ��� ������ ������ ������"
					<< endl;
			str = inputString(cin);
			while (true) {
				begin = ServiceUserAccounts::findUserAccountByMidname(begin,
						end, str);
				if (begin == end)
					break;
				findListUserAccounts.push_back(*begin);
				begin++;
			}
			if (findListUserAccounts.size() != 0) {
				showList(findListUserAccounts);
				cin.get();
			} else
				showNotFindData();
			break;
		case 5:
			system("cls");
			cout
					<< "������� ������ (������/�����/����� ������) ��� ������ ������ ������"
					<< endl;
			str = inputString(cin);
			while (true) {
				begin = ServiceUserAccounts::findUserAccountByDepartment(begin,
						end, str);
				if (begin == end)
					break;
				findListUserAccounts.push_back(*begin);
				begin++;
			}
			if (findListUserAccounts.size() != 0) {
				showList(findListUserAccounts);
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

void AdministratorScreen::findToyMenu(){
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
