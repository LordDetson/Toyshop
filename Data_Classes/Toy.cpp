/*
 * Toy.cpp
 *
 *  Created on: 29 нояб. 2017 г.
 *      Author: Дмитрий
 */

#include "Toy.h"

const string Toy::PATH_TOYS = "./Resources/Toys.txt";

Toy::Toy() :
		titel(""), price(0.0), count(0), fromYear(0), beforeYear(0) {
}

Toy::Toy(string titel, float price, unsigned int count,
		unsigned int fromYear, unsigned int beforeYear) :
		titel(titel), price(price), count(count), fromYear(fromYear), beforeYear(
				beforeYear) {
}

Toy::Toy(const Toy& obj) :
		titel(obj.titel), price(obj.price), count(obj.count), fromYear(
				obj.fromYear), beforeYear(obj.beforeYear) {
}

Toy::~Toy() {
}

unsigned int Toy::getBeforeYear() const {
	return beforeYear;
}

void Toy::setBeforeYear(unsigned int beforeYear) {
	this->beforeYear = beforeYear;
}

unsigned int Toy::getCount() const {
	return count;
}

void Toy::setCount(unsigned int count) {
	this->count = count;
}

unsigned int Toy::getFromYear() const {
	return fromYear;
}

void Toy::setFromYear(unsigned int fromYear) {
	this->fromYear = fromYear;
}

float Toy::getPrice() const {
	return price;
}

void Toy::setPrice(float price) {
	this->price = price;
}

const string& Toy::getTitel() const {
	return titel;
}

void Toy::setTitel(const string& titel) {
	this->titel = titel;
}

Toy& Toy::operator=(const Toy &obj) {
	this->beforeYear = obj.beforeYear;
	this->count = obj.count;
	this->fromYear = obj.fromYear;
	this->price = obj.price;
	this->titel = obj.titel;
	return *this;
}

bool operator<(const Toy &first, const Toy &second) {
	return first.titel.compare(second.titel) == -1 ? true : false;
}

bool operator==(const Toy &first, const Toy &second) {
	return first.titel.compare(second.titel) == 0 ? true : false;
}

ostream& operator<<(ostream& stream, Toy& obj) {
	stream << "Название: " << obj.titel << "\n" << "Цена: " << obj.price << "\n"
			<< "Количество: " << obj.count << "\n" << "Возростные ограничения: "
			<< obj.fromYear << " - " << obj.beforeYear << "\n";
	return stream;
}

istream& operator>>(istream& stream, Toy& obj) {
	cout << "Название" << endl;
	obj.titel = inputLine(stream);
	cout << "Цена" << endl;
	obj.price = inputFloat(stream);
	cout << "Количество" << endl;
	obj.count = inputUnsignedInt(stream);
	cout << "Возростные ограничения" << endl;
	cout << "от" << endl;
	obj.fromYear = inputUnsignedInt(stream);
	cout << "до" << endl;
	obj.beforeYear = inputUnsignedInt(stream);
	return stream;
}

ofstream& operator<<(ofstream& stream, Toy& obj) {
	stream << obj.titel.length() << " " << obj.titel << " " << obj.price << " "
			<< obj.count << " " << obj.fromYear << " " << obj.beforeYear << " ";
	return stream;
}

ifstream& operator>>(ifstream& stream, Toy& obj) {
	size_t length;
	stream >> length;
	stream.get();
	obj.titel.clear();
	for (size_t i = 0; i < length; i++) {
		obj.titel += stream.get();
	}
	stream >> obj.price >> obj.count >> obj.fromYear >> obj.beforeYear;
	return stream;
}
