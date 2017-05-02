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
    //Inicio la bala
    _bala = new sf::Sprite;
    _textBala = new sf::Texture;
    _textBala->loadFromFile("resources/bala.png");
    _bala->setTexture(*_textBala);
    _disparo = false;
     //Inicio el Survivor
    _survivor2 = new sf::Sprite;
    _textSurvivor2 = new sf::Texture;
    _textSurvivor2->loadFromFile("resources/survivor2-fusil.png");
    _survivor2->setTexture(*_textSurvivor2);
    _survivor2->setPosition(1250/4, 750/2); //Esto es el centro del juego, habra que cambiarlo
    _survivor2->setOrigin(100.0, 100.0);
    _survivor2->scale(0.8, 0.8);

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
    delete _survivor2;
    delete _textSurvivor2;
    delete _bala;
    delete _textBala;
}

void Companyero::drawCompanyero(Render* window) {
    //window->getWindow()->draw(*_vida);
    window->getWindow()->draw(*_survivor2);
}

void Companyero::tecladoCompanyero() {
    vida();

}


void Companyero::updateCompanyero(Render* window,float posX,float posY,Mapa * mapa) {//mapa es el enemigo al que tiene que disparar
    //MOVIMIENTO HACIA EL PERSONAJE PRINCIPAL
    sf::Vector2f movement(0.f, 0.f);
    sf::Time frameTime=frameClock.restart();
    
    float path = updatepath.getElapsedTime().asSeconds();
        
        if(path>0.5){
            perseguir(posX, posY, speedx, speedy, 1.5);
            updatepath.restart();
        }
    movement.x=speedx;
    movement.y=speedy;
    
    _survivor2->move(movement * frameTime.asSeconds());
    
    ////////////////////////////////////////////////////
    //Rotacion de Survivor2 CAMBIAR PARA QUE DISPARE AL ENEMIGO MAS CERCANO
   
        sf::Vector2f objetivo;
        objetivo.x = mapa->getBarril()->getPosition().x;
        objetivo.y = mapa->getBarril()->getPosition().y;
        
        int Distancia=sqrt(pow(objetivo.x-_survivor2->getPosition().x,2)+pow(objetivo.y-_survivor2->getPosition().y,2));
        float rotation;
        if(Distancia < 500){
        float dx = objetivo.x - _survivor2->getPosition().x;
        float dy = objetivo.y - _survivor2->getPosition().y;
        rotation = (atan2(dy, dx)) * 180 / PI2;
        _survivor2->setRotation(rotation);
        //Movemos el objetivo con el movimiento del raton
        //El update de la bala
        _bala->setPosition(_survivor2->getPosition().x, _survivor2->getPosition().y);
        _bala->setRotation(rotation);
        }
        else{
            sf::Vector2f movimientoMouse;
            movimientoMouse.x = sf::Mouse::getPosition(*window->getWindow()).x;
            movimientoMouse.y = sf::Mouse::getPosition(*window->getWindow()).y;
            float dx = movimientoMouse.x - _survivor2->getPosition().x;
            float dy = movimientoMouse.y - _survivor2->getPosition().y;
            rotation = (atan2(dy, dx)) * 180 / PI2;
            _survivor2->setRotation(rotation);
            //Movemos el objetivo con el movimiento del raton
            //El update de la bala
            _bala->setPosition(_survivor2->getPosition().x, _survivor2->getPosition().y);
            _bala->setRotation(rotation);
        }
     ///////////////////////////////////////////////////////////////////////////
   
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

void Companyero::perseguir(float posX, float posY, float& speedx, float& speedy, float factor) {
     bool abajo;
    bool derecha;
    bool diagonal=false;
    bool vavertical;
    //calculamos la distancia en x y en y del objetivo al enemgio
    movX=posX-_survivor2->getPosition().x;
    movY=posY-_survivor2->getPosition().y;
    
    if(fabs(movX)>300 || fabs(movY)>300){

    //comprobamos la dirección de movimiento del enemigo
    if(movX>0){
        derecha=true;
    }
    else{
        derecha=false;
        
    }
    if(movY>0){
        abajo=true;
    }
    else{
        abajo=false;
    }

    
    movX=fabs(movX);
    movY=fabs(movY);


    if((movX+20)>movY && (movX-20)<movY){

        diagonal=true;
        if(abajo && derecha){
            speedx=56*factor;
            speedy=56*factor;
        }
        else if(!abajo && derecha){
            speedx=56*factor;
            speedy=-56*factor;
        }
        else if(abajo && !derecha){
            speedx=-56*factor;
            speedy=56*factor;
        }
        else if(!abajo && !derecha){
            speedx=-56*factor;
            speedy=-56*factor;
        }
    }
    
    //Si nos movemos en horizontal
    else if(movX>movY){
        vavertical=false;
        if(derecha){
                
                speedx=80*factor;
                speedy=0;
            
        }
        else{
            speedx=-80*factor;
            speedy=0; 
           
            
        }
    }
    //si nos movemos en vertical
    else{
        vavertical=true;

        if(abajo){
                speedy=80*factor;
                speedx=0;
                
               
        }
        else{
            speedy=-80*factor;
            speedx=0;
          
        }
    }
 
    }
    else{
        speedy=0;
        speedx=0;
    }
}
