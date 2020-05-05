#include "stdafx.h"
#include "SerieValidator.h"

using namespace std;

SerieException::SerieException(vector<string> _errors) : errors{ _errors }
{
}

vector<string> SerieException::getErrors() const
{
	return this->errors;
}

void SerieValidator::validate(Serie* s)
{
	vector<string> errors;
	if (s->getNrOfProducts()<=100)
		errors.push_back(string("You can only add series with more than 100 products!\n"));
	if (errors.size() > 0)
		throw SerieException(errors);
}
