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
#include "Mapa.hpp"
#include <math.h>       /* atan2 */
#include <iostream>
#include <sstream>
using namespace std;

const float PI = 3.14159265;
const float speed = 150.f;


class Personaje {
public:
    Personaje();
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    void tecladoPersonaje();
    void drawPersonaje(Render * window);
    void updatePersonaje(Render * window);
    void disparo(Render * window);
    void cambiarArma();
    void vida();
    void colisionesMapa(Mapa * mapa);
    sf::Sprite * getPersonaje();
private:
    sf::Sprite * _survivor, *_objective, *_bala, *_vida;
    sf::Texture * _textSurvivor, *_textObj, *_textBala, *_textVida;
    sf::Clock * _frameClock;
    bool _disparo, _colision;
    int _cantVida;
};

#endif /* PERSONAJE_HPP */

