#include <string.h>
#include "Entitate.h"

//Desc: create an entity
//In: -
//Out: an instance of Entitate
Entitate::Entitate()
{
	this->ziua = 0;
	this->suma = 0;
	this->tip = NULL;
}

//Desc: create an entity
//In: a day, a sum and a type
//Out: an instance (with info) of Entitate
Entitate::Entitate(int day, int sum, char* type)
{
	this->ziua = day;
	this->suma = sum;
	this->tip = new char[strlen(type) + 1];
	strcpy_s(this->tip, strlen(type) + 1, type);
}

//Desc: create an entity using info from another entity
//In: an entity e
//Out: an instance of Entitate with info from e
Entitate::Entitate(const Entitate &e)
{
	this->ziua = e.ziua;
	this->suma = e.suma;
	this->tip = new char[strlen(e.tip) + 1];
	strcpy_s(this->tip, strlen(e.tip) + 1, e.tip);
}

//Desc: destroy a entity
//In: an entity
//Out: -
Entitate::~Entitate()
{
	if (this->tip != NULL)
	{
		delete[] this->tip;
		this->tip = NULL;
	}
}

//Desc: access the day of an entity
//In: an entity
//Out: the day
int Entitate::getZiua()
{
	return this->ziua;
}

//Desc: access the sum of an entity
//In: an entity
//Out: the sum
int Entitate::getSuma()
{
	return this->suma;
}

//Desc: acces the type of an entity
//In: an entity
//Out: the type
char* Entitate::getTip()
{
	return this->tip;
}

//Desc: change the day of an entity
//In: an entity and a day
//Out: the entity with changed day
void Entitate::setZiua(int day)
{
	this->ziua = day;
}

//Desc: change the sum of an entity
//In: an entity and a sum
//Out: the entity with changed sum
void Entitate::setSuma(int sum)
{
	this->suma = sum;
}

//Desc: change the type of an entity
//In: an entity and a type
//Out: the entity with changed type
void Entitate::setTip(char* type)
{
	if (this->tip)
		delete[] this->tip;
	this->tip = new char[strlen(type) + 1];
	strcpy_s(this->tip, strlen(type) + 1, type);
}

//Desc: convert an entity to a string
//In: an entity
//Out: a string with info about the entity
char* Entitate::toString()
{
	if (this->tip != NULL)
	{
		int noChars = strlen(this->tip) + 1 + 3 + 5 + 3;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[3];
		_itoa_s(this->ziua, aux2, 3, 10);
		strcpy_s(s, noChars, aux2);
		strcat_s(s, noChars, ":");
		strcat_s(s, noChars, this->tip);
		strcat_s(s, noChars, "-");
		_itoa_s(this->suma, aux, 5, 10);
		strcat_s(s, noChars, aux);
		if (aux2)
		{
			delete[] aux2;
			aux2 = NULL;
		}
		if (aux)
		{
			delete[] aux;
			aux = NULL;
		}
		return s;
	}
	else
	{
		char* s = new char[1];
		return s;
	}
}

//Desc: campare 2 entities (the current one and a new one)
//In: 2 entities
//Out: true -if the entities are "equal"
//     false -if the entities are different
bool Entitate::operator==(const Entitate &e)
{
	return ((strcmp(this -> tip, e.tip) == 0) && (this->ziua == e.ziua) && (this->suma == e.suma));
}

//Desc: assignment operator
//In: 2 entities
//Out: the new state of the current object (this)
Entitate& Entitate::operator=(const Entitate &t)
{
	this->setZiua(t.ziua);
	this->setTip(t.tip);
	this->setSuma(t.suma);
	return *this;
}

//Desc: print an entity
//In: an entity
//Out: -
void Entitate::afisare()
{
	cout << this->ziua << ": " << this->tip << '-' << this->suma << ';' << endl;
}