#include "Humain.h"
#include <iostream>

Humain::Humain(const string nom, const string boissonFavorite)
{

}

Dame::Dame(const string nom, const string boissonFaverite, const string couleurRobe)
	:Humain(nom,boissonFaverite),couleurRobe(couleurRobe),etat("libre")
{
	
}

string Dame::getNom() const
{
	return nom;
}

string Dame::getEtat() const
{
	return etat;
}

void Dame::sePresente() const
{
	cout << "Bonjour, je suis Miss Jenny et j'ai une jolie robe blanche";
}

void Dame::changeDeRobe(const string _couleurRobe)
{
	couleurRobe = _couleurRobe;
}


