#include <iostream>
#include "Humain.h"
using namespace std;

void presentezVous(Humain& humain) {
	humain.sePresente();
}

int main()
{
	Dame jenny("jenny");
	Cowboy lucky("Lucky Luke","Coca-Cola");
	Brigand joe("Joe");
	Barman robert("Robert","biere","Saloon Robert");
	Sherif clint("Clint", "eau");
	//histoire 1
	cout << "Histoire 1" << endl;
	presentezVous(lucky);
	presentezVous(jenny);
	presentezVous(joe);
	presentezVous(robert);
	robert.sert(lucky);
	robert.sert(jenny);
	robert.sert(joe);
	//histoire 2
	cout << "Histoire 2" << endl;
	presentezVous(lucky);
	jenny.sePresente();
	joe.sePresente();
	joe.kidnappe(jenny);//pour augmenter la prime de joe à 100$
	presentezVous(robert);
	presentezVous(clint);
	clint.avisRecherche(joe);
	clint.cofferBrigand(joe);
}
