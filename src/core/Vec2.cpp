
#include <assert.h>
#include <iostream>

#include "Vec2.h"

using namespace std;


Vec2 ::Vec2() : x(0), y(0){}

Vec2 :: Vec2(int _x, int _y){
    x=_x;
    y=_y;

}

int Vec2:: getX()const{
    return x;
}
    //assesseur de y
int Vec2:: getY()const{
    return y;
}

 void Vec2:: setX(int _x){
    x = _x;
}
    
void Vec2:: setY(int _y){
    y = _y;
}   

Vec2 Vec2:: operator+(const Vec2& other) const {
    return {x + other.x, y + other.y};
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return {x - other.x, y - other.y};
}

 bool Vec2::operator==( const Vec2& other)const{
    return x==other.x && y==other.y;
}

Vec2& Vec2::operator=(const Vec2& other){
    x = other.x;
    y = other.y;
    return *this;
}

void Vec2 :: setVec2(int a, int _b){
    x = a;
    y = _b;
}


void Vec2 :: testRegressionVec2()const{
    //test toutes les fonctions
    Vec2 v1(1,2);
    Vec2 v2(3,4);
    Vec2 v3(1,2);
    //appel des fonctions
    assert(v1.getX() == 1);
    assert(v1.getY() == 2);
    assert(v2.getX() == 3);
    assert(v2.getY() == 4);
    assert(v3.getX() == 1);
    assert(v3.getY() == 2);
    //test de l'operateur +
    assert((v1+v2).getX() == 4);
    assert((v1+v2).getY() == 6);
    //test de l'operateur -
    assert((v2-v1).getX() == 2);
    assert((v2-v1).getY() == 2);
    //test de l'operateur ==
    assert(v1==v3);
    //test de l'operateur =
    v1 = v2;
    assert(v1.getX() == 3);
    assert(v1.getY() == 4);
    //test de la fonction setVec2
    v1.setVec2(5,6);
    assert(v1.getX() == 5);
    assert(v1.getY() == 6);
    //test de la fonction setX
    v1.setX(7);
    assert(v1.getX() == 7);
    //test de la fonction setY
    v1.setY(8);
    assert(v1.getY() == 8);
    //test de la fonction getX
    assert(v1.getX() == 7);
    //test de la fonction getY
    assert(v1.getY() == 8);
    //test du constructeur par défaut
    Vec2 v4;
    assert(v4.getX() == 0);
    assert(v4.getY() == 0);
    //test du constructeur avec des arguments
    Vec2 v5(9,10);
    assert(v5.getX() == 9);
    assert(v5.getY() == 10);
    cout << "testRegressionVec2 Ok" << endl;
}