//
// Created by igor on 13/09/18.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "Sprite.h"
#include <map>
#include <string>
#include <vector>
#include "Vector2.h"

class Graphics;

class AnimatedSprite : public Sprite
{

public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string & filePath, int srcX,
                   int srcY, int width, int height, float posX, float posY, float timeToUpdate);

    void playAnimation(const std::string & animation, bool once = false);

    void update(int elapsedTime);

    void draw(Graphics & graphics, int x, int y);

private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;

protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
    void resetAnimation();
    void stopAnimation();
    void setVisible(bool visible);
    virtual void animationDone(std::string currentAnimation) = 0;
    virtual void setupAnimation() = 0;
};

#endif //ANIMATEDSPRITE_H
