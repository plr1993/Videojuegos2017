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



class Enemigo {
public:
    Enemigo();
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();
    void drawNpc(Render * window);
    void updateNpc(Render * window);
     
private:
    sf::Sprite * enem;
    sf::Texture * texture;
    sf::Texture * texture2;
    sf::Texture * texture3;
    sf::Texture * texture4;
    sf::IntRect postext;
    float speedx, speedy;
    bool noKeyWasPressed;
    float inicioX, inicioY, finX, finY;
    sf::Clock frameClock;
    sf::Clock _reloj;
    sf::Clock _relojini;
    bool fuera;
};

#endif /* ENEMIGO_HPP */

