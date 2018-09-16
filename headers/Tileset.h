//
// Created by igor on 16/09/18.
//

#ifndef TILESET_H
#define TILESET_H

struct SDL_Texture;

class Tileset
{
public:

    Tileset();
    Tileset(SDL_Texture * texture, int firstGid);
    ~Tileset();

    SDL_Texture *getTexture() const;
    void setTexture(SDL_Texture *texture);
    int getFirstGid() const;
    void setFirstGid(int firstGid);

private:
    SDL_Texture * texture;
    int firstGid;
};

#endif //TILESET_H
