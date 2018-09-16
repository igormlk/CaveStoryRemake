//
// Created by igor on 13/09/18.
//

#include "../headers/Vector2.h"

Vector2::Vector2() : x(0), y(0)
{

}

Vector2::Vector2(double x, double y) : x(x), y(y)
{

}

double Vector2::getX() const
{
    return x;
}

void Vector2::setX(double x)
{
    Vector2::x = x;
}

double Vector2::getY() const
{
    return y;
}

void Vector2::setY(double y)
{
    Vector2::y = y;
}

Vector2 Vector2::zero()
{
    return Vector2(0,0);
}
