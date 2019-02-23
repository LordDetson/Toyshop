/*
 * AdministratorScreen.h
 *
 *  Created on: 13 íîÿá. 2017 ã.
 *      Author: Äìèòðèé
 */

#ifndef SCREENS_ADMINISTRATORSCREEN_H_
#define SCREENS_ADMINISTRATORSCREEN_H_

#include <iostream>
#include <string>
#include <list>
#include "../Data_Classes/UserAccount.h"
#include "../Data_Classes/Toy.h"
#include "../Services/ServiceData.h"
#include "../Services/ServiceUserAccounts.h"
#include "../Ñontrollers/ControllerIStream.h"
#include "../Ñontrollers/ControllerIOFStream.h"
#include "../Services/ServiceToys.h"
#include "ExceptionScreen.h"
using namespace std;

class AdministratorScreen {
private:
	list<UserAccount> *ListUserAccounts;
	list<unsigned int> ListFreeUserId;
	list<Toy> *ListToys;
	static bool created;

	AdministratorScreen(list<UserAccount>&, list<Toy>&);
	AdministratorScreen(const AdministratorScreen&);
	~AdministratorScreen();
	AdministratorScreen& operator=(const AdministratorScreen&);

	void accountManagementMenu();
	void toyManagementMenu();
	void editingUserAccountMenu();
	void editingToyMenu();
	void sortInAscendingOrderUserAccountsMenu();
	void sortInAscendingOrderToysMenu();
	void sortInDecreasingOrderUserAccountsMenu();
	void sortInDecreasingOrderToysMenu();
	void findUserAccountMenu();
	void findToyMenu();
public:
	static AdministratorScreen& instance(list<UserAccount>&, list<Toy>&);
	void showAdministratorScreen();
};

#endif /* SCREENS_ADMINISTRATORSCREEN_H_ */
