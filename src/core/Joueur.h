#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

#include "Chrono.h"
#include "Piece.h"


class Joueur {

private:
    /**
    * @brief est une chaine de caractere qui designe le nom du joueur
    */
    string nom;

    /**
    * @brief est une couleur qui designe la couleur du joueur
    */
    Couleur couleur;

    /**
    * @brief est un entier qui designe le nombre de partie jouee
    */
    unsigned int nbpartiejouee = 0;

    /**
    * @brief est un entier qui designe le nombre de victoire
    */
    unsigned int win;

    /**
    * @brief est un entier qui designe le nombre de defaite
    */
    unsigned int lose;

    /**
    * @brief est un entier qui designe le nombre d'egalite
    */
    unsigned int egalite;

    /**
    * @brief est un double qui designe le ratio de victoire
    */
    double ratio;

    /**
    * @brief est un chrono
    */
    Chrono chrono;

public:
    /**
    * @brief constructeur par défaut
    */
    Joueur();

    /**
    * @brief constructeur
    */
    Joueur(string _nom, Couleur _couleur);

    /**
    * @brief constructeur avec tous les paramètres
      @param _nom : correspond au nom du joueur
      @param _nbpartiejouee : correspond au nombre de partie jouee
      @param _win : correspond au nombre de victoire
      @param _lose : correspond au nombre de defaite
      @param _egalite : correspond au nombre d'egalite
      @param _ratio : correspond au ratio de victoire
    */
    Joueur(string _nom, unsigned int _nbpartiejouee, unsigned int _win,
        unsigned int _lose, unsigned int _egalite, double _ratio);

    /**
    * @brief destructeur
    */
    ~Joueur();

    /**
    * @brief assesseur nom
    */
    string getNom()const;

    /**
    * @brief assesseur couleur
    */
    Couleur getCouleur()const;

    /**
    * @brief assesseur couleur string
    */
    string getCouleurString()const;

    /**
    * @brief assesseur victoire
    */
    unsigned int getWin()const;

    /**
    * @brief assesseur defaite
    */
    unsigned int getLose()const;

    /**
    * @brief assesseur egalite
    */
    unsigned int getEgalite()const;

    /**
    * @brief assesseur ratio
    */
    double getRatio()const;

    /**
    * @brief assesseur partie jouee
    */
    unsigned int getPartieJouee()const;

    /**
    * @brief assesseur chrono
    */
    Chrono getChrono()const;

    /**
    * @brief mutateur nom
      @param _nom : correspond a une chaine de caractere qui sera le nouveau nom
    */
    void setNom(string _nom);

    /**
    * @brief mutateur couleur
      @param _couleur : correspond a une couleur qui sera la nouvelle couleur
    */
    void setCouleur(Couleur _couleur);

    /**
    * @brief mutateur victoire
      @param _win : correspond a un entier qui designe le nombre de victoire
    */
    void setWin(unsigned int _win);

    /**
    * @brief mutateur defaite
      @param _lose : correspond a un entier qui designe le nombre de defaite
    */
    void setLose(unsigned int _lose);

    /**
    * @brief mutateur egalite
      @param _egalite : correspond a un entier qui designe le nombre d'egalite
    */
    void setEgalite(unsigned int _egalite);

    /**
    * @brief mutateur rato
    */
    void setRatio();

    /**
    * @brief mutateur partie jouee
      @param _nbpartiejouee : correspond a un entier qui designe le nombre de partie jouee
    */
    void setPartieJouee(unsigned int _nbpartiejouee);

    /**
    * @brief mutateur chrono
      @param _chrono : correspond a la nouvlle valeur du chrono
    */
    void setChrono(Chrono _chrono);

    /**
    * @brief incrementation victoire
    */
    void incWin();

    /**
    * @brief incrementation defaite
    */
    void incLose();

    /**
    * @brief incrementation egalite
    */
    void incEgalite();

    /**
    * @brief incrementation partie jouee
    */
    void incPartieJouee();

    /**
    * @brief sauvegarde le nom du joueur dans un fichier avec son nombre de victoire et de défaite et son ratio
    */
    void sauvegarderJoueur()const;

    /**
    * @brief charge un joueur d'un fichier
    */
    void chargerJoueur();

    /**
    * @brief on supprime un joueur du fichier
      @param nomJoueur : est une chaine de caratere du joueur a supprimer
    */
    void supprimerJoueur(const std::string& nomJoueur);

    /**
    * @brief test de la classe Joueur
    */
    void testRegressionJoueur()const;

};



#endif