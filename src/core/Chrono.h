#pragma once
#include <chrono>
#include "Piece.h"

class Chrono {

public:
    Chrono(); // initialisation à 0

    void start(); // démarrer le chrono

    void pause(); // mettre en pause le chrono

    void resume(); // reprendre le chrono après une pause

    void reset(); // remettre le chrono à 0

    void setTime(unsigned int hours, unsigned int minutes, unsigned int seconds); // initialiser le chrono avec un temps donné

    void ajouterTemps(unsigned int hours, unsigned int minutes, unsigned int seconds); // ajouter du temps au chrono

    void retirerTemps(unsigned int hours, unsigned int minutes, unsigned int seconds); // retirer du temps au chrono

    void mettreAJour(); // mettre à jour le temps du chrono en fonction du temps écoulé depuis la dernière mise à jour

    unsigned int getHeures() const; // obtenir le nombre d'heures écoulées depuis le début du chrono

    unsigned int getMinutes() const; // obtenir le nombre de minutes écoulées depuis le début du chrono

    unsigned int getSecondes() const; // obtenir le nombre de secondes écoulées depuis le début du chrono


private:

    bool m_enPause; // vrai si le chrono est en pause, faux sinon

    
    std::chrono::system_clock::time_point m_timeStart; // temps de départ du chrono
    std::chrono::system_clock::time_point m_timePause; // temps de la dernière mise en pause du chrono
    std::chrono::duration<unsigned int> m_dureePause; // durée totale des pauses du chrono

    unsigned int m_tempsHeures; // nombre d'heures écoulées depuis le début du chrono
    unsigned int m_tempsMinutes; // nombre de minutes écoulées depuis le début du chrono
    unsigned int m_tempsSecondes; // nombre de secondes écoulées depuis le début du chrono
};
