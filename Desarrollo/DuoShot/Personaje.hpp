/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.hpp
 * Author: sergio
 *
 * Created on 14 de marzo de 2017, 13:44
 */

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include "Motor/Render.hpp"
#include <math.h>       /* atan2 */
const float PI = 3.14159265;
const float speed = 80.f;


class Personaje {
public:
    Personaje();
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    void tecladoPersonaje();
    void drawPersonaje(Render * window);
    void updatePersonaje(Render * window);
private:
    sf::Sprite * _survivor, *_objective;
    sf::Texture * _textSurvivor, *_textObj;
    sf::Clock frameClock;
};

#endif /* PERSONAJE_HPP */

