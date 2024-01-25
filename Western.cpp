#include <iostream>
#include "Humain.h"
using namespace std;

int main()
{
	Dame jenny("jenny");
	Cowboy lucky("Lucky Luke","Coca-Cola");
	Brigand joe("Joe");
	lucky.sePresente();
	jenny.sePresente();
	joe.sePresente();
	joe.kidnappe(jenny);
	lucky.sePresente();
	joe.sePresente();
	joe.affNbDammesEnlevees();
	joe.affPrime();
	lucky.tire(joe);
	lucky.emprisonne(joe);
	lucky.libere(jenny);
}
