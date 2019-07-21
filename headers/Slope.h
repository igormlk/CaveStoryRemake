//
// Created by igor on 26/09/18.
//

#ifndef SLOPE_H
#define SLOPE_H

#include <cmath>
#include "globals.h"
#include "Vector2.h"
#include "Rectangle.h"

class Slope
{
public:
    Slope(Vector2 p1, Vector2 p2) : _p1(p1), _p2(p2)
    {
        if(this->_p1.getX() - _p2.getX() != 0)
        {
            this->_slope = static_cast<float>((fabs(this->_p1.getY()) - fabs(this->_p1.getY())) / (fabs(this->_p2.getX()) - fabs(this->_p2.getX())));
        }
    }

    const inline float getSlope() const
    {
        return this->_slope;
    }

    const bool collidesWith(const Rectangle &other) const
    {

    }

private:
    Vector2 _p1, _p2;
    float _slope;
};

#endif //SLOPE_H
