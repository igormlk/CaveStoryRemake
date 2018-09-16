//
// Created by igor on 09/09/18.
//

#ifndef GAME_H
#define GAME_H

#include "AnimatedSprite.h"
#include "Player.h"
#include "Level.h"

class Graphics;

class Game{
public:
    Game();
    virtual ~Game();
private:
    void gameLoop();
    void draw(Graphics & graphics);
    void update(float elapsedTime);
    Player player;
    Level level;
};

#endif GAME_H
