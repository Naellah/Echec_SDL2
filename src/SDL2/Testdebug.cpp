#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <string>

#include <iostream>
#include "../core/Chrono.h"

#include "../core/Vec2.h"
#include "../core/Joueur.h"
#include "../core/Piece.h"
#include "../core/ConfigJeu.h"
#include "../core/Classement.h"
#include "ChessSDL2.h"
#include "Testdebug.h"


Testdebug :: Testdebug() {
    sdl2.Initjoueur();
}

Testdebug :: ~Testdebug() {}


ChessSDL2 Testdebug::getChesssdl2()const{
    return sdl2;
}


void Testdebug::affichecarre(const Vec2 & p) {
    SDL_RenderClear(sdl2.getRenderer());
    sdl2.afficherPlateauSDL2();
    vector <Coup> coupSDL2 = sdl2.getConfigJeu().coupsPossibles(p);
    for (int k = 0; k < coupSDL2.size(); k++) {
        SDL_Rect recta;
        recta.x = 57 + 85 * (coupSDL2[k].deplacement.getX() - 1);
        recta.y = 55 + 85 * (coupSDL2[k].deplacement.getY() - 1);
        recta.w = 83;
        recta.h = 83;
        if (sdl2.getConfigJeu().getPiece(coupSDL2[k].deplacement).getCouleur() != Couleur::VIDEC) {
            sdl2.getCarreVert().draw(sdl2.getRenderer(), recta.x, recta.y, recta.h, recta.w);
        }
        else
            sdl2.getCarreBleu().draw(sdl2.getRenderer(), recta.x, recta.y, recta.h, recta.w);
    }
    sdl2.afficherPiecesSDL2();
    sdl2.drawNom();
    sdl2.drawinfo();
    SDL_RenderPresent(sdl2.getRenderer());
    SDL_Delay(1500);
}



void Testdebug :: afficher(){
    SDL_RenderClear(sdl2.getRenderer());
    sdl2.afficherPlateauSDL2();
    sdl2.afficherPiecesSDL2();
    sdl2.drawNom();
    sdl2.drawinfo();
    SDL_RenderPresent(sdl2.getRenderer());
    SDL_Delay(1500);
    sdl2.echecAllSDL2();

    SDL_Delay(150);
    if (sdl2.getConfigJeu().EchecEtMatNoir() || sdl2.getConfigJeu().EchecEtMatBlanc()) {
        sdl2.drawVainqueur();
        SDL_Delay(5000);
        exit(0);
    }


}


void Testdebug::coupAuto() {
    sdl2.getJoueur1().setNomBot1();
    sdl2.getJoueur2().setNomBot2();
    SDL_Delay(2000);
    affichecarre(Vec2(6, 7));
    sdl2.getConfigJeu().deplacePiece(Coup(Vec2(6,7),Vec2(6,6)));
    afficher();
    affichecarre(Vec2(5, 2));
    sdl2.getConfigJeu().deplacePiece(Coup(Vec2(5,2),Vec2(5,3)));
    afficher();
    affichecarre(Vec2(7, 7));
    sdl2.getConfigJeu().deplacePiece(Coup(Vec2(7,7),Vec2(7,5)));
    afficher();
    affichecarre(Vec2(4, 1));
    sdl2.getConfigJeu().deplacePiece(Coup(Vec2(4,1),Vec2(8,5)));
    afficher();
}



void Testdebug::partieAuto() {
    SDL_RenderClear(sdl2.getRenderer());
	sdl2.afficherPlateauSDL2();
	sdl2.afficherPiecesSDL2();
	sdl2.drawNom();
    sdl2.drawinfo();
	SDL_RenderPresent(sdl2.getRenderer());
    coupAuto();
    SDL_Delay(2000);

}