#include "Humain.h"
#include <iostream>

/*#####################class Humain#####################*/

Humain::Humain(const string nom, const string boissonFavorite):nom(nom),boissonFavorite(boissonFavorite)
{

}

Humain::~Humain()
{
}

string Humain::getBoissonFavorite() const
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

void Humain::sePresente()
{
	cout << "(" << nom << ") -- " << "Bonjour, je suis " << nom << " et j'aime le " << boissonFavorite << endl;
}

string Humain::getNom()
{
	return nom;
}


/*#####################class Dame#####################*/

void Dame::hurle()
{
	cout << "** " << getNom() << " hurle"<<endl;
}

void Dame::remercie(const Cowboy& heros)
{
	cout << "(" << nom << ") -- " << "Merci " << heros.getNom() << ", je suis enfin "<<etat<<" !" << endl;
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

void Dame::seFaitKidnapper()
{
	hurle();
	etat = "kidnapper";
	cout << "(" << nom << ") -- " << "Au secours, je me fais " << etat << " !"<<endl;
}

void Dame::seFaitLiberer(Cowboy& cowboy)
{
	etat = "libre";
	remercie(cowboy);
}


/*#####################class Cowboy#####################*/

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

int Cowboy::getPopularite()
{
	return popularite;
}

void Cowboy::setPopularite(const int _popularite)
{
	popularite = _popularite;
}

void Cowboy::setQualite(const string _qualite)
{
	qualite = _qualite;
}

void Cowboy::incrementePopularite()
{
	popularite++;
}

void Cowboy::decrementePopularite()
{
	if (popularite > 0) {
		popularite--;
	}
}

void Cowboy::tire(const Brigand& brigand)
{
	cout << "** Le " << qualite << " " << nom << " tire sur " << brigand.getNom() << " !" << endl;
	cout << "(" << nom << ") -- " << "Prends ca, rascal ! "<<endl;
}

void Cowboy::emprisonne(Brigand& brigand)
{
	brigand.seFaitEmprisonner(*this);
	incrementePopularite();
}

void Cowboy::libere(Dame& dame)
{
	dame.seFaitLiberer(*this);
}

/*#####################class Brigand#####################*/

Brigand::Brigand(const string nom, const string boissonFavorite, const string comportement) :Humain(nom, boissonFavorite), comportement(comportement),nbDamesEnlevees(0),recompense(0),enPrison(false)
{
}

string Brigand::getComportement() const
{
	return comportement;
}

int Brigand::getNbDamesEnlevees() const
{
	return nbDamesEnlevees;
}

int Brigand::getRecompense() const
{
	return recompense;
}

void Brigand::affPrime()
{
	cout << "(" << nom << ") -- " << "Ma tete est mise a prix, " << recompense << " $ !"<<endl;
}

void Brigand::affNbDammesEnlevees()
{
	cout << "(" << nom << ") -- " << "J'ai l'air " << comportement << " et j'ai deja kidnapper " << getNbDamesEnlevees() << " femme(s) ! " << endl;
}

void Brigand::sePresente() const 
{
	cout << "(" << nom << ") -- " << "Bonjour, je suis " << getNom() << " le " << getComportement() << " et j'aime le " << getBoissonFavorite() << "." << endl;
}

void Brigand::kidnappe(Dame& dame)
{
	if (!estEnPrison()) {
		dame.seFaitKidnapper();
		nbDamesEnlevees++;
		augmenteRecompense();
		cout << "(" << nom << ") -- " << "Ah ah ! " << dame.getNom() << " , tu es mienne desormais ! " << endl;
	}
}

void Brigand::seFaitEmprisonner(Cowboy& cowboy)
{
	if (!estEnPrison()) {
		enPrison = true;
		cout << "(" << nom << ") -- " << "Damned, je suis fait ! " << cowboy.getNom() << " tu m'as eu !" << endl;
	}
}

void Brigand::augmenteRecompense(const int prix)
{
	if (prix > 0) {
		this->recompense += prix;
	}
}

void Brigand::diminueRecompense(const int prix)
{
	if (prix > 0 && prix <= recompense) {
		this->recompense -= prix;
	}
}

bool Brigand::estEnPrison() const
{
	return enPrison;
}

string Brigand::getNom() const
{
	return nom;
}

int Brigand::getPrimes()
{
	return recompense;
}

/*#####################class Brigand#####################*/

string Barman::terminePhrase() const
{
	return " mon gars.\n";
}

Barman::Barman(const string nom, const string boissonFavorite, const string nomBar) :Humain(nom, boissonFavorite), nomBar(nomBar)
{
}

string Barman::getNomBar()
{
	return nomBar;
}

void Barman::parle(const string texte)
{
	cout << texte;
}

void Barman::sePresente()
{
	cout << "(" << nom << ") -- Bonjour, je suis " << getNom() << " le barman du " << getNomBar() << " et j'aime le " << getBoissonFavorite()<< terminePhrase();
}

void Barman::sert(Humain& client)
{
	cout << "(" << nom << ") -- " << "Tiens " << client.getNom() << ", un verre de " << client.getBoissonFavorite() << terminePhrase();
}

/*#####################class Sherif#####################*/

Sherif::Sherif(const string nom, const string boissonFavorite, int nbBrigandsCoffres, string qualite, int popularite) :Cowboy(nom, boissonFavorite, qualite, popularite)
{
}

void Sherif::cofferBrigand(Brigand& brigand)
{
	cout << "(" << nom << ") -- " << "Au nom de la loi, je vous arrete !" << endl;
	brigand.seFaitEmprisonner(*this);
	nbBrigandsCoffres++;
	incrementePopularite();
}

void Sherif::avisRecherche(Brigand& brigand)
{
	cout << "** OYEZ OYEZ BRAVE GENS !!! " << brigand.getRecompense() << "$ a qui arretera " << brigand.getNom() << " mort ou vif !" << endl;
}

void Sherif::sePresente()
{
	cout << "(" << nom << ") -- " << "Bonjour je suis Sherif " << nom << " j'aime l'/le " << boissonFavorite << " et j'ai arrete "<< nbBrigandsCoffres << " brigand(s) !" << endl;
}


