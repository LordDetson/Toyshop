/*
 * Toy.h
 *
 *  Created on: 29 íîÿá. 2017 ã.
 *      Author: Äìèòðèé
 */

#ifndef DATA_CLASSES_TOY_H_
#define DATA_CLASSES_TOY_H_
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include "../Ñontrollers/ControllerIStream.h"

class Toy {
private:
	string titel;
	float price;
	unsigned int count;
	unsigned int fromYear;
	unsigned int beforeYear;
public:
	static const string PATH_TOYS;

	Toy();
	Toy(string, float, unsigned int, unsigned int, unsigned int);
	Toy(const Toy&);
	~Toy();

	unsigned int getBeforeYear() const;
	void setBeforeYear(unsigned int beforeYear);
	unsigned int getCount() const;
	void setCount(unsigned int count);
	unsigned int getFromYear() const;
	void setFromYear(unsigned int fromYear);
	float getPrice() const;
	void setPrice(float price);
	const string& getTitel() const;
	void setTitel(const string& titel);
	Toy& operator=(const Toy&);
	friend bool operator<(const Toy&, const Toy&);
	friend bool operator==(const Toy&, const Toy&);
	friend ostream& operator<<(ostream&, Toy&);
	friend istream& operator>>(istream&, Toy&);
	friend ofstream& operator<<(ofstream&, Toy&);
	friend ifstream& operator>>(ifstream&, Toy&);
};

#endif /* DATA_CLASSES_TOY_H_ */
