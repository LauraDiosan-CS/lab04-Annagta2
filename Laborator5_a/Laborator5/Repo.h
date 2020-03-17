#include "Entitate.h"
using namespace std;

class Repo
{
	private:
		Entitate entities[10];
		int noEntities;
	public:
		Repo();
		~Repo();
		void addItem(Entitate &e);
		Entitate getItemFromPos(int pos);
		int getSize();
};