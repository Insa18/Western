#include <iostream>
#include "Humain.h"
using namespace std;

int main()
{
	Dame jenny("jenny");
	Cowboy lucky("Lucky Luke");
	lucky.sePresente();
	jenny.sePresente();
	jenny.changeDeRobe("verte");
	jenny.boit();
	lucky.boit();
}
