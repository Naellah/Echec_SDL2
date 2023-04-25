#include "Chrono.h"

Chrono::Chrono() : m_enPause(false), m_timeStart(std::chrono::system_clock::now()), m_timePause(m_timeStart), 
m_dureePause(std::chrono::duration<unsigned int>::zero()), m_tempsHeures(0), m_tempsMinutes(0), m_tempsSecondes(0) {}

void Chrono::start() {
    if (m_enPause) {
    // Si le chrono est en pause, on ajoute la durée de la pause à la durée totale des pauses
        m_dureePause += std::chrono::duration_cast<std::chrono::duration<unsigned int>>(std::chrono::system_clock::now() - m_timePause);
        m_enPause = false;
    }
}

void Chrono::pause() {
    if (!m_enPause) {
    // Si le chrono n'est pas en pause, on enregistre le temps de pause
        m_timePause = std::chrono::system_clock::now();
        m_enPause = true;
    }
}

void Chrono::resume() {
    if (m_enPause) {
    // Si le chrono est en pause, on ajoute la durée de la pause à la durée totale des pauses
        m_dureePause += std::chrono::duration_cast<std::chrono::duration<unsigned int>>(std::chrono::system_clock::now() - m_timePause);
        m_enPause = false;
    }
}

void Chrono::reset() {
    m_enPause = false;
    m_timeStart = std::chrono::system_clock::now();
    m_timePause = m_timeStart;
    m_dureePause = std::chrono::duration<unsigned int>::zero();
    m_tempsHeures = 0;
    m_tempsMinutes = 0;
    m_tempsSecondes = 0;
}

void Chrono::setTime(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    m_tempsHeures = hours;
    m_tempsMinutes = minutes;
    m_tempsSecondes = seconds;
    mettreAJour();
}

void Chrono::ajouterTemps(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    m_tempsHeures += hours;
    m_tempsMinutes += minutes;
    m_tempsSecondes += seconds;
    mettreAJour();
}

void Chrono::retirerTemps(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    if (m_tempsHeures >= hours && m_tempsMinutes >= minutes && m_tempsSecondes >= seconds) {
        m_tempsHeures -= hours;
        m_tempsMinutes -= minutes;
        m_tempsSecondes -= seconds;
        mettreAJour();
    }   
}

void Chrono::mettreAJour() {
    if (!m_enPause) {
        // On calcule la durée écoulée depuis le début du chrono en enlevant la durée totale des pauses
        std::chrono::duration<unsigned int> duree = std::chrono::duration_cast<std::chrono::duration<unsigned int>>(std::chrono::system_clock::now() - m_timeStart - m_dureePause);


        // On ajoute le temps correspondant à cette durée aux heures, minutes et secondes du chrono
        unsigned int totalSecondes = duree.count();
        m_tempsHeures = totalSecondes / 3600;
        m_tempsMinutes = (totalSecondes % 3600) / 60;
        m_tempsSecondes = totalSecondes % 60;
    }   
}

unsigned int Chrono::getHeures() const {
    return m_tempsHeures;
}

unsigned int Chrono::getMinutes() const {
    return m_tempsMinutes;
}

unsigned int Chrono::getSecondes() const {
    return m_tempsSecondes;
}


