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
    _textSurvivor->loadFromFile("resources/survivor-pistola.png");
    _survivor->setTexture(*_textSurvivor);
    _survivor->setPosition(1920/2, 1080/2); //Esto es el centro del juego, habra que cambiarlo
    _survivor->setOrigin(100.0, 100.0);
    _survivor->scale(0.8, 0.8);
    
    //Inicio el Objetivo
    _objective = new sf::Sprite;
    _textObj = new sf::Texture;
    _textObj->loadFromFile("resources/objective.png");
    _objective->setTexture(*_textObj);
    _objective->scale(0.1, 0.1);
    
    //Inicio la bala
    _bala = new sf::Sprite;
    _textBala = new sf::Texture;
    _textBala->loadFromFile("resources/bala.png");
    _bala->setTexture(*_textBala);
    _disparo = false;
    

    _cantVida = 30;
    _vida = new sf::Sprite;
    _textVida = new sf::Texture;
    _textVida->loadFromFile("resources/vida/30.png");
    _vida->setTexture(*_textVida);
    _vida->setPosition(40, 130);
    _vida->scale(0.20, 0.20);
    
    //Inicio los relojes
    _frameClock = new sf::Clock;
    _clock = new sf::Clock;
    
    //Comprobamos colision
    _colision = false;
}

Personaje::Personaje(const Personaje& orig) {
}

Personaje::~Personaje() {
    delete _survivor;
    delete _textSurvivor;
    delete _objective;
    delete _textObj;
    delete _frameClock;
    delete _bala;
    delete _textBala;
    delete _vida;
    delete _textVida;
    delete _clock;
}

void Personaje::drawPersonaje(Render* window) {
    window->getWindow()->draw(*_survivor);
    window->getWindow()->draw(*_objective);
    window->getWindow()->draw(*_vida);
    if(_disparo){
        window->getWindow()->draw(*_bala);
    } 
    

}

void Personaje::updatePersonaje(Render * window, Camera * camera) {
     sf::Vector2f mouse_pos = window->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*window->getWindow()));

     float dx = mouse_pos.x - _survivor->getPosition().x;
     float dy = mouse_pos.y - _survivor->getPosition().y;
    //Rotacion de Survivor     
     float rotation = (atan2(dy, dx)) * 180 / PI;
     _survivor->setRotation(rotation);
     //Movemos el objetivo con el movimiento del raton
     _objective->setPosition(mouse_pos);
     updateBala();
     
     //MUEVO LA VIDA CON LA CAMARA
   _vida->setPosition(camera->getCamera().getCenter().x - 900, camera->getCamera().getCenter().y-520);
}

void Personaje::updateBala() {
    _posX = _mouseX-_inicialBalaX;
    _posY = _mouseY-_inicialBalaY;
   
    _bala->move(_posX, _posY);
}



void Personaje::tecladoPersonaje() {
        sf::Vector2f movement(0.f, 0.f);
        sf::Time frameTime = _frameClock->restart();
    if(_colision==false){ 

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
        _survivor->move(movement * frameTime.asSeconds());
        
        cambiarArma();
        vida();

}

void Personaje::disparo(Render * window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {   
        sf::Vector2f mouse_pos = window->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*window->getWindow()));
        //Calculo la posicion inicial de la bala y la posicion del raton donde ha disparado
        _mouseX = mouse_pos.x;
        _mouseY = mouse_pos.y;
        _inicialBalaX = _survivor->getPosition().x;
        _inicialBalaY = _survivor->getPosition().y;
        
        //Calculo el angulo inicial de la bala
        float dx = mouse_pos.x - _survivor->getPosition().x;
        float dy = mouse_pos.y - _survivor->getPosition().y;
        _rotation = (atan2(dy, dx)) * 180 / PI;
        
         //Posicion inicial de la bala
         _bala->setPosition(_inicialBalaX, _inicialBalaY);
         _bala->setRotation(_rotation);
                  
        _disparo = true;
    }
}

//Este metodo es el que cambia de arma
void Personaje::cambiarArma() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            _textSurvivor->loadFromFile("resources/survivor-fusil.png");
            _survivor->setTexture(*_textSurvivor);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            _textSurvivor->loadFromFile("resources/survivor-rifle.png");
            _survivor->setTexture(*_textSurvivor);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            _textSurvivor->loadFromFile("resources/survivor-pistola.png");
            _survivor->setTexture(*_textSurvivor);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        {
            _textSurvivor->loadFromFile("resources/survivor-taser.png");
            _survivor->setTexture(*_textSurvivor);
        }

}

//Este metodo es el que le va a restar o sumar vida, habra que quitar lo del teclado
void Personaje::vida() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(_cantVida > 0){
            _cantVida--;
            std::ostringstream stream;
            stream << "resources/vida/" << _cantVida << ".png";
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
            stream << "resources/vida/" << _cantVida << ".png";
            std::string result = stream.str();
            _textVida->loadFromFile(result);
            _vida->setTexture(*_textVida);
        }
        
    }
}

//Metodo que comprueba las colisiones del mapa
void Personaje::colisionesMapa(mapa * mapa) {
    /*if(mapa->getBarril()->getGlobalBounds().intersects(_survivor->getGlobalBounds())){
        _colision = true;
    }else{
        _colision = false;
    }*/
}


sf::Sprite * Personaje::getPersonaje() {
    return _survivor;
}
