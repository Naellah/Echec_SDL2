#include "Vec2.h"
#include "Piece.h"
#include "Joueur.h"
#include "ConfigJeu.h"
#include "Noeud.h"
#include "Ia.h"


#include <iostream>

using namespace std;

Ia :: Ia() {}

Ia :: ~Ia() {
}

int Ia :: valeurPiece(Piece piece) {
   //switch avec les types
    switch (piece.getType()) {
        case PION1:
        case PION2:
        case PION3:
        case PION4:
        case PION5:
        case PION6:
        case PION7:
        case PION8:
            return 1;
        

        case CAVALIER1:
        case CAVALIER2:
            return 3;

        case FOU1:
        case FOU2:
            return 3;

        case TOUR1:
        case TOUR2:
            return 5;

        case DAME:
            return 9;

        case ROI:
            return 100;

        default:
            return 0;
    }
}

int Ia :: valeurPlateau(ConfigJeu config) {
    //parcours le plateau et ajoute les valeurs des pieces*10 + le nombre de deplacement possible si joueur courant sinon - les valeurs des pieces*10 - le nombre de deplacement possible
    int valeur = 0;
    for (int i = 0; i < config.getPlateau().size(); i++) {
        for (int j = 0; j < config.getPlateau()[i].size(); j++) {
            if (config.getPlateau()[i][j].getType() != VIDE) {
                if (config.getJoueurCourant() == config.getPlateau()[i][j].getCouleur()) {
                    valeur = valeur + (valeurPiece(config.getPlateau()[i][j]) * 10) + static_cast<int>(config.coupsPossibles(Vec2(i,j)).size());

                } else {
                    config.setJoueurCourant();
                    valeur = valeur - (valeurPiece(config.getPlateau()[i][j]) * 10) - static_cast<int>(config.coupsPossibles(Vec2(i,j)).size());
                    config.setJoueurCourant();
                }
            }
        }
    }
    cout << "valeur1 : " << valeur << endl;
    return valeur;

}


void Ia :: ajouterConfig(int valeur, Coup coup) {
    //ajoute la valeur du plateau a l'arbre
    arbre.ajouterFils(valeur, coup);
    
}

Coup Ia :: minmax(ConfigJeu & config){
    
    arbre.supprimeArbre();
    arbre.setValeur(valeurPlateau(config));
    vector <Coup> coups;
    int val;
    // parcours du plateau
    for (int i = 0; i < config.getPlateau().size(); i++) {
        for (int j = 0; j < config.getPlateau()[i].size(); j++) {
            // si la case n'est pas vide
            if (config.getPlateau()[i][j].getType() != VIDE) {
                // parcours des coups possibles
                coups = config.coupsPossibles(Vec2(i,j));
                for (int k = 0; k < coups.size(); k++) {
                    // on joue le coup
                    config.deplacePieceTest(coups[k]);
                    val = valeurPlateau(config);
                    cout << "valeur2 : " << val << endl;
                     // on ajoute la valeur du plateau a l'arbre
                     ajouterConfig(val,coups[k]);
                     // on annule le coup
                    config.annulerCoup();
                }
                coups.clear();   
            }
        }
    }
    // on parcours le vecteur de fils de l'arbre et on prend le max
    Noeud* max = arbre.getFilsVec()[0];
    for (int i = 1; i < arbre.getFilsVec().size(); i++) {
        if (arbre.getFilsVec()[i]->getValeur() > max->getValeur()) {
            max = arbre.getFilsVec()[i];
           
        }
         //cout << "valeur : " << arbre.getFilsVec()[i]->getValeur() << endl;
    }
    // on retourne la valeur du meilleur coup
    cout << "valeur max : " << max->getValeur() << endl;
    return max->getCoup();


}
    
