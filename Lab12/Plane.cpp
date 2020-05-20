#include "Plane.h"

Plane::Plane() {
}

Plane::Plane(char* begin, char* ending) {
	strcpy_s(beginning, strlen(begin) + 1, begin);
	strcpy_s(end, strlen(ending) + 1, ending);
}

char* Plane::getBeginning() {
	return this->beginning;
}

char* Plane::getEnd() {
	return this->end;
}

void Plane::setBeginning(char* newB) {
	strcpy_s(beginning, strlen(newB) + 1, newB);
}

void Plane::setEnd(char* newE) {
	strcpy_s(end, strlen(newE) + 1, newE);
}

Plane::~Plane() {
}