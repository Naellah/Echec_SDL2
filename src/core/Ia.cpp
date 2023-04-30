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
    vector <Coup> coups1;
    int val;
    // parcours du plateau
    for (int i = 0; i < config.getPlateau().size(); i++) {
        for (int j = 0; j < config.getPlateau()[i].size(); j++) {
            // si la case n'est pas vide
            if (config.getPlateau()[i][j].getType() != VIDE && config.getPlateau()[i][j].getCouleur() == config.getJoueurCourant()) {
                // parcours des coups possibles
                coups = config.coupsPossibles(Vec2(i,j));
                
                //profondeur 2
                for (int k = 0; k < coups.size(); k++) {
                    // on joue le coup
                    config.deplacePieceTest(coups[k]);
                    val = valeurPlateau(config);
                    cout << "valeur2 : " << val << endl;
                    // on ajoute la valeur du plateau a l'arbre
                    ajouterConfig(val,coups[k]);
                    // pointeur vers le noeud fils
                    Noeud* fils1 = arbre.getFilsVec()[k];

                    cout << "fils1 : " << fils1->getValeur() << endl;
                    //profondeur 3
                    config.setJoueurCourant();
                    for (int l = 0; l < config.getPlateau().size(); l++) {
                        for (int m = 0; m < config.getPlateau()[l].size(); m++) {
                            // si la case n'est pas vide
                            if (config.getPlateau()[l][m].getType() != VIDE && config.getPlateau()[l][m].getCouleur() == config.getJoueurCourant()) {
                                // parcours des coups possibles
                                
                                coups1 = config.coupsPossibles(Vec2(l,m));
                                
                                for (int n = 0; n < coups1.size(); n++) {
                                    // on joue le coup
                                    config.deplacePieceTest(coups1[n]);
                                    config.setJoueurCourant();
                                    val = valeurPlateau(config);
                                    config.setJoueurCourant();
                                    cout << "valeur3 : " << val << endl;
                                    // on ajoute la valeur du plateau a l'arbre
                                    fils1->ajouterFils(val,coups1[n]);

                                    config.annulerCoup();
                                    // pointeur vers le noeud fils
                                    //Noeud* fils2 = fils->getFilsVec()[n];

                                }
                                coups1.clear();
                            }
                        }
                    }
                    config.annulerCoup();
                    config.setJoueurCourant();
                }
                coups.clear();   
            }
        }
    }
    cout << "atteint" << endl;
    // on parcours le vecteur de fils de chaque fils de l'arbre et on prend le minimum et ensuite on prend le maximum de ces minimums
    Noeud* max = arbre.getFilsVec()[0];
   for (int i = 0; i < arbre.getFilsVec().size(); i++) {
        if (!arbre.getFilsVec().empty() && !arbre.getFilsVec()[i]->getFilsVec().empty()) {
            Noeud* min = arbre.getFilsVec()[i]->getFilsVec()[0];
            for (int j = 0; j < arbre.getFilsVec()[i]->getFilsVec().size(); j++) {
                if (arbre.getFilsVec()[i]->getFilsVec()[j]->getValeur() < min->getValeur()) {
                    min = arbre.getFilsVec()[i]->getFilsVec()[j];
                }
            }
            if (min->getValeur() > max->getValeur()) {
                max = min;
            }
        }
    }   

    // on retourne la valeur du meilleur coup
    cout << "valeur max : " << max->getValeur() << endl;
    return max->getCoup();


}
    
