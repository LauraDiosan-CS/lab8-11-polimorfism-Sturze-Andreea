#pragma once
#include <iostream>
using namespace std;

class Serie {
protected:
	char* producerName;
	char* modelName;
	int nrOfProducts;
public:
	Serie();
	Serie(const char*, const char*, int);
	Serie(const Serie&);
	char* getProducerName();
	char* getModelName();
	int getNrOfProducts();
	void setProducerName(const char*);
	void setModelName(const char*);
	void setNrOfProducts(int);
	virtual Serie& operator=(const Serie&);
	virtual bool operator==(const Serie&);
	friend ostream& operator<<(ostream& os, Serie);
	friend istream& operator>>(istream&, Serie&);
	~Serie();
};