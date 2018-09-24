//
// Created by igor on 23/09/18.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "globals.h"

class Rectangle
{
public:
    Rectangle(){}
    Rectangle(int x, int y, int width, int height) : _x(x), _y(y), _width(width), _height(height){}

    inline const int getCenterX() const
    {
        return this->_x + (this->_width / 2);
    }

    inline const int getCenterY() const
    {
        return this->_y + (this->_height / 2);
    }

    inline const int getLeft() const
    {
        return this->_x;
    }

    inline const int getRight() const
    {
        return this->_x + this->_width;
    }

    inline const int getTop() const
    {
        return this->_y;
    }

    inline const int getBottom() const
    {
        return this->_y + this->_height;
    }

    inline const int getWidth() const
    {
        return this->_width;
    }

    inline const int getHeigth() const
    {
        return this->_height;
    }

    inline const int getSide(const sides::Side side ) const
    {
        return
            side == sides::LEFT ? this->getLeft() :
            side == sides::RIGHT ? this->getRight() :
            side == sides::TOP ? this->getTop() :
            side == sides::BOTTOM ? this->getBottom() :
            sides::NONE;
    }

    inline const bool collidesWith(const Rectangle &other) const
    {
        return
            this->getRight() >= other.getLeft() &&
            this->getLeft() <= other.getRight() &&
            this->getTop() <= other.getBottom() &&
            this->getBottom() >= other.getTop();
    }

    inline const bool isValidRectangle() const
    {
        return (this->_x >= 0 && this->_y >= 0 && this->_width >= 0 && this->_height >= 0);
    }

private:
    int _x, _y, _width, _height;

};

#endif //RECTANGLE_H
