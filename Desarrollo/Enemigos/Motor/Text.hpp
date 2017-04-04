#ifndef TEXT_HPP
#define TEXT_HPP
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std; 

class Text : public sf::Drawable{
public:
    Text();
    Text(const Text& orig);
    virtual ~Text();
    void setString(string texto);
    void setColor(sf::Color color);
    void setCharacterSize(int size);
    void setPosition(float x, float y);
    float getPositionX();
    float getPositionY();
    
private:
    sf::Text * text;
    sf::Font font;
     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(*text, states);
    }
};

#endif /* TEXT_HPP */

