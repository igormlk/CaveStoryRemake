//
// Created by igor on 13/09/18.
//

#include "../headers/Sprite.h"
#include "../headers/globals.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

Sprite::Sprite(Graphics &graphics, const std::string &filepath, int srcX, int srcY, int width, int height, float posX,
               float posY) : x(posX), y(posY)
{
    this->_srcRect.x = srcX;
    this->_srcRect.y = srcY;
    this->_srcRect.w = width;
    this->_srcRect.h = height;

    this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filepath));

    if(this->spriteSheet == NULL)
    {
        std::cout << "Error loading spriteSheet" << std::endl;
    }

    this->_boundingBox = Rectangle(this->x, this->y, width * globals::SPRITE_SCALE, height * globals::SPRITE_SCALE);

}

void Sprite::update()
{
    this->_boundingBox = Rectangle(this->x, this->y, this->_srcRect.w * globals::SPRITE_SCALE, this->_srcRect.h * globals::SPRITE_SCALE);
}

void Sprite::draw(Graphics &graphics, int x, int y)
{
    SDL_Rect dstRect = {x,y,int ( this->_srcRect.w * globals::SPRITE_SCALE) , int(this->_srcRect.h * globals::SPRITE_SCALE)};
    graphics.blitSurface(this->spriteSheet,&this->_srcRect,&dstRect);
}

const Rectangle &Sprite::getBoundingBox() const
{
    return this->_boundingBox;
}

const sides::Side Sprite::getCollisionSide(Rectangle &other) const
{
    int amtRight, amtLeft, amtTop, amtBottom;
    amtRight = this->getBoundingBox().getRight() - other.getLeft();
    amtLeft = other.getRight() - this->getBoundingBox().getRight();
    amtTop =  other.getBottom() - this->getBoundingBox().getTop();
    amtBottom = this->getBoundingBox().getBottom() - other.getTop();

    int val[4] = {abs(amtRight), abs(amtLeft), abs(amtTop), abs(amtBottom)};
    int lowest = val[0];

    for(int i : val)
    {
        if(i < lowest)
            lowest = i;
    }

    return
            lowest == val[0] ? sides::RIGHT :
            lowest == val[1] ? sides::LEFT :
            lowest == val[2] ? sides::TOP :
            lowest == val[3] ? sides::BOTTOM :
            sides::NONE;
}
