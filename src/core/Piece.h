#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>

#include "Vec2.h"


using namespace std;



// Couleur de la piece
enum Couleur {VIDEC, BLANC, NOIR};

// Type de la piece
enum TypePiece {
    VIDE=-1,
    PION1=0,PION2=1,PION3=2,PION4=3,PION5=4,PION6=5,PION7=6,PION8=7,
    TOUR1=8,TOUR2=9,
    CAVALIER1=10,CAVALIER2=11,
    FOU1=12,FOU2=13,
    DAME=14,
    ROI=15
};

Couleur aleatoireCouleur();



//opearateur de flux d'entre pour la couleur
ifstream& operator>>(ifstream& is, Couleur& couleur);




class Piece{
    private:
        Couleur couleur;
        TypePiece type;
        Vec2 position;
        bool est_vivante;

    public:
        
        //constructeur par défaut
        Piece();

        //constructeur prenant des arguments
        Piece(Couleur coul,TypePiece typ,Vec2 pos);

        //destructeur
        ~Piece();

       //operateur de comparaison
        bool operator==(const Piece& other)const;
       
        //operateur d'affectation
        Piece& operator=(const Piece& other);

        

        //mutateur deplacement
        void deplacement(Vec2 coor);

       

        //retourne vrai si la piece est vivante
        bool vivant()const;

        //retourne vrai si le coup est valide
        //bool coupValide(/*Comprend un Config Jeu*/)const;

        
        //retourne la position de la piece
        const Vec2 & getPosition()const;

        //retourne la couleur de la piece
        const Couleur& getCouleur()const;

        //retourne le type de la piece
        const TypePiece& getType()const;

        const TypePiece getPiecenum (const std :: string &choix)const;


        //deviens une piece vide
        void devientVide();
        
        //mutateurs couleurs
        void setCouleur(Couleur coul);

        //mutateurs type
        void setType(TypePiece typ);

        //mutateurs position
        void setPosition(Vec2 pos);

        // retourne vrai si la piece est vide
        bool pieceVide()const;

        //test de regression d'une piece
        void testRegressionPiece()const;

        
};




#endif