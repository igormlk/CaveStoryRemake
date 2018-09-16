//
// Created by igor on 16/09/18.
//

#include "../headers/Tileset.h"

SDL_Texture *Tileset::getTexture() const
{
    return texture;
}

void Tileset::setTexture(SDL_Texture *texture)
{
    Tileset::texture = texture;
}

int Tileset::getFirstGid() const
{
    return firstGid;
}

void Tileset::setFirstGid(int firstGid)
{
    Tileset::firstGid = firstGid;
}

Tileset::Tileset()
{
    this->firstGid = -1;
}

Tileset::Tileset(SDL_Texture *texture, int firstGid) :
                texture(texture),firstGid(firstGid)
{

}

Tileset::~Tileset()
{

}
