#pragma once
#include <string>
using namespace std;
class Brigand;
class Dame;
class Cowboy;
/*#####################class Humain#####################*/

class Humain
{
protected:
	string nom;
	string boissonFavorite;
public:
	Humain(const string nom = "", const string boissonFavorite = "eau");
	~Humain();
	string getBoissonFavorite() const;
	void setBoissonFavorite(const string _boissonFavorite);
	void parle(const string texte);
	void boit();
	virtual void sePresente();
	string getNom();
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
};

/*#####################class Cowboy#####################*/
class Arme;
class Cowboy : public Humain
{
private:
	int popularite = 0;
	string qualite;
	Arme* arme;
public:
	Cowboy(const string nom = "", const string boissonFavorite = "whisky", const string qualite = "vaillant", const int popularite = 0);
	~Cowboy();
	void sePresente() const;
	string getNom() const;
	string getQualite() const;
	int getPopularite();
	void setPopularite(const int _popularite);
	void setQualite(const string _qualite);
	void incrementePopularite();
	void decrementePopularite();
	void emprisonne(Brigand& brigand);
	void libere(Dame& dame);
	void setArme(Arme* arme);
	void tire(const Brigand& brigand) const;
	void AffArmeCara(Arme* arme);
};

/*#####################class Brigand#####################*/
class Arme;
class Brigand : public Humain
{
private:
	string comportement;
	int nbDamesEnlevees, recompense;
	bool enPrison;
	Arme* arme;
public:
	Brigand(const string nom = "", const string boissonFavorite = "tord-boyaux", const string comportement = "mechant");
	~Brigand();
	string getComportement() const;
	int getNbDamesEnlevees() const;
	int getRecompense() const;
	void affPrime();
	void affNbDammesEnlevees();
	void sePresente() const;
	void kidnappe(Dame& dame);
	void seFaitEmprisonner(Cowboy& cowboy);
	void augmenteRecompense(const int prix = 100);
	void diminueRecompense(const int prix = 100);
	bool estEnPrison() const;
	string getNom() const;
	int getPrimes();
	void setArme(Arme* arme);
	void tire(const Cowboy& heros) const;
	void AffArmeCara(Arme* arme);
};

/*#####################class Barman#####################*/

class Barman : public Humain
{
private:
	string nomBar;
	string terminePhrase() const;
public:
	Barman(const string nom = "", const string boissonFavorite = "biere", const string nomBar = "");
	string getNomBar();
	void parle(const string texte);
	void sePresente() override;
	void sert(Humain& client);
};

/*#####################class Sherif#####################*/

class Sherif : public Cowboy
{
private:
	int nbBrigandsCoffres=0;
public:
	Sherif(const string nom = "", const string boissonFavorite = "", int nbBrigandsCoffres=0,string qualite = "honnete",int popularite=0);
	void cofferBrigand(Brigand& brigand);
	void avisRecherche(Brigand& brigand);
	void sePresente();
};

/*#####################class Arme#####################*/

class Arme
{
private:
	string nom;
	int capacite, nbBalles, prix;
public:
	Arme(const string nom = "", int prix = 100, int capacite = 6, int nbBalles = 0);
	string getNom();
	int getPrix();
	int getNbBalles();
	void tire();
	void recharge(int nbBalles);
};