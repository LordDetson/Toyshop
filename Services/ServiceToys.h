/*
 * ServiceToys.h
 *
 *  Created on: 28 íîÿá. 2017 ã.
 *      Author: Äìèòðèé
 */

#ifndef SERVICES_SERVICETOYS_H_
#define SERVICES_SERVICETOYS_H_
#include <iostream>
#include <list>
#include "../Data_Classes/Toy.h"
#include "../Ñontrollers/ControllerIOFStream.h"
#include "../Ñontrollers/ControllerIOFStream.h"
#include "../Screens/ExceptionScreen.h"
using namespace std;

class ServiceToys {
	ServiceToys();
	ServiceToys(const ServiceToys&);
	~ServiceToys();
	ServiceToys& operator=(const ServiceToys&);
public:

	static bool compToyByPrice(Toy&, Toy&);
	static bool compToyByCount(Toy&, Toy&);
	static bool compToyByFromYear(Toy&, Toy&);
	static bool compToyByBeforeYear(Toy&, Toy&);

	static bool recompToyByTitle(Toy&, Toy&);
	static bool recompToyByPrice(Toy&, Toy&);
	static bool recompToyByCount(Toy&, Toy&);
	static bool recompToyByFromYear(Toy&, Toy&);
	static bool recompToyByBeforeYear(Toy&, Toy&);

	static list<Toy>::iterator findToyByTitle(list<Toy>::iterator begin,
			list<Toy>::iterator end, string titel);
	static list<Toy>::iterator findToyByPrice(list<Toy>::iterator begin,
			list<Toy>::iterator end, float price);
	static list<Toy>::iterator findToyByCount(
			list<Toy>::iterator begin, list<Toy>::iterator end,
			unsigned int count);
	static list<Toy>::iterator findToyByFromYear(
			list<Toy>::iterator begin, list<Toy>::iterator end,
			unsigned int fromYear);
	static list<Toy>::iterator findToyByBeforeYear(list<Toy>::iterator begin,
			list<Toy>::iterator end, unsigned int beforeYear);

	static void addToy(list<Toy>&);
	static void editingTitleToy(list<Toy>::iterator&);
	static void editingPriceToy(list<Toy>::iterator&);
	static void editingCountToy(list<Toy>::iterator&);
	static void editingFromYearAndBeforeYearToy(list<Toy>::iterator&);

	static void deleteToy(list<Toy>&);
	static void deleteAllToy(list<Toy>&);

	static void showListToyByFromYearBeforeYear(list<Toy>&);

};

#endif /* SERVICES_SERVICETOYS_H_ */
