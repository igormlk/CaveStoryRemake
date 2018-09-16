//
// Created by igor on 13/09/18.
//

#include "../headers/Player.h"

namespace player_constants{
    const float WALK_SPEED = 0.2f;
}

void Player::animationDone(std::string currentAnimation)
{

}

void Player::setupAnimation()
{
    this->addAnimation(1,0,0,"IdleLeft",16,16, Vector2(0,0));
    this->addAnimation(1,0,16,"IdleRight",16,16, Vector2(0,0));
    this->addAnimation(3,0,0, "RunLeft",16,16, Vector2(0,0));
    this->addAnimation(3,0,16,"RunRight",16,16, Vector2(0,0));
}

Player::Player()
{

}

Player::Player(Graphics &graphics, float x, float y) :
        AnimatedSprite(graphics,"../resources/sprites/MyChar.png",0,0,16,16,x,y,100)
{
    graphics.loadImage("../resources/MyChar.png");
    this->setupAnimation();
    this->playAnimation("RunRight");
}

void Player::draw(Graphics &graphics)
{
    AnimatedSprite::draw(graphics, this->x, this->y);
}

void Player::update(int elapsedTime)
{
    this->x += this->_dx * elapsedTime;
    AnimatedSprite::update(elapsedTime);
}

void Player::moveLeft()
{
    this->_dx = -player_constants::WALK_SPEED;
    this->playAnimation("RunLeft");
    this->_facing = DIRECTION::LEFT;
}

void Player::moveRight()
{
    this->_dx = +player_constants::WALK_SPEED;
    this->playAnimation("RunRight");
    this->_facing = DIRECTION::RIGHT;
}

void Player::stopMoving()
{
    this->_dx = 0;
    switch(this->_facing)
    {
            case DIRECTION::LEFT:
                this->playAnimation("IdleLeft");
            break;

            case DIRECTION::RIGHT:
                this->playAnimation("IdleRight");
            break;

            case UP:
            break;

            case DOWN:
            break;
    }
}
