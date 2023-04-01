#ifndef CONFIGJEU_H
#define CONFIGJEU_H

#include "Vec2.h"
#include "Piece.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;




struct Coup {
    Vec2 posi;
    Vec2 deplacement;
    
    // constructeur par défaut
    Coup() {}
    
    // constructeur
    Coup(Vec2 _pos, Vec2 _dep) {
        posi = _pos;
        deplacement = _dep;
    }
    
    // opérateur d'égalité
    bool operator==(const Coup& other) const {
        return posi == other.posi && deplacement == other.deplacement;
    }
};


class ConfigJeu{
    private:
        vector <Piece> piecesBlanches;
        vector <Piece> piecesNoires;
        vector<vector<Piece>> plateau;
        Couleur joueurCourant;

        unsigned int nbPiecesBlanches;
        unsigned int nbPiecesNoires;

    public:
        
        //constructeur par défaut
        ConfigJeu();

        //destructeur
        ~ConfigJeu();
        
        //init le jeu
        void initConfigJeu();

        //retourne vrai si le coup est valide (dans le plateau et pas de pièce de la même couleur)
        //bool coupValide(const Coup & c)const;

        //retourne un tableau de coups possibles
        vector <Coup> coupsPossibles(const Vec2& pos)const;

        void jouerCoup(const Coup & c);

        //void annulerCoup(const Coup & c);

        //assesseurs à partir de la position
        const Piece& getPiece(const Vec2& pos)const;

        //assesseurs du plateau
        const vector<vector<Piece>>& getPlateau()const;

        void deplacePiece(const Coup& c);

        //retourne la position finale de la piece avec le coup
        
        //assesseurs à partir de son identifiant
        //const Piece& getPiece(const IdPiece& id)const;

        //assesseurs du joueur courant
        const Couleur& getJoueurCourant()const;

        string JoueurCourant()const;

        //affiche le plateau en mettant en rouge les pieces noires et en bleu les pieces blanches et des étoiles pour les cases vides
        void afficherPlateauTxt()const;

        void afficherCoupsPossibles(const Vec2& pos)const;

        //mutateurs du joueur qui joue
        void setJoueurCourant();

        //recupere le vec2 coordonnees selon ses coordonnées lettre et chiffre
        Vec2 recuperePosition(const char& lettre, const char& chiffre)const;


        void estMangeConfig(Piece &p);


        bool EchecBlanc()const;

        bool EchecNoir()const;

        bool EchecEtMatBlanc()const;

        bool EchecEtMatNoir()const;



        /*retourne vrai si pour un coup donné, il n'y a pas d'obstacle 
        entre la position de départ et la position d'arrivée et que le coup 
        ne fasse pas sortir la pièce du plateau*/
        bool testCoup(const Coup & c)const;

        bool PartieFinie()const;

        Couleur couleurGagnante()const;

        void testRegressionConfigJeu()const;





        
};


#endif