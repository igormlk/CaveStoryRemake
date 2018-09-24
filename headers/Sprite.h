//
// Created by igor on 13/09/18.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Rectangle.h"
#include "globals.h"

class Sprite
{
public:
    Sprite();
    virtual ~Sprite();
    Sprite(Graphics & graphics, const std::string & filepath, int srcX, int srcY, int width, int height, float posX, float posY);
    virtual void update();
    void draw(Graphics & graphics, int x, int y);

    const Rectangle & getBoundingBox() const;
    const sides::Side getCollisionSide(Rectangle &other) const;

private:

protected:
    float x, y;
    SDL_Rect _srcRect;
    SDL_Texture * spriteSheet;
    Rectangle _boundingBox;
};


#endif //SPRITE_H
