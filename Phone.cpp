#include "stdafx.h"
#include "Phone.h"
#include <string.h>
#include <iostream>
using namespace std;


Phone::Phone() {
	
}

Phone::Phone(const char* n, const char* l, int s, vector<char*> op) :Serie(n, l, s) {
	operatorsGSM = op;
}

Phone::Phone(const Phone& s):Serie(s) {
	operatorsGSM = s.operatorsGSM;
}

Phone::~Phone() {
}

vector<char*> Phone::getOperatorsGSM() {
	return operatorsGSM;
}

void Phone::setOperatorsGSM(vector<char*> op) {
	operatorsGSM = op;
}

Phone& Phone::operator=(const Phone& c) {
	if (this == &c)
		return *this; 
	Serie::operator=(c);
	operatorsGSM = c.operatorsGSM;
	return *this;
}

bool Phone::operator==(const Phone& c) {
	return (Serie::operator==(c) && (operatorsGSM == c.operatorsGSM));
}

//ostream& operator<<(ostream& os, Phone c) {
//	if (c.getProducerName())
//	{
//		os << c.getProducerName() << " " << c.getModelName() << " " << c.getNrOfProducts() << " ";
//		for (int i = 0; i < c.operatorsGSM.size(); i++)
//			cout << c.getOperatorsGSM[i] << " ";
//		cout << endl;
//	}
//	return os;
//}

istream & operator>>(istream &is, Phone &c)
{
	cout << "Prodcer Name: ";
	char* producerName = new char[20];
	is >> producerName;
	cout << "Model Name: ";
	char* modelName = new char[20];
	is >> modelName;
	cout << "Number of products: ";
	int nrOfProducts;
	is >> nrOfProducts;
	int i = 0;
	vector<char*> x;
	cout << "List of GSM operators: ";
	while (is >> x[i])
		i++;
	c.setProducerName(producerName);
	c.setModelName(modelName);
	c.setNrOfProducts(nrOfProducts);
	c.setOperatorsGSM(x);
	delete[] producerName;
	delete[] modelName;
	return is;
}