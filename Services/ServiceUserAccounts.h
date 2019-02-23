/*
 * ServiceUserAccounts.h
 *
 *  Created on: 21 ����. 2017 �.
 *      Author: �������
 */

#ifndef SERVICES_USERACCOUNTS_H_
#define SERVICES_USERACCOUNTS_H_
#include <iostream>
#include <list>
#include "../Data_Classes/UserAccount.h"
#include "../�ontrollers/ControllerIOFStream.h"
#include "../Screens/ExceptionScreen.h"
#include "ServiceToys.h"
using namespace std;

class ServiceUserAccounts {
private:
	ServiceUserAccounts();
	ServiceUserAccounts(const ServiceUserAccounts&);
	~ServiceUserAccounts();
	ServiceUserAccounts& operator=(const ServiceUserAccounts&);
public:
	static const string PATH_FREE_USERID;

	static bool compUserAccountByUserId(UserAccount& first, UserAccount& second);
	static bool compUserAccountByName(UserAccount& first, UserAccount& second);
	static bool compUserAccountByMidname(UserAccount& first, UserAccount& second);
	static bool compUserAccountByDepartment(UserAccount& first, UserAccount& second);
	static bool recompUserAccountByUserId(UserAccount& first, UserAccount& second);
	static bool recompUserAccountBySurname(UserAccount& first, UserAccount& second);
	static bool recompUserAccountByName(UserAccount& first, UserAccount& second);
	static bool recompUserAccountByMidname(UserAccount& first, UserAccount& second);
	static bool recompUserAccountByDepartment(UserAccount& first, UserAccount& second);


	static list<UserAccount>::iterator findUserAccountByUserId(
			list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
			unsigned int userId);
	static list<UserAccount>::iterator findUserAccountByPassword(
			list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
			string password);
	static list<UserAccount>::iterator findUserAccountBySurname(
			list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
			string surname);
	static list<UserAccount>::iterator findUserAccountByName(
			list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
			string name);
	static list<UserAccount>::iterator findUserAccountByMidname(
			list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
			string midname);
	static list<UserAccount>::iterator findUserAccountByDepartment(
			list<UserAccount>::iterator begin, list<UserAccount>::iterator end,
			string department);

	static void addUserAccount(list<UserAccount>&, list<unsigned int>&);
	static void editingSNMUserAccount(list<UserAccount>::iterator&, string);
	static void editingDepartmentUserAccount(list<UserAccount>::iterator&);
	static void editingPasswordUserAccount(list<UserAccount>::iterator&, string);
	static void editingAllDataUserAccount(list<UserAccount>::iterator&);

	static void deleteUserAccount(list<UserAccount>&, list<unsigned int>&);
	static void deleteUserAccountByIterator(list<UserAccount>&, list<UserAccount>::iterator&, list<unsigned int>&);
	static void deleteAllUserAccounts(list<UserAccount>&, list<unsigned int>&);
};

#endif /* SERVICES_USERACCOUNTS_H_ */
