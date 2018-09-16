//
// Created by igor on 09/09/18.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/Graphics.h"
#include "../headers/globals.h"

#define WINDOW_TITLE "CaveStory"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window, WINDOW_TITLE);
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

void Graphics::operator()() {

}

SDL_Surface *Graphics::loadImage(const std::string &filepath)
{
    if(this->_spriteSheets.count(filepath) == 0)
    {
        this->_spriteSheets[filepath] = IMG_Load(filepath.c_str());
    }
    return _spriteSheets[filepath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *srcRectangle, SDL_Rect *destRectangle)
{
    SDL_RenderCopy(this->renderer,source,srcRectangle, destRectangle);
}

void Graphics::draw()
{
    SDL_RenderPresent(this->renderer);
}

void Graphics::clear()
{
    SDL_RenderClear(this->renderer);
}

SDL_Renderer *Graphics::getRenderer() const
{
    return this->renderer;
}
