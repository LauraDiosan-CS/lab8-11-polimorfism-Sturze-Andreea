// Lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tests.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Start tests..." << endl;
	testPhone();
	testDrone();
	testUser();
	testRepoTemplate();
	//testRepoFileCSV();
	//testRepoFileCustom();
	//testRepoFileCSVP();
	testService();
	cout << "Tests finished succesfully!" << endl;
	cout << "Do you want to use csv or custom txt files?" << endl;
	char* x= new char[5];
	cin >> x;
	RepoFile<Serie*>* repo = new RepoFileCSV<Serie*>;
	SerializerSerie* s = new SerializerSerie;
	if (strcmp(x,"csv")==0)
		repo = new RepoFileCSV<Serie*>("objects.csv",s);
	else
		repo = new RepoFileCustom<Serie*>("objects.txt",s);
	SerializerWithoutP<User>* sr = new SerializerWithoutP<User>;
	RepoFileCustom<User>* repoU= new RepoFileCustom<User>("user.txt", sr);
	Service serv(repo, repoU);
	UI ui(serv);
	ui.run();
	delete[] x, repo, repoU;
	for (Serie* crt : repo->getAll())
		delete crt;
    return 0;
}

