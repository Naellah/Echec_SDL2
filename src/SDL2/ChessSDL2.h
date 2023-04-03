#ifndef CHESSSDL2_H
#define CHESSSDL2_H




#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <iostream>
#include "../core/Chrono.h"
#include "../core/Vec2.h"
#include "../core/Joueur.h"
#include "../core/Piece.h"
#include "../core/ConfigJeu.h"



class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;

public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromFilePlateau (const char* filename, SDL_Renderer * renderer);

    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};














class ChessSDL2{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* piece;
        SDL_Event event;
        SDL_Rect rect;
        SDL_Surface* surface;
        TTF_Font* font; 
        SDL_Texture* texture;
        bool partie = true;

        Mix_Chunk* piece_sound;
        Mix_Chunk* echec_blanc;
        Mix_Chunk* echec_blanc_mat;
        Mix_Chunk* echec_noir;
        Mix_Chunk* echec_noir_mat;

        bool withSound;
        ConfigJeu configJeu;
        
        Image pionNoire ;
        Image pionBlanc ;
        Image tourNoire ;
        Image tourBlanc ;
        Image cavalierNoire ;
        Image cavalierBlanc ;
        Image fouNoire ;
        Image fouBlanc ;
        Image dameNoire ;
        Image dameBlanc ;
        Image roiNoire ;
        Image roiBlanc ;
        Image plateauImage ;
        Image ChessBackground;
        Image carre_bleu;
        Image carre_vert;


        Joueur joueur1;
        Joueur joueur2;
        



    public: 
        
    // Constructeur
    ChessSDL2();

    // Destructeur
     ~ChessSDL2();

   

    void afficherPlateauSDL2();

    //affiche

       

    //void nettoyer(){
    

    void afficherMenu();

    void SDL2Boucle();

    void drawText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y);

    void drawTextBleu(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y);

    void drawNom();

    void drawVainqueur();

    string saisirTexte(SDL_Renderer* renderer, TTF_Font* font, const std::string& message);



        //affiche toutes les pieces
    void afficherPiecesSDL2();

    void afficherParametres();

    void afficherChrono(const Joueur& j);

    void saisirNomsJoueurs();

    void echecAllSDL2();

    void SDL2coupPossibles();

    void affichercarre(vector <Coup> &cp);

    void Initjoueur();
   

    
};





#endif