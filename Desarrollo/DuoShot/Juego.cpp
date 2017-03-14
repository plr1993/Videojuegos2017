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

Juego::Juego() {
   _window = new Render(1250, 750);

}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
    delete _window;
}

Render* Juego::getWindow() {
    return _window;
}

//Aqui todo lo que vayamos a pintar del juego
void Juego::draw() {

}
//Aqui introducimos todos los comenados del teclado
void Juego::teclado() {

}
//Aqui vamos a llamar al resto
void Juego::update() {

}
//Aqui vamos a llamar a la IA al boss
void Juego::updateIA() {

}
