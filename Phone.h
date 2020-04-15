#pragma once
#include <iostream>
#include <vector>
#include "Serie.h"
using namespace std;

class Phone:public Serie {
private:
	vector<char*> operatorsGSM;
public:
	Phone();
	Phone(const char*, const char*, int, vector<char*>);
	Phone(const Phone&);
	vector<char*> getOperatorsGSM();
	void setOperatorsGSM(vector<char*>);
	Phone& operator=(const Phone&);
	bool operator==(const Phone&);
	//friend ostream& operator<<(ostream& os, Phone);
	friend istream& operator>>(istream&, Phone&);
	~Phone();
};