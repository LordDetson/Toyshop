#include <iostream>
#include <list>
#include "./Screens/LoginAndPasswordScreen.h"
#include "./Screens/AdministratorScreen.h"
#include "./Screens/UserScreen.h"
#include "./Ñontrollers/ControllerIOFStream.h"
#include "./Data_Classes/UserAccount.h"
#include "./Data_Classes/Toy.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list<UserAccount> ListUserAccounts;
	ListUserAccounts = readFile(UserAccount::PATH_USER_ACCOUNTS,
			ListUserAccounts);
	list<Toy> ListToys;
	ListToys = readFile(Toy::PATH_TOYS, ListToys);
	list<UserAccount>::iterator activeAccount =
			LoginAndPasswordScreen::instance(ListUserAccounts).showLoginAndPasswordScreen();
	if ((*activeAccount).getUserId() == 0) {
		AdministratorScreen::instance(ListUserAccounts, ListToys).showAdministratorScreen();
		return 0;
	}
	UserScreen::instance(ListToys).showUserScreen();
	return 0;
}
