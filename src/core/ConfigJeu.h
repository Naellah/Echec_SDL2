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

    /**
      * @brief constructeur par défaut
    */
    Coup() {}


    /**
      * @brief constructeur avec des arguments
      @param _pos : est un vecteur qui designe la position de d'depart
      @param _dep : est un vecteur qui designe la position d'arrive
    */
    Coup(Vec2 _pos, Vec2 _dep) {
        posi = _pos;
        deplacement = _dep;
    }

    /**
      * @brief operateur d'egalite
      @param other : coorespond a un coup
    */
    bool operator==(const Coup& other) const {
        return posi == other.posi && deplacement == other.deplacement;
    }
    /**
      * @brief operateur inferieur
      @param other : coorespond a un coup
    */
    bool operator<(const Coup& other) const {
        if (posi.getX() < other.posi.getX())
            return true;
        else if (posi.getX() > other.posi.getX())
            return false;
        else
            return posi.getY() < other.posi.getY();
    }
};

class ConfigJeu {
private:
    /**
    * @brief un tableau de pieces blanche
    */
    vector <Piece> piecesBlanches;

    /**
    * @brief un tableau de pieces noir
    */
    vector <Piece> piecesNoires;

    /**
    * @brief un tableau 2d de piece pour le plateau
    */
    vector<vector<Piece>> plateau;

    /**
    * @brief une couleur qui designe le joueur courant
    */
    Couleur joueurCourant;

    /**
    * @brief correspond au nombre de tour
    */
    unsigned int tour;

    /**
    * @brief corrsspond au nombre de piece blanche encore en vie
    */
    unsigned int nbPiecesBlanches;

    /**
    * @brief corrsspond au nombre de piece noir encore en vie
    */
    unsigned int nbPiecesNoires;

public:

    /**
    * @brief constructeur par défaut
    */
    ConfigJeu();

    /**
    * @brief destructeur
    */
    ~ConfigJeu();

    /**
    * @brief init le jeu
    */
    void initConfigJeu();

    /**
    * @brief retourne un tableau de coups possibles d'une piece
      @param pos : est un vecteur qui designe la position d'une piece
    */
    vector <Coup> coupsPossibles(const Vec2& pos)const;

    /**
    * @brief joue la coup d'une piece
      @param c : est un coup
    */
    void jouerCoup(const Coup& c);

    /**
    * @brief assesseurs à partir de la position
      @param pos : est un vectreur qui designe la position d'une piece
    */
    const Piece& getPiece(const Vec2& pos)const;

    /**
    * @brief assesseurs du plateau
    */
    const vector<vector<Piece>>& getPlateau()const;

    /**
    * @brief deplace la piece selon un coup et passe au joueur suivant
      @param c : correspond a un coup
    */
    void deplacePiece(const Coup& c);

    /**
    * @brief assesseur du joueur courant
    */
    const Couleur& getJoueurCourant()const;

    /**
    * @brief retourne une phrase disant qui doit jouer
    */
    string JoueurCourantstr()const;

    /**
    * @brief affiche le plateau en mettant en rouge les pieces noires et en bleu les pieces blanches et des étoiles pour les cases vides
    */
    void afficherPlateauTxt()const;

    /**
    * @brief affiche en texte les coups possibles d'une piece(coordonnees)
      @param pos : correspond a un vecteur qui designe la position d'une piece
    */
    void afficherCoupsPossibles(const Vec2& pos)const;

    /**
    * @brief mutateurs du joueur qui joue
    */
    void setJoueurCourant();

    /**
    * @brief recupere le vec2 coordonnees selon ses coordonnées lettre et chiffre
      @param lettre : correspond a la lettre du plateau en mode texte
      @param chiffre : correspond au chiffre du plateau en mode texte
    */
    Vec2 recuperePosition(const char& lettre, const char& chiffre)const;

    /**
    * @brief modifie les valeurs d'une piece si elle est mange
      @param p : correspond a une piece
    */
    void estMangeConfig(Piece& p);

    /**
    * @brief renvoie vrai si le roi blanc est en echec
    */
    bool EchecBlanc()const;

    /**
    * @brief renvoie vrai si le roi noir est en echec
    */
    bool EchecNoir()const;

    /**
    * @brief renvoie vrai si le roi blanc est en echec et mat
    */
    bool EchecEtMatBlanc()const;

    /**
    * @brief renvoie vrai si le roi noir est en echec et mat
    */
    bool EchecEtMatNoir()const;

    /**
    * @brief affiche en texte tous les echecs et echecs et mat
    */
    void Echecall()const;


    /**
    * @brief /*retourne vrai si pour un coup donné, il n'y a pas d'obstacle
    entre la position de départ et la position d'arrivée et que le coup
    ne fasse pas sortir la pièce du plateau
    */
    bool testCoup(const Coup& c)const;

    /**
    * @brief renvoie vrai si la partie est fini
    */
    bool PartieFinie()const;

    /**
    * @brief retourne la couleur du jouer qui a gagne la partie
    */
    Couleur couleurGagnante()const;

    /**
    * @brief test de regression de ConfigJeu
    */
    void testRegressionConfigJeu()const;

};


#endif