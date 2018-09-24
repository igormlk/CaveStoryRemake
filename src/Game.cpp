//
// Created by igor on 09/09/18.
//

#include "../headers/Game.h"
#include "../headers/Graphics.h"
#include "../headers/InputKeyboard.h"
#include "../headers/Player.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <boost/thread.hpp>

namespace
{
    const int FPS = 50;
    const int MAX_FRAME_TIME = (5 * 1000) / FPS;
}


Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop() {

    Graphics graphics;
    SDL_Event event;
    InputKeyboard input;

    this->level = Level("Map1", Vector2(100,100), graphics);
    this->player = Player(graphics, level.getPlayerSpawnPoint().getX(), level.getPlayerSpawnPoint().getY());

    int LAST_UPDATE_TIME = SDL_GetTicks();
    int CURRENT_TIME = 0;
    int ELAPSED_TIME = 0;
    while(true)
    {
        input.beginNewFrame();
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.repeat == 0)
                    input.keyDownEvent(event);
            }
            else if(event.type == SDL_KEYUP)
            {
                input.keyUpEvent(event);
            }

            if(event.type == SDL_QUIT)
            {
                return;
            }
        }

        if(input.isKeyPressed(SDL_SCANCODE_ESCAPE))
            return;
        else if(input.isKeyHeld(SDL_SCANCODE_LEFT))
        {
            this->player.moveLeft();
        }
        else if(input.isKeyHeld(SDL_SCANCODE_RIGHT))
        {
            this->player.moveRight();
        }

        if(!input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_LEFT))
        {
            this->player.stopMoving();
        }

        CURRENT_TIME = SDL_GetTicks();
        ELAPSED_TIME = CURRENT_TIME - LAST_UPDATE_TIME;
        LAST_UPDATE_TIME = CURRENT_TIME;
        this->update(std::min(ELAPSED_TIME,MAX_FRAME_TIME));
        this->draw(graphics);
    }

}

void Game::draw(Graphics &graphics)
{
    graphics.clear();
    this->level.draw(graphics);
    this->player.draw(graphics);
    graphics.draw();
}

void Game::update(float elapsedTime)
{
    this->player.update(elapsedTime);
    this->level.update(elapsedTime);
    //Check Collisions
    std::vector<Rectangle> others = this->level.checkTileCollisions(this->player.getBoundingBox());
    if(others.size() > 0)
    {
        this->player.handleTileCollisions(others);
    }
}
