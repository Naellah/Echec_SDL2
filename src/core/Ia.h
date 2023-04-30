#ifndef IA_H
#define IA_H

#include "Vec2.h"
#include "Piece.h"
#include "Joueur.h"
#include "ConfigJeu.h"
#include "Noeud.h"

#include <iostream>

using namespace std;


class Ia {
    
    private:
       
    /**
     * @brief Arbre de recherche
     */
     Noeud arbre;
    
    public:

    /**
     * @brief constructeur par defaut
     */
    Ia();

    /**
     * @brief destructeur par defaut
     */
    ~Ia();

    /**
     * @brief fonction qui permet de calculer la valeur d'une piece
     * @param piece : est une piece
     * @return un entier qui designe la valeur de la piece
     */
    int valeurPiece(Piece piece);

    /**
     * @brief fonction qui permet de calculer la valeur du plateau
     * @param Configjeu : est une configuration du jeu
     * @return un entier qui designe la valeur du plateau
     */
     
    int valeurPlateau(ConfigJeu config);

    
     /**
      * @brief fonction qui permet d'ajouter la valeur du plateau a l'arbre et le coup associe
      * @param valeur : est un entier qui designe la valeur du plateau
      * @param coup : est un coup
      */
    void ajouterConfig(int valeur, Coup coup);

    /**
     * @brief fonction qui permet de calculer le meilleur coup
     * @param config : est une configuration du jeu
     * @return un entier qui designe la valeur du meilleur coup
     */
    Coup minmax(ConfigJeu & config);


};

#endif