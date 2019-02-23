/*
 * ServiceBooks.cpp
 *
 *  Created on: 28 ����. 2017 �.
 *      Author: �������
 */

#include "ServiceToys.h"

bool ServiceToys::compToyByPrice(Toy &first, Toy &second){
	return first.getPrice() < second.getPrice();
}
bool ServiceToys::compToyByCount(Toy &first, Toy &second){
	return first.getCount() < second.getCount();
}
bool ServiceToys::compToyByFromYear(Toy &first, Toy &second){
	return first.getFromYear() < second.getFromYear();
}
bool ServiceToys::compToyByBeforeYear(Toy &first, Toy &second){
	return first.getBeforeYear() < second.getBeforeYear();
}

bool ServiceToys::recompToyByTitle(Toy &first, Toy &second){
	return first.getTitel().compare(second.getTitel()) == 1 ? true : false;
}
bool ServiceToys::recompToyByPrice(Toy &first, Toy &second){
	return first.getPrice() > second.getPrice();
}
bool ServiceToys::recompToyByCount(Toy &first, Toy &second){
	return first.getCount() > second.getCount();
}
bool ServiceToys::recompToyByFromYear(Toy &first, Toy &second){
	return first.getFromYear() > second.getFromYear();
}
bool ServiceToys::recompToyByBeforeYear(Toy &first, Toy &second){
	return first.getBeforeYear() > second.getBeforeYear();
}

list<Toy>::iterator ServiceToys::findToyByTitle(list<Toy>::iterator begin,
		list<Toy>::iterator end, string titel){
	for (; begin != end; begin++)
		if ((*begin).getTitel().find(titel) != string::npos)
			return begin;
	return end;
}
list<Toy>::iterator ServiceToys::findToyByPrice(list<Toy>::iterator begin,
		list<Toy>::iterator end, float price){
	for (; begin != end; begin++)
		if (to_string((double)(*begin).getPrice()).find(to_string((double)price)) != string::npos)
			return begin;
	return end;
}
list<Toy>::iterator ServiceToys::findToyByCount(
		list<Toy>::iterator begin, list<Toy>::iterator end,
		unsigned int count){
	for (; begin != end; begin++)
		if (to_string((*begin).getCount()).find(to_string(count)) != string::npos)
			return begin;
	return end;
}
list<Toy>::iterator ServiceToys::findToyByFromYear(
		list<Toy>::iterator begin, list<Toy>::iterator end,
		unsigned int fromYear){
	for (; begin != end; begin++)
		if (to_string((*begin).getFromYear()).find(to_string(fromYear)) != string::npos)
			return begin;
	return end;
}
list<Toy>::iterator ServiceToys::findToyByBeforeYear(list<Toy>::iterator begin,
		list<Toy>::iterator end, unsigned int beforeYear){
	for (; begin != end; begin++)
		if (to_string((*begin).getBeforeYear()).find(to_string(beforeYear)) != string::npos)
			return begin;
	return end;
}

void ServiceToys::addToy(list<Toy> &ListToys){
	system("cls");
	Toy newToy;
	cout << "������� ������ � ����� �������" <<endl;
	cin>>newToy;
	cout << "����������� �������� ����� ������� � �������� (��/���)" << endl;
	cout << newToy << endl;
	string confirmation(inputString(cin));
	if (confirmation == "��")
		ListToys.push_back(newToy);
	if (confirmation != "��" && confirmation != "���")
		showExceptionScreen();

}
void ServiceToys::editingTitleToy(list<Toy>::iterator &findToy){
	cout<<"��������"<<endl;
	(*findToy).setTitel(inputLine(cin));
}
void ServiceToys::editingPriceToy(list<Toy>::iterator &findToy){
	cout<<"����"<<endl;
	(*findToy).setPrice(inputFloat(cin));
}
void ServiceToys::editingCountToy(list<Toy>::iterator &findToy){
	cout<<"����������"<<endl;
	(*findToy).setCount(inputUnsignedInt(cin));
}
void ServiceToys::editingFromYearAndBeforeYearToy(list<Toy>::iterator &findToy){
	cout<<"���������� �����������\n��"<<endl;
	(*findToy).setFromYear(inputUnsignedInt(cin));
	cout<<"��"<<endl;
	(*findToy).setBeforeYear(inputUnsignedInt(cin));
}

void ServiceToys::deleteToy(list<Toy> &ListToys){
	system("cls");
	cout << "������� �������������� �����, ������ �������� ���������� �������"
			<< endl;
	string inputToyTitle = inputLine(cin);
	ListToys.sort();
	list<Toy>::iterator findToy = ServiceToys::findToyByTitle(ListToys.begin(),ListToys.end(), inputToyTitle);
	if (findToy != ListToys.end()) {
		cout<< "����������� �������� �����(��/���)"
				<< endl;
		cout << (*findToy) << endl;
		string confirmation(inputString(cin));
		if (confirmation == "��")
			ListToys.remove(*findToy);
		if (confirmation != "��" && confirmation != "���")
			showExceptionScreen();
	} else
		showNotFindData();
}
void ServiceToys::deleteAllToy(list<Toy> &ListToys){
	cout<< "����������� �������� ���� ����(��/���)"
			<< endl;
	string confirmation(inputString(cin));
	if (confirmation == "��") {
		while (true) {
			list<Toy>::iterator begin = ListToys.begin();
			list<Toy>::iterator end = ListToys.end();
			if (begin == end)
				break;
			ListToys.remove(*begin);
		}
	}
	if (confirmation != "��" && confirmation != "���")
		showExceptionScreen();
}

void ServiceToys::showListToyByFromYearBeforeYear(list<Toy> &ListToys){
	unsigned int FromYear;
	unsigned int BeforeYear;
	bool findData = false;
	cout<<"���������� �����������\n��"<<endl;
	FromYear = inputUnsignedInt(cin);
	cout<<"��"<<endl;
	BeforeYear = inputUnsignedInt(cin);
	for(Toy t:ListToys)
		if(t.getFromYear()>=FromYear&&t.getBeforeYear()<=BeforeYear){
			findData = true;
			cout<<t<<endl;
		}
	if(!findData)
		showNotFindData();
}
