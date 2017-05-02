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
    
    _width = new int();
    _height = new int();
    _tileHeight = new int();
    _tileWidth = new int();
    _capaColisiones = new int*[64];  
    for(int i =0; i<64; i++){
        _capaColisiones[i] = new int[64];
    }
    
    _spritesMapa = new sf::Sprite*[64];
     for(int i =0; i<64; i++){
        _spritesMapa[i] = new sf::Sprite[64];
        }


    //Iniciamos las texturas
    _Agua = new sf::Texture();
    _Ciudad1 = new sf::Texture();
    _Ciudad2 = new sf::Texture();
    _Ciudad3 = new sf::Texture();
    _Ciudad4 = new sf::Texture();
    _Fuego1 = new sf::Texture();
    _Fuego2 = new sf::Texture();
    _Fuego3 = new sf::Texture();
    
    //Cargamos el mapa
    _mapa = new sf::Sprite;
    _textMapa = new sf::Texture;
    _textMapa->loadFromFile("tileset/Ciudad.jpg");
    _mapa->setTexture(*_textMapa);
    _mapa->setPosition((1920-3000)/2, (1080-3000)/2.0f);
    
   

}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
    delete _mapa;
    delete _textMapa;
    delete _barril;
    delete _barril2;
    delete _textBarril;
    delete _reloj;
    
    delete _width;
    delete _height;
    delete _tileHeight;
    delete _tileWidth;
    delete _Agua;
    delete _Ciudad1;
    delete _Ciudad2;
    delete _Ciudad3;
    delete _Ciudad4;
    delete _Fuego1;
    delete _Fuego2;
    delete _Fuego3;
   
    
     for(int i =0; i<64; i++){
        delete[] _spritesMapa[i];
    }
      for(int i =0; i<64; i++){
        delete[] _capaColisiones[i];
    }
}

void Mapa::cargarMapaXML(int nivel) {
    if(nivel == 1){
        
    }else if(nivel == 2){
        
    }else if(nivel == 3){
        
    }
   
   
}




void Mapa::drawMapa(Render* window) {
    window->getWindow()->draw(*_mapa);
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

