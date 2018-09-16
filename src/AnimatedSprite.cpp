//
// Created by igor on 13/09/18.
//

#include "../headers/AnimatedSprite.h"
#include "../headers/Vector2.h"
#include "../headers/globals.h"


AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, int srcX, int srcY, int width,
                               int height, float posX, float posY, float timeToUpdate):
                                Sprite(graphics,filePath,srcX,srcY,width,height,posX,posY),
                                _frameIndex(0),_timeToUpdate(timeToUpdate),_visible(true),
                                _currentAnimationOnce(false),_currentAnimation("")
{

}

void AnimatedSprite::playAnimation(const std::string & animation, bool once)
{
    this->_currentAnimationOnce = once;
    if(this->_currentAnimation != animation)
    {
        this->_currentAnimation = animation;
        this->_frameIndex = 0;
    }
}

void AnimatedSprite::update(int elapsedTime)
{
    Sprite::update();
    this->_timeElapsed += elapsedTime;
    if(this->_timeElapsed > this->_timeToUpdate)
    {
        this->_timeElapsed -= this->_timeToUpdate;
        if(this->_frameIndex < this->_animations[_currentAnimation].size() - 1)
        {
            this->_frameIndex++;
        }
        else
        {
            if(this->_currentAnimationOnce)
            {
                this->setVisible(false);
            }
            this->_frameIndex = 0;
            this->animationDone(this->_currentAnimation);
        }
    }
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y)
{
    if(this->_visible)
    {
        SDL_Rect dstRect;
        dstRect.x = static_cast<int>(x + this->_offsets[this->_currentAnimation].getX());
        dstRect.y = static_cast<int>(y + this->_offsets[this->_currentAnimation].getY());
        dstRect.w = static_cast<int>(this->_srcRect.w * globals::SPRITE_SCALE);
        dstRect.h = static_cast<int>(this->_srcRect.h * globals::SPRITE_SCALE);

        SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
        graphics.blitSurface(this->spriteSheet, &sourceRect, &dstRect);
    }
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
    std::vector<SDL_Rect> rectangles;
    for(int i = 0; i < frames; i++)
    {
        SDL_Rect newRect = {(i + x) * width, y, width, height};
        rectangles.push_back(newRect);
    }

    this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
    this->_offsets.insert(std::pair<std::string, Vector2>(name, offset));

}

void AnimatedSprite::resetAnimation()
{
    this->_animations.clear();
    this->_offsets.clear();
}

void AnimatedSprite::stopAnimation()
{
    this->_frameIndex = 0;
    animationDone(this->_currentAnimation);
}

void AnimatedSprite::setVisible(bool visible)
{
    this->_visible = visible;
}
