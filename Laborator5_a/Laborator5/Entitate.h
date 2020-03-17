#pragma once

#include <stdlib.h>
#include <iostream>
using namespace std;

class Entitate
{
	private:
		int ziua;
		int suma;
		char* tip;
	public:
		Entitate();
		Entitate(int day, int sum, char* type);
		Entitate(const Entitate &e);
		~Entitate();
		int getZiua();
		int getSuma();
		char* getTip();
		void setZiua(int day);
		void setSuma(int sum);
		void setTip(char* type);
		char* toString();
		bool operator==(const Entitate &e);
		Entitate& operator=(const Entitate &t);
		void afisare();
};