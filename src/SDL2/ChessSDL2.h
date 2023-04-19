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

    SDL_Surface* m_surface;
    SDL_Texture* m_texture;
    bool m_hasChanged;

public:
    Image();
    ~Image();
    void loadFromFile(const char* filename, SDL_Renderer* renderer);
    void loadFromFilePlateau(const char* filename, SDL_Renderer* renderer);

    void loadFromCurrentSurface(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer, int x, int y, int w = -1, int h = -1);
    SDL_Texture* getTexture() const;
    void setSurface(SDL_Surface* surf);
};






class ChessSDL2 {
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

    Image pionNoire;
    Image pionBlanc;
    Image tourNoire;
    Image tourBlanc;
    Image cavalierNoire;
    Image cavalierBlanc;
    Image fouNoire;
    Image fouBlanc;
    Image dameNoire;
    Image dameBlanc;
    Image roiNoire;
    Image roiBlanc;
    Image plateauImage;
    Image ChessBackground;
    Image carre_bleu;
    Image carre_vert;


    Joueur joueur1;
    Joueur joueur2;




public:

    /**
    * @brief constructeur
    */
    ChessSDL2();

    /**
    * @brief destructeur
    */
    ~ChessSDL2();


    /**
    * @brief affiche le plateau
    */
    void afficherPlateauSDL2();

    //void nettoyer(){

    /**
    * @brief affiche le menu
    */
    void afficherMenu();

    /**
    * @brief affiche le tout
    */
    void SDL2Boucle();


    /**
    * @brief permet d'afficher le texte
      @param font : est une police de caractere
      @param text : le message a afficher
      @param x : est la coordonnee x du texte
      @param y : est la coordonnee y du texte
    */
    void drawText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y);

    /**
    * @brief permet d'afficher le texte en bleu
      @param font : est une police de caractere
      @param text : le message a afficher
      @param x : est la coordonnee x du texte
      @param y : est la coordonnee y du texte
    */
    void drawTextBleu(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y);

    /**
    * @brief ecrit le nom des joueur
    */
    void drawNom();

    /**
    * @brief ecrit le joueur qui a gagne
    */
    void drawVainqueur();

    /**
    * @brief permet de gerer la saisie de texte
      @param : font est une police de caractere
      @param : message est le message a afficher
    */
    string saisirTexte(SDL_Renderer* renderer, TTF_Font* font, const std::string& message);



    /**
    * @brief affiche toute les pieces
    */
    void afficherPiecesSDL2();

    /**
    * @brief affiche les parametre
    */
    void afficherParametres();

    /**
    * @brief affiche le chrono
    */
    void afficherChrono(const Joueur& j);

    /**
    * @brief permet de gerer la saisie des noms des joueur
    */
    void saisirNomsJoueurs();

    /**
    * @brief permet de prevenir si un des 2 roi est en echec ou en echec et mat
    */
    void echecAllSDL2();

    /**
    * @brief trouve les coups possible en sdl2
    */
    void SDL2coupPossibles();

    /**
    * @brief affiche l'image des coups possible
    */
    void affichercarre(vector <Coup>& cp);

    /**
    * @brief initialise les joueur
    */
    void Initjoueur();



};





#endif