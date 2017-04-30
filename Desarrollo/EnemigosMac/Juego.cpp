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
#include "Enemigo.hpp"

Juego::Juego() {
   _window = new Render(1250, 750);
    Enemigos[0]=new Enemigo();
    Enemigos[1]=new Enemigo();
    Enemigos[2]=new Enemigo();
    Enemigos[3]=new Enemigo();
    Enemigos[4]=new Enemigo();
    Enemigos[5]=new Enemigo();
    Enemigos[6]=new Enemigo();
 

}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
    delete _window;
    delete Enemigos[0];
    delete Enemigos[1];
    delete Enemigos[2];
    delete Enemigos[3];
    delete Enemigos[4];
    delete Enemigos[5];
    delete Enemigos[6];
}

Render* Juego::getWindow() {
    return _window;
}

//Aqui todo lo que vayamos a pintar del juego
void Juego::draw() {

   Enemigos[0]->drawNpc(_window);
   Enemigos[1]->drawNpc(_window);
   Enemigos[2]->drawNpc(_window);
   Enemigos[3]->drawNpc(_window);
   Enemigos[4]->drawNpc(_window);
   Enemigos[5]->drawNpc(_window);
   Enemigos[6]->drawNpc(_window);
}
//Aqui introducimos todos los comenados del teclado
void Juego::teclado() {

}
//Aqui vamos a llamar al resto
void Juego::update() {

    Enemigos[0]->updateNpc(_window);
    Enemigos[1]->updateNpc(_window);
    Enemigos[2]->updateNpc(_window);
    Enemigos[3]->updateNpc(_window);
    Enemigos[4]->updateNpc(_window);
    Enemigos[5]->updateNpc(_window);
    Enemigos[6]->updateNpc(_window);

}
//Aqui vamos a llamar a la IA al boss
void Juego::updateIA() {

}
