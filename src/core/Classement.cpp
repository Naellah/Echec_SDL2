
#include <string>
#include <vector>

#include "Joueur.h"
#include "Piece.h"
#include "Classement.h"

using namespace std;

Classement::Classement(){
    nbjoueur = 0;
}

Classement::Classement(unsigned int _nbjoueur){
    nbjoueur = _nbjoueur;
    classement.reserve(nbjoueur);
}

Classement::~Classement(){
}

unsigned int Classement::getNbjoueur()const{
    return nbjoueur;
}

vector<Joueur> Classement::getClassement()const{
    return classement;
}

void Classement::setNbjoueur(unsigned int _nbjoueur){
    nbjoueur = _nbjoueur;
    classement.reserve(nbjoueur);
}

void Classement::setClassement(vector<Joueur> _classement){
    classement = _classement;
}

void Classement::ajouterJoueur(Joueur _joueur){
    classement.push_back(_joueur);
}

void Classement::supprimerJoueur(Joueur _joueur){
    for(unsigned int i = 0; i < classement.size(); i++){
        if(classement[i].getNom() == _joueur.getNom()){
            classement.erase(classement.begin() + i);
        }
    }
}

void Classement::afficherClassement(){
    for(unsigned int i = 0; i < classement.size(); i++){
        cout<<  i+1 << " : " << classement[i].getNom() << " "<< classement[i].getPartieJouee() << " " << 
        classement[i].getWin() << " " << classement[i].getLose() << " " << classement[i].getEgalite() << " " 
        << classement[i].getRatio() << endl;
    }

}

void Classement::sauvegarderClassement(){
    ofstream fichier("data/classement.txt", ios::out | ios::trunc);
    if(fichier){
        for(unsigned int i = 0; i < classement.size(); i++){
            fichier << classement[i].getNom() << " " << classement[i].getPartieJouee() << " " << 
            classement[i].getWin() << " " << classement[i].getLose() << " " << classement[i].getEgalite() << " " 
            << classement[i].getRatio() << endl;
        }
        fichier.close();
    }
    else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Classement::chargerClassement(){
    ifstream fichier("data/classement.txt", ios::in);
    if(fichier){
        string _nom;
        unsigned int _partieJouee;
        unsigned int _win;
        unsigned int _lose;
        unsigned int _egalite;
        float _ratio;
        while(fichier >> _nom >> _partieJouee >> _win >> _lose >> _egalite >> _ratio){
            Joueur joueur(_nom, _partieJouee, _win, _lose, _egalite, _ratio);
            classement.push_back(joueur);
        }
        fichier.close();
    }
    else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }

}

void Classement::trierClassement(){
    for(unsigned int i = 0; i < classement.size(); i++){
        for(unsigned int j = 0; j < classement.size(); j++){
            if(classement[i].getWin() > classement[j].getWin()){
                Joueur temp = classement[i];
                classement[i] = classement[j];
                classement[j] = temp;
            }
        }
    }
}


void Classement::testRegressionClassement()const{
    Classement c(4);
    assert(c.getNbjoueur() == 4);
    c.setNbjoueur(5);
    assert(c.getNbjoueur() == 5);
    Joueur joueur1("joueur1", 10, 5, 3, 2, 0.5);
    Joueur joueur2("joueur2", 10, 3, 5, 2, 0.3);
    Joueur joueur3("joueur3", 10, 2, 3, 5, 0.2);
    Joueur joueur4("joueur4", 10, 1, 2, 7, 0.1);
    Joueur joueur5("joueur5", 10, 4, 2, 4, 0.4);
    c.ajouterJoueur(joueur1);
    c.ajouterJoueur(joueur2);
    c.ajouterJoueur(joueur3);
    c.ajouterJoueur(joueur4);
    c.ajouterJoueur(joueur5);

    for (unsigned int i = 0; i < classement.size(); i++){
       assert(c.classement[i].getNom() == "joueur" + to_string(i+1));
    }
    c.supprimerJoueur(joueur1);
    assert(c.classement[0].getNom() == "joueur2");
    assert(c.classement[1].getNom() == "joueur3");
    assert(c.classement[2].getNom() == "joueur4");
    assert(c.classement[3].getNom() == "joueur5");

    c.trierClassement();
    assert(c.classement[0].getNom() == "joueur5");
    assert(c.classement[1].getNom() == "joueur2");
    assert(c.classement[2].getNom() == "joueur3");
    assert(c.classement[3].getNom() == "joueur4");

    Joueur joueur6("joueur6", 10, 5, 3, 2, 0.5);
    c.ajouterJoueur(joueur6);

    c.trierClassement();
    assert(c.classement[0].getNom() == "joueur6");
    assert(c.classement[1].getNom() == "joueur5");
    assert(c.classement[2].getNom() == "joueur2");
    assert(c.classement[3].getNom() == "joueur3");
    assert(c.classement[4].getNom() == "joueur4");

    c.sauvegarderClassement();
    
    Classement c2(0);
    c2.chargerClassement();

    cout << "Test de la classe Classement : OK" << endl;




}