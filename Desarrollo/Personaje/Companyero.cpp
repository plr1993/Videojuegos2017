/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Companyero.cpp
 * Author: sergio
 * 
 * Created on 27 de marzo de 2017, 11:11
 */

#include "Companyero.hpp"
#include "Motor/Render.hpp"

Companyero::Companyero() {
   //Inicio la vida
    _cantVida = 30;
    _vida = new sf::Sprite;
    _textVida = new sf::Texture;
    _textVida->loadFromFile("resources/vida-comp/30.png");
    _vida->setTexture(*_textVida);
    _vida->setPosition(20, 150);
    _vida->scale(0.2, 0.2);
}

Companyero::Companyero(const Companyero& orig) {
}

Companyero::~Companyero() {
    delete _vida;
    delete _textVida;
}

void Companyero::drawCompanyero(Render* window) {
    window->getWindow()->draw(*_vida);

}

void Companyero::tecladoCompanyero() {
    vida();

}

void Companyero::updateCompanyero(Render* window) {

}

void Companyero::cambiarArma() {

}

void Companyero::disparo(Render* window) {

}

void Companyero::vida() {

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(_cantVida > 0){
            _cantVida--;
            std::ostringstream stream;
            stream << "resources/vida-comp/" << _cantVida << ".png";
            std::string result = stream.str();
            _textVida->loadFromFile(result);
            _vida->setTexture(*_textVida);
        }
        
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(_cantVida < 30){
            _cantVida++;
            std::ostringstream stream;
            stream << "resources/vida-comp/" << _cantVida << ".png";
            std::string result = stream.str();
            _textVida->loadFromFile(result);
            _vida->setTexture(*_textVida);
        }
        
    }
}
