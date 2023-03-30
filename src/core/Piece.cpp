#include <iostream>
#include <string>
#include <assert.h>

#include "Vec2.h"
#include "Piece.h"




using namespace std;

ifstream& operator>>(ifstream& is, Couleur& couleur){
    int tmp;
    is >> tmp;
    couleur = static_cast<Couleur>(tmp);
    return is;
}

Couleur aleatoireCouleur(){
    //random entre 1 et 2
    int tmp = rand()%2 + 1;
    return static_cast<Couleur>(tmp);
}



        //constructeur par défaut


Piece :: Piece(){
    couleur = VIDEC;
    type = VIDE;
    est_vivante = true;
}
        //constructeur prenant des arguments
Piece :: Piece(Couleur coul,TypePiece typ,Vec2 pos){
    couleur = coul;
    type = typ;
    position = pos;
    est_vivante = true;
}

Piece :: ~Piece(){
    couleur = VIDEC;
    type = VIDE;
    position = {0,0};
    est_vivante = false;

}

Piece& Piece :: operator=(const Piece& other){
    this->couleur = other.couleur;
    this->type = other.type;
    this->setPosition(other.position);
    this->est_vivante = other.est_vivante; 
    return *this;
}

bool Piece :: operator==(const Piece& other)const{
    return (this->couleur == other.couleur && this->type == other.type && this->position == other.position && this->est_vivante == other.est_vivante);
}





void Piece :: deplacement(Vec2 coor){
    assert(coor.getX() >= 1 && coor.getX() <= 8);
    assert(coor.getY() >= 1 && coor.getY() <= 8);
    position.setVec2(coor.getX(),coor.getY());
}

bool Piece :: vivant()const{
    return est_vivante;
}

//bool Piece :: coupValide()const {};

const Vec2 & Piece :: getPosition()const{
    return position;
}

void Piece :: setCouleur(Couleur coul){
    couleur = coul;
}

void Piece :: setType(TypePiece typ){
    type = typ;
}

void Piece :: setPosition(Vec2 pos){
    position = pos;
}


const Couleur& Piece :: getCouleur()const{
    return couleur;
}

const TypePiece& Piece :: getType()const{
    return type;
}

void Piece :: estmangee(){
    this->couleur = VIDEC;
    this->type = VIDE;
    position = {0,0};
    this->est_vivante = false;
}


void Piece :: devientVide(){
    this->couleur = VIDEC;
    this->type = VIDE;
    //position = {0,0};
    this->est_vivante = false;
}

bool Piece :: pieceVide()const{
    return (type == VIDE);
}

const TypePiece Piece::getPiecenum(const std::string& choix) const {
    // On utilise la méthode stoi() du header <string> pour convertir la chaîne en entier
    int num = std::stoi(choix);
    return static_cast<TypePiece>(num);
}

void Piece :: testRegressionPiece()const{
    Piece p1;
    //test constructeur par defaut
    assert(p1.vivant() == true);
    assert(p1.pieceVide() == true);
    assert(p1.getCouleur() == VIDEC);
    assert(p1.getType() == VIDE);
    assert(p1.getPosition().getX() == 0);
    assert(p1.getPosition().getY() == 0);
    //test constructeur avec arguments
    Piece p2(BLANC,DAME,{1,2});
    p1.setCouleur(BLANC);
    p1.setType(PION1);
    p1.setPosition({1,2});
    assert(p1.getCouleur() == BLANC);
    assert(p1.getType() == PION1);
    assert(p1.getPosition().getX() == 1);
    assert(p1.getPosition().getY() == 2);
    //test operateur d'affectation
    Piece p3;
    p3 = p2;
    assert(p3.getCouleur() == BLANC);
    assert(p3.getType() == DAME);
    assert(p3.getPosition().getX() == 1);
    assert(p3.getPosition().getY() == 2);
    //test deplacement
    p3.deplacement({3,4});
    assert(p3.getPosition().getX() == 3);
    assert(p3.getPosition().getY() == 4);

    //test pieceVide
    assert(p3.pieceVide() == false);
    //test getPiecenum
    assert(p3.getPiecenum("0") == PION1);
    assert(p3.getPiecenum("15") == ROI);

    cout << "Test de la classe Piece reussi" << endl;
 
}