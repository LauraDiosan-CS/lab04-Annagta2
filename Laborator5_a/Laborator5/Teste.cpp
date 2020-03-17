#include "Teste.h" 
#include "Repo.h"
#include <cassert> 
#include <iostream>
using namespace std; 

void testsEntities() 
{
	Entitate e1 = Entitate();
	assert(e1.getZiua() == 0);
	assert(e1.getSuma() == 0);
	assert(e1.getTip() == NULL);


	Entitate e2 = Entitate();
	e2.setZiua(14);
	e2.setSuma(1230);
	assert(e2.getZiua() == 14);
	assert(e2.getSuma() == 1230);

}

void testsRepo()
{
	Repo r = Repo();
	assert(r.getSize() == 0);


	char* tip1 = new char[20];
	char* tip2 = new char[20];

	strcpy_s(tip1, sizeof "apa", "apa");
	strcpy_s(tip2, sizeof "gaz", "gaz");

	Entitate e1 = Entitate(5, 100, tip1);
	Entitate e2 = Entitate(2, 10, tip2);

	r.addItem(e1);
	assert(r.getSize() == 1);

	r.addItem(e2);
	assert(r.getSize() == 2);
}