#ifndef TESTDEBUG_H
#define TESTDEBUG_H

#include <iostream>

class Testdebug{

private:
    ChessSDL2 sdl2;

public:
    
    Testdebug();
    ~Testdebug();

    ChessSDL2 getChesssdl2()const;

    void affichecarre(const Vec2& p);

    void test();

    void afficher();

    void coupAuto();

    void partieAuto();


};

#endif