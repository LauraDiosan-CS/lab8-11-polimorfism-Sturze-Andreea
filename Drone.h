#pragma once
#include <iostream>
#include "Serie.h"
#include <vector>
using namespace std;

class Drone:public Serie {
private:
	int rotorsNr;
public:
	Drone();
	Drone(const char*, const char*,int ,int);
	Drone(const Drone&);
	int getRotorsNr();
	void setRotorsNr(int);
	Drone& operator=(const Drone&);
	bool operator==(const Drone&);
	friend ostream& operator<<(ostream& os, Drone);
	friend istream& operator>>(istream&, Drone&);
	~Drone();
};