#include "stdafx.h"
#include "Drone.h"
#include <string.h>
#include <iostream>
using namespace std;


Drone::Drone() {
	rotorsNr = 0;
}

Drone::Drone(const char* n, const char* l, int s, int nr) :Serie(n, l, s) {
	rotorsNr =nr;
}

Drone::Drone(const Drone& s) : Serie(s) {
	rotorsNr = s.rotorsNr;
}

Drone::~Drone() {
}

int Drone::getRotorsNr() {
	return rotorsNr;
}

void Drone::setRotorsNr(int nr) {
	rotorsNr = nr;
}

Drone& Drone::operator=(const Drone& c) {
	if (this == &c)
		return *this;
	Serie::operator=(c);
	rotorsNr = c.rotorsNr;
	return *this;
}

bool Drone::operator==(const Drone& c) {
	return (Serie::operator==(c) && (rotorsNr = c.rotorsNr));
}

ostream& operator<<(ostream& os, Drone c) {
	if (c.getProducerName())
	{
		os << c.getProducerName() << " " << c.getModelName() << " " << c.getNrOfProducts() << " " << c.rotorsNr << endl;
	}
	return os;
}

istream & operator>>(istream &is, Drone &c)
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
	int nr;
	is >> nr;
	c.setProducerName(producerName);
	c.setModelName(modelName);
	c.setNrOfProducts(nrOfProducts);
	c.setRotorsNr(nr);
	delete[] producerName;
	delete[] modelName;
	return is;
}