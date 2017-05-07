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
#include "Estado.hpp"

Juego::Juego() {
   _window = new Render(1920, 1080);
   _personaje = new Personaje;
   _companyero = new Companyero;
   _mapa = new mapa;
   _estado = new Estado;
   _menu = new Menu();
   _camera = new Camera();

   //El Objetivo del puntero
    //Inicio el Objetivo
    _objective = new sf::Sprite;
    _textObj = new sf::Texture;
    _textObj->loadFromFile("resources/objective.png");
    _objective->setTexture(*_textObj);
    _objective->scale(0.1, 0.1);

     //Cargamos la barra superior
    _barraSuperior = new sf::Sprite;
    _textBarra = new sf::Texture;
    _textBarra->loadFromFile("resources/barra-superior.png");
    _barraSuperior->setTexture(*_textBarra);
    _barraSuperior->setPosition(0, 0);
    
     //Creo los enemigos
    for(int i = 0; i<10; i++){
        _enemigos[i] = new Enemigo();
    }
   
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
    delete _window;
    delete _personaje;
    delete _companyero;
    delete _mapa;
    delete _menu;
    delete _estado;
    delete _objective;
    delete _textObj;
    delete _camera;
    delete _barraSuperior;
    delete _textBarra;
    
   
    for(int i = 0; i<10; i++){
        delete _enemigos[i];
    }
    
    
}

Render* Juego::getWindow() {
    return _window;
}

//Aqui todo lo que vayamos a pintar del juego
void Juego::draw() {
    //Segun el etsado pinto una cosa u otra
    if(*_estado->getEstado() == 0 || *_estado->getEstado() == 1 ||* _estado->getEstado() == 2){
        _menu->drawMenu(_window, _estado);
    }else if(*_estado->getEstado() == 3){
        _mapa->dibuja(_window);
        _personaje->drawPersonaje(_window);
        _companyero->drawCompanyero(_window);
        _window->getWindow()->draw(*_barraSuperior);
        //Pinto los enemigos
        for(int i = 0; i<10; i++){
            _enemigos[i]->drawNpc(_window);
        }
        
       


    }
    //Pinto el objetivo siempre

    _window->getWindow()->draw(*_objective);
    
    
    
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
    //Controlamos lo que pulsamos con el raton
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {  
        //Si cuando hace colision el raton con el menu cambiamos el estado
        if(*_estado->getEstado() == 0){
            if(_menu->colisionMenu(_objective) == 1){
                _estado->setEstado(1);
            }
        }else if(*_estado->getEstado() == 1){
            if(_menu->colisionSelecMapa(_objective) == 21 || _menu->colisionSelecMapa(_objective) == 22 ||_menu->colisionSelecMapa(_objective) == 23){
                _estado->setMapa(_menu->colisionSelecMapa(_objective));
                _estado->setEstado(2);
            }
        }else if(*_estado->getEstado() == 2){
            if(_menu->colisionesControles(_objective) == 3){
                _estado->setEstado(3);
                _mapa->CargarMapa(*_estado->getMapa());
            }
        }
        
        
        if(_menu->colisionSelecMapa(_objective) == 0 && *_estado->getEstado() == 1){
            _estado->setEstado(0);
        }
    }
    //Segun el estado cargo una cosa u otra
    if(*_estado->getEstado() == 0 || *_estado->getEstado() == 1 || *_estado->getEstado() == 2){ //Menu principal
       _menu->updateMenu(_window, _objective, _estado);
    }else if(*_estado->getEstado() == 3){ //Juego
       controlarCamera();
       _personaje->updatePersonaje(_window, _camera);
       _personaje->disparo(_window);
       _window->getWindow()->setView(_camera->getCamera());

       
       //Compañero
       float posX=_personaje->getPersonaje()->getPosition().x;//posicion del protagonista
       float posY=_personaje->getPersonaje()->getPosition().y;//posicion del protagonista
       //APUNTAR AL ENEMIGO MAS CERCANO
       int DistanciaEnemAnterior;
       for(int i=0;i<2;i++){//cual es el equivalente al enemigos.length?
            float posEnemx;
            float posEnemy;
           //distancia entre personaje y enemigo
            int DistanciaEnem=sqrt(pow(posX - _enemigos[i]->getEnemigo()->getPosition().x,2)+pow(posY - _enemigos[i]->getEnemigo()->getPosition().y,2));
            if(DistanciaEnem<=500){
                if(DistanciaEnem < DistanciaEnemAnterior)
                DistanciaEnemAnterior=DistanciaEnem;
                //masCerca=_enemigos[i]; 
                posEnemx=_enemigos[i]->getEnemigo()->getPosition().x;
                posEnemy=_enemigos[i]->getEnemigo()->getPosition().y;
            }
            _companyero->updateCompanyero(_window,posX, posY,_mapa, _camera,posEnemx,posEnemy);

       }
       _companyero->disparo(_window);
       
       //Enemigos
       for(int i = 0; i<10; i++){
           _enemigos[i]->updateNpc(_window, posX, posY);
       }
        
    }
    
    //Objetivo del puntero
    sf::Vector2f mouse_pos = _window->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*_window->getWindow()));
    _objective->setPosition(mouse_pos);

}

//Aqui vamos a llamar a la IA al boss
void Juego::updateIA() {

}

void Juego::controlarCamera() {
    if(_personaje->getPersonaje()->getPosition().x < 1500 && _personaje->getPersonaje()->getPosition().x > 425){
        _camera->setCenter(_personaje->getPersonaje()->getPosition().x, _camera->getCamera().getCenter().y);
        _barraSuperior->setPosition(_camera->getCamera().getCenter().x-960, _camera->getCamera().getCenter().y-550);
    }
    if(_personaje->getPersonaje()->getPosition().y < 1485  && _personaje->getPersonaje()->getPosition().y > 400){
        _camera->setCenter(_camera->getCamera().getCenter().x, _personaje->getPersonaje()->getPosition().y);
        _barraSuperior->setPosition(_camera->getCamera().getCenter().x-960, _camera->getCamera().getCenter().y-550);
    }
}
