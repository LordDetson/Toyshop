/*
 * UserScreen.h
 *
 *  Created on: 13 но€б. 2017 г.
 *      Author: ƒмитрий
 */

#ifndef SCREENS_USERSCREEN_H_
#define SCREENS_USERSCREEN_H_
#include <iostream>
#include <string>
#include <list>
#include "../Data_Classes/Toy.h"
#include "../Services/ServiceData.h"
#include "../Services/ServiceToys.h"
using namespace std;

class UserScreen {
private:
	list<Toy> *ListToys;
	static bool created;

	UserScreen(list<Toy>&);
	~UserScreen();
	UserScreen(const UserScreen&);
	UserScreen& operator=(const UserScreen&);
	void sortInAscendingOrderToysMenu();
	void sortInDecreasingOrderToysMenu();
	void findToyMenu();
public:
	static UserScreen& instance(list<Toy>&);
	void showUserScreen();
};

#endif /* SCREENS_USERSCREEN_H_ */
