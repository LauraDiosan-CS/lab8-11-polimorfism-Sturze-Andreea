#include "stdafx.h"
#include "PhoneValidator.h"

using namespace std;

PhoneException::PhoneException(vector<string> _errors) : errors{ _errors }
{
}

vector<string> PhoneException::getErrors() const
{
	return this->errors;
}

void PhoneValidator::validate(Phone s)
{
	vector<string> errors;
	if (s.getNrOfProducts() <= 100)
		errors.push_back(string("You can only add series with more than 100 products!\n"));
	if (s.getOperatorsGSM().size() < 1)
		errors.push_back(string("There must be at least one operator GSM in the list!\n"));
	if (errors.size() > 0)
		throw PhoneException(errors);
}
