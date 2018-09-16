//
// Created by igor on 09/09/18.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics{

public:

    Graphics();
    virtual ~Graphics();
    void operator()();

    SDL_Surface * loadImage(const std::string &filepath);
    void blitSurface(SDL_Texture *source, SDL_Rect *sourcRectangle, SDL_Rect *destRectangle);

    void draw();

    void clear();

    SDL_Renderer * getRenderer() const;

private:
    SDL_Window * window;
    SDL_Renderer * renderer;

    std::map<std::string, SDL_Surface * >_spriteSheets;

};


#endif //GRAPHICS_H
