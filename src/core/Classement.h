#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <string>
#include <vector>

#include "Joueur.h"
#include "Piece.h"

class Classement {
private:
    /**
    * @brief un tableau de joueur
    */
    vector<Joueur> classement;
    /**
    * @brief le nombre de joueur
    */
    unsigned int nbjoueur;
public:

    /**
    * @brief constructeur par defaut
    */
    Classement();

    /**
    * @brief constructeur
      @param _nbjoueur : correspond au nombre de joueur
    */
    Classement(unsigned int _nbjoueur);

    /**
    * @brief destructeur
    */
    ~Classement();

    /**
    * @brief assesseur nbjoueur
    */
    unsigned int getNbjoueur()const;

    /**
    * @brief assesseur classement
    */
    vector<Joueur> getClassement()const;

    /**
    * @brief mutateur nbjoueur
      @param _nbjoueur : correspond au nombre de joueur
    */
    void setNbjoueur(unsigned int _nbjoueur);

    /**
    * @brief mutateur classement
      @param _classement : correspond a un tableau de joueur
    */
    void setClassement(vector<Joueur> _classement);

    /**
    * @brief ajouter un joueur
      @param _joueur : correspond a un joueur
    */
    void ajouterJoueur(Joueur _joueur);

    /**
    * @brief supprimer un joueur
      @param _joueur : correspond a un joueur
    */
    void supprimerJoueur(Joueur _joueur);

    /**
    * @brief afficher le classement
    */
    void afficherClassement();

    /**
    * @brief sauvegarder le classement
    */
    void sauvegarderClassement();

    /**
    * @brief charger le classement
    */
    void chargerClassement();

    /**
    * @brief trier le classement en fonction du nombre de victoire
    */
    void trierClassement();

    /**
    * @brief test de regression du classement
    */
    void testRegressionClassement()const;
};



#endif