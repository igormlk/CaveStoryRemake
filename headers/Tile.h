//
// Created by igor on 16/09/18.
//

#ifndef TILE_H
#define TILE_H

#include "globals.h"
#include "Vector2.h"

struct SDL_Texture;
class Graphics;

class Tile
{
public:
    Tile();
    Tile(SDL_Texture * tileset, Vector2 size, Vector2 tileSetPosition, Vector2 position);
    void update(int elapsedTime);
    void draw(Graphics &graphics);
private:
    SDL_Texture * _tileset;
    Vector2 _size;
    Vector2 _tilesetPosition;
    Vector2 _position;
};


#endif //TILE_H
