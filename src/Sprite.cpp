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

}

void Sprite::update()
{

}

void Sprite::draw(Graphics &graphics, int x, int y)
{
    SDL_Rect dstRect = {x,y,int ( this->_srcRect.w * globals::SPRITE_SCALE) , int(this->_srcRect.h * globals::SPRITE_SCALE)};
    graphics.blitSurface(this->spriteSheet,&this->_srcRect,&dstRect);
}
