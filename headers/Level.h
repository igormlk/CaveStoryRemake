//
// Created by igor on 16/09/18.
//

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Vector2.h"
#include "Tile.h"
#include "Tileset.h"

class Graphics;
struct SDL_Texture;

class Level
{
public:
    Level();
    Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);
    ~Level();
    void update(int elapsedTime);
    void draw(Graphics &graphics);
private:
    std::string _mapName;
    Vector2 _spawnPoint;
    Vector2 _size;
    Vector2 _tileSize;
    SDL_Texture * _backgroundTexture;

    std::vector<Tile> _tileList;
    std::vector<Tileset> _tileSets;

    void loadMap(std::string name, Graphics & graphics);

    void splitTiles(std::string &stringT, std::vector<std::string> &tilesArray) const;
};




#endif //CAVESTORYREMAKE_LEVEL_H
