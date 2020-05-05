#pragma once
#include <string>
#include "Phone.h"
#include <vector>

class PhoneException
{
private:
	vector<string> errors;

public:
	PhoneException(vector<string>);
	vector<string> getErrors() const;
};

class PhoneValidator
{
public:
	PhoneValidator() {}
	void validate(Phone);
	~PhoneValidator() {}
};