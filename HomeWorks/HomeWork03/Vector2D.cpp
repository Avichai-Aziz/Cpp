

#include "Vector2D.h"

Vector2D::Vector2D(): x(0), y(0){}

Vector2D::Vector2D(double x, double y): x(x), y(y){}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

void Vector2D::setX(double newX) {
    this->x = newX;
}

void Vector2D::setY(double newY) {
    this->y = newY;
}

double Vector2D::norma(const double x, const double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2D Vector2D::operator+(const Vector2D& vector) const {
    Vector2D tempVec(this->x + vector.x, this->y + vector.y);
    return tempVec;
}

Vector2D Vector2D::operator-(const Vector2D& vector) const {
    Vector2D tempVec(this->x - vector.x, this->y - vector.y);
    return tempVec;
}

double Vector2D::operator*(const Vector2D& vector) const {
    return (this->x * vector.x) + (this->y * vector.y);
}

Vector2D Vector2D::operator*(const double scalar) const{
    Vector2D    tempV;

    tempV.setX((this->x * scalar));
    tempV.setY(this->y * scalar);
    return tempV;
}

Vector2D& Vector2D::operator=(const Vector2D& vector){
    this->x = vector.getX();
    this->y = vector.getY();
    return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& vector) {
    this->x *= vector.x;
    this->y *= vector.y;
    return *this;
}

Vector2D Vector2D::operator/(double number) const{
    Vector2D    tempV;

    tempV.setX(this->x / number);
    tempV.setY(this->y / number);
    return tempV;
}

bool Vector2D::operator==(const Vector2D &vector) const {
    return (this->x == vector.getX()) && (this->y == vector.getY());
}





