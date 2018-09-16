//
// Created by igor on 16/09/18.
//

#include "../headers/Tile.h"
#include "../headers/Graphics.h"
#include <SDL2/SDL.h>

Tile::Tile()
{

}

Tile::Tile(SDL_Texture *tileset, Vector2 size, Vector2 tileSetPosition, Vector2 position):
            _tileset(tileset), _size(size), _tilesetPosition(tileSetPosition),
            _position(Vector2(position.getX() * globals::SPRITE_SCALE, position.getY() * globals::SPRITE_SCALE))
{

}

void Tile::update(int elapsedTime)
{

}

void Tile::draw(Graphics &graphics)
{
    SDL_Rect dstRect = {this->_position.getX(), this->_position.getY(),
                        this->_size.getX() * globals::SPRITE_SCALE, this->_size.getY() * globals::SPRITE_SCALE};

    SDL_Rect srcRect = {this->_tilesetPosition.getX(), this->_tilesetPosition.getY(),
                        this->_size.getX(), this->_size.getY()};

    graphics.blitSurface(this->_tileset, &srcRect, &dstRect);

}
