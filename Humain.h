#pragma once
#include <string>
using namespace std;

class Humain
{
public:
	Humain(const string nom = "", const string boissonFavorite = "eau");

protected:
	string nom;
	string boissonravorite;
};
	// La classe Dame hérite de la classe Humain
class Dame : public Humain
{
public:
	Dame(const string nom = "", const string
		boissonFaverite = "lait", const string
		couleurRobe = "blanche");
	string getNom() const;
	string getEtat() const;
	void sePresente() const;
	void changeDeRobe(const string couleurRobe);

private:
	string couleurRobe;
	string etat;

};


