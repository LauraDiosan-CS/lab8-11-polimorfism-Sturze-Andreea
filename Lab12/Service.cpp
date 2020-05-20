#include "Service.h"
#include "Plane.h"

char **Service::getTable() {
	char **x = playerTable.getTable();
	return x;
}

void Service::addPlane(char beginning[4], char end[4]) {
	char* b = new char[4];
	for (int i = 0; i < 4; i++)
		b[i] = beginning[i];
	char* e = new char[4];
	for (int i = 0; i < 4; i++)
		e[i] = end[i];
	Plane v(b, e);
	delete[] b, e;
	playerTable.add(v);
}
