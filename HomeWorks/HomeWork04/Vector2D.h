

#ifndef HW4_CONTINUEDHW3_VECTOR2D_H
#define HW4_CONTINUEDHW3_VECTOR2D_H

#include <iostream>
#include <cmath>

// A class of vector, each vector have: <x,y>
class Vector2D {
private:
    // vector <x,y>
    double  x;
    double  y;

public:
    // constructors:

    // default constructor, x = 0, y = 0
    Vector2D();
    // constructor that gets x,y values
    Vector2D(double x, double y);

    // getters:

    // return the x location of the vector
    double  getX() const;
    // return the y location of the vector
    double  getY() const;

    // setters:

    // set the x location of the vector
    void    setX(double newX);
    // set the y location of the vector
    void    setY(double newY);


    // static function return the normalized vector ||(x,y)|| = sqrt(x^2, y^2)
    static double norma(double x, double y) ;

    // overloading operators:

    // operator that essay between two vectors: (𝑥1, 𝑦1) + (𝑥2, 𝑦2) = (𝑥1 + 𝑥2, 𝑦1 + 𝑦2)
    Vector2D    operator+(const Vector2D& vector) const;
    // operator that subtracting between two vectors: (𝑥1, 𝑦1) − (𝑥2, 𝑦2) = (𝑥1 − 𝑥2, 𝑦1 − 𝑦2)
    Vector2D    operator-(const Vector2D& vector) const;
    // operator that Internal multiplier between two vectors: (𝑥1, 𝑦1) ∙ (𝑥2, 𝑦2) = 𝑥1 ∗ 𝑥2 + 𝑦1 ∗ 𝑦2 : ∙ is the dot product operator
    double      operator*(const Vector2D& vector) const;
    // operator that multiplier between const number (scalar) and vector: c * (x, y) = (c * x, c * y)
    Vector2D    operator*(double scalar) const;
    // operator that placement this vector with other vector: x = x', y = y'
    Vector2D&   operator=(const Vector2D& vector);
    // operator that sums the essay between this vector and another vector: (𝑥1, 𝑦1) = (𝑥1, 𝑦1) + (𝑥2, 𝑦2)
    Vector2D&   operator+=(const Vector2D& vector);
    // operator that sums the subtraction between this vector and another vector: (𝑥1, 𝑦1) = (𝑥1, 𝑦1) - (𝑥2, 𝑦2)
    Vector2D&   operator-=(const Vector2D& vector);
    // operator that sums the multiplication between this vector and another vector: (𝑥1, 𝑦1) = (𝑥1, 𝑦1) * (𝑥2, 𝑦2)
    Vector2D&   operator*=(const Vector2D& vector);
    // operator that divide this vector with number: (𝑥\number, 𝑦\number)
    Vector2D    operator/(double number) const;
    // return true whether the vectors equals
    bool        operator==(const Vector2D& vector) const;

};


#endif //HW4_CONTINUEDHW3_VECTOR2D_H
