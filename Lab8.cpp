// Lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tests.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Start tests..." << endl;
	testSerie();
	testPhone();
	testDrone();
	testRepoFile();
	testRepoTemplate();
	cout << "Tests finished succesfully!" << endl;
    return 0;
}

