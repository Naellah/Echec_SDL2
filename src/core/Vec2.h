#ifndef VEC2_H
#define VEC2_H

class Vec2 {
private:
    /**
    * @brief coordonnee x du vecteur
    */
    int x;

    /**
    * @brief coordonnee y du vecteur
    */
    int y;

public:
    /**
    * @brief constructeur par défaut
    */
    Vec2();

    /**
    * @brief constructeur avec des arguments
      @param _x : correspond a la coordonnee x
      @param _y : correspond a la coordonnee y
    */
    Vec2(int _x, int _y);

    /**
    * @brief assesseur de x
    */
    int getX()const;

    /**
    * @brief assesseur de y
    */
    int getY()const;

    /**
    * @brief mutateur de x
      @param _x : correspond a la nouvelle coordonnee x
    */
    void setX(int _x);

    /**
    * @brief mutateur de y
      @param _y : correspond a la nouvelle coordonnee y
    */
    void setY(int _y);

    /**
    * @brief operateur d'addition entre 2 vecteurs
      @param other : correspond a un vecteur
    */
    Vec2 operator+(const Vec2& other) const;

    /**
    * @brief operateur de soustraction entre 2 vecteurs
      @param other : correspond a un vecteur
    */
    Vec2 operator-(const Vec2& other) const;

    /**
    * @brief operateur d'affection
      @param other : correspond a un vecteur
    */
    Vec2& operator=(const Vec2& other);

    /**
    * @brief operateur d'egalite entre 2 vecteurs
      @param other : correspond a un vecteur
    */
    bool operator==(const Vec2& other)const;

    /**
    * @brief operateur de differance entre 2 vecteurs
      @param other : correspond a un vecteur
    */
    bool operator!=(const Vec2& other)const;

    /**
    * @brief modifie les valeur x et y d'un vecteur
      @param a : correspond a la nouvelle valeur de la coordonnee x
      @param _b : correspond a la nouvelle valeur de la coordonnee y
    */
    void setVec2(int a, int _b);

    /**
    * @brief test de regression de la classe vecteur
    */
    void testRegressionVec2()const;


};



#endif
