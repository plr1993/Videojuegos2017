/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.cpp
 * Author: luislb1
 * 
 * Created on March 23, 2017, 8:20 AM
 */

#include "Enemigo.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Motor/Render.hpp"

Enemigo::Enemigo() {
    enem=new sf::Sprite;
    texture=new sf::Texture;
    if(!texture->loadFromFile("resources/Alien.png"))
    {
        exit(0);
    }
    texture2=new sf::Texture;
    if(!texture2->loadFromFile("resources/Alien2.png"))
    {
        exit(0);
    }
    texture3=new sf::Texture;
    if(!texture3->loadFromFile("resources/Alien3.png"))
    {
        exit(0);
    }
    texture4=new sf::Texture;
    if(!texture4->loadFromFile("resources/Alien4.png"))
    {
        exit(0);
    }

    int tipo;
    tipo=rand()%7;

    if(tipo%2==1){
    inicioX=48;
    inicioY=3*48;
    finX=48*3;
    finY=4*48;
    int a=1+rand()%(21-1);
    enem->setPosition(62*a, -50);
    speedy=80.f;
    fuera=true;
    }
    else if(tipo%2==0){
        inicioX=48;
    inicioY=48;
    finX=3*48;
    finY=1*48;
    int a=1+rand()%(21-1);
    enem->setPosition(62*a, 800);
    speedy=-80.f;
    fuera=true;
    }
    else
        exit(1);
    
    postext=sf::IntRect(inicioX, inicioY, 48, 48);
    if(tipo==0 || tipo==1)
         enem->setTexture(*texture);
    else if(tipo==2 || tipo==3)
        enem->setTexture(*texture2);
    else if(tipo==4 || tipo==5)
        enem->setTexture(*texture3);
    else
        enem->setTexture(*texture4);
    
    enem->setOrigin(48/2, 48/2);
    enem->setTextureRect(postext);
    
    if(tipo%2==0)
        enem->setRotation(180);
    
    
    
   
    speedx = 0;
    
    noKeyWasPressed = true;
}

Enemigo::Enemigo(const Enemigo& orig) {
}

Enemigo::~Enemigo() {
    delete enem;
    delete texture;
}

void Enemigo::drawNpc(Render* window){
    window->getWindow()->draw(*enem);
}

void Enemigo::updateNpc(Render * window){
    sf::Vector2f movement(0.f, 0.f);
    sf::Time frameTime=frameClock.restart();
    if(fuera==false){
    if(rand()%50==1){
        int a=rand()%8;
        if(a==0){
            speedx=80.f;
            speedy=0;
            enem->setRotation(-90);
        }
        else if(a==1){
            speedx=-80.f;
            speedy=0;
            enem->setRotation(90);
        }
        else if(a==2){
            speedx=0;
            speedy=80.f;
            enem->setRotation(0);
        }
        else if(a==3){
            speedx=0;
            speedy=-80.f;
            enem->setRotation(180);
        }   
        else if(a==4){
            speedx=56.f;
            speedy=56.f;
            enem->setRotation(-45);
        }
        else if(a==5){
            speedx=56.f;
            speedy=-56.f;
            enem->setRotation(-135);
        }
        else if(a==6){
            speedx=-56.f;
            speedy=-56.f;
            enem->setRotation(-225);
        }
        else if(a==7){
            speedx=-56.f;
            speedy=56.f;
            enem->setRotation(45);
        }
    }
    if(enem->getPosition().x<=0){
        speedx=-speedx;
        enem->setRotation(-90);
    }
    
    else if(enem->getPosition().x>=window->getWindow()->getSize().x){
        speedx=-speedx;
        enem->setRotation(90);
    }
    
    else if(enem->getPosition().y<=0){
        speedy=-speedy;
        enem->setRotation(0);
    }
    else if(enem->getPosition().y>=window->getWindow()->getSize().y){
        speedy=-speedy;
        enem->setRotation(180);
    }
    }
    
   float rt = _reloj.getElapsedTime().asSeconds();
   float rtini = _relojini.getElapsedTime().asSeconds();
    if(rt > 0.15){
        if(postext.left<finX)
            postext.left+=48;
        else if(postext.top<finY){
            postext.left=inicioX;
            postext.top+=48;
        }
        if(postext.left==finX && postext.top==finY){
            postext.left=inicioX;
            postext.top=inicioY;
        }
       _reloj.restart();
    }
   if(rtini>2){
       fuera=false;
   }
    
    enem->setTextureRect(postext);
    
    
    movement.x=speedx;
    movement.y=speedy;
    
    enem->move(movement * frameTime.asSeconds());
   
    
}

