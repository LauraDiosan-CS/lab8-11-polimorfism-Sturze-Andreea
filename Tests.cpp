#include "stdafx.h"
#include "Tests.h"
#include "Serie.h"
#include "Phone.h"
#include "Drone.h"
#include "RepoFile.h"
#include "RepoTemplate.h"
#include <assert.h>
#include <string.h>


void testSerie() {
	Serie c("ion", "CJ23AAA", 7);
	assert(strcmp(c.getProducerName(), "ion") == 0);
	assert(strcmp(c.getModelName(), "CJ23AAA") == 0);
	assert(c.getNrOfProducts()== 7);
	Serie c1;
	assert(c1.getProducerName() == NULL);
	assert(c1.getModelName() == NULL);
	assert(c1.getNrOfProducts() ==0);
	Serie c2(c);
	assert(strcmp(c2.getProducerName(), "ion") == 0);
	assert(strcmp(c2.getModelName(), "CJ23AAA") == 0);
	assert(c2.getNrOfProducts()== 7);
	c.setProducerName("ana");
	assert(strcmp(c.getProducerName(), "ana") == 0);
	c.setModelName("CJ44BBB");
	assert(strcmp(c.getModelName(), "CJ44BBB") == 0);
	c.setNrOfProducts(6);
	assert(c.getNrOfProducts()== 6);
	Serie c3("ana", "CJ44BBB", 6);
	assert(c == c3);
}

void testPhone() {
	vector<char*> x;
	/*x[0] = new char[strlen("aa") + 1];
	strcpy_s(x[0], strlen("aa") + 1, "aa");
	x[1] = new char[strlen("bb") + 1];
	strcpy_s(x[1], strlen("bb") + 1, "bb");*/
	Phone c("ion", "CJ23AAA", 7, x);
	assert(strcmp(c.getProducerName(), "ion") == 0);
	assert(strcmp(c.getModelName(), "CJ23AAA") == 0);
	assert(c.getNrOfProducts() == 7);
	//assert(c.getOperatorsGSM() == x);
	Phone c1;
	vector<char*> z;
	assert(c1.getProducerName() == NULL);
	assert(c1.getModelName() == NULL);
	assert(c1.getNrOfProducts() == 0);
	assert(c1.getOperatorsGSM() == z);
	Phone c2(c);
	assert(strcmp(c2.getProducerName(), "ion") == 0);
	assert(strcmp(c2.getModelName(), "CJ23AAA") == 0);
	assert(c2.getNrOfProducts() == 7);
	assert(c2.getOperatorsGSM() == x);
	c.setProducerName("ana");
	assert(strcmp(c.getProducerName(), "ana") == 0);
	c.setModelName("CJ44BBB");
	assert(strcmp(c.getModelName(), "CJ44BBB") == 0);
	c.setNrOfProducts(6);
	assert(c.getNrOfProducts() == 6);
	vector<char*> y;
	/*y[0] = new char[strlen("aa") + 1];
	strcpy_s(y[0], strlen("aa") + 1, "aa");
	y[1] = new char[strlen("cc") + 1];
	strcpy_s(y[1], strlen("cc") + 1, "c");*/
	//c.setOperatorsGSM(y);
	//assert(c.getOperatorsGSM() == y);
	Phone c3("ana", "CJ44BBB", 6, y);
	assert(c == c3);
}

void testDrone() {
	Drone c("ion", "CJ23AAA", 7, 2);
	assert(strcmp(c.getProducerName(), "ion") == 0);
	assert(strcmp(c.getModelName(), "CJ23AAA") == 0);
	assert(c.getNrOfProducts() == 7);
	assert(c.getRotorsNr() == 2);
	Drone c1;
	assert(c1.getProducerName() == NULL);
	assert(c1.getModelName() == NULL);
	assert(c1.getNrOfProducts() == 0);
	assert(c1.getRotorsNr() == 0);
	Drone c2(c);
	assert(strcmp(c2.getProducerName(), "ion") == 0);
	assert(strcmp(c2.getModelName(), "CJ23AAA") == 0);
	assert(c2.getNrOfProducts() == 7);
	assert(c2.getRotorsNr() == 2);
	c.setProducerName("ana");
	assert(strcmp(c.getProducerName(), "ana") == 0);
	c.setModelName("CJ44BBB");
	assert(strcmp(c.getModelName(), "CJ44BBB") == 0);
	c.setNrOfProducts(6);
	assert(c.getNrOfProducts() == 6);
	c.setRotorsNr(8);
	assert(c.getRotorsNr() == 8);
	Drone c3("ana", "CJ44BBB", 6, 8);
	assert(c == c3);
}

void testRepoTemplate() {
	RepoTemplate<Serie> repo;
	Serie c("ion", "CJ23AAA", 5);
	Serie c1("ana", "CJ44BBB", 4);
	Serie c2("maria", "CJ42BCB", 3);
	Serie c3("ioana", "B47HHH", 2);
	Serie cars[] = { c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Serie> l = repo.getAll();
	assert(repo.getSize() == 4);
	assert(l.front() == c);
	assert(l.back() == c3);
	int i = 0;
	for (list<Serie>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == cars[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 3);
	assert(repo.findElem(c2) == false);
	Serie c4("dana", "CJ11LLL", 6);
	repo.updateElem(c1, c4);
	assert(repo.findElem(c1) == false);
	assert(repo.getItemFromPos(1) == c4);
}

void testRepoFile() {
	RepoFile<Serie> repo("test.txt");
	Serie c("ion", "CJ23AAA", 5);
	Serie c1("ana", "CJ44BBB", 4);
	Serie c2("maria", "CJ42BCB", 3);
	Serie c3("ioana", "B47HHH", 2);
	Serie c4("Ion", "B44CCC", 10);
	Serie c5("Ana", "CJ65AAA", 9);
	Serie cars[] = { c4,c5, c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Serie> l = repo.getAll();
	assert(repo.getSize() == 6);
	int i = 0;
	for (list<Serie>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == cars[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 5);
	assert(repo.findElem(c2) == false);
	Serie c6("dana", "CJ11LLL", 7);
	repo.updateElem(c1, c6);
	assert(repo.findElem(c1) == false);
	assert(repo.getItemFromPos(3) == c6);
	repo.addElem(c1);
	repo.saveToFile();
	repo.loadFromFile("test.txt");
	assert(repo.getSize() == 6);
	assert(repo.getItemFromPos(5) == c1);
}
