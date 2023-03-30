#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <cstdlib>
#include <iomanip>

#include "../core/Vec2.h"
#include "../core/Joueur.h"
#include "../core/Piece.h"
#include "../core/ConfigJeu.h"
#include "../core/Classement.h"





using namespace std;

int main() {
    // Boucle de jeu
    //Vec2 v1(1,2);
    //v1.testRegressionVec2();
    //Piece p1;
    //p1.testRegressionPiece();

    ConfigJeu jeu;
    jeu.initConfigJeu();
    //jeu.testRegressionConfigJeu();

    

    
    //j1.testRegressionJoueur();

    //Classement c1;
    //c1.testRegressionClassement();
    
    
    char action;
    string os_name;
   
    #ifdef _WIN32
        os_name = "Windows";
        
    #elif __APPLE__
        os_name = "MacOS";
    #elif __linux__
        os_name = "Linux";
    #else   
        os_name = "Inconnue";
    #endif

    string nom1;
    string nom2;
    Joueur j1;
    Joueur j2;
    Couleur jouerpremier;
    Piece tempo;

    char p1[2];
    char p2[2];

    bool commencez = false;
    if (os_name == "Windows") {
        system("cls");
    }   
    else{
        system("clear");
    }
    
    vector <Coup> couptxt;

    cout << "Bienvenue dans Chess !" << endl;
    while (true){
        cout << endl << "Que voulez-vous faire ?" << endl;
        cout << "1. Jouer" << endl;
        cout << "2. Quitter" << endl;
        int choix;
        cin >> choix;
        switch (choix) {
            case 1:
                cout << "Lancement du jeu..." << endl;
                cout << "Choisissez le nom du joueur 1"  << endl;
                bool isNumber;
                do{
                    getline(cin, nom1);
                    isNumber = true;
                    for (char c : nom1) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                        }
                    }
                    if (isNumber) {
                    cout << "Le nom rentree ne doit pas etre un nombre." << std::endl;
                    }
                } while (isNumber);
                
                
                cout << "Choisissez le nom du joueur 2"  << endl;
                do{
                    getline(cin, nom2);
                    isNumber = true;
                    for (char c : nom2) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                        }
                    }
                    if (isNumber) {
                    cout << "Le nom rentre ne doit pas etre un nombre." << std::endl;
                    }
                }while (isNumber);
            
                jouerpremier =  aleatoireCouleur();
                j1.setNom(nom1);
                j1.setCouleur(jouerpremier);
                j2.setNom(nom2);
                if (jouerpremier == Couleur::BLANC) {
                    j2.setCouleur(Couleur::NOIR);
                }
                else {
                    j2.setCouleur(Couleur::BLANC);
                }
                
                cout << j1.getNom() << " Vous etes les" << j1.getCouleurString() <<"s ."<<" ";
                if (j1.getCouleur() == Couleur::BLANC) {
                    cout << "Vous commencez donc la partie." << endl;
                }else {cout << endl;}
                cout << j2.getNom() << " Vous etes les" << j2.getCouleurString() <<"s ."<<" ";
                
                if (j2.getCouleur() == Couleur::BLANC) {
                    cout << "Vous commencez donc la partie." << endl;
                }else {cout << endl;}
                cout << endl;
               
               
               
                while (commencez != true)
                {
                    cout << "Appuyer sur c pour commencez votre partie." << endl;
                    if((action=getchar()) == 'c' || (action=getchar()) == 'C'){
                        commencez = true;
                    }
                } 
                
                
                while (true) {
                //Effacer la console
                    
                    if (os_name == "Windows") {
                    system("cls");
                    }   
                    else {
                        system("clear");
                    }
                    
                  
                    
                    

                    // Affichage du plateau
                    jeu.afficherPlateauTxt();


                
                   // affiche le nom du joueur qui doit jouer
                    if (jeu.getJoueurCourant() == Couleur::BLANC) {
                        cout << " C'est a " << j1.getNom() << " de jouer." << endl;
                    }
                    else {
                        cout << " C'est a " << j2.getNom() << " de jouer." << endl;
                    }
                    
                   
                    
                    //rentre la position de la piece a deplacer et demande à l'utilisateur s'il est sur de vouloir deplacer la piece
                    cout << "Rentrez la position de la piece que vous voulez deplacer (ex: a1)" << endl;
                    cin >> p1[0] >> p1[1];
                        
                    cout << jeu.recuperePosition(p1[0],p1[1]).getX() << jeu.recuperePosition(p1[0],p1[1]).getY() << endl;
                    //affiche toutes les informations de la piece selectionner
                    cout << "Voici les informations de la piece que vous avez choisi :" << endl;
                    cout << "Type de la piece : " << jeu.getPiece(jeu.recuperePosition(p1[0],p1[1])).getType() << endl;
                    cout << "Couleur de la piece : " << jeu.getPiece(jeu.recuperePosition(p1[0],p1[1])).getCouleur() << endl;
                    cout << "Position de la piece : " << jeu.getPiece(jeu.recuperePosition(p1[0],p1[1])).getPosition().getX() << " " << jeu.getPiece(jeu.recuperePosition(p1[0],p1[1])).getPosition().getY() << endl;

            
                    couptxt = jeu.coupsPossibles(jeu.recuperePosition(p1[0],p1[1]));
                    cout << "Voici les coups possibles pour cette piece :" << endl;
                    for (unsigned int i = 0; i < couptxt.size(); i++) {
                        cout << couptxt[i].deplacement.getX() << " " << couptxt[i].deplacement.getY() << endl;
                    }
                    if (couptxt.size() == 0) {
                        cout << "Cette piece ne peut pas se deplacer." << endl;
                    }
                  
                   
                   
                   
                    cout << "Rentrez la nouvelle position de la piece que vous avez choisi (ex: b2)" << endl;
                    cin >> p2[0] >> p2[1];
                    //change la position de la piece selectionner avec les nouvelle coordonnées
                    jeu.deplacePiece(Coup(jeu.recuperePosition(p1[0],p1[1]),jeu.recuperePosition(p2[0],p2[1])));
                    //change le joueur courant
                    jeu.setJoueurCourant();
                    



                    //affiche le nom du joueur qui doit jouer et il doit appuiyer sur c pour passer au tour suivant
                    cout << "Appuyer sur c pour passer au tour suivant." << endl;
                    if ((action=getchar()) == 'c' || (action=getchar()) == 'C') {
                        continue;
                    }




                    if((action=getchar()) == 'q'){
                        break;
                    }
        
                }       
                break;
            
            
            case 2:
                cout << "Voulez vous vraiment quitter ? (o/n)" << endl;
                cin >> action;
                switch (action) {
                    case 'o':
                    case 'O':
                        cout << "Au revoir !" << endl;
                        return 0;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        cout << "Choix invalide. Veuillez entrer o ou n." << endl;
                        break;
                }

            default:
                cout << "Choix invalide. Veuillez entrer 1 ou 2." << endl;
                break;
            }
        }
   
    return 0;
}


