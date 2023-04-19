#pragma once
#include <chrono>
#include "Piece.h"

class Chrono {

public:
    /**
    * @brief initialisation à 0
    */
    Chrono();

    /**
    * @brief démarrer le chrono
    */
    void start();

    /**
    * @brief mettre en pause le chrono
    */
    void pause();

    /**
    * @brief reprendre le chrono après une pause
    */
    void resume();

    /**
    * @brief remettre le chrono à 0
    */
    void reset();

    /**
    * @brief initialiser le chrono avec un temps donné
      @param hours : correspond aux heures du chrono
      @param minutes : correspond aux minutes du chrono
      @param seconds : correspond aux secondes du chrono
    */
    void setTime(unsigned int hours, unsigned int minutes, unsigned int seconds);

    /**
    * @brief ajouter du temps au chrono
      @param hours : correspond aux heures ajoute au chrono
      @param minutes : correspond aux minutes ajoute au chrono
      @param seconds : correspond aux secondes ajoute au chrono
    */
    void ajouterTemps(unsigned int hours, unsigned int minutes, unsigned int seconds);

    /**
    * @brief retirer du temps au chrono
      @param hours : correspond aux heures enleve au chrono
      @param minutes : correspond aux minutes enleve au chrono
      @param seconds : correspond aux secondes enleve au chrono
    */
    void retirerTemps(unsigned int hours, unsigned int minutes, unsigned int seconds);

    /**
    * @brief mettre à jour le temps du chrono en fonction du temps écoulé depuis la dernière mise à jour
    */
    void mettreAJour();

    /**
    * @brief obtenir le nombre d'heures écoulées depuis le début du chrono
    */
    unsigned int getHeures() const;

    /**
    * @brief obtenir le nombre de minutes écoulées depuis le début du chrono
    */
    unsigned int getMinutes() const;

    /**
    * @brief obtenir le nombre de secondes écoulées depuis le début du chrono
    */
    unsigned int getSecondes() const;


private:
    /**
    * @brief vrai si le chrono est en pause, faux sinon
    */
    bool m_enPause;
    /**
    * @brief  temps de départ du chrono
    */
    std::chrono::system_clock::time_point m_timeStart;
    /**
    * @brief temps de la dernière mise en pause du chrono
    */
    std::chrono::system_clock::time_point m_timePause;
    /**
    * @brief durée totale des pauses du chrono
    */
    std::chrono::duration<unsigned int> m_dureePause;

    /**
    * @brief  nombre d'heures écoulées depuis le début du chrono
    */
    unsigned int m_tempsHeures;
    /**
    * @brief nombre de minutes écoulées depuis le début du chrono
    */
    unsigned int m_tempsMinutes;
    /**
    * @brief nombre de secondes écoulées depuis le début du chrono
    */
    unsigned int m_tempsSecondes;
};

