



#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include "../core/Chrono.h"

#include "../core/Vec2.h"
#include "../core/Joueur.h"
#include "../core/Piece.h"
#include "../core/ConfigJeu.h"
#include "../core/Classement.h"
#include "ChessSDL2.h"


using namespace std;



Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile(const char* filename, SDL_Renderer* renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load " << filename << ". Trying " << nfn << endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout << "Error: cannot load " << filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface* surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface, SDL_PIXELFORMAT_ARGB8888 , 0);
    SDL_FreeSurface(m_surface);
    m_surface = nullptr;

    m_texture = SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    SDL_FreeSurface(surfaceCorrectPixelFormat);
    surfaceCorrectPixelFormat = nullptr;

    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
        exit(1);
    }

}



void Image::loadFromFilePlateau (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}







void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;
    assert(renderer != nullptr);
    assert(m_texture != nullptr && "Error: texture is null" );
    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }
   
    assert(m_texture != nullptr);
   
    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}






ChessSDL2 :: ChessSDL2(){
    // mets les valeurs par défaut
    window = NULL;
    renderer = NULL;
    piece = NULL;
    texture = NULL;
    font = NULL;
    surface = NULL;
    rect = {0, 0, 0, 0};
    configJeu.initConfigJeu();
    event = SDL_Event();

     if(SDL_Init(SDL_INIT_VIDEO) != 0){
       cout << "Erreur d'initialisation de la SDL" << endl;
       SDL_Quit();
       exit(EXIT_FAILURE);
   }


   if(TTF_Init() != 0){
       cout << "Erreur d'initialisation de la SDL_ttf" << endl;
       SDL_Quit();
       exit(EXIT_FAILURE);
   }


   if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
       cout << "Erreur d'initialisation de la SDL_image" << endl;
       SDL_Quit();
       exit(EXIT_FAILURE);
   }

   

   
   


   SDL_DisplayMode displayMode;
   SDL_GetCurrentDisplayMode(0, &displayMode);

   int screenWidth = displayMode.w;
   int screenHeight = displayMode.h;
   SDL_SetWindowPosition(window, (displayMode.w - screenWidth) / 2, (displayMode.h - screenHeight) / 2);
   SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

   window = SDL_CreateWindow("ChessNP", (screenWidth - 844) / 2, (screenHeight - 793) / 2, 844, 793, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   if (window == NULL) {
       cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError()
           << endl;
       SDL_Quit();
   }

   


   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   if (renderer == NULL) {
       cout << "Erreur lors de la creation du rendu : " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
       SDL_Quit();
       exit(EXIT_FAILURE);
   }

  

    plateauImage.loadFromFilePlateau("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\plateau.png",renderer);
    ChessBackground.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\Chess_background.png",renderer);
    carre_bleu.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\carre_blue.png",renderer);

    pionNoire.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/black_pawn.png",renderer);
    assert(pionNoire.getTexture() != nullptr);
    tourNoire.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/black_rook.png",renderer);
    assert(tourNoire.getTexture() != nullptr);
    cavalierNoire.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/black_knight.png",renderer);
    assert(cavalierNoire.getTexture() != nullptr);
    fouNoire.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/black_bishop.png",renderer);
    assert(fouNoire.getTexture() != nullptr);
    dameNoire.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/black_queen.png",renderer);
    assert(dameNoire.getTexture() != nullptr);
    roiNoire.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/black_king.png",renderer);
    assert(roiNoire.getTexture() != nullptr);
    pionBlanc.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/white_pawn.png",renderer);
    assert(pionBlanc.getTexture() != nullptr);
    tourBlanc.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/white_rook.png",renderer);
    assert(tourBlanc.getTexture() != nullptr);
    cavalierBlanc.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/white_knight.png",renderer);
    assert(cavalierBlanc.getTexture() != nullptr);
    fouBlanc.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/white_bishop.png",renderer);
    assert(fouBlanc.getTexture() != nullptr);
    dameBlanc.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/white_queen.png",renderer);
    assert(dameBlanc.getTexture() != nullptr);
    roiBlanc.loadFromFile("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\/white_king.png",renderer);
    assert(roiBlanc.getTexture() != nullptr);

    //charge la police
    font = TTF_OpenFont("C:\\Users\\naell\\Documents\\Code\\Echecs\\chess\\data\\font.ttf", 20);
   

}


ChessSDL2 :: ~ChessSDL2(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}





  







void ChessSDL2::afficherPlateauSDL2() {
    //SDL_RenderClear(renderer);
    plateauImage.draw(renderer,0,25,794,743);
    
}



// Fonction pour dessiner un texte à l'écran

void ChessSDL2::drawText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y)
{
    SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), { 255, 255, 255, 255 });
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_Rect rect = { x, y, surf->w, surf->h };
    SDL_RenderCopy(renderer, tex, nullptr, &rect);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
}



void ChessSDL2::afficherMenu()
{
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (x >= 300 && x <= 450 && y >= 180 && y <= 220)
                    {
                        cout << "Jouer" << endl;
                        running = false;
                     
                    }
                    else if (x >= 300 && x <= 600 && y >= 280 && y <= 320)
                    {
                        cout << "Charger Partie" << endl;
                        // Charger Partie pas encore fait 
                    }
                    else if (x >= 300 && x <= 600 && y >= 380 && y <= 420)
                    {
                        cout << "Parametres" << endl;
                        // afficherParametres() pas encore fait
                    }
                    else if (x >= 300 && x <= 600 && y >= 480 && y <= 520)
                    {
                        cout << "Quitter" << endl;
                        running = false;
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                    }
                }
                break;
            }
        }

        SDL_RenderClear(renderer);
        ChessBackground.draw(renderer, 0, 0, 844, 793);

        // Dessine le texte des options du menu
        drawText(renderer, font, "Jouer", 300, 200);
        drawText(renderer, font, "Charger Partie", 300, 300);
        drawText(renderer, font, "Parametres", 300, 400);
        drawText(renderer, font, "Quitter", 300, 500);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}


void ChessSDL2 :: afficherParametres(){
    
}


void ChessSDL2::afficherPiecesSDL2() {
    //SDL_RenderClear(renderer); // enlever dans la fonction qui marche
    rect = { 57, 55, 83, 83 };
    // parcours le plateau du configJeu et met un case pour chaque piece
    for (int i = 1 ; i<9; i++){
        //met en couleur verte les indices de colonnes
        for (int j = 1; j < 9; j++){
            
            
            switch(configJeu.getPlateau()[j][i].getCouleur()){
                
                case Couleur::BLANC:
                    switch(configJeu.getPlateau()[j][i].getType()){
                        //on affiche les pieces blanches en bleu
                        
                        case TypePiece::PION1:
                        case TypePiece::PION2:
                        case TypePiece::PION3:
                        case TypePiece::PION4:
                        case TypePiece::PION5:
                        case TypePiece::PION6:
                        case TypePiece::PION7:
                        case TypePiece::PION8:

                            pionBlanc.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;

                        case TypePiece::TOUR1:
                        case TypePiece::TOUR2:
                            tourBlanc.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::CAVALIER1:
                        case TypePiece::CAVALIER2:
                            cavalierBlanc.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::FOU1:
                        case TypePiece::FOU2:
                            fouBlanc.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::DAME:
                            dameBlanc.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::ROI:
                            roiBlanc.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
            


                        default:    
                            break;
                    }
                    break;

                case Couleur::NOIR:
                    switch(configJeu.getPlateau()[j][i].getType()){
                       
                        case TypePiece::PION1:
                        case TypePiece::PION2:
                        case TypePiece::PION3:
                        case TypePiece::PION4:
                        case TypePiece::PION5:
                        case TypePiece::PION6:
                        case TypePiece::PION7:
                        case TypePiece::PION8:
                            pionNoire.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;

                        case TypePiece::TOUR1:
                        case TypePiece::TOUR2:
                            tourNoire.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::CAVALIER1:
                        case TypePiece::CAVALIER2:
                            cavalierNoire.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::FOU1:
                        case TypePiece::FOU2:
                            fouNoire.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::DAME:
                            dameNoire.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;
                        
                        case TypePiece::ROI:
                            roiNoire.draw(renderer, rect.x, rect.y, rect.h, rect.w);
                            break;  
                        
                        default:
                            break;
                    }
                    break;
                    
                

                case Couleur::VIDEC:
                    break;
                
            }
            rect.x += 85;
          
        }
        rect.y += 85;
        rect.x = 57;

        
    }
    SDL_RenderPresent(renderer);
    
  
    
}








void ChessSDL2:: afficherChrono(const Joueur& j) {
    string temps_str = to_string(j.getChrono().getHeures()) + ":" + to_string(j.getChrono().getMinutes()) + ":" + to_string(j.getChrono().getSecondes());

    if (j.getCouleur() == Couleur::BLANC) {
		drawText(renderer, font, temps_str, 396, 832);
	}
    else {
		drawText(renderer, font, temps_str, 396, 12);
	}


}




void ChessSDL2::SDL2coupPossibles() {
    vector<Coup> coupSDL2;
    SDL_Event event;
    SDL_Event event2;

    // Attend le premier clic de l'utilisateur
    SDL_WaitEvent(&event);

    // Parcourt le plateau si l'utilisateur a cliqué
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (configJeu.getPlateau()[i][j].getCouleur() == configJeu.getJoueurCourant()) {
                    // Vérifie si le clic est sur une pièce du joueur courant
                    if (event.button.x >= 57 + 85 * (i - 1) && event.button.x <= 57 + 85 * i && event.button.y >= 55 + 85 * (j - 1) && event.button.y <= 55 + 85 * j) {
                        // Affiche les coups possibles en dessinant des carrés bleus
                        coupSDL2 = configJeu.coupsPossibles(Vec2(i, j));
                        afficherPlateauSDL2();
                        
                        for (int k = 0; k < coupSDL2.size(); k++) {
                            SDL_Rect recta;
                            recta.x = 57 + 85 * (coupSDL2[k].deplacement.getX() - 1);
                            recta.y = 55 + 85 * (coupSDL2[k].deplacement.getY() - 1);
                            recta.w = 83;
                            recta.h = 83;
                            carre_bleu.draw(renderer, recta.x, recta.y, recta.h, recta.w);
                        }
                        afficherPiecesSDL2();
                        SDL_RenderPresent(renderer);

                        // Attend le deuxième clic de l'utilisateur pour mettre à jour le plateau
                        while (SDL_WaitEvent(&event2)) {
                            if (event2.type == SDL_MOUSEBUTTONDOWN && event2.button.button == SDL_BUTTON_LEFT) {
                                for (int k = 0; k < coupSDL2.size(); k++) {
                                    if (event2.button.x >= 57 + 85 * (coupSDL2[k].deplacement.getX() - 1) && event2.button.x <= 57 + 85 * coupSDL2[k].deplacement.getX() && event2.button.y >= 55 + 85 * (coupSDL2[k].deplacement.getY() - 1) && event2.button.y <= 55 + 85 * coupSDL2[k].deplacement.getY()) {
                                        configJeu.deplacePiece(coupSDL2[k]);
                                        break;
                                    }
                                }
                                coupSDL2.clear();
                                afficherPlateauSDL2();
                                afficherPiecesSDL2();
                                SDL_RenderPresent(renderer);
                                break;
                            }
                        }
                        
                        
                    }
                }
            }
        }
    }
}


void ChessSDL2::affichercarre(vector <Coup>& cp) {
    if (cp.size() > 0) {

        for (int k = 0; k < cp.size(); k++) {
            cout << cp[k].deplacement.getX() << " " << cp[k].deplacement.getY() << endl;
            SDL_Rect recta;
            recta.x = 57 + 85 * (cp[k].deplacement.getX() - 1);
            recta.y = 55 + 85 * (cp[k].deplacement.getY() - 1);
            recta.w = 83;
            recta.h = 83;
            carre_bleu.draw(renderer, recta.x, recta.y, recta.h, recta.w);
            //SDL_RenderPresent(renderer);
            cout << "bien dessiner" << endl;
        }

    }
    //vide le vecteur
    cp.clear();
    
}



void ChessSDL2::Initjoueur() {
    joueur1.setCouleur(aleatoireCouleur());
    if (joueur1.getCouleur() == Couleur::BLANC) {
        joueur2.setCouleur(Couleur::NOIR);
    }
    else {
        joueur2.setCouleur(Couleur::BLANC);
    }
}




void ChessSDL2::SDL2Boucle() {
    SDL_Event events;
    bool quit = false;
    

    joueur1.setCouleur(aleatoireCouleur());
    if (joueur1.getCouleur() == Couleur::BLANC) {
        joueur2.setCouleur(Couleur::NOIR);
    }
    else {
        joueur2.setCouleur(Couleur::BLANC);
    }



    vector <Coup> coupSDL2;
    afficherMenu();

  


    // Tant que ce n'est pas la fin ...
    while (!quit) {
        
        //afficherPlateauSDL2();
       

        /*
        if (configJeu.getJoueurCourant() == joueur1.getCouleur()) {
            joueur1.getChrono().resume();
            joueur2.getChrono().pause();
        }
        else {
            joueur2.getChrono().resume();
            joueur1.getChrono().pause();
        }*/



        // Tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) {
                quit = true;  // Si l'utilisateur a cliqué sur la croix de fermeture
            }
            if (events.type == SDL_KEYDOWN) {
                if (events.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;  // Si l'utilisateur appuie sur la touche Echap
                }
                else if (events.key.keysym.sym == SDLK_f) {
                    if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP) {
                        SDL_SetWindowFullscreen(window, 0);
                    }
                    else {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                }
            }
            
        }
        //affichercarre(coupSDL2);
        afficherPlateauSDL2();
        afficherPiecesSDL2();
        SDL2coupPossibles();
        SDL_RenderPresent(renderer);
       // On permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)

    }

}


