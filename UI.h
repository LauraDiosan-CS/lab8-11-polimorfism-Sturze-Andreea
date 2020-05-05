#pragma once
#include "Service.h"
#include "Drone.h"

class UI {
private:
	Service service;
	void printMenu();
	void printMenuOperare();
	void printAll();
	void add();
	void login();
	void operare();
	void logout();
public:
	UI(Service &serv) :service(serv) {};
	void run();
	~UI();
};