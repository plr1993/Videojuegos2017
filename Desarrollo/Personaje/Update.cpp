/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Update.cpp
 * Author: sergio
 * 
 * Created on 14 de marzo de 2017, 13:45
 */

#include "Update.hpp"
#include "iostream"
using namespace std;

Update::Update() {
    juego = new Juego();
}

Update::Update(const Update& orig) {
}

Update::~Update() {
    delete juego;
}

void Update::update() {

    sf::Clock clock;
    sf::Clock clockIA;
    juego->getWindow()->getWindow()->setFramerateLimit(60); //Interpolamos el juego por defecto a 60fps
    juego->getWindow()->getWindow()->setMouseCursorVisible(false);
    while(juego->getWindow()->getWindow()->isOpen()){

	


        
        juego->getWindow()->getWindow()->clear(sf::Color::Black);

         sf::Event event;
        
        while(juego->getWindow()->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed)
                juego->getWindow()->getWindow()->close();
        }
                 //sf::Time dt = clock.restart();
       
       juego->teclado();
       //Aqui meto todo lo que vaya a mover y limitamos a 1/60
       if(clockIA.getElapsedTime().asMilliseconds() > 0.1){
            juego->update(); //Aqui metemos el juego
            //Se muestra un mensaje por pantalla.
            //cout << "Entro al update" <<clock.getElapsedTime().asMilliseconds()<< endl; 
            clockIA.restart();

       }
       
       //Aqui meto todo lo que se ejecute de la IA y limitamos a 1/25
       if(clockIA.getElapsedTime().asMicroseconds() > WORLD_TICK_TIME_IA){
           juego->updateIA(); //Aqui metemos la IA
       }
       if(clock.getElapsedTime().asMilliseconds() > 1){
            juego->draw();
            juego->getWindow()->getWindow()->display(); 
            clock.restart(); 
            //cout << "Entro al Draw" <<clock.getElapsedTime().asMilliseconds()<< endl; 

       }
       
    }
}