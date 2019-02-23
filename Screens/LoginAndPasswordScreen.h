/*
 * LoginAndPasswordScreen.h
 *
 *  Created on: 13 ����. 2017 �.
 *      Author: �������
 */

#ifndef SCREENS_LOGINANDPASSWORDSCREEN_H_
#define SCREENS_LOGINANDPASSWORDSCREEN_H_
#include <iostream>
#include <windows.h>
#include <list>

#include "../�onverters/HashPasswordWithSal.h"
#include "../Services/ServiceData.h"
#include "../Services/ServiceUserAccounts.h"
#include "../Data_Classes/UserAccount.h"
#include "../�ontrollers/ControllerIStream.h"
#include "ExceptionScreen.h"
using namespace std;

class LoginAndPasswordScreen{
private:
	list<UserAccount> *ListUserAccounts;
	static bool created;

	LoginAndPasswordScreen(list<UserAccount>&);
	LoginAndPasswordScreen(const LoginAndPasswordScreen&);
	~LoginAndPasswordScreen();
	LoginAndPasswordScreen& operator=(const LoginAndPasswordScreen&);
	list<UserAccount>::iterator inputAndCheckLoginAndPassword();
public:
	static LoginAndPasswordScreen& instance(list<UserAccount>&);
	list<UserAccount>::iterator showLoginAndPasswordScreen();
};

#endif /* SCREENS_LOGINANDPASSWORDSCREEN_H_ */
