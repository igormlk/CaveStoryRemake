//
// Created by igor on 13/09/18.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "AnimatedSprite.h"
#include "Rectangle.h"
#include <string>

class Player : public AnimatedSprite
{
public:
    Player();
    Player(Graphics & graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(int elapsedTime);

    void moveLeft();
    void moveRight();
    void stopMoving();

    const float getX() const;
    const float getY() const;

    void handleTileCollisions(std::vector<Rectangle> &others);

protected:
    void animationDone(std::string currentAnimation) override;
    void setupAnimation() override;

private:
    float _dx, _dy;
    DIRECTION _facing;
    bool _grounded;
    Rectangle collideBox;
};

#endif //PLAYER_H
