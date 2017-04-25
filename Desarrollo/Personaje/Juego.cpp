/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: sergio
 * 
 * Created on 14 de marzo de 2017, 13:45
 */

#include "Juego.hpp"
#include "Personaje.hpp"

Juego::Juego() {
   _window = new Render(1920, 1080);
   _menu = new Menu;
   _personaje = new Personaje;
   _companyero = new Companyero;
   _mapa = new Mapa;
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
    delete _window;
    delete _menu;
    delete _personaje;
    delete _companyero;
    delete _mapa;
}

Render* Juego::getWindow() {
    return _window;
}

//Aqui todo lo que vayamos a pintar del juego
void Juego::draw() {
    _personaje->drawPersonaje(_window);
    _companyero->drawCompanyero(_window);
    //_mapa->drawMapa(_window);
    
}
//Aqui introducimos todos los comenados del teclado
void Juego::teclado() {
    _personaje->tecladoPersonaje();
    _companyero->tecladoCompanyero();
     //Para salir
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
     {
       _window->getWindow()->close();
     }
               
}
//Aqui vamos a llamar al resto
void Juego::update() {
    _personaje->updatePersonaje(_window);
    _personaje->disparo(_window);
    //_mapa->updateMapa();
    
    comprobarColisiones();
   
}
//Aqui vamos a llamar a la IA al boss
void Juego::updateIA() {

}

void Juego::comprobarColisiones() {
    //_personaje->colisionesMapa(_mapa);
}





