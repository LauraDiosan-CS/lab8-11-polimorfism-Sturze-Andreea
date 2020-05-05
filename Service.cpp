#include "stdafx.h"
#include "Service.h"
using namespace std;

Service::~Service() {
}


int Service::addToRepo(Serie* c) {
	v.validate(c);
	int rez = repo->addElem(c);
	return rez;
}

int Service::delFromRepo(Serie* c) {
	return repo->delElem(c);
}

int Service::updateInRepo(Serie*& c, Serie* newC) {
	repo->updateElem(c, newC);
	return 0;
}

list<Serie*> Service::getFromRepo() {
	return repo->getAll();
}

int Service::getRepoSize() {
	return repo->getSize();
}

bool Service::findElemInRepo(Serie*& c) {
	return repo->findElem(c);
}


Serie* Service::getItemFromPos(int i) {
	return repo->getItemFromPos(i);
}

bool Service::login(const char* u, const char* p)
{
	User usr(u, p);
	bool rez = repoUser->findElem(usr);
	if (rez == true)
	{
		user.setUserName(u);
		user.setPassword(p);
	}
	return rez;
}

void Service::logout()
{
	if (user.getUserName() == "")
		throw("You are not logged in!");
	user = User();

}

bool Service::loggedIn() {
	if (user.getUserName() == "")
		return false;
	return true;
}

void Service::validatePhone(Phone p) {
	vp.validate(p);
}