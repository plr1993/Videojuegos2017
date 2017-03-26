/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: sergio
 * 
 * Created on 14 de marzo de 2017, 13:44
 */

#include "Personaje.hpp"

Personaje::Personaje() {
    //Inicio el Survivor
    _survivor = new sf::Sprite;
    _textSurvivor = new sf::Texture;
    _textSurvivor->loadFromFile("resources/survivor.png");
    _survivor->setTexture(*_textSurvivor);
    _survivor->setPosition(1250/2, 750/2); //Esto es el centro del juego, habra que cambiarlo
    _survivor->setOrigin(100.0, 100.0);
    _survivor->scale(0.8, 0.8);
    
    //Inicio el Objetivo
    _objective = new sf::Sprite;
    _textObj = new sf::Texture;
    _textObj->loadFromFile("resources/objective.png");
    _objective->setTexture(*_textObj);
    _objective->scale(0.1, 0.1);

}

Personaje::Personaje(const Personaje& orig) {
}

Personaje::~Personaje() {
    delete _survivor;
    delete _textSurvivor;
    delete _objective;
    delete _textObj;
}

void Personaje::drawPersonaje(Render* window) {
    window->getWindow()->draw(*_survivor);
    window->getWindow()->draw(*_objective);
}

void Personaje::updatePersonaje(Render * window) {
     //Rotacion de Survivor
     sf::Vector2f movimientoMouse;
     movimientoMouse.x = sf::Mouse::getPosition(*window->getWindow()).x;
     movimientoMouse.y = sf::Mouse::getPosition(*window->getWindow()).y;
     float dx = movimientoMouse.x - _survivor->getPosition().x;
     float dy = movimientoMouse.y - _survivor->getPosition().y;
     float rotation = (atan2(dy, dx)) * 180 / PI;
     _survivor->setRotation(rotation);
     
     //Movemos el objetivo con el movimiento del raton
      _objective->setPosition(movimientoMouse);

}

void Personaje::tecladoPersonaje() {
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            movement.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            movement.y += speed;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            movement.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            movement.x += speed;
        }
}
