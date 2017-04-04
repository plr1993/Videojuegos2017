#include "Sprite.hpp"

Sprite::Sprite() {
    p_sprite = new sf::Sprite();
    p_textura = new sf::Texture();
    p_textura->setSmooth(true);
    p_sprite->setPosition(0, 0);
}

Sprite::Sprite(const Sprite& orig) { }

Sprite::~Sprite() {
    delete p_sprite;
    delete p_textura;
}

void Sprite::setTexture(sf::Texture * textura){
    p_sprite->setTexture(*textura);
}

void Sprite::setPosition(float x, float y){
    p_sprite->setPosition(x, y);
}

void Sprite::scale(float x, float y){
    p_sprite->scale(x, y);
}

float Sprite::getPositionX() {
    return p_sprite->getPosition().x;
}

float Sprite::getPositionY() {
    return p_sprite->getPosition().y;
}

float Sprite::getScaleX() {
    return p_sprite->getScale().x;
}

float Sprite::getScaleY() {
    return p_sprite->getScale().y;
}

void Sprite::move(float x, float y) {
    p_sprite->move(x, y);
}   

sf::Sprite Sprite::getSprite() {
    return * p_sprite;
}

sf::FloatRect Sprite::getGlobalBounds() {
    return p_sprite->getGlobalBounds();
}

sf::Color Sprite::getColor() {
    return p_sprite->getColor();
}

void Sprite::setColor(sf::Color color) {
    p_sprite->setColor(color);
}

void Sprite::setOrigin(float x, float y) {
    p_sprite->setOrigin(x, y);
}
