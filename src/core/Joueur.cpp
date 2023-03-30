#include "Piece.h"
#include "Joueur.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

Joueur::Joueur(){
    nom = "Inconnu";
    couleur = Couleur::VIDEC;
    nbpartiejouee = 0;
    win = 0;
    lose = 0;
    egalite = 0;
    ratio = 0.0;
}

Joueur::Joueur(string _nom, Couleur _couleur){
    nom = _nom;
    couleur = _couleur;
    nbpartiejouee = 0;
    win = 0;
    lose = 0;
    egalite = 0;
    ratio = 0.0;
}

Joueur :: Joueur(string _nom, unsigned int _nbpartiejouee, unsigned int _win, 
unsigned int _lose, unsigned int _egalite, double _ratio){
    nom = _nom;
    nbpartiejouee = _nbpartiejouee;
    win = _win;
    lose = _lose;
    egalite = _egalite;
    ratio = _ratio;
}

Joueur::~Joueur(){
    nom = "Inconnu";
    couleur = Couleur::VIDEC;
}

string Joueur::getNom()const{
    return nom;
}

Couleur Joueur::getCouleur()const{
    return couleur;
}

string Joueur::getCouleurString()const{
    string couleurString;
    switch(couleur){
        case Couleur::VIDEC:
            couleurString = "Vous n'avez pas de couleur";
            break;
        case Couleur::BLANC:
            couleurString = "Blanc";
            break;
        case Couleur::NOIR:
            couleurString = "Noir";
            break;
    }
    return couleurString;
}



unsigned int Joueur::getWin()const{
    return win;
}

unsigned int Joueur::getLose()const{
    return lose;
}

unsigned int Joueur::getEgalite()const{
    return egalite;
}

double Joueur::getRatio()const{
    return ratio;
}

unsigned int Joueur::getPartieJouee()const{
    return nbpartiejouee;
}

Chrono Joueur::getChrono()const {
	return chrono;
}

void Joueur::setNom(string _nom){
    nom = _nom;
}

void Joueur::setCouleur(Couleur _couleur){
    couleur = _couleur;
}

void Joueur::setWin(unsigned int _win){
    win = _win;
}

void Joueur::setLose(unsigned int _lose){
    lose = _lose;
}

void Joueur::setEgalite(unsigned int _egalite){
    egalite = _egalite;
}


void Joueur :: setRatio(){
    ratio = win / lose ;
}


void Joueur::setPartieJouee(unsigned int _nbpartiejouee){
    nbpartiejouee = _nbpartiejouee;
}

void Joueur :: incWin(){
    win++;
}

void Joueur :: incLose(){
    lose++;
}

void Joueur :: incEgalite(){
    egalite++;
}

void Joueur :: incPartieJouee(){
    nbpartiejouee++;
}


void Joueur::setChrono(Chrono _chrono) {
	chrono = _chrono;
}


void Joueur::sauvegarderJoueur()const{
    ofstream fichier("data/lstjoueur.txt", ios::out | ios::app);
    if(fichier){
        fichier << nom << endl ;
        fichier << nbpartiejouee << endl;
        fichier << win << endl;
        fichier << lose << endl;
        fichier << egalite << endl;
        
        fichier.close();
    }
    else{
        cerr << "Impossible de sauvegarder !" << endl;
    }
}


// a finir plus tard car a
void Joueur::chargerJoueur(){
    //afficher les joueurs puis permet de le chosir en rentrant un numéro associé et de le charger
    ifstream fichier("data/lstjoueur.txt", ios::in);
    string ligne;
    map<int,string> tableau ;
    int a =1;
    string b;
    
    while(getline(fichier,ligne)){

        tableau.insert(pair<int,string>(a,ligne));
        a+=5;
        //ignorer les 4 lignes en dessous
        for (int i =0 ; i<4 ; i++){
            getline(fichier,ligne);
        }
    }
    cout << "Veuillez bien choisir le joueur que vous voulez charger dans la liste des joueurs sauvegardes en entrant son numero correspondant"<< endl;
    //parcours de dictionnaire
    
    for (map <int,string> :: iterator it=tableau.begin(); it!=tableau.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    fichier.seekg(0, std::ios_base::beg);
    int choix;
    cin >> choix;
    string ligne_choix = tableau[choix];
    while (getline(fichier, ligne)) {
        if (ligne == ligne_choix) {
            // On a trouvé la ligne à supprimer, on passe à la suivante
            nom = ligne;
            getline(fichier, ligne);
            nbpartiejouee = stoi(ligne);
            getline(fichier, ligne);
            win = stoi(ligne);
            getline(fichier, ligne);
            lose= stoi(ligne);
            getline(fichier, ligne);
            ratio= stoi(ligne);
            break;
        }
    }
}
    





    

   
    
    




void Joueur :: supprimerJoueur(const std::string& nomJoueur) {
    ifstream fichierOriginal("data/lstjoueur.txt");
    ofstream fichierTemporaire("data/lstjoueur.tmp");

    string ligne;
    bool supprimerLigneSuivante = false;
    while (getline(fichierOriginal, ligne)) {
        if (supprimerLigneSuivante) {
            // On saute la ligne suivante car elle doit être supprimée
            supprimerLigneSuivante = false;
            continue;
        }

        if (ligne == nomJoueur) {
            // On a trouvé la ligne à supprimer, on passe à la suivante
            supprimerLigneSuivante = true;
            continue;
        }

        fichierTemporaire << ligne << endl << ligne << endl << ligne << endl << ligne << endl << ligne << endl;
    }

    // On ferme les fichiers
    fichierOriginal.close();
    fichierTemporaire.close();

    // On supprime le fichier original
    if (remove("data/lstjoueur.txt") != 0) {
        cerr << "Impossible de supprimer le fichier !" << endl;
        return;
    }

    // On renomme le fichier temporaire avec le nom du fichier original
    if (rename("data/lstjoueur.tmp", "data/lstjoueur.txt") != 0) {
        cerr << "Impossible de renommer le fichier temporaire !" << endl;
    }  
}


void Joueur :: testRegressionJoueur()const{
    Joueur j1("Joueur1", Couleur::BLANC);
    Joueur j2("Joueur2", Couleur::NOIR);
    assert(j1.getNom() == "Joueur1");
    assert(j1.getCouleur() == Couleur::BLANC);
    assert(j2.getNom() == "Joueur2");
    assert(j2.getCouleur() == Couleur::NOIR);
    j1.setNom("Joueur3");
    j1.setCouleur(Couleur::NOIR);
    j2.setNom("Joueur4");
    j2.setCouleur(Couleur::BLANC);
    assert(j1.getNom() == "Joueur3");
    assert(j1.getCouleur() == Couleur::NOIR);
    assert(j2.getNom() == "Joueur4");
    assert(j2.getCouleur() == Couleur::BLANC);
    j1.sauvegarderJoueur();
    j2.sauvegarderJoueur();
    j1.chargerJoueur();
    j2.chargerJoueur();
  
    cout << "Test de la classe Joueur OK !" << endl;

}