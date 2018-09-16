//
// Created by igor on 13/09/18.
//

#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    Vector2();
    Vector2(double x, double y);
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    static Vector2 zero();

private:
    double x;
    double y;

};


#endif //VECTOR2_H
