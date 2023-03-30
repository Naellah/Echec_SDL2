#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

#include "Chrono.h"
#include "Piece.h"




class Joueur{
    
    
    private:
        string nom;
        Couleur couleur;
        unsigned int nbpartiejouee = 0;
        unsigned int win;
        unsigned int lose;
        unsigned int egalite;
        double ratio;
        Chrono chrono;


    
    public:
        //constructeur par défaut
        Joueur();
        //constructeur
        Joueur(string _nom, Couleur _couleur);

        //constructeur avec tous les paramètres
        Joueur(string _nom, unsigned int _nbpartiejouee, unsigned int _win, 
        unsigned int _lose, unsigned int _egalite, double _ratio);
        
        //destructeur
        ~Joueur();
        //assesseurs nom
        string getNom()const;
        //assesseurs couleur
        Couleur getCouleur()const;

        //assesseurs couleur string
        string getCouleurString()const;

        //assesseurs victoire
        unsigned int getWin()const;

        //assesseurs defaite
        unsigned int getLose()const;

        //assesseurs egalite
        unsigned int getEgalite()const;

        //assesseurs ratio
        double getRatio()const;

        //assesseurs partie jouee
        unsigned int getPartieJouee()const;

        //assesseurs chrono
        Chrono getChrono()const;

        //mutateurs Nom
        void setNom(string _nom);

        //mutateurs Couleur
        void setCouleur(Couleur _couleur);

        //mutateurs victoire
        void setWin(unsigned int _win);

        //mutateurs defaite
        void setLose(unsigned int _lose);

        //mutateurs egalite
        void setEgalite(unsigned int _egalite);

        //mutateurs ratio
        void setRatio();

        //mutateurs partie jouee
        void setPartieJouee(unsigned int _nbpartiejouee);

        //mutateurs chrono
        void setChrono(Chrono _chrono);

        //incrementation victoire
        void incWin();

        //incrementation défaite
        void incLose();

        //incrementation égalité
        void incEgalite();

        //incrementation partie jouée
        void incPartieJouee();

       

        //sauvegarde le nom du joueur dans un fichier avec son nombre de victoire et de défaite et son ratio
        void sauvegarderJoueur()const;

        //charge un joueur d'un fichier
        void chargerJoueur();

        void supprimerJoueur(const std::string& nomJoueur); 

        //test de la classe Joueur
        void testRegressionJoueur()const;

    


};



#endif