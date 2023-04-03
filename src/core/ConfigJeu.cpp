#include <iostream>
#include <iomanip>

#include "ConfigJeu.h"
#include "Piece.h"
#include "Vec2.h"

#include <set>

using namespace std;


ConfigJeu :: ConfigJeu(){
    
    plateau.reserve(10);
    for(int i=0; i<10; i++) {
        plateau.push_back(vector<Piece>(10));
    }
    joueurCourant = Couleur::BLANC;
    nbPiecesBlanches = 16;
    nbPiecesNoires = 16;
    tour = 1;
}
  
ConfigJeu :: ~ConfigJeu(){
    piecesBlanches.clear();
    piecesNoires.clear();
    plateau.clear();
}
          
void ConfigJeu :: initConfigJeu(){
   
    //initialisation des pieces blanches
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION1,Vec2(1,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION2,Vec2(2,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION3,Vec2(3,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION4,Vec2(4,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION5,Vec2(5,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION6,Vec2(6,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION7,Vec2(7,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::PION8,Vec2(8,7)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::TOUR1,Vec2(1,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::CAVALIER1,Vec2(2,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::FOU1,Vec2(3,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::DAME,Vec2(4,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::ROI,Vec2(5,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::FOU2,Vec2(6,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::CAVALIER2,Vec2(7,8)));
    piecesBlanches.push_back(Piece(Couleur::BLANC,TypePiece::TOUR2,Vec2(8,8)));


    //initialisation des pieces noires
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION1,Vec2(1,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION2,Vec2(2,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION3,Vec2(3,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION4,Vec2(4,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION5,Vec2(5,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION6,Vec2(6,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION7,Vec2(7,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::PION8,Vec2(8,2)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::TOUR1,Vec2(1,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::CAVALIER1,Vec2(2,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::FOU1,Vec2(3,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::DAME,Vec2(4,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::ROI,Vec2(5,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::FOU2,Vec2(6,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::CAVALIER2,Vec2(7,1)));
    piecesNoires.push_back(Piece(Couleur::NOIR,TypePiece::TOUR2,Vec2(8,1)));
    
   

    //ajoute des pieces vides tout autour du plateau
    for (int i = 0 ; i<10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 || i == 9 || j == 0 || j == 9)
            {
                plateau[i][j].setType(TypePiece::VIDE);
                plateau[i][j].setPosition(Vec2(i,j));
                plateau[i][j].setCouleur(Couleur::VIDEC);
            }
        }
    }
   
    //initialisation du plateau avec les pieces noires 
    //initialise toute les case du tableau avec des pieces vide
    for (int i = 1 ; i<9; i++)
    {
        for (int j = 3; j < 7; j++)
        {
            //plateau[i][j].setType(TypePiece::VIDE);
            plateau[i][j].setPosition(Vec2(i,j));
            //plateau[i][j]=Piece(Couleur::VIDEC,TypePiece::VIDE,Vec2(i,j));
            assert(plateau[i][j].getCouleur() == Couleur::VIDEC);
            assert(plateau[i][j].getType() == TypePiece::VIDE);
            assert(plateau[i][j].getPosition().getX() == i);
            assert(plateau[i][j].getPosition().getY() == j);

        }
    }
    plateau[1][1] = piecesNoires[8];
    plateau[2][1] = piecesNoires[9];
    plateau[3][1] = piecesNoires[10];
    plateau[4][1] = piecesNoires[11];
    plateau[5][1] = piecesNoires[12];
    plateau[6][1] = piecesNoires[13];
    plateau[7][1] = piecesNoires[14];
    plateau[8][1] = piecesNoires[15];
    plateau[1][2] = piecesNoires[0];
    plateau[2][2] = piecesNoires[1];
    plateau[3][2] = piecesNoires[2];
    plateau[4][2] = piecesNoires[3];
    plateau[5][2] = piecesNoires[4];
    plateau[6][2] = piecesNoires[5];
    plateau[7][2] = piecesNoires[6];
    plateau[8][2] = piecesNoires[7];

    
    
    //initialisation du plateau avec les pieces blanches
    plateau[1][8] = piecesBlanches[8];
    plateau[2][8] = piecesBlanches[9];
    plateau[3][8] = piecesBlanches[10];
    plateau[4][8] = piecesBlanches[11];
    plateau[5][8] = piecesBlanches[12];
    plateau[6][8] = piecesBlanches[13];
    plateau[7][8] = piecesBlanches[14];
    plateau[8][8] = piecesBlanches[15];
    plateau[1][7] = piecesBlanches[0];
    plateau[2][7] = piecesBlanches[1];
    plateau[3][7] = piecesBlanches[2];
    plateau[4][7] = piecesBlanches[3];
    plateau[5][7] = piecesBlanches[4];
    plateau[6][7] = piecesBlanches[5];
    plateau[7][7] = piecesBlanches[6];
    plateau[8][7] = piecesBlanches[7];


   //initialisation du plateau avec les pieces vides
    
}







vector <Coup> ConfigJeu :: coupsPossibles(const Vec2& pos)const{
    Piece piece_actuelle = getPiece(pos);
    vector <Coup> coupsPossibles;
    
    switch(piece_actuelle.getType()){
        /////////////////////PIONT//////////////////////////
        case TypePiece::PION1:
        case TypePiece::PION2:
        case TypePiece::PION3:
        case TypePiece::PION4:
        case TypePiece::PION5:
        case TypePiece::PION6:
        case TypePiece::PION7:
        case TypePiece::PION8:
            if (piece_actuelle.getCouleur() == Couleur::BLANC) {

                if (piece_actuelle.getPosition().getY() == 7) {
                    if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 1)).getCouleur() == Couleur::VIDEC) {
                        if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 2)).getCouleur() == Couleur::VIDEC) {
                            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 2)));
                            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 1)));
                        }
                        else {
                            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 1)));
                        }
                    }
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 1)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - 1)));
                }


                //teste s'il y a un pion adverse en diagonale
                if (piece_actuelle.getPosition().getX() != 1){
                    if (plateau[piece_actuelle.getPosition().getX() - 1][piece_actuelle.getPosition().getY() - 1].getCouleur() == Couleur::NOIR) {
                        coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - 1, piece_actuelle.getPosition().getY() - 1)));
                    }
                }
                if (piece_actuelle.getPosition().getX() != 8) {
                    if (plateau[piece_actuelle.getPosition().getX() + 1][piece_actuelle.getPosition().getY() - 1].getCouleur() == Couleur::NOIR) {
                        coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + 1, piece_actuelle.getPosition().getY() - 1)));
                    }
                }

            }
			else if (piece_actuelle.getCouleur() == Couleur::NOIR){
                
                if (piece_actuelle.getPosition().getY() == 2) {
                    if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 1)).getCouleur() == Couleur::VIDEC) {
                        if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 2)).getCouleur() == Couleur::VIDEC) {
                            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 2)));
                            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 1)));
                        }
                        else {
                            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 1)));
                        }
                    }
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 1)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + 1)));
                }

                //teste s'il y a un pion adverse en diagonale
                if (piece_actuelle.getPosition().getX() != 8) {
                    if (plateau[piece_actuelle.getPosition().getX() + 1][piece_actuelle.getPosition().getY()+1].getCouleur() == Couleur::BLANC) {
						coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+1,piece_actuelle.getPosition().getY()+1)));
					}
                
                }
                if (piece_actuelle.getPosition().getX() != 1) {
                    if (plateau[piece_actuelle.getPosition().getX() - 1][piece_actuelle.getPosition().getY()+1].getCouleur() == Couleur::BLANC) {
							coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-1,piece_actuelle.getPosition().getY()+1)));
					}
				}
				
            }
            

            break;




                    
        
        /////////////////////TOUR//////////////////////////
        case TypePiece::TOUR1:
        case TypePiece::TOUR2:
            for(int i = 1; i < 9; i++){
                 coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(i,piece_actuelle.getPosition().getY())));
            }
                //test si ça sort du tableau
            
            for(int i = 1; i < 9; i++){
                
                coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX(),i)));
                
            }
            break;




        /////////////////////CAVALIER//////////////////////////
        case TypePiece::CAVALIER1:
        case TypePiece::CAVALIER2:
        
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+1,piece_actuelle.getPosition().getY()+2)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+2,piece_actuelle.getPosition().getY()+1)));
            
            
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+2,piece_actuelle.getPosition().getY()-1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+1,piece_actuelle.getPosition().getY()-2)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-1,piece_actuelle.getPosition().getY()-2)));
            
            
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-2,piece_actuelle.getPosition().getY()-1)));
            
            
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-2,piece_actuelle.getPosition().getY()+1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-1,piece_actuelle.getPosition().getY()+2)));
            
            break;



        case TypePiece::ROI:
            
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+1,piece_actuelle.getPosition().getY())));
            
            
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+1,piece_actuelle.getPosition().getY()+1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX(),piece_actuelle.getPosition().getY()+1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-1,piece_actuelle.getPosition().getY()+1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-1,piece_actuelle.getPosition().getY())));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-1,piece_actuelle.getPosition().getY()-1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX(),piece_actuelle.getPosition().getY()-1)));
            
           
            coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+1,piece_actuelle.getPosition().getY()-1)));
            
            break;

        





        /////////////////////FOU//////////////////////////
        case TypePiece::FOU1:
        case TypePiece::FOU2:
            for(int i = 1; i < 9; i++){
                coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+i,piece_actuelle.getPosition().getY()+i)));
                
            }
            for(int i = 1; i < 9; i++){
                
                coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()+i,piece_actuelle.getPosition().getY()-i)));
                
            }
            for(int i = 1; i < 9; i++){
               
                coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-i,piece_actuelle.getPosition().getY()+i)));
                
            }
            for(int i = 1; i < 9; i++){
                
                coupsPossibles.push_back(Coup(piece_actuelle.getPosition(),Vec2(piece_actuelle.getPosition().getX()-i,piece_actuelle.getPosition().getY()-i)));
                
            }
            break;

    





        /////////////////////DAME/////////////////////////

        case TypePiece::DAME:
            

            // coup ligne droite 

            int i = 1;
            while (piece_actuelle.getPosition().getX() - i > 0 ) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY())).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY())));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY())).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY())));
                    break;
                }
                else { break; }
            }

            i = 1;
            while (piece_actuelle.getPosition().getX() + i < 9 ) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY())).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY())));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY())).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY())));
                    break;
                }
                else { break; }
            }

            i = 1;
            while (piece_actuelle.getPosition().getY() - i > 0 ) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - i)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - i)));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - i)).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() - i)));
                    break;
                }
                else { break; }
            }

            i = 1;
            while (piece_actuelle.getPosition().getY() + i < 9) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + i)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + i)));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + i)).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX(), piece_actuelle.getPosition().getY() + i)));
                    break;
                }
                else { break; }
            }




            //diagonale


            i = 1;
            while (piece_actuelle.getPosition().getX() - i > 0 && piece_actuelle.getPosition().getY() - i > 0) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY()-i)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY()-i)));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY()-i)).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY()-i)));
                    break;
                }
                else { break; }
            }

            i = 1;
            while (piece_actuelle.getPosition().getX() + i < 9 && piece_actuelle.getPosition().getY() - i > 0) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() - i)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() - i)));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() - i)).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() - i)));
                    break;
                }
                else { break; }
            }


            i = 1;
            while (piece_actuelle.getPosition().getX() - i > 0 && piece_actuelle.getPosition().getY() + i < 9) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY() + i)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY() + i)));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY() + i)).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() - i, piece_actuelle.getPosition().getY() + i)));
                    break;
                }
                else { break; }
            }

            i = 1;
            while (piece_actuelle.getPosition().getX() + i < 9 && piece_actuelle.getPosition().getY() + i < 9) {
                if (getPiece(Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() + i)).getCouleur() == Couleur::VIDEC) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() + i)));
                    i++;
                }
                else if (getPiece(Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() + i)).getCouleur() != piece_actuelle.getCouleur()) {
                    coupsPossibles.push_back(Coup(piece_actuelle.getPosition(), Vec2(piece_actuelle.getPosition().getX() + i, piece_actuelle.getPosition().getY() + i)));
                    break;
                }
                else { break; }

            }

            break;

           
        
       
    }




    
    unsigned int i = 0;
    while (i < coupsPossibles.size()) {
        if (coupsPossibles[i].deplacement.getX() > 8 || coupsPossibles[i].deplacement.getX() < 1 || coupsPossibles[i].deplacement.getY() > 8 || coupsPossibles[i].deplacement.getY() < 1) {
            coupsPossibles.erase(coupsPossibles.begin() + i);
        }
        else {
            i++;
        }
    }
    

    i = 0;
    while (i < coupsPossibles.size()) {
        if (getPiece(coupsPossibles[i].deplacement).getType() != TypePiece::VIDE) {
            if (getPiece(coupsPossibles[i].deplacement).getCouleur() == piece_actuelle.getCouleur()) {
                coupsPossibles.erase(coupsPossibles.begin() + i);
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }

    

    i = 0;
    //test si le pion arrive sur une case ou il y a une piece de la meme couleur
    for (int i = static_cast<int>(coupsPossibles.size()) - 1; i >= 0; i--) {
        if (getPiece(coupsPossibles[i].deplacement).getType() != TypePiece::VIDE) {
            if (getPiece(coupsPossibles[i].deplacement).getCouleur() == piece_actuelle.getCouleur()) {
                coupsPossibles.erase(coupsPossibles.begin() + i);
            }
        }
    }
    for (unsigned int i = 0; i < coupsPossibles.size(); ) {
        if (coupsPossibles[i].posi == coupsPossibles[i].deplacement) {
            coupsPossibles.erase(coupsPossibles.begin() + i);
        }
        else {
            i++;
        }
    }

    
    switch (piece_actuelle.getType()){
        case CAVALIER1:
        case CAVALIER2:
        case PION1:
        case PION2:
        case PION3:
        case PION4:
        case PION5:
        case PION6:
        case PION7:
        case PION8:
        case ROI:
        case DAME:
            break;

       //tout le reste
       
        case TOUR1:
        case TOUR2:
            //teste si la tour passe au dessus d'une piece
            for (unsigned int i = 0; i < coupsPossibles.size(); i++) {
                if (coupsPossibles[i].posi.getX() == coupsPossibles[i].deplacement.getX()) {
                    if (coupsPossibles[i].posi.getY() < coupsPossibles[i].deplacement.getY()) {
                        for (int j = coupsPossibles[i].posi.getY() + 1; j < coupsPossibles[i].deplacement.getY(); j++) {
                            if (getPiece(Vec2(coupsPossibles[i].posi.getX(), j)).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                    else {
                        for (int j = coupsPossibles[i].posi.getY() - 1; j > coupsPossibles[i].deplacement.getY(); j--) {
                            if (getPiece(Vec2(coupsPossibles[i].posi.getX(), j)).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                }
                else {
                    if (coupsPossibles[i].posi.getX() < coupsPossibles[i].deplacement.getX()) {
                        for (int j = coupsPossibles[i].posi.getX() + 1; j < coupsPossibles[i].deplacement.getX(); j++) {
                            if (getPiece(Vec2(j, coupsPossibles[i].posi.getY())).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                    else {
                        for (int j = coupsPossibles[i].posi.getX() - 1; j > coupsPossibles[i].deplacement.getX(); j--) {
                            if (getPiece(Vec2(j, coupsPossibles[i].posi.getY())).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                }
            }

            break;
        



        case FOU1:
        case FOU2: 
            //teste si le fou passe au dessus d'une piece
            
            for (unsigned int i = 0; i < coupsPossibles.size(); i++) {
                if (coupsPossibles[i].posi.getX() < coupsPossibles[i].deplacement.getX()) {
                    if (coupsPossibles[i].posi.getY() < coupsPossibles[i].deplacement.getY()) {
                        for (int j = coupsPossibles[i].posi.getX() + 1, k = coupsPossibles[i].posi.getY() + 1; j < coupsPossibles[i].deplacement.getX(); j++, k++) {
                            if (getPiece(Vec2(j, k)).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                    else {
                        for (int j = coupsPossibles[i].posi.getX() + 1, k = coupsPossibles[i].posi.getY() - 1; j < coupsPossibles[i].deplacement.getX(); j++, k--) {
                            if (getPiece(Vec2(j, k)).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                }
                else {
                    if (coupsPossibles[i].posi.getY() < coupsPossibles[i].deplacement.getY()) {
                        for (int j = coupsPossibles[i].posi.getX() - 1, k = coupsPossibles[i].posi.getY() + 1; j > coupsPossibles[i].deplacement.getX(); j--, k++) {
                            if (getPiece(Vec2(j, k)).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                    else {
                        for (int j = coupsPossibles[i].posi.getX() - 1, k = coupsPossibles[i].posi.getY() - 1; j > coupsPossibles[i].deplacement.getX(); j--, k--) {
                            if (getPiece(Vec2(j, k)).getType() != TypePiece::VIDE) {
                                coupsPossibles.erase(coupsPossibles.begin() + i);
                                i--;
                                break;
                            }
                        }
                    }
                }
            }
            break;

        default:
			break;

    }
    
    
    /*
    system("cls");
    std :: cout << piece_actuelle.getType() << endl;

    // affiche les coups pour debug
    for (unsigned int i = 0; i < coupsPossibles.size(); i++) {
		std :: cout << "Coup possible : "  << coupsPossibles[i].deplacement.getX() << " " << coupsPossibles[i].deplacement.getY() << endl;
	}*/

    return coupsPossibles;
}
 



void ConfigJeu :: afficherCoupsPossibles(const Vec2& pos_actuelle)const{
    vector<Coup> cpos = coupsPossibles(pos_actuelle);
    if (cpos.size()==0){
        std :: cout << "Aucun coup possible" << endl;
        return;
    }
    for(long unsigned int i=0; i<cpos.size(); i++){
        if (i==1){
            std :: cout << "1er coup possible:" << endl;
        }else 
        {
            std :: cout << i << "eme coup possible:" << endl;
        }
        std :: cout<<"("<<cpos[i].posi.getX()<<","<<cpos[i].posi.getY()<<") -> ("<<cpos[i].deplacement.getX()<<","<<cpos[i].deplacement.getY()<<")"<<endl;
    }
}





string ConfigJeu :: JoueurCourantstr()const{
    if (joueurCourant == Couleur::BLANC){
        return "C'est au joueur blanc de jouer";
    }
    else{
        return "C'est au joueur noir de jouer";
    }
}




void ConfigJeu :: jouerCoup(const Coup & c){
    Coup cnew(c.posi, c.deplacement);
    cnew.posi.setX(c.posi.getX() + c.deplacement.getX());
    cnew.posi.setY(c.posi.getY() + c.deplacement.getY());
    Piece tempo=getPiece(c.posi);
    tempo.setPosition(cnew.posi);
}




const Piece& ConfigJeu :: getPiece(const Vec2& pos)const{
    int a,b;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(pos.getX() == plateau[i][j].getPosition().getX() && pos.getY() == plateau[i][j].getPosition().getY()){
                a=i;
                b=j;
            }
        }
    } 
    return plateau[a][b];
}






bool ConfigJeu::EchecBlanc()const {
    // parcours le tableau en donnant les coups donnés pour chaque pièce et si chaque coup donné donnera avec getPiece sur le Roi
    // Si un coup donne sur le roi alors on retourne true
    // Sinon on retourne false
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (getPiece(Vec2(i, j)).getType() != TypePiece::VIDE) {
                vector<Coup> cpos = coupsPossibles(Vec2(i, j));
                for (unsigned int k = 0; k < cpos.size(); k++) {
                    if (getPiece(cpos[k].deplacement).getType() == TypePiece::ROI && getPiece(cpos[k].deplacement).getCouleur() == Couleur::BLANC) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool ConfigJeu::EchecNoir()const {
    // parcours le tableau en donnant les coups donnés pour chaque pièce et si chaque coup donné donnera avec getPiece sur le Roi
    // Si un coup donne sur le roi alors on retourne true
    // Sinon on retourne false
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (getPiece(Vec2(i, j)).getType() != TypePiece::VIDE) {
                vector<Coup> cpos = coupsPossibles(Vec2(i, j));
                for (unsigned int k = 0; k < cpos.size(); k++) {
                    if (getPiece(cpos[k].deplacement).getType() == TypePiece::ROI && getPiece(cpos[k].deplacement).getCouleur() == Couleur::NOIR) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}





bool ConfigJeu::EchecEtMatBlanc()const {
    // Si le roi est en échec et que aucun coup ne permet de le sauver alors on retourne true
    // Sinon on retourne false
    if (joueurCourant == Couleur :: NOIR)
        if (EchecBlanc() == true) {
            return true;
        }
    return false;
}

bool ConfigJeu::EchecEtMatNoir()const {
	// Si le roi est en échec et que aucun coup ne permet de le sauver alors on retourne true
	// Sinon on retourne false
	if (joueurCourant == Couleur :: BLANC)
        if (EchecNoir() == true) {
            return true;
        }
	return false;
}





void ConfigJeu::Echecall()const {
    // affiche tous les echecs et echecs et mat
    system("cls");
    
    if (this->EchecBlanc()==true) {
        cout << "Echec du Roi blanc" << endl;
        
    }
    if (this->EchecEtMatBlanc()==true) {
        cout << "Echec et mat du Roi blanc" << endl;
    }

    if (this->EchecNoir()==true) {
		cout << "Echec du Roi noir" << endl;
	}

    if (this->EchecEtMatNoir()==true) {
		cout << "Echec et mat du Roi noir" << endl;
	}

}











void ConfigJeu :: afficherPlateauTxt()const{
     for (int i = 1 ; i<9; i++){
        //met en couleur verte les indices de colonnes
        std :: cout << "\033[32;10m" << i << "\033[0m";
        for (int j = 1; j < 9; j++){
            std :: cout << " "<< " " ;
            switch(plateau[j][i].getCouleur()){
                
                case Couleur::BLANC:
                    switch(plateau[j][i].getType()){
                        //on affiche les pieces blanches en bleu
                        
                        case TypePiece::PION1:
                        case TypePiece::PION2:
                        case TypePiece::PION3:
                        case TypePiece::PION4:
                        case TypePiece::PION5:
                        case TypePiece::PION6:
                        case TypePiece::PION7:
                        case TypePiece::PION8:
                            std :: cout <<setw(2)<<  "\033[34;10mP\033[0m" << " ";
                            break;

                        case TypePiece::TOUR1:
                        case TypePiece::TOUR2:
                            std :: cout <<setw(2)<<  "\033[34;10mT\033[0m" << " ";
                            break;
                        
                        case TypePiece::CAVALIER1:
                        case TypePiece::CAVALIER2:
                            std :: cout <<setw(2)<<  "\033[34;10mC\033[0m" << " ";
                            break;
                        
                        case TypePiece::FOU1:
                        case TypePiece::FOU2:
                            std :: cout <<setw(2)<<  "\033[34;10mF\033[0m" << " ";
                            break;
                        
                        case TypePiece::DAME:
                            std :: cout <<setw(2)<<  "\033[34;10mD\033[0m" << " ";
                            break;
                        
                        case TypePiece::ROI:
                            std :: cout <<setw(2)<<  "\033[34;10mR\033[0m" << " ";
                            break;
            


                        default:    
                            break;
                    }
                    break;

                case Couleur::NOIR:
                    switch(plateau[j][i].getType()){
                        //on affiche les pieces noires en rouge
                        case TypePiece::PION1:
                        case TypePiece::PION2:
                        case TypePiece::PION3:
                        case TypePiece::PION4:
                        case TypePiece::PION5:
                        case TypePiece::PION6:
                        case TypePiece::PION7:
                        case TypePiece::PION8:
                            std :: cout <<setw(2)<<  "\033[31;10mP\033[0m" << " ";
                            break;

                        case TypePiece::TOUR1:
                        case TypePiece::TOUR2:
                            std :: cout <<setw(2)<<  "\033[31;10mT\033[0m" << " ";
                            break;
                        
                        case TypePiece::CAVALIER1:
                        case TypePiece::CAVALIER2:
                            std :: cout <<setw(2)<<  "\033[31;10mC\033[0m" << " ";
                            break;
                        
                        case TypePiece::FOU1:
                        case TypePiece::FOU2:
                            std :: cout <<setw(2)<<  "\033[31;10mF\033[0m" << " ";
                            break;
                        
                        case TypePiece::DAME:
                            std :: cout <<setw(2)<<  "\033[31;10mD\033[0m" << " ";
                            break;
                        
                        case TypePiece::ROI:
                            std :: cout <<setw(2)<<  "\033[31;10mR\033[0m" << " ";
                            break;
                        
                        default:
                            break;
                    }
                    break;
                    
                

                case Couleur::VIDEC:
                    std :: cout << "*" << " ";
                    break;
                
            }          
        }
        std :: cout << endl;
    }
    std :: cout << endl ;
    std :: cout << " "<< " " << " ";
    //on affiche les indices de lignes en vert
    std :: cout << "\033[32;10mA\033[0m" << " " << " "<<" " << "\033[32;10mB\033[0m" << " " << " " << " "<< "\033[32;10mC\033[0m" << " " << " " << " "<< "\033[32;10mD\033[0m" << " " << " " << " "<< "\033[32;10mE\033[0m" << " " << " " << " "<< "\033[32;10mF\033[0m" << " " << " " << " "<< "\033[32;10mG\033[0m" << " " << " " << " "<< "\033[32;10mH\033[0m" << " " << " " << " "<< endl;
    std :: cout << endl << endl;
}




Vec2 ConfigJeu :: recuperePosition(const char& lettre, const char& chiffre)const{
    int x = lettre - 'a'+1;
    //char to int
    int y = chiffre - '0';
    Vec2 pos(x,y);
    return pos;
}



void ConfigJeu :: deplacePiece(const Coup& c){
    estMangeConfig(plateau[c.deplacement.getX()][c.deplacement.getY()]);
    plateau[c.deplacement.getX()][c.deplacement.getY()] = plateau[c.posi.getX()][c.posi.getY()];
    plateau[c.deplacement.getX()][c.deplacement.getY()].setPosition(c.deplacement);
    plateau[c.posi.getX()][c.posi.getY()] = Piece(Couleur::VIDEC,TypePiece::VIDE,Vec2(c.posi.getX(),c.posi.getY()));
    setJoueurCourant();
}





const vector<vector<Piece>>& ConfigJeu :: getPlateau()const{
    return this->plateau;
}


const Couleur& ConfigJeu :: getJoueurCourant()const{
    return this->joueurCourant;
}


void ConfigJeu :: setJoueurCourant(){
    if (this->joueurCourant == Couleur::BLANC) {
		this->joueurCourant = Couleur::NOIR;
	}
    else {
		this->joueurCourant = Couleur::BLANC;
	}
}



void ConfigJeu :: estMangeConfig(Piece &p){
    if (p.getCouleur() == Couleur::BLANC) {
        // p devient nulle
        p.estmangee();
        nbPiecesBlanches--;
    }
    else if (p.getCouleur() == Couleur::NOIR) {
       // p devient nulle
        p=Piece(Couleur::VIDEC,TypePiece::VIDE,Vec2(0,0));
        nbPiecesNoires--;
    }
}



void ConfigJeu :: testRegressionConfigJeu()const{
    std :: cout<<"testRegressionConfigJeu"<<endl;
    ConfigJeu c;
    c.initConfigJeu();

    //test de la configuration initiale couleur et type des pieces
    assert(c.getJoueurCourant() == Couleur::BLANC);

    /*assert(c.piecesBlanches[0].getCouleur() == Couleur::BLANC);
    assert(c.piecesBlanches[0].getType() == TypePiece::PION1);
    assert(c.piecesBlanches[0].getPosition().getX() == 1);
    assert(c.piecesBlanches[0].getPosition().getY() == 7);*/
    assert(c.piecesBlanches[0] == Piece(Couleur::BLANC,TypePiece::PION1,Vec2(1,7)));
    assert(c.piecesBlanches[1] == Piece(Couleur::BLANC,TypePiece::PION2,Vec2(2,7)));
    assert(c.piecesBlanches[2] == Piece(Couleur::BLANC,TypePiece::PION3,Vec2(3,7)));
    assert(c.piecesBlanches[3] == Piece(Couleur::BLANC,TypePiece::PION4,Vec2(4,7)));
    assert(c.piecesBlanches[4] == Piece(Couleur::BLANC,TypePiece::PION5,Vec2(5,7)));
    assert(c.piecesBlanches[5] == Piece(Couleur::BLANC,TypePiece::PION6,Vec2(6,7)));
    assert(c.piecesBlanches[6] == Piece(Couleur::BLANC,TypePiece::PION7,Vec2(7,7)));
    assert(c.piecesBlanches[7] == Piece(Couleur::BLANC,TypePiece::PION8,Vec2(8,7)));
    assert(c.piecesBlanches[8] == Piece(Couleur::BLANC,TypePiece::TOUR1,Vec2(1,8)));
    assert(c.piecesBlanches[9] == Piece(Couleur::BLANC,TypePiece::CAVALIER1,Vec2(2,8)));
    assert(c.piecesBlanches[10] == Piece(Couleur::BLANC,TypePiece::FOU1,Vec2(3,8)));
    assert(c.piecesBlanches[11] == Piece(Couleur::BLANC,TypePiece::DAME,Vec2(4,8)));
    assert(c.piecesBlanches[12] == Piece(Couleur::BLANC,TypePiece::ROI,Vec2(5,8)));
    assert(c.piecesBlanches[13] == Piece(Couleur::BLANC,TypePiece::FOU2,Vec2(6,8)));
    assert(c.piecesBlanches[14] == Piece(Couleur::BLANC,TypePiece::CAVALIER2,Vec2(7,8)));
    assert(c.piecesBlanches[15] == Piece(Couleur::BLANC,TypePiece::TOUR2,Vec2(8,8)));
    


    assert(c.piecesNoires[0] == Piece(Couleur::NOIR,TypePiece::PION1,Vec2(1,2)));
    assert(c.piecesNoires[1] == Piece(Couleur::NOIR,TypePiece::PION2,Vec2(2,2)));
    assert(c.piecesNoires[2] == Piece(Couleur::NOIR,TypePiece::PION3,Vec2(3,2)));
    assert(c.piecesNoires[3] == Piece(Couleur::NOIR,TypePiece::PION4,Vec2(4,2)));
    assert(c.piecesNoires[4] == Piece(Couleur::NOIR,TypePiece::PION5,Vec2(5,2)));
    assert(c.piecesNoires[5] == Piece(Couleur::NOIR,TypePiece::PION6,Vec2(6,2)));
    assert(c.piecesNoires[6] == Piece(Couleur::NOIR,TypePiece::PION7,Vec2(7,2)));
    assert(c.piecesNoires[7] == Piece(Couleur::NOIR,TypePiece::PION8,Vec2(8,2)));
    assert(c.piecesNoires[8] == Piece(Couleur::NOIR,TypePiece::TOUR1,Vec2(1,1)));
    assert(c.piecesNoires[9] == Piece(Couleur::NOIR,TypePiece::CAVALIER1,Vec2(2,1)));
    assert(c.piecesNoires[10] == Piece(Couleur::NOIR,TypePiece::FOU1,Vec2(3,1)));
    assert(c.piecesNoires[11] == Piece(Couleur::NOIR,TypePiece::DAME,Vec2(4,1)));
    assert(c.piecesNoires[12] == Piece(Couleur::NOIR,TypePiece::ROI,Vec2(5,1)));
    assert(c.piecesNoires[13] == Piece(Couleur::NOIR,TypePiece::FOU2,Vec2(6,1)));
    assert(c.piecesNoires[14] == Piece(Couleur::NOIR,TypePiece::CAVALIER2,Vec2(7,1)));
    assert(c.piecesNoires[15] == Piece(Couleur::NOIR,TypePiece::TOUR2,Vec2(8,1)));
    
    
    
    // test du plateau
    assert(c.plateau[1][1] == c.piecesNoires[8]);
    assert(c.plateau[2][1] == c.piecesNoires[9]);
    assert(c.plateau[3][1] == c.piecesNoires[10]);
    assert(c.plateau[4][1] == c.piecesNoires[11]);
    assert(c.plateau[5][1] == c.piecesNoires[12]); 
    assert(c.plateau[6][1] == c.piecesNoires[13]);
    assert(c.plateau[7][1] == c.piecesNoires[14]);
    assert(c.plateau[8][1] == c.piecesNoires[15]);
    assert(c.plateau[1][2] == c.piecesNoires[0]);
    assert(c.plateau[2][2] == c.piecesNoires[1]);
    assert(c.plateau[3][2] == c.piecesNoires[2]);
    assert(c.plateau[4][2] == c.piecesNoires[3]);
    assert(c.plateau[5][2] == c.piecesNoires[4]);
    assert(c.plateau[6][2] == c.piecesNoires[5]);
    assert(c.plateau[7][2] == c.piecesNoires[6]);
    assert(c.plateau[8][2] == c.piecesNoires[7]);
    
    assert(c.plateau[1][7] == c.piecesBlanches[0]);
    assert(c.plateau[2][7] == c.piecesBlanches[1]);
    assert(c.plateau[3][7] == c.piecesBlanches[2]);
    assert(c.plateau[4][7] == c.piecesBlanches[3]);
    assert(c.plateau[5][7] == c.piecesBlanches[4]);
    assert(c.plateau[6][7] == c.piecesBlanches[5]);
    assert(c.plateau[7][7] == c.piecesBlanches[6]);
    assert(c.plateau[8][7] == c.piecesBlanches[7]);
    assert(c.plateau[1][8] == c.piecesBlanches[8]);
    assert(c.plateau[2][8] == c.piecesBlanches[9]);
    assert(c.plateau[3][8] == c.piecesBlanches[10]);
    assert(c.plateau[4][8] == c.piecesBlanches[11]);
    assert(c.plateau[5][8] == c.piecesBlanches[12]);
    assert(c.plateau[6][8] == c.piecesBlanches[13]);
    assert(c.plateau[7][8] == c.piecesBlanches[14]);
    assert(c.plateau[8][8] == c.piecesBlanches[15]);

    
    
    

    //Teste si les cases autour du plateau sont bien nulles
    for (int i = 0 ; i<10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 || i == 9 || j == 0 || j == 9)
            {
                assert(c.plateau[i][j].pieceVide() == true);
                assert(c.plateau[i][j].getCouleur() == Couleur::VIDEC);
                assert(c.plateau[i][j].getType() == TypePiece::VIDE);
                assert(c.plateau[i][j].getPosition().getX() == i);
                assert(c.plateau[i][j].getPosition().getY() == j);
            }
        }

    }
    std :: cout << "assertions ok" << endl;




     for (int i = 0 ; i<10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
 
        std :: cout<<setw(2)<<c.plateau[i][j].getType()<<" ";
        }
        std :: cout<<endl;
    }

    //test si les cases vides sont bien nulles
    for (int i = 1 ; i<9; i++)
    {
        for (int j = 3; j < 7; j++)
        {
            
            assert(c.plateau[i][j].pieceVide() == true);
            assert(c.plateau[i][j].getCouleur() == Couleur::VIDEC);
            assert(c.plateau[i][j].getType() == TypePiece::VIDE);
            assert(c.plateau[i][j].getPosition().getX() == i);
            assert(c.plateau[i][j].getPosition().getY() == j);

        }
    }

    std :: cout << "test d'initalisation du plateau OK" << endl;

    //Test des CoupsPossibles
    //test des pions

    //test des pions noirs du plateau
    for (int i = 1; i < 9; i++) {
        vector <Coup> coupsPionsNoirs = coupsPossibles(c.plateau[i][2].getPosition());
        for (unsigned int j = 0; j < coupsPionsNoirs.size(); j++)
        {
            assert(coupsPionsNoirs.size() == 2);
            //assert(positionfinale(coupsPionsNoirs[0]) == Vec2(i, 4));
            //assert(positionfinale(coupsPionsNoirs[1]) == Vec2(i, 3));
        }
    }

    std :: cout << "pas de probleme avec les coups possibles des pions noirs" << endl;

    //test des tours noirs du plateau
    //vector <Coup> coupsToursNoirs = coupsPossibles(c.plateau[1][1].getPosition());

    

    
}
