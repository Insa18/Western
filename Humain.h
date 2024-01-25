#pragma once
#include <string>
using namespace std;

/*#####################class Humain#####################*/

class Humain
{
protected:
	string nom;
	string boissonFavorite;
public:
	Humain(const string nom = "", const string boissonFavorite = "eau");
	string getBoissonFavorite();
	void setBoissonFavorite(const string _boissonFavorite);
	void parle(const string texte);
	void boit();
};

/*#####################class Dame#####################*/

class Dame : public Humain
{
private:
	string couleurRobe;
	string etat;
	void hurle();
	void remercie(const Cowboy& heros);
public:
	Dame(const string nom = "", const string
		boissonFaverite = "lait", const string
		couleurRobe = "blanche");
	string getNom() const;
	string getEtat() const;
	void sePresente() const;
	void changeDeRobe(const string couleurRobe);
	void seFaitKidnapper();
	void seFaitLiberer(Cowboy& cowboy);
	void changeDeRobe(const string couleurRobe);
};

/*#####################class Cowboy#####################*/

class Cowboy : public Humain
{
private:
	const int popularite = 0;
	const string qualite;
public:
	Cowboy(const string nom = "", const string boissonFavorite = "whisky", const string qualite = "vaillant", const int popularite = 0);
	void sePresente() const;
	string getNom() const;
	string getQualite() const;
	int getPopularite();
	void setPopularite(const int _popularite);
	void setQualite(const string _qualite);
	void incrementePopularite();
	void decrementePopularite();
	void tire(const Brigand& brigand);
	void emprisonne(Brigand& brigand);
	void libere(Dame& dame);
};

/*#####################class Brigand#####################*/

class Brigand : public Humain
{
private:
	string comportement;
	int nbDamesEnlevees, recompense;
	bool enPrison;
public:
	Brigand(const string nom = "", const string boissonFavorite = "tord-boyaux", const string comportement = "mechant");
	string getComportement();
	int getNbDamesEnlevees();
	int getRecompense();
	void sePresente();
	void kidnappe(Dame& dame);
	void seFaitEmprisonner(const int prix = 100);
	void diminueRecompense(const int prix = 100);
	bool estEnPrison();
	void augmenteRecompense();
};