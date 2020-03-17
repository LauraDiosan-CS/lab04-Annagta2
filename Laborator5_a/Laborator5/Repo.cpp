#include "Repo.h" 

Repo::Repo() 
{
	this->noEntities = 0;
}

Repo::~Repo()
{
}

void Repo::addItem(Entitate &e) 
{
	this->entities[this->noEntities++] = e;
}

Entitate Repo::getItemFromPos(int pos) 
{
	return this->entities[pos]; 
}

int Repo::getSize() 
{
	return this->noEntities; 
}