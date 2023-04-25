#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>

#include "Vec2.h"

using namespace std;

//Couleur de la piece
enum Couleur { VIDEC, BLANC, NOIR };

//Type de la piece
enum TypePiece {
    VIDE = -1,
    PION1 = 0, PION2 = 1, PION3 = 2, PION4 = 3, PION5 = 4, PION6 = 5, PION7 = 6, PION8 = 7,
    TOUR1 = 8, TOUR2 = 9,
    CAVALIER1 = 10, CAVALIER2 = 11,
    FOU1 = 12, FOU2 = 13,
    DAME = 14,
    ROI = 15
};

/**
* @brief choisi une couleur aleatoirement entre Noir et Blanc
*/
Couleur aleatoireCouleur();

/**
* @brief opearateur de flux d'entre pour la couleur
*/
ifstream& operator>>(ifstream& is, Couleur& couleur);

class Piece {
private:

    /**
    * @brief est la couleur de la piece
    */
    Couleur couleur;

    /**
    * @brief est le type de la piece
    */
    TypePiece type;

    /**
    * @brief est la position de la piece
    */
    Vec2 position;

    /**
    * @brief designe si la piece est vivante ou non
    */
    bool est_vivante;

public:
    /**
    * @brief constructeur par défaut
    */
    Piece();
    /**
    * @brief constructeur prenant des arguments
      @param coul : correspond a la coordonnee couleur
      @param typ : correspond au type
      @param pos : correspond a la position
    */
    Piece(Couleur coul, TypePiece typ, Vec2 pos);

    /**
    * @brief destructeur
    */
    ~Piece();

    /**
    * @brief operateur de comparaison
      @param other : correspond a une piece
    */
    bool operator==(const Piece& other)const;

    /**
    * @brief operateur d'affectation
      @param other : correspond a une piece
    */
    Piece& operator=(const Piece& other);

    /**
    * @brief mutateur deplacement qui change la position du vecteur
      @param coor : correspond a un vecteur
    */
    void deplacement(Vec2 coor);

    /**
    * @brief retourne vrai si la piece est vivante
    */
    bool vivant()const;

    //retourne vrai si le coup est valide
    //bool coupValide(/*Comprend un Config Jeu*/)const;

    /**
    * @brief retourne la position de la piece
    */
    const Vec2& getPosition()const;

    /**
    * @brief retourne la couleur de la piece
    */
    const Couleur getCouleur()const;

    /**
    * @brief retourne le type de la piece
    */
    const TypePiece getType()const;

    /**
    * @brief retourne le numero de la piece corespondant a sont type dans le enum
      @param choix : correspond a une chaine de caractere du type
    */
    const TypePiece getPiecenum(const std::string& choix)const;

    /**
    * @brief deviens une piece vide
    */
    void devientVide();

    /**
    * @brief mutateurs couleurs
      @param coul : correspond a la nouvelle couleur de la piece
    */
    void setCouleur(Couleur coul);

    /**
    * @brief mutateurs type
      @param coul : correspond au nouveau type de la piece
    */
    void setType(TypePiece typ);

    /**
    * @brief mutateurs position
      @param coul : correspond a la nouvelle position de la piece
    */
    void setPosition(Vec2 pos);

    /**
    * @brief retourne vrai si la piece est vide
    */
    bool pieceVide()const;

    /**
    * @brief test de regression d'une piece
    */
    void testRegressionPiece()const;

    /**
    * @brief change les valeur de la piece si celle-ci est mange
    */
    void estmangee();


};




#endif