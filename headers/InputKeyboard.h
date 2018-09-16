//
// Created by igor on 09/09/18.
//

#ifndef INPUTKEYBOARD_H
#define INPUTKEYBOARD_H

#include <SDL2/SDL.h>
#include <map>

class InputKeyboard{

public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);

private:
    std::map<SDL_Scancode, bool> heldKeys;
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;

};

#endif //INPUTKEYBOARD_H
