#include "Humain.h"
#include <iostream>

Humain::Humain(const string nom, const string boissonFavorite):nom(nom),boissonFavorite(boissonFavorite)
{

}

string Humain::getBoissonFavorite()
{
	return boissonFavorite;
}

void Humain::setBoissonFavorite(const string _boissonFavorite)
{
	boissonFavorite = _boissonFavorite;
}

void Humain::parle(const string texte)
{
	cout << texte;
}

void Humain::boit()
{
	cout << "(" << nom << ") -- " << "Ah un bon verre de " << boissonFavorite << " ! GLOUPS !" << endl;
}

Dame::Dame(const string nom, const string boissonFaverite, const string couleurRobe)
	:Humain(nom,boissonFaverite),couleurRobe(couleurRobe),etat("libre")
{
	
}

string Dame::getNom() const
{
	return "Miss "+nom;
}

string Dame::getEtat() const
{
	return etat;
}

void Dame::sePresente() const
{
	cout << "(" << nom << ") -- " << "Bonjour, je suis " << getNom() << " et j'ai une jolie robe " << couleurRobe << endl;
}

void Dame::changeDeRobe(const string _couleurRobe)
{
	this -> couleurRobe = _couleurRobe;
	cout << "(" << nom << ") -- " << "Regardez ma nouvelle robe " << couleurRobe << " !" << endl;
}

Cowboy::Cowboy(const string nom, const string boissonFavorite, const string qualite, const int _popularite):Humain(nom, boissonFavorite),qualite(qualite),popularite(_popularite)
{
}

void Cowboy::sePresente() const
{
	cout << "(" << nom << ") -- " << "Bonjour, je suis le " << getQualite() <<" "<< getNom() << " et j'aime le " << boissonFavorite << endl;
}

string Cowboy::getNom() const
{
	return nom;
}

string Cowboy::getQualite() const
{
	return qualite;
}

void Brigand::kidnappe(Dame& dame)
{
	dame.seFaitKidnapper();
	nbDamesEnlevees++;
	augmenteRecompense();
	cout << "(" << nom << ") -- " << "Ah ah ! " << dame.getNom() << " , tu es mienne desormais ! " << endl;
}
