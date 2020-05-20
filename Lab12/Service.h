#pragma once
#include "Table.h"

class Service {
private:
	Table playerTable;
	Table computerTable;
public:
	Service(){}
	~Service(){}
	char **getTable();
	void addPlane(char[4], char[4]);
};