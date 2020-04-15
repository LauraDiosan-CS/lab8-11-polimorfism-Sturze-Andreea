#include "stdafx.h"
#include "Serie.h"
#include <string.h>
#include <iostream>
using namespace std;


Serie::Serie() {
	producerName = NULL;
	modelName = NULL;
	nrOfProducts = 0;
}

Serie::Serie(const char* n, const char* l, int s) {
	producerName = new char[strlen(n) + 1];
	strcpy_s(producerName, strlen(n) + 1, n);
	modelName = new char[strlen(l) + 1];
	strcpy_s(modelName, strlen(l) + 1, l);
	nrOfProducts = s;
}

Serie::Serie(const Serie& s) {
	producerName = new char[strlen(s.producerName) + 1];
	strcpy_s(producerName, strlen(s.producerName) + 1, s.producerName);

	modelName = new char[strlen(s.modelName) + 1];
	strcpy_s(modelName, strlen(s.modelName) + 1, s.modelName);

	nrOfProducts = s.nrOfProducts;
}

Serie::~Serie() {
	if (producerName)
	{
		delete[] producerName;
		producerName = NULL;
	}
	if (modelName)
	{
		delete[] modelName;
		modelName = NULL;
	}
	nrOfProducts = 0;
}

char* Serie::getProducerName() {
	return producerName;
}

char* Serie::getModelName() {
	return modelName;
}

int Serie::getNrOfProducts() {
	return nrOfProducts;
}

void Serie::setProducerName(const char* n) {
	if (producerName)
		delete[] producerName;
	producerName = new char[strlen(n) + 1];
	strcpy_s(producerName, strlen(n) + 1, n);
}

void Serie::setModelName(const char* l) {
	if (modelName)
		delete[] modelName;
	modelName = new char[strlen(l) + 1];
	strcpy_s(modelName, strlen(l) + 1, l);
}

void Serie::setNrOfProducts(int s) {
	nrOfProducts = s;
}

Serie& Serie::operator=(const Serie& c) {
	if (this == &c)
		return *this;
	if (c.producerName)
		setProducerName(c.producerName);
	if (c.modelName)
		setModelName(c.modelName);
	setNrOfProducts(c.nrOfProducts);
	return *this;
}

bool Serie::operator==(const Serie& c) {
	if (c.producerName and c.modelName)
		return (strcmp(producerName, c.producerName) == 0 and strcmp(modelName, c.modelName) == 0 and nrOfProducts== c.nrOfProducts);
	return false;
}

ostream& operator<<(ostream& os, Serie c) {
	if (c.getProducerName())
		os << c.getProducerName() << " " << c.getModelName() << " " << c.getNrOfProducts() << endl;
	return os;
}

istream & operator>>(istream &is, Serie &c)
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
	c.setProducerName(producerName);
	c.setModelName(modelName);
	c.setNrOfProducts(nrOfProducts);
	delete[] producerName;
	delete[] modelName;
	return is;
}
