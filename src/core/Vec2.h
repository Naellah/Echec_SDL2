#ifndef VEC2_H
#define VEC2_H

class Vec2{
    private:  
    int x;
    int y;

    
    public:
    //constructeur par défaut
    Vec2();
    //constructeur avec des arguments
    
    Vec2(int _x, int _y);

    //assesseur de x
    int getX()const;
    
    //assesseur de y
    int getY()const;

    //mutateur de x
    void setX(int _x);

    //mutateur de y
    void setY(int _y);


    

    Vec2 operator+(const Vec2& other) const;
       
    

    Vec2 operator-(const Vec2& other) const;

    Vec2& operator=(const Vec2& other);
       

    bool operator==( const Vec2& other)const;

    bool operator!=( const Vec2& other)const;
    
    void setVec2(int a, int _b);

    void testRegressionVec2()const;


};



#endif
