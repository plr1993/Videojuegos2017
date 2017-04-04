/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.cpp
 * Author: sergio
 * 
 * Created on 27 de marzo de 2017, 11:46
 */

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Mapa.hpp"

Mapa::Mapa() {
    //Inicio los barriles
    _barril = new sf::Sprite;
    _textBarril = new sf::Texture;
    _textBarril->loadFromFile("resources/barril.png");
    _barril->setTexture(*_textBarril);
    _barril->setPosition(200, 600);
    _barril->scale(0.2, 0.2);
    
    _barril2 = new sf::Sprite;
    _barril2->setTexture(*_textBarril);
    _barril2->setPosition(1500, 400);
    _barril2->scale(0.2, 0.2);
    
    //Inicio el reloj
    _reloj = new sf::Clock;
    
}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
    delete _barril;
    delete _barril2;
    delete _textBarril;
    delete _reloj;
}


void Mapa::drawMapa(Render* window) {
    window->getWindow()->draw(*_barril);
    window->getWindow()->draw(*_barril2);
}

void Mapa::updateMapa() {
    moverBarril();

}


void Mapa::moverBarril() {
    float rt = _reloj->getElapsedTime().asSeconds();
    if(rt > 0.1 && rt < 0.2){
     _textBarril->loadFromFile("resources/barril.png");
    }else if(rt > 0.2 && rt < 0.3){
     _textBarril->loadFromFile("resources/barril2.png");
    }else if(rt > 0.3 && rt <0.4){
     _textBarril->loadFromFile("resources/barril3.png");
      _reloj->restart();
    }else if(rt > 0.4){
      _reloj->restart();
    }  

}

sf::Sprite * Mapa::getBarril() {
    return _barril;
}

sf::Sprite* Mapa::getBarril2() {
    return _barril2;
}

