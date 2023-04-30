#ifndef NOEUD_H
#define NOEUD_H

#include "Vec2.h"
#include "Piece.h"
#include "ConfigJeu.h"
#include <vector>

/**
 * @brief Classe représentant un nœud d'un arbre à N fils.
 */
class Noeud {

    private:

    int valeur;
    Coup coup;
    vector<Noeud*> fils;


    public:

    /**
     * @brief Constructeur par défaut de la classe Noeud.
     */
    Noeud();



    /**
     * @brief Constructeur de la classe Noeud.
     * @param v La valeur du nœud.
     * @param c Le coup du nœud.
     */
    Noeud(int v, Coup c);

    /**
     * @brief Destructeur de la classe Noeud.
     */
    ~Noeud();

    /**
     * @brief Assesseur de la racine de l'arbre.
     */
    int getValeur() const;
    

    /**
     * @brief Assesseur du coup.
     */ 
    Coup getCoup() const;

    /**
     * @brief Ajoute un fils à ce nœud.
     * @param fils Le nœud fils à ajouter.
     */

    /**
     * @brief Ajoute un fils à ce nœud.
     * @param v La valeur du nœud.
     * @param c Le coup du nœud.
     */
    void ajouterFils(int v, Coup c);
    

     /**
    * @brief mutateur de la valeur du noeud
    * @param valeur : est un entier qui designe la valeur du noeud
    */
    void setValeur(int valeur);

    /**
     * @brief assesseur du fils
     * @param i : est un entier qui designe le fils
     */
    Noeud * getFils(int i) const;

     /**
     * @brief assesseur du vecteur de fils
     */
    vector<Noeud*> getFilsVec() const;


    /**
    * @brief Supprime tous les fils de ce nœud.
    */
    void supprimeArbre();

    
};





#endif // NOEUD_H
