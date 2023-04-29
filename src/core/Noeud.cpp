#include "Noeud.h"
#include <vector>

Noeud::Noeud() {
    valeur = 0;
    coup = Coup(Vec2(0,0), Vec2(0,0));
}


Noeud::Noeud(int v, Coup c) {
    valeur = v;
    coup = c;
}

Noeud::~Noeud() {
}

int Noeud::getValeur() const {
    return valeur;
}

void Noeud::setValeur(int valeur) {
    this->valeur = valeur;
}

Coup Noeud::getCoup() const {
    return coup;
}

Noeud * Noeud::getFils(int i) const {
    return fils[i];
}

vector<Noeud*> Noeud :: getFilsVec() const {
    return fils;
}

void Noeud::ajouterFils(int v, Coup c) {
    fils.push_back(new Noeud(v, c));
}

void Noeud::supprimeArbre() {
    for (Noeud* fils : fils) {
        fils->supprimeArbre();
        delete fils;
    }
    fils.clear();
}
