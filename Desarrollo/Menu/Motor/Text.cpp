#include "Text.hpp"

Text::Text() {
    font.loadFromFile("Gameplay.ttf");
    text = new sf::Text();
    text->setFont(font);
}

Text::Text(const Text& orig) {
}

Text::~Text() {
    delete text;
}

void Text::setCharacterSize(int size) {
    text->setCharacterSize(size);
}

void Text::setColor(sf::Color color) {
    text->setColor(color);
}

void Text::setPosition(float x, float y) {
    text->setPosition(x, y);
}

void Text::setString(string texto) {
    text->setString(texto);
}

float Text::getPositionX() {
    return text->getPosition().x;
}

float Text::getPositionY() {
    return text->getPosition().y;
}
