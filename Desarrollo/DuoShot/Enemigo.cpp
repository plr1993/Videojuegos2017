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
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Motor/Render.hpp"
#include <string>




Enemigo::Enemigo() {
    
    //cargo las texturas
    enem=new sf::Sprite;
    enem->scale(3.5, 3.5);
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

    //elijo el tipo de enemigo y los coloco en el mapa

    tipo=rand()%7;
    //los de tipo impar apareceran arriba de la pantalla y los de tipo impar abajo, esto es temporal
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
    
    //asignamos la vida según el tipo de enemigo
    if(tipo==0 || tipo==1){
         enem->setTexture(*texture);
         _cantVida = 45;
    }
    else if(tipo==2 || tipo==3){
        enem->setTexture(*texture2);
        _cantVida = 30;
    }
    else if(tipo==4 || tipo==5){
        enem->setTexture(*texture3);
        _cantVida = 30;
    }
    else{
        enem->setTexture(*texture4);
        _cantVida = 20;
    }
    
    enem->setOrigin(48/2, 48/2);
    enem->setTextureRect(postext);
    
    if(tipo%2==0)
        enem->setRotation(180);
    
    speedx = 0;
    
    noKeyWasPressed = true;
    //configuramos la vida
    _vida = new sf::Sprite;
    _vida->setOrigin(1075, 74);
    _textVida = new sf::Texture;
    _textVida->loadFromFile("resources/vida/30.png");
    _vida->setTexture(*_textVida);
    _vida->setPosition(enem->getPosition().x, enem->getPosition().y-30);
    _vida->scale(0.05, 0.05);
    
    //balas de los enemigos que tengan armas
     balaprov = new sf::Sprite;
    texBala=new sf::Texture;
    if (!texBala->loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }   
    
    //true si esta disparando el enemigo
    disparo=false;
    explosion=false;
    
   
}

Enemigo::Enemigo(const Enemigo& orig) {
}

Enemigo::~Enemigo() {
    delete enem;
    delete texture;
    delete _vida;
    delete _textVida;
    delete texBala;
    delete balaprov;
}

void Enemigo::drawNpc(Render* window){
    window->getWindow()->draw(*enem);
    window->getWindow()->draw(*_vida);
    window->getWindow()->draw(*balaprov);
}

void Enemigo::perseguir(float posX, float posY, float &speedx, float &speedy, float factor){
    bool abajo;
    bool derecha;
    bool diagonal=false;
    bool vavertical;
    //calculamos la distancia en x y en y del objetivo al enemgio
    movX=posX-enem->getPosition().x;
    movY=posY-enem->getPosition().y;
    
    if(fabs(movX)>20 || fabs(movY)>20){

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
    //ESTO ES SOLO PARA EL SPRITE, LO COLOCA ORIENTADO CORRECTAMENTE
    if(diagonal){
        if(abajo && derecha){
            enem->setRotation(-45);
        }
        else if(abajo && !derecha){
            enem->setRotation(45);
        }
        else if(!abajo && derecha){
            enem->setRotation(-135);
        }
        else{
            enem->setRotation(135);
        }
    }
    else{
        if(vavertical){
            if(abajo){
                enem->setRotation(0);
            }
            else{
                enem->setRotation(180);
            }
        }
        else{
            if(derecha){
                enem->setRotation(-90);
            }
            else{
                enem->setRotation(90);
            }
        }
    }
    }
    else{
        speedy=0;
        speedx=0;
    }
}

void Enemigo::updateNpc(Render * window, float posX, float posY){
    //velocidad de cada tipo de enemigo
    if(tipo==0 || tipo==1){
        factor=1;
    }
    else if(tipo==2 || tipo==3 || tipo==4){
        factor=1.5;
    }
    else{
        factor=1.75;
    }
    
    sf::Vector2f movement(0.f, 0.f);
    sf::Time frameTime=frameClock.restart();
    if(fuera==false){
        
        //movimiento
        float path = updatepath.getElapsedTime().asSeconds();
        
        if(path>0.33){
            perseguir(posX, posY, speedx, speedy, factor);
            updatepath.restart();
        }
        
    
     //fin movimiento
    //comprueba colisiones con la pantalla
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
    
    //anima el sprite
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
    if(!disparo/* && (tipo==0 || tipo==1 || tipo==2 || tipo==3 || tipo==4)*/)
        comprobarEnemigo(posX, posY);
    else if(disparo/* && (tipo==0 || tipo==1 || tipo==2 || tipo==3 || tipo==4)*/)
        updateBala();
    
   /* if(!explosion && (tipo==5 || tipo==6))
        comprobarEnemigo(600, 370);
    else if(explosion && (tipo==5 || tipo==6))
        updateExplosion();*/
    
    movement.x=speedx;
    movement.y=speedy;
    
    enem->move(movement * frameTime.asSeconds());
    _vida->move(movement * frameTime.asSeconds());
    
    //update bala
    movement.x=velBalaX;
    movement.y=velBalaY;
    
    balaprov->move(movement * frameTime.asSeconds());
    
    
    
    
    
}



bool Enemigo::vida() {
    int spritevida;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(_cantVida > 1){
            _cantVida--;
            //este if es temporal
        if(_cantVida<1)
            _cantVida=1;
            std::ostringstream stream;
            
            if(tipo==0 || tipo==1){
                spritevida=_cantVida*30/45;
            }
            else if(tipo==2 || tipo==3 || tipo==4){
                spritevida=_cantVida;
            }
            else{
                spritevida=_cantVida*30/20;
            }
            
            stream << "resources/vida/" << spritevida << ".png";
            std::string result = stream.str();
            _textVida->loadFromFile(result);
            _vida->setTexture(*_textVida);
        }
        
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(_cantVida < 20){
            _cantVida++;
            std::ostringstream stream;

           
            stream << "resources/vida/" << _cantVida << ".png";
            std::string result = stream.str();
            _textVida->loadFromFile(result);
            _vida->setTexture(*_textVida);
        }
        
    }
    if(_cantVida<=0){
        return true;
    }
    else
        return false;
}

void Enemigo::colisiona() {
    
}

void Enemigo::destroy(){
    delete this;
}

float Enemigo::comprobarEnemigo(float posX, float posY){
     movX=posX-enem->getPosition().x;
     movY=posY-enem->getPosition().y;
     int maxdistancia;
     int mindistancia;
     if(tipo==0 || tipo==1){
         maxdistancia=800;
         mindistancia=50;
     }
     else if(tipo==2 || tipo==3 || tipo==4){
         maxdistancia=500;
         mindistancia=50;
     }
     
     else{
         maxdistancia=500;
         mindistancia=50;
     }
    
    if(fabs(movX)<maxdistancia && fabs(movX)>mindistancia && fabs(movY)<maxdistancia && fabs(movY)>mindistancia){
        posFinX=posX;
        posFinY=posY;
            //Y creo el spritesheet a partir de la imagen anterior
        balaprov->setTexture(*texBala);
        //Cojo el sprite que me interesa por defecto del sheet
   /*     if(tipo==5 || tipo==6){
            enem->setTextureRect(sf::IntRect(20, 769, 40, 30));
            balaprov->setScale(1,1); 
            balaprov->setPosition(enem->getPosition().x, enem->getPosition().y);
            balaprov->setOrigin(15, 15);
            explosion=true;
            
            relojexplosion.restart();
            
        }*/
 
     //   else{
             balaprov->setTextureRect(sf::IntRect(520, 858, 100, 20));
        balaprov->setScale(0.5,0.08);     
        // Lo dispongo en el centro de la pantalla
        balaprov->setPosition(enem->getPosition().x, enem->getPosition().y);
        if(movX<0)
            balaprov->setRotation(((atan(movY/movX))*180/3.1416)+180);
        else
            balaprov->setRotation((atan(movY/movX))*180/3.1416);
        disparo=true;
       // }
       
    }
    
}

void Enemigo::updateBala(){
    

    float angulo=balaprov->getRotation();
    if(angulo>=0 && angulo<90){
        velBalaX=500*(cos(angulo/180*3.1416));
        velBalaY=500*(sin(angulo/180*3.1416));
    }
    else if(angulo>=90 && angulo<180){
        velBalaX=500*(cos(angulo/180*3.1416));
        velBalaY=500*(sin(angulo/180*3.1416));
    }
    else if(angulo>=180 && angulo<270){
        velBalaX=500*(cos(angulo/180*3.1416));
        velBalaY=500*(sin(angulo/180*3.1416));
    }
    else if(angulo>=270 && angulo<360){
        velBalaX=500*(cos(angulo/180*3.1416));
        velBalaY=500*(sin(angulo/180*3.1416));
    }
    
 
    
    if(fabs(posFinX-balaprov->getPosition().x)<20 && fabs(posFinY-balaprov->getPosition().y)<20){
        disparo=false;
    }
  
    
    
}

void Enemigo::updateExplosion(){
    explosionrel = relojexplosion.getElapsedTime().asSeconds();
    if(explosionrel>0.7){
        _cantVida=1;
        explosion=false;
    }
    else if(explosionrel>0.4){
    
            balaprov->setTextureRect(sf::IntRect(0, 843, 185, 185));
            balaprov->setOrigin(92, 92);
          
    }
    
    else if(explosionrel>0.2){
    
            balaprov->setTextureRect(sf::IntRect(217, 882, 70, 70));
            balaprov->setOrigin(35, 35);
          
    }
    else if(explosionrel>0.1){
    
            balaprov->setTextureRect(sf::IntRect(84, 762, 50, 50));
            balaprov->setOrigin(25, 25);

    }
    
    balaprov->scale(balaprov->getScale().x+0.00000005, balaprov->getScale().y+0.00000005);
     
}

sf::Sprite * Enemigo::getEnemigo() {
    return enem;
}
