#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std; 

class Sprite : public sf::Drawable{
public:
    Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    void setTexture(sf::Texture * textura);
    void setPosition(float x, float y);
    void scale(float x, float y);
    void move(float x, float y);
    sf::Sprite getSprite();
    float getPositionY();
    float getPositionX();
    float getScaleX();
    float getScaleY();
    sf::FloatRect getGlobalBounds();
    sf::Color getColor();
    void setColor(sf::Color color);

private:
    sf::Sprite* p_sprite;
    sf::Texture* p_textura;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(*p_sprite, states);
    }
    
};

#endif /* SPRITE_HPP */