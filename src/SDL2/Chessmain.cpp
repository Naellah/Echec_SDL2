
#define SDL_MAIN_HANDLED


#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>

#include "../core/Piece.h"
#include "../core/Vec2.h"
#include "../core/Joueur.h"
#include "../core/ConfigJeu.h"
#include "../core/Classement.h"
#include "ChessSDL2.h"




int main() {
    ChessSDL2 jeu;
    jeu.SDL2Boucle();
    
    
    return 0;
}


