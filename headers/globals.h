//
// Created by igor on 13/09/18.
//

#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals{
    const unsigned int SCREEN_WIDTH = 640;
    const unsigned int SCREEN_HEIGHT = 480;
    const float SPRITE_SCALE = 2.0f;
    const float GRAVITY = 0.002f;
    const float GRAVITY_CAP = 0.8f;
    const float JUMP_SPEED = 0.7f;
}

namespace sides
{
    enum Side
    {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT,
        NONE
    };

    const inline Side getOppositeSide(Side side)
    {
        return
            side == TOP ? BOTTOM :
            side == BOTTOM ? TOP :
            side == LEFT ? RIGHT :
            side == RIGHT ? LEFT :
            NONE;
    }

}

enum DIRECTION
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

#endif // GLOBALS_H
