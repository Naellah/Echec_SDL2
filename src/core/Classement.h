#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <string>
#include <vector>

#include "Joueur.h"
#include "Piece.h"

class Classement{
    private:
        vector<Joueur> classement;
        unsigned int nbjoueur;
    public:
        
        //constructeur par défaut
        Classement();
        
        //constructeur
        Classement(unsigned int _nbjoueur);
        
        //destructeur
        ~Classement();
        
        //assesseurs nbjoueur
        unsigned int getNbjoueur()const;
        
        //assesseurs classement
        vector<Joueur> getClassement()const;
        
        //mutateurs nbjoueur
        void setNbjoueur(unsigned int _nbjoueur);
        
        //mutateurs classement
        void setClassement(vector<Joueur> _classement);
        
        //ajouter un joueur
        void ajouterJoueur(Joueur _joueur);
        
        //supprimer un joueur
        void supprimerJoueur(Joueur _joueur);
        
        //afficher le classement
        void afficherClassement();
        
        //sauvegarder le classement
        void sauvegarderClassement();
        
        //charger le classement
        void chargerClassement();

        //trier le classement en fonction du nombre de victoire
        void trierClassement();


        void testRegressionClassement()const ;
};






#endif