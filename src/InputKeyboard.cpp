//
// Created by igor on 09/09/18.
//

#include "../headers/InputKeyboard.h"


void InputKeyboard::beginNewFrame() {
    this->pressedKeys.clear();
    this->releasedKeys.clear();
}

void InputKeyboard::keyUpEvent(const SDL_Event &event) {
    this->releasedKeys[event.key.keysym.scancode] = true;
    this->heldKeys[event.key.keysym.scancode] = false;
}

void InputKeyboard::keyDownEvent(const SDL_Event &event) {
    this->pressedKeys[event.key.keysym.scancode] = true;
    this->heldKeys[event.key.keysym.scancode] = true;
}

bool InputKeyboard::isKeyPressed(SDL_Scancode key) {
    return this->pressedKeys[key];
}

bool InputKeyboard::isKeyReleased(SDL_Scancode key) {
    return this->releasedKeys[key];
}

bool InputKeyboard::isKeyHeld(SDL_Scancode key) {
    return this->heldKeys[key];
}
