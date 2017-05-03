/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.hpp
 * Author: luislb1
 *
 * Created on March 23, 2017, 8:20 AM
 */

#ifndef ENEMIGO_HPP
#define ENEMIGO_HPP
#include "Motor/Render.hpp"
#include <sstream>

using namespace std;



class Enemigo {
public:
    Enemigo();
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();
    void drawNpc(Render * window);
    void updateNpc(Render * window, float posX, float posY);
    void colisiona();
    float comprobarEnemigo(float posX, float posY);
    bool vida();
    void updateBala();
    void updateExplosion();
    void destroy();
    void perseguir(float posX, float posY, float &speedx, float &speedy, float factor);
     
private:
    sf::Sprite * enem, *_vida, *balaprov;
    sf::Texture * texture, *texture2, *texture3, *texture4, *_textVida, *texBala;
    sf::IntRect postext;
    int _cantVida, tipo;
    float speedx, speedy, inicioX, inicioY, finX, finY, factor;
    //bala
    float posFinX, posFinY, velBalaX, velBalaY;
    //variables que marcan la distancia al enemigo:
    float movX, movY, explosionrel;
    bool noKeyWasPressed, fuera, disparo, explosion;
    sf::Clock frameClock, _reloj, _relojini, updatepath, relojexplosion;

};

#endif /* ENEMIGO_HPP */

