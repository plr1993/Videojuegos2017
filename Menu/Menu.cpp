/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: sergio
 * 
 * Created on 25 de marzo de 2017, 18:29
 */

#include "Menu.hpp"
#include "Motor/Render.hpp"
#include "Motor/Text.hpp"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string> 
#include <iostream>

Menu::Menu() {
    
    //Inicio las variables
    _fuente = new sf::Font;
    _fondo1 = new sf::Texture;
    _fondo2 = new sf::Texture;
    _subfondo1 = new sf::Texture;
    _subfondo2 = new sf::Texture;
    _botones = new sf::Texture;
    _titulo = new sf::Texture;
    _sfondo1 = new sf::Sprite;
    _sfondo2 = new sf::Sprite;
    _ssubfondo1 = new sf::Sprite;
    _ssubfondo2 = new sf::Sprite;
    _stitulo = new sf::Sprite;
    _botonJugar1=new sf::Sprite;
    _botonJugar2=new sf::Sprite;
    _botonJugar3=new sf::Sprite;
    _botonJugar4=new sf::Sprite;
    _botonOp1=new sf::Sprite;
    _botonOp2=new sf::Sprite;
    _botonOp3=new sf::Sprite;
    _botonOp4=new sf::Sprite;
    _botonSa1=new sf::Sprite;
    _botonSa2=new sf::Sprite;
    _botonSa3=new sf::Sprite;
    _botonSa4=new sf::Sprite;
  
    //_survivor->setOrigin(100.0, 100.0);
    //_survivor->scale(0.8, 0.8);
    
    
    if (!_fuente->loadFromFile("resources/sansation.ttf"))
        std::cerr << "Error cargando la imagen cuadro.png";
    if (!_fondo1->loadFromFile("resources/fondo1.png"))
        std::cerr << "Error cargando la imagen fondo1.png";
    if (!_fondo2->loadFromFile("resources/fondo2.png"))
        std::cerr << "Error cargando la imagen fondo2.png";
    if (!_subfondo1->loadFromFile("resources/subfondo1.png"))
        std::cerr << "Error cargando la imagen fondo1.png";
    if (!_subfondo2->loadFromFile("resources/subfondo2.png"))
        std::cerr << "Error cargando la imagen subfondo2.png";
    if (!_titulo->loadFromFile("resources/Titulo.png"))
        std::cerr << "Error cargando la imagen titulo.png";
    if (!_botones->loadFromFile("resources/Botones.png"))
        std::cerr << "Error cargando la imagen Botones.png";
    
    _sfondo1->setTexture(*_fondo1);
    _sfondo2->setTexture(*_fondo2);
    _ssubfondo1->setTexture(*_subfondo1);
    _ssubfondo2->setTexture(*_subfondo2);
    _stitulo->setTexture(*_titulo);
    
    _botonJugar1->setTexture(*_botones);
    _botonJugar2->setTexture(*_botones);
    _botonJugar3->setTexture(*_botones);
    _botonJugar4->setTexture(*_botones);
    _botonOp1->setTexture(*_botones);
    _botonOp2->setTexture(*_botones);
    _botonOp3->setTexture(*_botones);
    _botonOp4->setTexture(*_botones);
    _botonSa1->setTexture(*_botones);
    _botonSa2->setTexture(*_botones);
    _botonSa3->setTexture(*_botones);
    _botonSa4->setTexture(*_botones);
    
    _botonJugar1->setTextureRect(sf::IntRect(0, 0, 160, 60));
    _botonJugar1->setPosition(750, 100);
    _botonJugar1->scale(2, 2);
    _botonJugar2->setTextureRect(sf::IntRect(180, 0, 160, 60));
    _botonJugar2->setPosition(770, 100);
    _botonJugar2->scale(2, 2);
    _botonJugar3->setTextureRect(sf::IntRect(180, 70, 160, 60));
    _botonJugar3->setPosition(770, 100);
    _botonJugar3->scale(2, 2);
    _botonJugar4->setTextureRect(sf::IntRect(0, 70, 160, 60));
    _botonJugar4->setPosition(760, 100);
    _botonJugar4->scale(2, 2);
    
    _botonOp1->setTextureRect(sf::IntRect(0, 140, 160, 60));
    _botonOp1->setPosition(750, 300);
    _botonOp1->scale(2, 2);
    _botonOp2->setTextureRect(sf::IntRect(180, 140, 160, 60));
    _botonOp2->setPosition(770, 300);
    _botonOp2->scale(2, 2);
    _botonOp3->setTextureRect(sf::IntRect(180, 206, 160, 67));
    _botonOp3->setPosition(770, 300);
    _botonOp3->scale(2, 2);
    _botonOp4->setTextureRect(sf::IntRect(0, 210, 160, 60));
    _botonOp4->setPosition(760, 300);
    _botonOp4->scale(2, 2);
    
    
    _botonSa1->setTextureRect(sf::IntRect(0, 280, 160, 60));
    _botonSa1->setPosition(750, 480);
    _botonSa1->scale(2, 2);
    _botonSa2->setTextureRect(sf::IntRect(180, 280, 160, 60));
    _botonSa2->setPosition(770, 480);
    _botonSa2->scale(2, 2);
    _botonSa3->setTextureRect(sf::IntRect(180, 340, 160, 65));
    _botonSa3->setPosition(770, 470);
    _botonSa3->scale(2, 2);
    _botonSa4->setTextureRect(sf::IntRect(0, 340, 160, 60));
    _botonSa4->setPosition(760, 480);
    _botonSa4->scale(2, 2);
    
    
    
    _sfondo1->setPosition(0, 0); //Esto es el centro del juego, habra que cambiarlo
    _sfondo2->setPosition(0, 0); //Esto es el centro del juego, habra que cambiarlo
    _ssubfondo1->setPosition(0, 0); //Esto es el centro del juego, habra que cambiarlo
    _ssubfondo2->setPosition(-50, 0); //Esto es el centro del juego, habra que cambiarlo
    _stitulo->setPosition(0, 0); //Esto es el centro del juego, habra que cambiarlo
    _stitulo->scale(0.5, 0.5);
    
    _sfondo1->scale(2, 1.2); //Esto es el centro del juego, habra que cambiarlo
    _sfondo2->scale(2, 1.2); //Esto es el centro del juego, habra que cambiarlo
    _ssubfondo1->scale(2, 1.2); //Esto es el centro del juego, habra que cambiarlo
    _ssubfondo2->scale(2.2, 1.2); //Esto es el centro del juego, habra que cambiarlo

    
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
    delete _fuente;
    delete _fondo1;
    delete _fondo2;
    delete _subfondo1;
    delete _subfondo2;
    delete _sfondo1;
    delete _sfondo2;
    delete _ssubfondo1;
    delete _ssubfondo2;
    delete _stitulo;
    delete _titulo;
}

//Aqui pintamos todo lo del menu, recibo por parametro la ventana si nos no puedes pintar
void Menu::drawMenu(Render* window) {
    //Pintamos el rectangulo
    //Le tienes que pasar el rectangulo, para ello se lo pasas con el *_rectPrueba...para acceder al rectangulo en memoria
    //Si le pasas _rectPrueba, le estas pasando un puntero y no vale.
    if (fon==1) {
        window->getWindow()->draw(*_ssubfondo1);
        window->getWindow()->draw(*_sfondo1); 
    } else {
        window->getWindow()->draw(*_ssubfondo2); 
        window->getWindow()->draw(*_sfondo2); 
    } 
    switch(pos) {
        case 0: {   
            window->getWindow()->draw(*_botonJugar1);
            window->getWindow()->draw(*_botonOp1);
            window->getWindow()->draw(*_botonSa1);
            break;
        } 
        case 1: {  
            if (aux3<2) {
               window->getWindow()->draw(*_botonJugar4);
               aux3++;
            }else if(aux3>=2 && aux3<4){
               window->getWindow()->draw(*_botonJugar2);
               aux3++;
            }else{
               window->getWindow()->draw(*_botonJugar3);
               aux3++;
            }
            window->getWindow()->draw(*_botonOp1);
            window->getWindow()->draw(*_botonSa1);
            break;
        }
        case 2: {  
            if (aux3<2) {
               window->getWindow()->draw(*_botonOp4);
               aux3++;
            }else if(aux3>=2 && aux3<4){
               window->getWindow()->draw(*_botonOp2);
               aux3++;
            }else{
               window->getWindow()->draw(*_botonOp3);
               aux3++;
            }
            window->getWindow()->draw(*_botonJugar1);
            window->getWindow()->draw(*_botonSa1);
            break;
        } 
        case 3: {  
            window->getWindow()->draw(*_botonJugar1);
            window->getWindow()->draw(*_botonOp1);
            if (aux3<2) {
               window->getWindow()->draw(*_botonSa4);
               aux3++;
            }else if(aux3>=2 && aux3<4){
               window->getWindow()->draw(*_botonSa2);
               aux3++;
            }else{
               window->getWindow()->draw(*_botonSa3);
               aux3++;
            }
            break;
        } 
    }
    window->getWindow()->draw(*_stitulo);

    
}
void Menu::updateMenu(Render * window) {
    if (fon==1) {
        if(aux<100){
            _ssubfondo1->setPosition(_ssubfondo1->getPosition().x+0.3,_ssubfondo1->getPosition().y);
            aux++;
        }
        if(aux>=100){
           _ssubfondo1->setPosition(_ssubfondo1->getPosition().x-0.3,_ssubfondo1->getPosition().y);
            aux++; 
        }
        if(aux==200)
            aux=0;
    } else {
        if(aux<100){
            _ssubfondo2->setPosition(_ssubfondo2->getPosition().x+0.3,_ssubfondo2->getPosition().y);
            aux++;
        }
        if(aux>=100){
           _ssubfondo2->setPosition(_ssubfondo2->getPosition().x-0.3,_ssubfondo2->getPosition().y);
            aux++; 
        }
        if(aux==200)
            aux=0;
    }
    if(aux2<55){
        p1=p1+0.02f;
        p2=p2+0.02f;
        _stitulo->scale(p1,p2);
        aux2++;
    }
    sf::Vector2f movimientoMouse;
    movimientoMouse.x = sf::Mouse::getPosition(*window->getWindow()).x;
    movimientoMouse.y = sf::Mouse::getPosition(*window->getWindow()).y;
    if(movimientoMouse.x>=775 && movimientoMouse.x<=1070 && movimientoMouse.y>=120 && movimientoMouse.y<=200 ){
        pos=1;
    }else if(movimientoMouse.x>=775 && movimientoMouse.x<=1070 && movimientoMouse.y>=320 && movimientoMouse.y<=400){
        pos=2;
    }else if(movimientoMouse.x>=775 && movimientoMouse.x<=1070 && movimientoMouse.y>=490 && movimientoMouse.y<=560){
        pos=3;
    }else{
        pos=0;
        aux3=0;
    }
}
