#include <iostream>
#include "Humain.h"
using namespace std;

void presentezVous(Humain& humain) {
	humain.sePresente();
}

int main()
{
	Dame jenny("jenny");
	Cowboy lucky("Lucky Luke", "Coca-Cola");
	Brigand joe("Joe");
	Barman robert("Robert", "biere", "Saloon Robert");
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
	// test arme
	Arme* arme1 = new Arme("Smith and Wesson", 100, 5, 5);
	lucky.setArme(arme1);
	Arme* arme2 = new Arme("Revolver", 50, 6, 6);
	joe.setArme(arme2);
	lucky.parle("Au nom de la loi je vous arrete !");
	joe.parle("Non je ne me laissrai pas faire");
	joe.tire(lucky);
	joe.AffArmeCara(arme2);
	joe.parle("Je recharge");
	arme2->recharge(1);
	joe.AffArmeCara(arme2);
	lucky.tire(joe);
	lucky.AffArmeCara(arme1);
	lucky.emprisonne(joe);
	cout <<"("<< lucky.getNom()<< ") -- " << "J'ai " << lucky.getPopularite() << "point(s) de popularite !" << endl;
}
